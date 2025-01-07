// RSA.c
#include<stdio.h>
#include<bigint.h>
#include<conio.h>
int main(void) {
	printf("Bitte eine Taste drücken, um den Zufallsgenerator zu starten\n");
	getch(); srand(clock());
	big o,p,q,s,t,N,F,e,d,m,mm,c;
	InitBig(o,64); InitBig(p,64); InitBig(q,64); InitBig(s,64);
	InitBig(t,64); InitBig(N,64); InitBig(F,64); InitBig(e,64);
	InitBig(d,64); InitBig(m,64); InitBig(mm,64); InitBig(c,64);
	InitDec(o,"1"); InitHex(mm,"0123456789");
	while (m!=mm) {
		printf("Bitte warten, Alice generiert ihre Schlüssel.....\n");
		RandPrime(p,16); printf("p="); OutputHex(p,32);
		RandPrime(q,16); printf("q="); OutputHex(q,32);
		RandPrime(e,16); printf("Alices öffentlicher Schlüssel:\n");
		OutputHex(e,32);
		N=p*q; F=(p-o)*(q-o);
		EGGT(e,F,s,t); d=s;
		printf("Alices privater Schlüssel:\n"); d.OutputHex(32);
		InitHex(m,"0123456789");
		ModExp(c,m,e,N); ModExp(m,c,d,N);
		if (m!=mm) {
			printf("p,q oder e ungültig, generiere neue Schlüssel...\n");
		}
	}
	InitASCII(m,"IN BOBS GARTEN");
	printf("RSA-Nachricht von Bob an Alice:\n"); ModExp(c,m,e,N);
	OutputHex(c,32);
	printf("Alice trifft sich mit Bob:\n"); ModExp(m,c,d,N);
	OutputText(m);
	return 0;
}
