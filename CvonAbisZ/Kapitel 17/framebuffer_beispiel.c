#include<stdlib.h>
#include<stdio.h>
FILE *FB;
unsigned long int BackBuff[0xC0000]; // 1024x768 Pixel Hintergrundpuffer

void InitGraph() {
	FB=fopen("/dev/fb0","r+b"); // Zugriff lesend UND schreibend
}

void CloseGraph() {
	fclose(FB);
}

void PSet(long int x, long int y, long int Color) {
	long int Address=(1024*y)+x; // Eine Zeile hat 1024 Pixel
	BackBuff[Address]=Color; // Pixel im Back Buffer ablegen
}

void Update() {
	fseek(FB,0,SEEK_SET); // Mit "fseek" an die Adresse 0 von FB gehen
	fwrite(&BackBuff,0x300000,1,FB); // Daten per Block-DMA schreiben
}

int main(void) {
	InitGraph(); // Hintergrund wird schwarz
	PSet(100,100,0xffffff); // RGB 255,255,255=Weiﬂ
	Update();
	return EXIT_SUCCESS;
}
