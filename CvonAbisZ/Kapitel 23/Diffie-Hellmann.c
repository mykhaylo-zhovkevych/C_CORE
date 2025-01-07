// Diffie-Hellmann.c
#include<stdio.h>
#include<bigint.h>

int main(void) {
	big p,g,a,b,o,A,B,KA,KB;
	InitBig(p,32); InitBig(g,32);
	InitBig(a,32); InitBig(b,32);
	InitBig(A,32); InitBig(B,32);
	InitBig(KA,32); InitBig(KB,32);
	InitBig(o,32); InitDec(o,"1"); // o=1
	InitHex(p,"24503c5ff3de2c96a40fbbcd8842e685");
	InitHex(g,"4bc3b168bbcb2c75eea116d1efd7bf7f");
	InitHex(a,"b3ed4f134990442a9f0b72e779ef90ad");
	InitHex(b,"43420ae1f164b41cfe11968048e918bd");
	ModExp(A,g,a,p); // Alice sendet A an Bob
	printf("Alice sendet an Bob: "); OutputHex(A,16);
	ModExp(B,g,b,p); // Bob sendet B an Alice
	printf("Bob sendet an Alice: "); OutputHex(B,16);
	ModExp(KA,B,a,p); // Alice
	printf("Alices Geheimnis ist:"); OutputHex(KA,16);
	ModExp(KB,A,b,p); // Bob
	printf("Bobs Geheimnis ist:  "); OutputHex(KB,16);
	return 0;
}
