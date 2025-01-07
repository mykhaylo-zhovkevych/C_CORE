/* circle.c */
void Circle(long int x1, long int y1, long int r, long int BorderColor) {
	double rd=0,x1d=0,y1d=0,phi=0,s=0,L=0,U=0;
	unsigned long int k=0;
	L=(x1-y1)/(x1+y1);
	U=(x1+y1)*_PI*(1+(3*L*L)/(10+sqrt(4-3*L*L)));
	s=(2*_PI)/U;
	x1d=(double)(x1); y1d=(double)(y1); rd=(double)(r);
	for (phi=-_PI; phi<_PI; phi+=s) {
		PSet(x1d+rd*sin(phi),y1d+rd*cos(phi),BorderColor);
	}
}
