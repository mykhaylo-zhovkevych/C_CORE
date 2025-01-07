#include<Windows.h>
#include<stdio.h>
#include<conio.h>

unsigned long int *_PBits; // Globales Pixel-Array
unsigned long int _XSize,_YSize; // Screen-Infos
HDC Console_DC; // HDC der Konsole
HDC HDCBackBuff; // HDC des Backbuffers

void PSet(long int x, long int y, long int Color) {
	_PBits[_XSize*y+x]=Color;
}

long int Point(long int x, long int y, long int Color) {
	return _PBits[_XSize*y+x];
}

void InitGraph(unsigned long int Width, unsigned long int Height) {
	HWND hwnd=FindWindow("ConsoleWindowClass",NULL);
	Console_DC=GetDC(hwnd);
	BITMAPINFO bmi;
	bmi.bmiHeader.biSize=sizeof(BITMAPINFO);
	bmi.bmiHeader.biWidth=_XSize;
	bmi.bmiHeader.biHeight=-_YSize;
	bmi.bmiHeader.biPlanes=1;
	bmi.bmiHeader.biBitCount=32;
	bmi.bmiHeader.biCompression=BI_RGB;
	bmi.bmiHeader.biSizeImage=_XSize*_YSize*4;
	HDCBackBuff=CreateCompatibleDC(Console_DC);
	HBITMAP BitmapBackBuff=CreateDIBSection(0,&bmi,0,(void**)&_PBits,NULL,0);
	SelectObject(HDCBackBuff,BitmapBackBuff);
}

void Update() {
	BitBlt(Console_DC,0,0,_XSize,_YSize,HDCBackBuff,0,0,SRCCOPY);
}

int main(void) {
	InitGraph(1024,768);
	PSet(100,100,0xffffff);
	Update();
	getch();
	return 0;
}
