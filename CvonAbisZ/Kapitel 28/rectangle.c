/* rectangle.c */
void Rectangle(long int x1, long int y1, long int x2, long int y2, 
long int Color) {
	long int Temp=0,x=0,y=0;
	if (x1>x2) { Temp=x1; x1=x2; x2=Temp; }
	if (y1>y2) { Temp=y1; y1=y2; y2=Temp; }
	for (y=y1; y<=y2; y++) {
		for (x=x1; x<=x2; x++) {
			PSet(x,y,Color);
		}
	}
}
