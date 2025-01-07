// enigma.c
#include<conio.h> // für getch() unter Windows
#include<stdio.h>

char Reflektor[27]="yruhqsldpxngokmiebfzcwvjat ";
char Walze[10][27]={
"                           ",
"                           ",
"                           ",
"abcdefghijklmnopqrstuvwxyz ",
"bdfhjlcprtxvznyeiwgakmusqo ",
"ajdksiruxblhwtmcqgznpyfvoe ",
"ekmflgdqvzntowyhxuspaibrcj ",
"bdfhjlcprtxvznyeiwgakmusqo ",
"ajdksiruxblhwtmcqgznpyfvoe ",
"ekmflgdqvzntowyhxuspaibrcj "};

char Stecker[26];
 
int Suche(int W, char Buchstabe) {
	int Pos=-1, i=0;
	while ((i<26)&&(Pos==-1)) {
		if (Walze[W][i]==Buchstabe) { Pos=i; }
		i++;
	}
	return Pos;
}

char Lookup(int W, char Buchstabe) {
	char C=Walze[W][Buchstabe-'a'];
	return C;
}

char InvLookup(int W, char Buchstabe) {
	char C=0;
	int Pos=Suche(W,Buchstabe);
	if (Pos>=0) { C='a'+Pos; } 
	return C;
}

void Rotiere(int W) {
	int C=0;
	char Temp=0;
	Temp=Walze[W][0];
	for (int i=1; i<26; i++) {
		Walze[W][i-1]=Walze[W][i]-1;
		if (Walze[W][i-1]<'a') { Walze[W][i-1]='z'; }
	}
	Temp--;
	if (Temp<'a') { Temp='z'; }
	Walze[W][25]=Temp;
}

int GetWalzenZaehler(int W) {
	return Walze[W][26];
}

void IncWalzenZaehler(int W) {
	Walze[W][26]++;
}

void SetWalzenZaehler(int W, int V) {
	Walze[W][26]=V;
}

char Reflekt(char In) {
    return Reflektor[In-'a'];
}

char EnigmaZeichen(char In) {
	char Out=In;
	int i=0;
	Out=Stecker[Out-'a']; // Erste Ersetzung
	// Standard:abcdefghijklmnopqrstuvwxyz
	// Dies bedeutet, dass alle Zeichen auf sich selbst abgebildet werden
	// Um bestimmte Zeichen zu "steckern", müssen diese miteinander vertauscht werden
	// Beispiel: a und e, sowie t und z sollen durch einen Stecker verbunden werden
	// Neuer Stecker-Array:ebcdafghijklmnopqrszuvwxyt
	for (i=0; i<3; i++) {
		Out=Lookup(i,Out); // Die ersten drei Walzen durchlaufen
	}
	Out=Reflekt(Out); // Umehrung durch den Reflektor
	for (i=2; i>0; i--) {
		Out=InvLookup(i,Out); // Die ersten drei Walzen umgekehrt durchlaufen
	}
	return Out;
}

char Enigma(char In) {
	char Out;
	if (In==' ') { Out=In; }
	else {  
		Out=EnigmaZeichen(In);
		Rotiere(0); IncWalzenZaehler(0);
		if (GetWalzenZaehler(0)==26) { SetWalzenZaehler(0,0);
		Rotiere(1); IncWalzenZaehler(1); }
		if (GetWalzenZaehler(1)==26) { SetWalzenZaehler(1,0);
		Rotiere(2); IncWalzenZaehler(2); }
		if (GetWalzenZaehler(2)==26) { SetWalzenZaehler(2,0); }
	}
	return Out;
}

void main() {
	char C;
	int a,b,c,i;
	printf("Walzen einsetzen:\n");
	printf("Walze an Position 0:"); scanf("%d",&a);
	printf("Walze an Position 1:"); scanf("%d",&b);    
	printf("Walze an Position 2:"); scanf("%d",&c);
	for (i=0; i<26; i++) {
		Walze[0][i]=Walze[a+3][i];
		Walze[1][i]=Walze[b+3][i];
		Walze[2][i]=Walze[c+3][i];        
	}
	printf("Enigma Grundeinstellungen (Ringe):\n");
	a=-1; b=-1; c=-1;
	while ((a<0)||(a>25)) { printf("Ring a:"); scanf("%d",&a); }
	while ((b<0)||(b>25)) { printf("Ring b:"); scanf("%d",&b); }
	while ((c<0)||(c>25)) { printf("Ring c:"); scanf("%d",&c); }
	SetWalzenZaehler(0,0); for (i=0; i<a; i++) { Rotiere(0); }
	SetWalzenZaehler(1,0); for (i=0; i<b; i++) { Rotiere(1); } 
	SetWalzenZaehler(2,0); for (i=0; i<c; i++) { Rotiere(2); }
	printf("Steckbrett (Standard:abcdefghijklmnopqrstuvwxyz):\n");
	scanf("%s",Stecker);
	while (C!=13) {
		C=getch();
		printf("%c",Enigma(C));
	}
}
