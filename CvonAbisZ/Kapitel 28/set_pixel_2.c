/* set_pixel_2.c */
#include<stdio.h>
#define XRES 1024 // Bei Bedarf anpassen
#define YRES 768 // Bei Bedarf anpassen
FILE *FB; // Framebuffer-Gerätedatei, ist /dev/fb0
unsigned long int BackBuff[XRES+YRES*4];
long int BufferSize; // Größe des Framebuffers in Bytes
 
void InitGraph() {
	FB=fopen("/dev/fb0","r+b"); // Zugriff auf FB0 lesend UND schreibend
	BufferSize=XRES*YRES*4;
}
 
void CloseGraph() {
	fclose(FB);
}
 
void PSet(long int x, long int y, long int Color) {
	long int Pos=(XRES*y)+x; // Eine Zeile hat XRES Pixel
	BackBuff[Pos]=Color; // Pixel im Back Buffer ablegen
}
 
void Update() {
	fseek(FB,0,SEEK_SET); // Mit "fseek" an die Adresse 0 von FB gehen
	fwrite(&BackBuff,BufferSize,1,FB); // sizeof funktioniert hier nicht!
}
 
int main(void) {
	InitGraph(); // Hintergrund wird schwarz
	PSet(100,100,0xffffff); // RGB 255,255,255=Weiß
	Update();
	return EXIT_SUCCESS;
}
