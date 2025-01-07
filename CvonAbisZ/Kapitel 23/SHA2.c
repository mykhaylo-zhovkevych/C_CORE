#include<stdio.h>
#include<string.h>

typedef unsigned long int uint_32;

uint_32 I[8]= {
    0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x510e527f,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19,
};

void Padding(char *S) {
    int i=0, L=strlen(S);
    S[L]=0x80; // angehängtes Bit ist im MSB, SHA verwendet also die ARM/Intel-Schreibweise (LSB first)
    for (i=L+1; i<63; i++) { S[L]=0; } // Padding mit 0-Bits
    S[63]=64; // Im letzten Byte steht die Länge der Nachricht, dies ist 
}

long int ReadLongInt(void *S, long int Pos) { // Diese Funktion liest 4 Zeichen eines String als long int ein
    char *BOS=(char *)S+Pos; // BOS=BeginOfString
    long int *NumArray=(long int *)BOS; // String als Array aus long ints betrachten (Typecasting nötig)
    return NumArray[0];
}

void WriteLongInt(void *S, long int Pos, long int Val) { // Diese Funktion schreibt ein long int als 4 Bytes in einen String
    char *BOS=(char *)S+Pos; // BOS=BeginOfString
    long int *NumArray=(long int *)BOS; // String als Array aus long ints betrachten (Typecasting nötig)
    NumArray[0]=Val;
}

uint_32 ROR(long int x, int w) {
    int N=32; // 32 Bit breite Zahlen
    uint_32 lsbs=x&((1<<w)-1);
    return (((x>>w)&0x7fffffff)|(lsbs<<(N-w))); // Rechstsschift und OR=ROR
}

uint_32 Ch(uint_32 *P) {
   int A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7;
   uint_32 Out=(P[E]&P[F])^(~P[E]&P[G]);
   return Out;
}

uint_32 Ma(uint_32 *P) {
   int A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7;
   uint_32 Out=(P[A]&P[B])^(P[A]&P[C])^(P[B]&P[C]);
   return Out;
}

uint_32 S0(uint_32 *P) {
   int A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7;
   uint_32 Out=(ROR(P[A],2))^(ROR(P[A],13))^(ROR(P[A],22));
   return Out;
}

uint_32 S1(uint_32 *P) {
   int A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7;
   uint_32 Out=(ROR(P[E],6))^(ROR(P[E],11))^(ROR(P[E],25));
   return Out;
}

void SHA2(char *HV, char *S) // HV=erzeugter Hash-Wert (hash value), S=Klartext-String (source)
{
    int A=0,B=1,C=2,D=3,E=4,F=5,G=6,H=7;
    int i=0, j=0, Pos=0;
    uint_32 P[8]; // Plaintext-Puffer
    Padding(S); // Padding
    for (j=0; j<2; j++) // 2 Blöcke=64 Bytes verarbeiten
    {
        // Daten kopieren
        for (i=0; i<8; i++) {
            P[i]=ReadLongInt(S,Pos);
            Pos+=4;
        }
        // Daten mit IV verknüpfen
        for (i=0; i<8; i++) {
            P[i]=P[i]+I[i];
        }
        // 64 Runden durchführen
        for (i=0; i<64; i++) {
            //Ch(E,F,G)=(E&F)^(~E&G)
            P[E]=Ch((unsigned long int *)P);
            P[F]=Ch((unsigned long int *)P);
            P[G]=Ch((unsigned long int *)P);
            // Ma(A,B,C)=(A&B)^(A&C)^(B&C)
            P[A]=Ma((unsigned long int *)P);
            P[B]=Ma((unsigned long int *)P);
            P[C]=Ma((unsigned long int *)P);
            //S0(A)=(A>>>2)^(A>>>13)^(A>>>22)
            P[A]=S0((unsigned long int *)P);
            //S1(E)=(E>>>6)^(E>>>11)^(E>>>25)
            P[E]=S1((unsigned long int *)P);
        }
        // Neuen IV aus den verschlüsselten Daten erzeugen
        for (int i=0; i<8; i++) {
            I[i]=P[i];
        }
    }
    // Hash-Wertes in den String HashString
    for (int i=0; i<8; i++) {
        WriteLongInt(HV,4*i,P[i]);
    }
}

int main(void) {
    FILE *PasswortDatei;
    char PWDHash[32]; // In der Datei gespeicherter Hash
    char Login[64]; // Zusammengesetzte Login-Infos (z.B. rene@pinguin:Skipper)
    char DName[64]; // Domain/Rechnername (z.B. pinguin)
    char UName[64]; // Benutzername (z.B. rene)
    char PWD[64]; // Passwort (z.B. Skipper)
    printf("Benutzername:"); scanf("%s",UName);
    printf("Domain/Rechnername:"); scanf("%s",DName);
    printf("Passwort:"); scanf("%s",PWD);
    strcpy(Login,UName); // Benutzername nach Login kopieren
    strcat(Login,"@"); strcat(Login,DName); // @[Domainname] anhängen
    strcat(Login,":"); strcat(Login,PWD); // :[Passwort] anhängen
    printf("Login-Daten:%s\n",Login); // Login-Daten ausgeben
    SHA2(PWDHash,Login); // SHA2 ausführen und Hash erzeugen
    printf("Passwort-Hash:");
    // Hash-String ausgeben (kann Nullbytes enthalten)
    for (int i=0; i<32; i++) { printf("%02x",PWDHash[i]&0xff); }
    printf("\n");
    PasswortDatei=fopen("logins.bin","wb"); // Passwort-Datei öffnen (binär schreiben)
    fseek(PasswortDatei,0,SEEK_END); // Hash an das Ende der Datei anhängen
    fwrite(&PWDHash,256,1,PasswortDatei); // Hash im Block schreiben (fwrite)
    fclose(PasswortDatei); // Passwort-Datei wieder schließen
    return 0;
}

