// caesar-chiffre.c
#include<stdio.h>
#include<string.h> // f�r strlen()

int main(void) {
	char *P="WIR TREFFEN UNS UM DREI UHR IN DEINEM GARTEN";
	char C;
	int i=0, L=strlen(P); // L�nge von P ermitteln
	for (i=0; i<L; i++) {
		if (P[i]!=' ') { // Leerzeichen auf sich selbst abbilden
			C=P[i]-'A'; // den Buchstaben A auf den Wert 1 abbilden
			C=(C+5)%26; // Caesar-Chiffre mit dem Schl�ssel 5 anwenden
			P[i]=C+'A'; // Wert 1 wieder auf das ASCII-A abbilden
		}
	}
	printf("%s\n",P); // P wird hier direkt verschl�sselt
	return 0;
}
