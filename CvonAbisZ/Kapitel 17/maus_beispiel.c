#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

FILE *MOUSE;
int Mouse=0;
long int XMouse=0,YMouse=0,BMouse=0;

void InitMouse()
{
	MOUSE=open("/dev/hidraw3",O_NONBLOCK);
}

void DeinitMouse()
{
	close(MOUSE);
}

void ReadMouse() {
    long int LenRead=0,DX=0,DY=0;
	char MousePacket[4];
	LenRead=read(MOUSE,MousePacket,4);
	if (LenRead!=-1) {
	    	BMouse=MousePacket[0]; // Button Byte
 		    DX=MousePacket[1];
        if ((MousePacket[1]&0x80)==0x80) { DX-=256; } // rel. X-Koordinate
		    DY=MousePacket[2];
        if ((MousePacket[2]&0x80)==0x80) { DY-=256; } // rel. Y-Koordinate
		    XMouse=XMouse+DX; YMouse=YMouse+DY; // absolute Koordinaten
	    	// Der Bildschirm wurde hier auf 1024x768 Pixel eingestellt
		    if (XMouse<0) { XMouse=0; } if (XMouse>=1024) { XMouse=1024; }
		    if (YMouse<0) { YMouse=0; } if (YMouse>=768) { YMouse=767; }
	}
}

int main(void) {
   InitMouse();
   while ((BMouse|0x02)!=0x02) {
      while (BMouse==0) { ReadMouse(); }
      printf("Mauskoordinaten:X=%ld,Y=%ld\n",XMouse,YMouse);
   }
   DeInitMouse(); return EXIT_SUCCESS;
}
