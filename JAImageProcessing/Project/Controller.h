#pragma once
#include "Utilities.h"
#include <thread>
#include <vector>
#include <math.h>
//using namespace std;

//typedef unsigned char byte;
typedef void(_stdcall* Proc1)(byte*, byte*, int, int, int, int, int, int);
//typedef double(_stdcall* ReadTime1)(byte*, byte*, int);
class Controller
{
public:
	BMPFile* loadedFileA;
	BMPFile* outputFile;
	int numThreads = ;
	//int numpixels = loadedFileA->infoHeader->biWidth * loadedFileA->infoHeader->biHeight;
	HINSTANCE library;
	
	Controller()
	{
		loadedFileA = new BMPFile("kratos.bmp");
		outputFile = new BMPFile(*loadedFileA);
		library = LoadLibraryA("JADll.dll");
	}
	
	~Controller()
	{
		delete loadedFileA;
		delete outputFile;
	}
	
	float smooth_func()
	{
		int numpixels = loadedFileA->infoHeader->biWidth * loadedFileA->infoHeader->biHeight;
		int szer = loadedFileA->infoHeader->biWidth;
		int wys = loadedFileA->infoHeader->biHeight;
		
		
		Proc1 proc1 = (Proc1)GetProcAddress(library, "Proc1");

		int pixels_sections = numpixels / numThreads; // ostatni watek musi obsluzyc reszte pikseli bo int zaokragla w dol 
		std::vector<std::thread> threads(numThreads);
		
		int padding = 0;
		if ((szer * 3) % 4 != 0)
		{
			padding = 4 - (szer*3) % 4;
		}
	
		int last_thread_numpixels = 0;
		int padding_correction = 0;

		std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();


		if (numThreads == 1)
		{
			threads[0] = std::thread(proc1, loadedFileA->pixels, outputFile->pixels, pixels_sections, szer, wys, 0, 0, padding);
		}
		else
		{
			int i = 0;
			for (i = 0; i < numThreads -  1; i++)
			{
				padding_correction = padding * (ceil(i * pixels_sections / szer) );/*i * pixels_sections % (szer - 1);*/

				threads[i] = std::thread(proc1, loadedFileA->pixels + i * (pixels_sections * 3) + padding_correction, outputFile->pixels + i * (pixels_sections * 3) + padding_correction, pixels_sections, szer, wys,/*x*/ (i * pixels_sections % szer),/*y*/ ceil(i * pixels_sections / szer), padding);

			}

			int todo = numpixels - (i * pixels_sections);
			threads[i + 1] = std::thread(proc1, loadedFileA->pixels + i * (pixels_sections * 3) + padding_correction, outputFile->pixels + i * (pixels_sections * 3) + padding_correction, todo, szer, wys,/*x*/ (i * pixels_sections % szer),/*y*/ ceil(i * pixels_sections / szer), padding);

		}

		for (auto& th : threads)
		{
			th.join();
		}
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		float elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
		

		
		/*ReadTime1 readtime_1 = (ReadTime1)GetProcAddress(library, "Proc1");
		std::cout<<readtime_1(loadedFileA->pixels, outputFile->pixels, numpixels));*/
		//std::thread thr(proc1);
			//thr.join();

		return elapsed;
		outputFile->saveFile("c.bmp");
	}
};