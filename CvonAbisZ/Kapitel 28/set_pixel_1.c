// set_pixel_1.c
#include<stdio.h>
#define XRES 1024 // Bei Bedarf anpassen
#define YRES 768 // Bei Bedarf anpassen
FILE *FB; // Framebuffer-Ger‰tedatei, ist /dev/fb0
 
void InitGraph() {
	FB=fopen("/dev/fb0","r+b"); // Zugriff auf FB0 lesend UND schreibend
	BufferSize=XRES*YRES*4;
}
 
void CloseGraph() {
	fclose(FB);
}
 
void PSet(long int x, long int y, long int Color) {
	long int Pos=(XRES*4*y)+4*x; // Eine Zeile hat XRES Pixel
	fseek(FB,Pos,SEEK_SET); // Mit "fseek" an die Adresse Pos von FB gehen
	fwrite(&Color,4,1,FB); // Color hat 4 Byte
}
 
int main(void) {
	InitGraph(); // Hintergrund wird schwarz
	PSet(100,100,0xffffff); // RGB 255,255,255=Weiﬂ
	return EXIT_SUCCESS;
}
