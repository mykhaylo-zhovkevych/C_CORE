// vigenere-chiffre.c
#include<stdio.h>
#include<string.h> // f�r strlen()

int main() {
	char *P="WIR TREFFEN UNS UM DREI UHR IN DEINEM GARTEN";
	char *K="ALICE"; // K=Schl�ssel (engl. key)
	char C,D;
	int i=0, j=0;
	int L=strlen(P), M=strlen(K);
	for (i=0; i<L; i++) {
		if (P[i]!=' ') {
			C=P[i]-'A'; D=K[j]-'A'; // Klartext und Schl�sselzeichen holen
			P[i]=((C+D)%26)+'A'; // Viniegre-Chiffre-Algorithmus
			j++;
			if (j==M) { j=0; } // Schl�ssel immer von vorne beginnen
		}
	}
	printf("%s\n",P);
	return 0;
}
