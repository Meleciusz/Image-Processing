#pragma once
#ifdef JAApp_API
#undef JAApp_API
#define JAApp_API __declspec(dllexport)
#else
#define JAApp_API __declspec(dllimport)
#endif

typedef unsigned char byte;

extern "C" void JAApp_API Proc1(byte * f_p, byte * f_p_save, int numpixels, int szer, int wys, int x, int y, int padding);