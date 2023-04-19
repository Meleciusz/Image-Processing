#include "pch.h"
#include "Utilities.h"
#include "Controller.h"

//typedef int(__cdecl* Proc2)(int*);

int main() {
	
	Controller sth;
    float elapsed = 0;
    //for (int i = 0; i < 100; i++)
   // {
        elapsed += sth.smooth_func();
   // }

    //elapsed = elapsed / 100;
    std::cout << "Time measured: " << elapsed << std::endl;
	//int* ptr = new int(20);
	
    
    //HINSTANCE library;
    //Proc2 ProcAdd; 
    //BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
    //library = LoadLibrary(TEXT("JADll.dll"));
    //ProcAdd = (Proc2)GetProcAddress(library, "Proc2"); 
    //int* ptr = new int(35);
    //cout << "adress value: " << ProcAdd(ptr);
    //fFreeResult = FreeLibrary(library); 

	return 0;
}