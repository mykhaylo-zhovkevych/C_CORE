// ConsoleGrafik.c
#include<Windows.h> // Windows-API
#include<stdio.h> // Standard-C-Lib
#include<conio.h> // Für getch() unter Windows
 
HDC CONSOLE_DC;
 
void InitGraph() {
	HWND hwnd = FindWindow("ConsoleWindowClass", NULL);
	CONSOLE_DC = GetDC(hwnd);
}
 
int main(void) {
	InitGraph(); // Grafik initialisieren
	SetPixel(CONSOLE_DC,100,100,0xffffff); // Weißes Pixel
	getch(); // Auf eine Taste warten
	EXIT_SUCCESS;
}
