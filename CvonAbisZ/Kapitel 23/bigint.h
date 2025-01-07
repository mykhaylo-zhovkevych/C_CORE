// C++-Klasse für Zahlen vom Typ bigint
// C++ muss an dieser Stelle benutzt werden, da in ANSI-C keine neuen Operatoren definiert werden können
// Ferner können in C keine neuen mathematischen Zahlengruppen definiert werden, wie in C++
class big // Dies ist eine Zahlenklasse, und muss auch mit dem C++-Konstrukt class definiert werden (auch dies kann ANSI-C nicht)
{
    private:
    void InitBigText(unsigned char *Dst, char *NumStr, long int Len)
    {
        long int i,L;
        L=strlen(NumStr);
        for (i=0; i<Len; i++) { Dst[i]=0; }
        for (i=0; i<L; i++) { Dst[i]=NumStr[i]; }
    }
    void InitBigHex(unsigned char *Dst, char *NumStr, long int Len) // Zahleneingabe zur Basis 16
    {
        long int i=0, j=0;
        unsigned char Byte=0;
        char HexByteStr[3]; // Hex-Zahl und 0-Zeichen
        ClearBig(Dst,Len); // Ausgabezahl am Anfang mit Nullen füllen (wichtig!)
        long int Pos=strlen(NumStr)-1; // Letzte Position der Eingabezeichenkette finden (->LSB first)
        while (Pos>0) // An der letzten Position steht natürlich der niedrigste Exponent (also 1)
        {
            HexByteStr[0]=NumStr[Pos-1]; HexByteStr[1]=NumStr[Pos]; // Hex-Ziffer sind immer 2 Zeichen
            HexByteStr[2]=0; // HexByteStr mit 0 abschließen
            Byte=strtol(HexByteStr,NULL,16); // strtol wandelt in diesem Fall eine Hex-Zeichenkette (z.B. "2e") in ein Byte
            Dst[i]=Byte; // Big- Zahlen werden Byte für Byte gespeichert
            i++; Pos-=2; // Bitte aufpassen: Die Anzahl der Ziffern in NumStr muss bei Hex durch 2 teilbar sein!
        }
    }
    void InitBigDec(unsigned char *Dst, char *NumStr, long int L) // Zahleneingabe zur Basis 10
    {
        unsigned char *NumDigit=new char [L]; // Puffer für aktuelle Ziffer
        unsigned char *Exponent=new char [L]; // Puffer für aktuellen Exponenten
        unsigned char *Temp=new char [L]; // Zwischenspeicher 1
        unsigned char *Temp2=new char [L]; // Zwischenspeicher 2
        ClearBig(Dst,L); // Ausgabezahl am Anfang mit Nullen füllen (wichtig!)
        ClearBig(Exponent,L); Exponent[0]=1; // Exponent mit 10^0=1 initialisieren
        ClearBig(NumDigit,L); // Pufferspeicher für aktuelle Ziffer leeren (wichtig!)
        long int Pos=strlen(NumStr)-1; // Letzte Position der Eingabezeichenkette finden (->LSB first)
        while (Pos>=0)
        {
            if (NumStr[Pos]>'0') // Nullen Ignorieren, denn diese leisten keinen Beitrag zum Betrag der Zahl
            {
                NumDigit[0]=NumStr[Pos]-'0'; // Wenn man den ASCII- Wert für die Ziffer 0 abzieht, erhält man den Dezimalwert der Ziffer
                // -> NumDigit enthält immer nur ein Byte, und das ist der Wert der letzten Ziffer
                // ClearBig(Temp,Len); ClearBig(Temp2,Len); // Puffer müssen vor jeder Zwischenrechnung geleert werden
                // Zwischenrechnung:
                CopyBig(Temp,Exponent,L);
                MulBig(Temp,NumDigit,L); // Wert der aktuellen Ziffer: NumDigit*Exponent -> Puffer 1
                AddBig(Dst,Temp,L); // Puffer 2 = Alter Wert+(NumDigit*Exponent)
            }
            NumDigit[0]=10;
            MulBig(Exponent,NumDigit,L); // Exponent*10=nächste Stelle
            //CopyBig(Exponent,Temp,Len); // Auch hier muss der Puffer zurückkopiert werden
            Pos--; // Ziffern rückwärts zählen
        }
        //CopyBig(Dst,Temp2,Len);
    }
    void ClearBig(unsigned char *a, long int L)
    {
        long int i=0;
        for (i=0; i<L; i++) { a[i]=0; } // Clear füllt die gesamten Bytes der Big-Zahl mit Nullen auf
    }
    void CopyBig(unsigned char *a, unsigned char *b, long int L)
    {
        long int i;
        for (i=0; i<L; i++)
        {
            a[i]=b[i]; // Copy kopiert Big- Zahlen byteweise, ähnlich der Funktion strcpy
        }
    }
    void NotBig(unsigned char *a, long int Len)
    {
        long int i=0;
        for (i=0; i<Len; i++)
        {
            a[i]=~a[i]; // Not füllt die gesamten Bytes der Big-Zahl mit derem Komplement auf
        }
    }
    void IncBig(unsigned char *a, long int Len)
    {
        int CLo=0,CHi=0,Src1=0,Src2=0;
        long int i=0;
        for (i=0; i<Len; i++)
        {
            Src1=a[i]; // Bei dieser Addition ist Quelle=Ziel
            if (i==0) { Src2=1; } // Bei dem ersten Byte der zu addierenden zahl steht eine 1
            else { Src2=0; } // ansonsten steht immer eine 0
            CLo=Src1+Src2+CHi;
            a[i]=CLo;
            CHi=(CLo>>8);
        }
    }
    void ShiftBigLeft(unsigned char *a, long int Len)
    {
        long int i=0;
        for (i=Len-1; i>=0; i--)
        {   
            a[i]<<=1; // Die Big- Zahl Byteweise um 1 bit nach links verschieben
            if (i>0) { a[i]|=(a[i-1]>>7); } // Außer bei Byte 0 muss das MSB des vorigen Bytes in das LSB des aktuellen Bytes geschoben werden
        }
    }
    void ShiftBigRight(unsigned char *a, long int Len)
    {
        long int i=0;
        for (i=0; i<Len; i++)
        {
            a[i]>>=1; // Die Big- Zahl Byteweise um 1 bit nach rechts verschieben
            if (i<Len-1) { a[i]|=(a[i+1]<<7); } // Außer beim letzen Byte 0 muss das LSB des vorigen Bytes in das MSB des aktuellen Bytes geschoben werden
        }
    }
    bool BigsEqual(unsigned char *a, unsigned char *b, long int Len)
    {
        bool EQ=true;
        long int i;
        for (i=0; i<Len; i++)
        {
            if (a[i]!=b[i]) { EQ=false; break; }
        }
        return EQ;
    }
    void AddBig(unsigned char *a, unsigned char *b, long int L)
    {
        int CLo=0,CHi=0; // Diese Variablen müssen unsigned int sein, sonst funktioniert die Addition nicht!
        long int i=0;
        for (i=0; i<L; i++) // Um Big Zahlen zu addieren, byteweise vorgehen
        {
            CLo=a[i]+b[i]+CHi; // Lo-Byte=Byte 1+Byte 2+Letzes Hi-Byte (Anfangswert 0)
            // ->Wenn die Addition überläuft, befinden sich die Überlaufbits an Position 8 und 9
            a[i]=CLo; // Jetzt Lo-Byte in das entsprechende Ziel-Byte schreiben
            CHi=(CLo>>8); // Die Hi-Bytes der aktuellen Addition für den nächsten Schritt merken
        }
    }
    void SubBig(unsigned char *a, unsigned char *b, long int L)
    {
        unsigned char *Buff=new char[L];
        CopyBig(Buff,b,L); // b sichern
        // Die Subtraktion kann durch Addition dargestellt werden: a-b=-b+a
        // Negative Zahlen (also -b) erhält man ganz einfach:
        NotBig(Buff,L); // 1. Das Komplement bilden
        IncBig(Buff,L); // 2. Das Ergebnis um 1 erhöhen
        AddBig(a,Buff,L); // Der Rest ist Klar:Dst=-Src2+Src1
        delete(Buff);
    }
    bool IsZero(unsigned char *a, long int L)
    {
        bool Zero=true;
        long int i=0;
        while ((i<L)&&(Zero==true))
        {
            if (a[i]!=0) { Zero=false; } // Der Vergleich auf 0 ist einfach: Alle Bytes sind 0
            i++;
        }
        return Zero;
    }
    bool IsMore(unsigned char *a, unsigned char *b, long int L) // Stellt fest, ob Src1>Src2 ist und gibt in diesem Fall WAHR zurück
    {
        unsigned char *Buff=new char [Len]; // a nicht verändern!
        CopyBig(Buff,a,L); // a nicht verändern!
        SubBig(Buff,b,L); // a-b berechnen
        if ((Buff[L-1]&0x80)==0x80) { delete(Buff); return true; } // wenn Src1-Src2 negativ ist, ist das MSB der Zahl (letztes Bit im letzen Byte) gesetzt
        else { delete(Buff); return false; } // WAHR nur zurückgeben, wenn das Ergebnis SRC1-Src2 negativ ist. Bei Src1=Src2 wird also FALSCH zurückgegeben
    }
    bool IsLess(unsigned char *a, unsigned char *b, long int Len)
    {
        return (IsMore(b,a,Len));
    }
    void MulBig(unsigned char *a, unsigned char *b, long int L)
    {
        // Diese Funktion verwendet die ägyptische Multiplikation
        // Hierfür benötigt man 3 Zwischenspeicher
        unsigned char *Buff1=new char[L];
        unsigned char *Buff2=new char[L];
        unsigned char *Buff3=new char[L];
        ClearBig(Buff1,L);
        CopyBig(Buff3,b,L);
        long int i=0, BitLen=8*L; // Die Anzahl Schritte ist die Anzahl der Bits (also Bytezahl*8)
        for (i=0; i<BitLen; i++)
        {
            if ((a[0]&0x01)==1) // Erst muss man immer prüfen, ob eine Division modulo 2 aufgeht, denn dann ist der aktuelle Faktor gerade
            { 
                // Wenn die Addition modulo 2 nicht aufgeht, dann mache hier weiter:
                AddBig(Buff1,Buff3,L);
            }
            ShiftBigLeft(Buff3,L); // Nun wird der aktuelle Faktor in Src2 mit 2 multipliziert, dadurch erhält man die nächste Binärstelle der Multiplikation
            ShiftBigRight(a,L); // Der erste Faktor wird nun durch 2 dividiert
        }
        // Leider werden bei dieser Art Multiplikation die Ursprungswerte verändert, deshalb muss man die Originalwerte zurückkopieren
        CopyBig(a,Buff1,L);
        delete(Buff1); delete(Buff2); delete(Buff3);
    }
    void DivBig(unsigned char *a, unsigned char *b, long int L, bool Modulo)
    {
        // Diese Funktion verwendet die ägyptische Division
        unsigned char *Temp=new char [L];
        unsigned char *Bit=new char [L];
        unsigned char *Dst=new char [L];
        long int Steps=0, i=0;
        ClearBig(Dst,L);
        ClearBig(Bit,L);
        IncBig(Bit,L); // Aktuelle Bitposition der ersten Stelle des Dividenden:Bit 0 (=1)
        CopyBig(Temp,b,L);
        // Erst einmal muss der Dividend so lange mit 2 multipliziert werden, bis er größer ist als Src1
        while (IsMore(a,Temp,L)==false)
        {
            ShiftBigLeft(Temp,L); // *2=Bitshift um 1 nach links
            ShiftBigLeft(Bit,L); // Auch die aktuelle Bitposition muss mit verschoben werden!
            Steps++; // Dies ist die Anzahl der Schritte für die Ägyptische Division +1
        }
        // Jetzt muss die letzte Verschiebung rückgängig gemacht werden, damit Div gerade eben kleiner ist, als Src1
        // -> Ergebnis wäre sonst um den Betrag des Dividenden zu groß
        ShiftBigRight(Temp,L);
        ShiftBigRight(Bit,L);
        for (i=0; i<Steps; i++) // Jetzt benötigt man so viele Schritte, wie die Zahlen Bits haben
        {
            if(IsMore(a,Temp,L)==false) // In jedem Schritt schauen, ob der aktuelle Dividend größer als der verbleibende Rest der Division ist
            {
                // Wenn ja, mache folgendes:
                SubBig(a,Temp,L); //CopyBig(Src,Temp1,Len); // 1. Ziehe den aktuellen Dividenden vom verbleibenden Rest ab
                AddBig(Dst,Bit,L); //CopyBig(Dst,Temp2,Len); // 2. Addiere zur auszugebenden Zahl (am Anfang 0) den Wert des aktuellen Bits
            }
            // Nun aktualisiere den Dividenden und den Wert des aktuellen Bits:
            // Teile beide durch 2 -> Das ist eine Bitverschiebung jeweils um 1 nach rechts
            ShiftBigRight(Bit,L); ShiftBigRight(Temp,L);
        }
        if (Modulo==false) { CopyBig(a,Dst,L); }
        delete(Temp); delete(Bit); delete(Dst);
    }
    void ABSBig(unsigned char *a, long int Len)
    {
        if ((a[Len-1]&0x80)==0x80)
        {
            NotBig(a,Len);
            IncBig(a,Len);
        }
    }
    void SquareBig(unsigned char *a, long int Len)
    {
        unsigned char *b=new char(Len);
        CopyBig(b,a,Len);
        MulBig(a,b,Len);
        delete(b);
    }
    unsigned char *N;
    long int Len;
    public:
    // Operatoren
    big& operator+=(const big &rhs) // += ruft AddBig() auf
    {                     
        AddBig(this->N,rhs.N,this->Len);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    big& operator-=(const big &rhs) // -=ruft SubBig() auf
    { 
        SubBig(this->N,rhs.N,this->Len);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    big& operator*=(big const &rhs) // *= ruft MulBig() auf
    { 
        MulBig(this->N,rhs.N,this->Len);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    big& operator%=(const big &rhs) // %= ruft ModBig() auf
    {
        DivBig(this->N,rhs.N,this->Len,true);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    big& operator/=(const big &rhs) // /= ruft DivBig() auf
    {
        DivBig(this->N,rhs.N,this->Len,false);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    big& operator=(const big &rhs)
    {
        CopyBig(this->N,rhs.N,this->Len);
        return *this; // Zeiger auf den linken Operators zurückgeben
    }
    bool operator==(const big& rhs)
    {
        return BigsEqual(this->N,rhs.N,this->Len);
    }
    bool operator!=(const big& rhs)
    {
        if (BigsEqual(this->N,rhs.N,this->Len)==false) { return true; }
        else { return false; }
    }
    bool operator>=(const big& rhs)
    {
        return IsMore(this->N,rhs.N,this->Len);
    }
    bool operator<=(const big& rhs)
    {
        return IsLess(this->N,rhs.N,this->Len);
    }
    friend big operator+(const big &lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        big temp; temp.Init(lhs.Len); temp.InitDec("1");
        temp*=lhs; temp+=rhs;
        return temp;
    }
    friend big operator-(const big &lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        big temp; temp.Init(lhs.Len); temp.InitDec("1");
        temp*=lhs; temp-=rhs;
        return temp;
    }
    friend big operator*(const big &lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        big temp; temp.Init(lhs.Len); temp.InitDec("1");
        temp*=lhs; temp*=rhs;
        return temp;
    }
    friend big operator%(big lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        big temp; temp.Init(lhs.Len); temp.InitDec("1");
        temp*=lhs; temp%=rhs;
        return temp;
    }
    friend big operator/(const big &lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        big temp; temp.Init(lhs.Len); temp.InitDec("1");
        temp*=lhs; temp/=rhs;
        return temp;
    }
    friend big operator>(big lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        lhs >= rhs;
        return lhs;
    }
    friend big operator<(big lhs, const big& rhs) // rechten operator nicht verändern, linker ist friend
    {
        lhs <= rhs;
        return lhs;
    }
    // Funktionen
    big();
    big(int L);
    void Init(long int L);
    long int GetLen();
    void abs();
    void Random(long int L);
    void ShiftLeft();
    void ShiftRight();
    void Inc();
    void OutputHex(long int L);
    void OutputText();
    void square();
    bool LSBSet();
    bool MSBSet();
    bool Zero();
    void ModExp(char *a, char *b);
    void InitDec(char *NumStr);
    void InitHex(char *NumStr);
    void InitASCII(char *NumStr);
};

big::big() { } // Dummy

void big::Init(long int L)
{
    long int i;
    N=new char [L]; Len=L;
    for (i=0; i<L; i++) { N[i]=0; }
}

long int big::GetLen() { return Len; }

big::big(int L)
{
    long int i;
    N=new char [L]; Len=L;
    for (i=0; i<L; i++) { N[i]=0; }
}

void big::abs()
{
    ABSBig(N,Len);
}

void big::Random(long int L)
{
    long int i;
    for (i=0; i<L; i++) { N[i]=rand()%256; }
}

void big::ShiftLeft()
{
    ShiftBigLeft(N,Len);
}

void big::ShiftRight()
{
    ShiftBigRight(N,Len);
}

void big::Inc()
{
    IncBig(N,Len);
}

void big::OutputHex(long int L)
{
    long int i;
    for (i=L-1; i>=0; i--)
    {
        printf("%02x",N[i]);
    }
    printf("\n");
}

void big::OutputText()
{
    long int i;
    for (i=0; i<Len; i++)
    {
        if (N[i]==0) { break; }
        printf("%c",N[i]);
    }
    printf("\n");
}

void big::square()
{
    SquareBig(N,Len);
}

bool big::LSBSet()
{
    if ((N[0]&0x01)==0x01) { return true; }
    else { return false; }
}

bool big::MSBSet()
{
    if ((N[Len-1]&0x80)==0x80) { return true; }
    else { return false; }
}

bool big::Zero()
{
    if (IsZero(N,Len)) { return true; }
    else { return false; }
}

void big::InitDec(char *NumStr)
{
    InitBigDec(N,NumStr,Len);
}

void big::InitHex(char *NumStr)
{
    InitBigHex(N,NumStr,Len);
}

void big::InitASCII(char *NumStr)
{
    InitBigText(N,NumStr,Len);
}

void InitASCII(big &N, char *Text) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.InitASCII(Text);
}

void OutputText(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.OutputText();
}

void InitHex(big &N, char *Text) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.InitHex(Text);
}

void OutputHex(big &N, long int L) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.OutputHex(L);
}

void InitDec(big &N, char *Text) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.InitDec(Text);
}

void InitBig(big &N, long int L) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.Init(L);
}

long int GetLen(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    return N.GetLen();
}

void Random(big &N, long int L) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.Random(L);
}

bool LSBSet(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    return N.LSBSet();
}

bool IsZero(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    return N.Zero();
}

void ShiftRight(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.ShiftRight();
}

void ShiftLeft(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.ShiftLeft();
}

void Inc(big &N) // Wrapper-Funktion für einen Aufruf, der "C-like" ist
{
    N.Inc();
}

void ModExp(big &result, big &base, big &exponent, big &modulus)
{    
    // Implementiert square and multiply
    big Temp1,Temp2,Temp3,Mod,Null,Eins,Zwei;
    long int Len;
    Len=GetLen(base); InitBig(Temp1,Len); InitBig(Temp2,Len); InitBig(Temp3,Len); InitBig(Mod,Len); InitBig(Null,Len);
    Temp1=base; Temp2=exponent; Temp3=modulus;
    InitBig(Eins,Len); InitHex(Eins,"01");
    InitBig(Zwei,Len); InitHex(Zwei,"02");
    InitHex(result,"01");
    base=base%modulus;
    while (IsZero(exponent)==false)
    {
        if (LSBSet(exponent)==true) { result=(result*base)%modulus; }
        ShiftRight(exponent);
        base=(base*base)%modulus;
    }
    base=Temp1; exponent=Temp2; modulus=Temp3;
}

void EGGT(big &a, big &b, big &s, big &t)
{
    long int L=GetLen(a);
    big z,u,v,q,u1,v1,b1,at,bt;
    s.Init(L); t.Init(L); u.Init(L); v.Init(L); q.Init(L);
    u1.Init(L); v1.Init(L); b1.Init(L); z.Init(L);
    at.Init(L); bt.Init(L); at=a; bt=b;
    InitDec(s,"1"); //s = 1; // Initialisierung der Zeiger
    InitDec(t,"0"); //t = 0;
    InitDec(u,"0"); //u = 0; // Deklaration der lokalen Variablen
    InitDec(v,"1"); //v = 1
    while (IsZero(b)==false) //while (b != 0)
    {
        q=a/b;
        b1=b; // Variable zum Zwischenspeichern
        b=a-(q*b);
        a=b1;
        u1=u; // Variable zum Zwischenspeichern
        u=s-(q*u);
        s=u1;
        v1=v; // Variable zum Zwischenspeichern
        v=t-(q*v);
        t=v1;
    }
    a=at; b=bt;
}

bool MRT (big &n, big &a) // n ungerade, a Primzahl<100
{ 
    long int e=1,L=GetLen(n);
    big z; InitBig(z,L); InitDec(z,"0");
    big o; InitBig(o,L); InitDec(o,"1");
    big m; InitBig(m,L); m=n-o;
    big d; InitBig(d,L); d=m; ShiftRight(d);
    while (LSBSet(d)==false) { ShiftRight(d); ++e; }
    big p,q; InitBig(p,L); InitBig(q,L); p=a; q=a;
    while (IsZero(d)==false)
    {
        if (IsZero(d)==false)
        {
            ShiftRight(d);
            q*=q; q%=n; // quadriere modular: q=q^2 mod n
            if (LSBSet(d)==true) { p=p*q; p=p%n; }
        }
    }
    // p=1 oder p=m -> n ist wahrscheinlich prim
    if (p==o) { return true; }
    if (p==m) { return true; }
    while (--e)
    {
      p*=p; p%=n;
      if (p==m) { return true; }
      if (p==o) { break; }
      if (p==z) { break; }
   }
   return false; // n ist nicht prim, wenn der Test druchläuft
}

void RandPrime(big &n, long int L)
{
    bool M=false;
    big a; InitBig(a,GetLen(n));
    Random(n,L); if (LSBSet(n)==false) { Inc(n); } // Inc:n+=1;
    while (M==false)
    {
        InitDec(a,"2"); M=MRT(n,a);
        if (M==false) { InitDec(a,"3"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"4"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"5"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"6"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"7"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"8"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"9"); M=MRT(n,a); }
        if (M==false) { InitDec(a,"10"); M=MRT(n,a); }
        if (M==false) { Inc(n); Inc(n); }
    }
}
