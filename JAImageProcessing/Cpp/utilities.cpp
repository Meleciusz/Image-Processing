#include "pch.h"
#include "utulities.h"
#include <iostream>
#include <chrono>
using namespace std;

void Proc1(byte* f_p, byte* f_p_save, int numpixels, int szer, int wys, int x, int y, int padding) {

	for (int i = 0; i < numpixels; i++)
	{
		double u = 0.5; double v = 0.5; byte* Q11 = nullptr; byte* Q21 = nullptr; byte* Q12 = nullptr; byte* Q22 = nullptr;

		if (x == 0 || x == szer-1  || y == 0 || y == wys-1)
		{
			;
		}
		else
		{
			
			Q11 = f_p - (szer * 3 + padding) - 3; //xmm0
			Q21 = f_p - (szer * 3 + padding) + 3; //xmm1
			Q12 = f_p + (szer * 3 + padding) - 3; //xmm2
			Q22 = f_p + (szer * 3 + padding) + 3; //xmm3
			

			for (int j = 0; j < 3; j++)
			{
				int p1 = *(Q11 + j) >> 2; // mnozenie razy 1/2 to przesuniecie bitowe w prawo
				int p2 = *(Q12 + j) >> 2;
				int p3 = *(Q21 + j) >> 2;
				int p4 = *(Q22 + j) >> 2;
				int p = p1 + p2 + p3 + p4;
				*(f_p_save + j) = p;
			}
		}	

		x += 1;
		f_p += 3;
		f_p_save += 3;
		if (x == szer)
		{
			y += 1;
			x = 0;
			f_p += padding;
			f_p_save += padding;
		}
	}
}