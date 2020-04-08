#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

class Punct
{
private:
    float x;
    float y;
    static int n;
public:
    Punct(float, float);
    Punct(Punct &);
    ~Punct();
    Punct& operator = (Punct& P);
    void citire(istream &in);
    void afisare(ostream &out);
    friend istream& operator >>(istream& in, Punct& P);
    friend ostream& operator <<(ostream& out, Punct& P);
    static int NumarPuncte()
    {
        return n;
    }
    friend class Patrat;
    friend class Dreptunghi;
    friend class Romb;
    friend class Paralelogram;
    friend class Trapez;
};

int Punct::n;

Punct::Punct(float x = 0, float y = 0)
{
    n++;
    this->x = x;
    this->y = y;
}

Punct::Punct(Punct& P)
{
    this->x = P.x;
    this->y = P.y;
}


Punct::~Punct()
{
    this->x = 0;
    this->y = 0;
}

Punct& Punct::operator=(Punct& P)
{
    x = P.x;
    y = P.y;
}

void Punct::citire(istream& in)
{
    cout<<"Cititi abscisa punctului: ";
    in>>x;
    cout<<"Cititi ordonata punctului: ";
    in>>y;
}

void Punct::afisare(ostream& out)
{
    out<<"("<<x<<", "<<y<<")";
}

istream& operator>>(istream& in, Punct &P)
{
    P.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Punct& P)
{
    P.afisare(out);
    return out;
}

class Patrat
{
protected:
    Punct stanga_jos;
    float latura;
    bool validitate;
    static int n;
public:
    Patrat();
    Patrat(Punct, float);
    virtual ~Patrat();
    Patrat(Patrat&);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
    Patrat &operator = (Patrat& Pat);
    friend istream& operator >>(istream& in, Patrat& Pat);
    friend ostream& operator <<(ostream& out, Patrat& Pat);
    float arie();
    float perimetru();
    virtual void corectitudine(bool);
    virtual bool getvaliditate();
    static int NumarPatrate()
    {
        return n;
    }
};

int Patrat::n;

Patrat::Patrat()
{
    n++;
    latura = 0;
};

Patrat::Patrat(Punct stanga_jos, float latura)
{
    try
    {
        if(latura <= 0)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Eroare constructor, latura este un numar pozitiv.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->stanga_jos.x = stanga_jos.x;
    this->stanga_jos.y = stanga_jos.y;
    this->latura = latura;
}



Patrat::~Patrat()
{
    this->latura = 0;
}

Patrat::Patrat(Patrat& Pat)
{
    this->stanga_jos = Pat.stanga_jos;
    this->latura = Pat.latura;
}

void Patrat::citire(istream &in)
{
    cout<<"Punctul din stanga_jos: "<<endl;
    cout<<"Cititi abscisa: ";
    in>>stanga_jos.x;
    cout<<"Cititi odonata: ";
    in>>stanga_jos.y;
    cout<<"Cititi latura: ";
    in>>latura;
    try
    {
        if(latura <= 0)
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare constructor, latura este un numar pozitiv.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
}

istream& operator>>(istream& in, Patrat& Pat)
{
    Pat.citire(in);
    return in;
}

void Patrat::afisare(ostream &out)
{
    if(stanga_jos.x == 0 && stanga_jos.y == 0 & latura == 0)
        out<<"";
    else
    {
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y<<"), ";
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y + latura<<"), ";
        out<<"("<<stanga_jos.x + latura<<", "<<stanga_jos.y<<"), ";
        out<<"("<<stanga_jos.x + latura<<", "<<stanga_jos.y + latura<<"), ";
        out<<"\b ";
        out<<"Latura: "<<latura<<endl;
    }
}

ostream& operator<<(ostream& out, Patrat& Pat)
{
    Pat.afisare(out);
    return out;
}

Patrat& Patrat::operator=(Patrat &Pat)
{
    stanga_jos.x = Pat.stanga_jos.x;
    stanga_jos.y = Pat.stanga_jos.y;
    latura = Pat.latura;
}

float Patrat::arie()
{
    return latura*latura;
}

float Patrat::perimetru()
{
    return 4*latura;
}

void Patrat::corectitudine(bool validitate = false)
{
    this->validitate = validitate;
}

bool Patrat::getvaliditate()
{
    return validitate;
}

class Dreptunghi:virtual public Patrat
{
protected:
    float latura2;
    static int n;
public:
    Dreptunghi();
    Dreptunghi(Punct, float, float);
    virtual ~Dreptunghi();
    Dreptunghi(Dreptunghi&);
    virtual void citire(istream& in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream&,Dreptunghi&);
    friend ostream& operator<<(ostream&, Dreptunghi&);
    Dreptunghi &operator = (Dreptunghi& D);
    float arie();
    float perimetru();
    virtual void corectitudine(bool);
    virtual bool getvaliditate();
    static int NumarDreptunghiuri()
    {
        return n;
    }
    int compatibilitatePARlaD(Punct P)
    {
        if (stanga_jos.x+latura2 == P.x && stanga_jos.y  +latura== P.y)
            return 1;
        return 0;
    }
    int compatibilitateDlaPAT()
    {
        if ( latura == latura2 )
            return 1;
        return 0;
    }
};

int Dreptunghi::n;

Dreptunghi::Dreptunghi():Patrat()
{
    n++;
    Patrat::n--;
    latura2 = 0;
}

Dreptunghi::Dreptunghi(Punct stanga_jos, float latura, float latura2)
{
    try
    {
        if(latura <= 0)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Eroare constructor, latura este un numar pozitiv.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->stanga_jos.x = stanga_jos.x;
    this->stanga_jos.y = stanga_jos.y;
    this->latura = latura;
    try
    {
        if(latura2 <= 0)
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare constructor, latura este un numar pozitiv.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->latura2 = latura2;
}

Dreptunghi::~Dreptunghi()
{
    this->latura = 0;
    this->latura2 = 0;
}

Dreptunghi::Dreptunghi(Dreptunghi &D)
{
    this->stanga_jos = D.stanga_jos;
    this->latura = D.latura;
    this->latura2 = D.latura2;
}

Dreptunghi& Dreptunghi::operator=(Dreptunghi &D)
{
    stanga_jos.x = D.stanga_jos.x;
    stanga_jos.y = D.stanga_jos.y;
    latura = D.latura;
    latura2 = D.latura2;
}

void Dreptunghi::citire(istream& in)
{
    Patrat::citire(in);
    cout<<"Cititi latura2: ";
    in>>latura2;
    try
    {
        if(latura2 <= 0)
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare constructor, latura este un numar pozitiv.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);

}

void Dreptunghi::afisare(ostream &out)
{
    if(stanga_jos.x == 0 && stanga_jos.y == 0 & latura == 0 && latura2 == 0)
        out<<"";
    else
    {
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y<<"), ";
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y + latura<<"), ";
        out<<"("<<stanga_jos.x + latura2<<", "<<stanga_jos.y<<"), ";
        out<<"("<<stanga_jos.x + latura2<<", "<<stanga_jos.y + latura<<"), ";
        out<<"\b ";
        out<<"Latura: "<<latura<<", ";
        out<<"Latura2: "<<latura2<<endl;
    }
}

istream& operator>>(istream& in, Dreptunghi &D)
{
    D.citire(in);
    return in;
}

ostream &operator<<(ostream& out, Dreptunghi &D)
{
    D.afisare(out);
    return out;
}

float Dreptunghi::arie()
{
    return latura*latura2;
}

float Dreptunghi::perimetru()
{
    return 2 * latura + 2 * latura2;
}

void Dreptunghi::corectitudine(bool validitate = false)
{
    Patrat::corectitudine(validitate);
}

bool Dreptunghi::getvaliditate()
{
    Patrat::getvaliditate();
}

class Romb:virtual public Patrat
{
protected:
    Punct colt_opus;
    static int n;
public:
    Romb();
    Romb(Punct, float, Punct);
    virtual ~Romb();
    Romb(Romb&);
    virtual void citire(istream& in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream&, Romb&);
    friend ostream& operator<<(ostream&, Romb&);
    Romb &operator = (Romb& D);
    float arie();
    float perimetru();
    virtual void corectitudine(bool);
    virtual bool getvaliditate();
    static int NumarRomburi()
    {
        return n;
    }
    int compatibilitatePARlaRB( float lat )
    {
        if( lat == latura )
            return 1;
        return 0;
    }
    float compatibilitateRBlaPat()
    {
        if( colt_opus.x == stanga_jos.x +latura && colt_opus.y == stanga_jos.y + latura )
            return 1;
        return 0;
    }
};

int Romb::n;

Romb::Romb():Patrat()
{
    n++;
    Patrat::n--;
}

Romb::Romb(Punct stanga_jos, float latura, Punct colt_opus):Patrat(stanga_jos, latura)
{
    try
    {
        if( (sqrt( (colt_opus.x - latura - stanga_jos.x) * (colt_opus.x - latura - stanga_jos.x)
                   + (colt_opus.y - stanga_jos .y) * (colt_opus.y - stanga_jos .y) )  !=  latura) ||
                (stanga_jos.x == colt_opus.x && stanga_jos.y == colt_opus.y) )
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare punct colt_opus, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->colt_opus.x = colt_opus.x;
    this->colt_opus.y = colt_opus.y;
}

Romb::~Romb()
{
    this->latura = 0;
}

Romb::Romb(Romb &R)
{
    this->stanga_jos = R.stanga_jos;
    this->latura = R.latura;
    this->colt_opus = R.colt_opus;
}

void Romb::citire(istream& in)
{
    Patrat::citire(in);
    cout<<"Punctul din coltul_opus: "<<endl;
    cout<<"Cititi abscisa: ";
    in>>colt_opus.x;
    cout<<"Cititi odonata: ";
    in>>colt_opus.y;
    try
    {
        if( (sqrt( (colt_opus.x - latura - stanga_jos.x) * (colt_opus.x - latura - stanga_jos.x)
                   + (colt_opus.y - stanga_jos .y) * (colt_opus.y - stanga_jos .y) )  !=  latura) ||
                (stanga_jos.x == colt_opus.x && stanga_jos.y == colt_opus.y) )
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare punct colt_opus, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
}

void Romb::afisare(ostream& out)
{
    if(stanga_jos.x == 0 && stanga_jos.y == 0 & latura == 0 && colt_opus.x == 0 && colt_opus.y == 0)
        out<<"";
    else
    {
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y<<"), ";
        out<<"("<<colt_opus.x<<", "<<colt_opus.y<<"), ";
        out<<"("<<colt_opus.x - latura<<", "<<colt_opus.y<<"), ";
        out<<"("<<stanga_jos.x + latura<<", "<<stanga_jos.y<<") ";
        out<<"\b ";
        out<<"Latura: "<<latura<<endl;
    }
}

istream &operator>>(istream &in, Romb &R)
{
    R.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Romb &R)
{
    R.afisare(out);
    return out;
}

Romb& Romb::operator=(Romb &R)
{
    stanga_jos.x = R.stanga_jos.x;
    stanga_jos.y = R.stanga_jos.y;
    latura = R.latura;
    colt_opus.x = R.colt_opus.x;
    colt_opus.y = R.colt_opus.y;
}

float Romb::arie()
{
    float d1 = sqrt((stanga_jos.x - colt_opus.x) * (stanga_jos.x - colt_opus.x)
                    + (stanga_jos.y - colt_opus.y) * (stanga_jos.y - colt_opus.y));
    float d2 =  sqrt((stanga_jos.x + latura - colt_opus.x + latura) * (stanga_jos.x + latura - colt_opus.x + latura)
                     + (stanga_jos.y - colt_opus.y) * (stanga_jos.y - colt_opus.y));

    return (d1*d2)/2;
}

float Romb::perimetru()
{
    return 4*latura;
}

void Romb::corectitudine(bool validitate = false)
{
    Patrat::corectitudine(validitate);
}

bool Romb::getvaliditate()
{
    Patrat::getvaliditate();
}

class Paralelogram: public Dreptunghi, public Romb
{
protected:
    static int n;
public:
    Paralelogram();
    Paralelogram(Punct, float, Punct, float);
    virtual ~Paralelogram();
    Paralelogram(Paralelogram&);
    virtual void citire(istream& in);
    virtual void afisare(ostream &out);
    friend istream& operator>>(istream&, Paralelogram&);
    friend ostream& operator<<(ostream&, Paralelogram&);
    Paralelogram &operator = (Paralelogram& Par);
    float arie();
    float perimetru();
    virtual void corectitudine(bool);
    virtual bool getvaliditate();
    static int NumarParalelograme()
    {
        return n;
    }
    int gettcolt_opus_x()
    {
        return colt_opus.x;
    }
    int gettcolt_opus_y()
    {
        return colt_opus.y;
    }
    float gettlatura2()
    {
        return latura2;
    }

};

int Paralelogram::n;

Paralelogram::Paralelogram():Dreptunghi(),Romb()
{
    n++;
    Dreptunghi::n--;
    Romb::n--;
    Patrat::n++;
}

Paralelogram::Paralelogram(Punct stanga_jos, float latura, Punct colt_opus, float latura2)
    :Dreptunghi(stanga_jos, latura, latura2)
{
    try
    {
        if( (sqrt( (colt_opus.x - latura2 - stanga_jos.x) * (colt_opus.x - latura2 - stanga_jos.x)
                   + (colt_opus.y - stanga_jos .y) * (colt_opus.y - stanga_jos .y) )  !=  latura) ||
                (stanga_jos.x == colt_opus.x && stanga_jos.y == colt_opus.y) )
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare punct colt_opus, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->colt_opus.x = colt_opus.x;
    this->colt_opus.y = colt_opus.y;

}

Paralelogram::~Paralelogram()
{
    this->latura = 0;
    this->latura2 = 0;
}

Paralelogram::Paralelogram(Paralelogram &Par)
{
    this->latura2 = Par.latura2;
    this->latura = Par.latura;
    this->stanga_jos = Par.stanga_jos;
    this->colt_opus = Par.colt_opus;
}

void Paralelogram::citire(istream &in)
{
    Dreptunghi::citire(in);
    cout<<"Punctul din coltul_opus: "<<endl;
    cout<<"Cititi abscisa: ";
    in>>colt_opus.x;
    cout<<"Cititi odonata: ";
    in>>colt_opus.y;
    try
    {
        if( (sqrt( (colt_opus.x - latura2 - stanga_jos.x) * (colt_opus.x - latura2 - stanga_jos.x)
                   + (colt_opus.y - stanga_jos .y) * (colt_opus.y - stanga_jos .y) )  !=  latura) ||
                (stanga_jos.x == colt_opus.x && stanga_jos.y == colt_opus.y) )
            throw 1;
    }
    catch( int i )
    {
        cout<<"Eroare punct colt_opus, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
}

void Paralelogram::afisare(ostream &out)
{
    if(stanga_jos.x == 0 && stanga_jos.y == 0 && latura == 0 && latura2 == 0 && colt_opus.x == 0 && colt_opus.y == 0)
        out<<"";
    else
    {
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y<<"), ";
        out<<"("<<colt_opus.x<<", "<<colt_opus.y<<"), ";
        out<<"("<<colt_opus.x - latura2<<", "<<colt_opus.y<<"), ";
        out<<"("<<stanga_jos.x + latura2<<", "<<stanga_jos.y<<"), ";
        out<<"\b ";
        out<<"Latura: "<<latura<<", ";
        out<<"Latura2: "<<latura2<<endl;
    }
}

istream &operator>>(istream &in, Paralelogram &Par)
{
    Par.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Paralelogram &Par)
{
    Par.afisare(out);
    return out;
}

Paralelogram& Paralelogram::operator=(Paralelogram &Par)
{
    stanga_jos.x = Par.stanga_jos.x;
    stanga_jos.y = Par.stanga_jos.y;
    latura = Par.latura;
    latura2 = Par.latura2;
    colt_opus.x = Par.colt_opus.x;
    colt_opus.y = Par.colt_opus.y;
}

float Paralelogram::arie()
{
    return latura2 * (colt_opus.y - stanga_jos.y);
}

float Paralelogram::perimetru()
{
    return latura * 2 + latura2 * 2;
}

void Paralelogram::corectitudine(bool validitate = false)
{
    Dreptunghi::corectitudine(validitate);
}

bool Paralelogram::getvaliditate()
{
    Dreptunghi::getvaliditate();
}

class Trapez: public Paralelogram
{
private:
    float baza2;
    static int n;
public:
    Trapez();
    Trapez(Punct, float, Punct, float, float);
    ~Trapez();
    Trapez(Trapez&);
    void citire(istream& in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Trapez&);
    friend ostream& operator<<(ostream&, Trapez&);
    Trapez &operator = (Trapez& T);
    float arie();
    float perimetru();
    void corectitudine(bool);
    bool getvaliditate();
    static int NumarTrapezuri()
    {
        return n;
    }
};

int Trapez::n;

Trapez::Trapez():Paralelogram()
{
    baza2 = 0;
    n++;
    Paralelogram::n--;
}

Trapez::Trapez(Punct stanga_jos, float latura, Punct colt_opus, float latura2, float baza2)
    :Paralelogram(stanga_jos, latura, colt_opus, latura2)
{
    try
    {
        if( baza2 <=0 || stanga_jos.x + baza2 != colt_opus.x + ( colt_opus.x - latura2 - stanga_jos.x ) )
            throw 1;
    }
    catch ( int i )
    {
        cout<<"Eroare constructor, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
    this->baza2 = baza2;
}

Trapez::~Trapez()
{
    this->latura = 0;
    this->latura2 = 0;
    this->baza2 = 0;
}

Trapez::Trapez(Trapez& T)
{
    this->latura2 = T.latura2;
    this->latura = T.latura;
    this->stanga_jos = T.stanga_jos;
    this->colt_opus = T.colt_opus;
    this->baza2 = T.baza2;
}

void Trapez::citire(istream &in)
{
    Paralelogram::citire(in);
    cout<<"Cititi baza2: ";
    in>>baza2;
    try
    {
        if( baza2 <=0 || stanga_jos.x + baza2 != colt_opus.x + ( colt_opus.x - latura2 - stanga_jos.x ) )
            throw 1;
    }
    catch ( int i )
    {
        cout<<"Eroare constructor, nu se poate construi figura.\n";
        exit(EXIT_FAILURE);
    }
    corectitudine(true);
}

void Trapez::afisare(ostream &out)
{
    if(stanga_jos.x == 0 && stanga_jos.y == 0 && latura == 0
            && latura2 == 0 && colt_opus.x == 0 && colt_opus.y == 0 && baza2 == 0)
        out<<"";
    else
    {
        out<<"("<<stanga_jos.x<<", "<<stanga_jos.y<<"), ";
        out<<"("<<colt_opus.x<<", "<<colt_opus.y<<"), ";
        out<<"("<<colt_opus.x - latura2<<", "<<colt_opus.y<<"), ";
        out<<"("<<stanga_jos.x + baza2<<", "<<stanga_jos.y<<"), ";
        out<<"\b ";
        out<<"Latura: "<<latura<<", ";
        out<<"Latura2: "<<latura2<<", ";
        out<<"Baza2: "<<baza2<<endl;
    }
}

istream &operator>>(istream &in, Trapez &T)
{
    T.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Trapez &T)
{
    T.afisare(out);
    return out;
}

Trapez& Trapez::operator=(Trapez &T)
{
    stanga_jos.x = T.stanga_jos.x;
    stanga_jos.y = T.stanga_jos.y;
    latura = T.latura;
    latura2 = T.latura2;
    colt_opus.x = T.colt_opus.x;
    colt_opus.y = T.colt_opus.y;
}

float Trapez::arie()
{
    float h = colt_opus.y - stanga_jos.y;
    return ( ( baza2 + latura2 ) * h ) / 2;
}

float Trapez::perimetru()
{
    return latura * 2 + baza2 + latura2;
}

void Trapez::corectitudine(bool validitate = false)
{
    Paralelogram::corectitudine(validitate);
}

bool Trapez::getvaliditate()
{
    Paralelogram::getvaliditate();
}

void generare(Patrat *&Pat, int &i, string *cuv)
{
    string s;
    cout<<"\n";
    cout<<"Introduceti figura "<<i+1<<": ";
    cin>>s;
    try
    {
        if( s == "patrat" )
        {
            Pat = new Patrat;
            cin >> *Pat;
            cuv[i] = "Patrat";
            i++;
        }
        else if(s == "dreptunghi" )
        {
            Pat = new Dreptunghi;
            cin >> *Pat;
            cuv[i] = "Dreptunghi";
            i++;
        }
        else if (s=="romb")
        {
            Pat = new Romb;
            cin >> *Pat;
            cuv[i] = "Romb";
            i++;
        }
        else if(s == "paralelogram" )
        {
            Pat = new Paralelogram;
            cin >> *Pat;
            cuv[i] = "Paralelogram";
            i++;
        }
        else if( s == "trapez" )
        {
            Pat = new Trapez;
            cin >> *Pat;
            cuv[i] = "Trapez";
            i++;
        }
        else
            throw 1;
    }
    catch (bad_alloc var)
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus o figura valida. Incercati patrat, dreptunghi, romb, paralelogram sau trapez.\n ";
    }
}

void menu_output()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - 'Figuri geometrice' - Tema 5 "<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n===========================================================\n";
    cout<<endl;
    cout<<"1. Introduceti figurile geometrice";
    cout<<"\n";
    cout<<"2. Afisare figuri";
    cout<<"\n";
    cout<<"3. Numar figuri de fiecare tip";
    cout<<"\n";
    cout<<"4. Compatibilitate figura precedenta/ Arie/ Perimetru";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

void menu()
{
    int option = 0, ok = 0;
    int nr_figuri;
    Patrat **v;
    string *cuv;
    do
    {
        menu_output();
        cout<<"\n Introduceti alegerea: ";
        cin>>option;

        switch( option )
        {
        case 1:
        {
et1:{}
            cout<<"\nNumar figuri: ";
            cin>>nr_figuri;
            if ( nr_figuri <= 0 )
            {
                cout<<"\nEroare!";
                goto et1;
            }
            v=new Patrat*[nr_figuri];
            cuv = new string[nr_figuri];
            ok = 1;
            for(int i=0; i<nr_figuri;)
                generare(v[i],i, cuv);
        }
        break;
        case 2:
        {
            if( ok == 0 )
            {
                cout<<"\nEroare, nu ati intodus numarul de figuri!\n\n";
                break;
            }
            for(int i=0; i<nr_figuri; i++)
            {
                cout<<cuv[i]<<": "<<endl;
                cout<<*v[i];
                cout<<"----------------------------------------------------------------\n";
            }

        }
        break;
        case 3:
        {
            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!\n\n";
                break;
            }
            cout<<"\n";
            cout<<"Numar puncte: "<<Punct::NumarPuncte();
            cout<<"\nNumar patrate: "<<Patrat::NumarPatrate();
            cout<<"\nNumar dreptunghiuri: "<<Dreptunghi::NumarDreptunghiuri();
            cout<<"\nNumar romburi: "<<Romb::NumarRomburi();
            cout<<"\nNumar paralelograme: "<<Paralelogram::NumarParalelograme();
            cout<<"\nNumar trapezuri: "<<Trapez::NumarTrapezuri()<<endl;
        }
        break;
        case 4:
        {
            cout<<"Introduceti figura geometrica: ";
            string s;
            cin>>s;
            try
            {
                if(s == "patrat")
                {
                    cout<<"Patrat:\n";
                    Patrat Pat;
                    cin>>Pat;
                    cout<<Pat;
                    cout<<"Arie: "<<Pat.arie()<<"  Perimetru: "<<Pat.perimetru()<<endl;
                    cout<<"Incompatibil cu alte figuri geometrice.\n";
                    cout<<"----------------------------------------------------------------\n";
                }
                else if(s == "dreptunghi")
                {
                    cout<<"Dreptunghi:\n";
                    Dreptunghi D;
                    cin>>D;
                    cout<<D;
                    cout<<"Arie: "<<D.arie()<<"  Perimetru: "<<D.perimetru()<<endl;
                    if( D.compatibilitateDlaPAT() != 0)
                        cout<<"Compatibil cu un patrat.\n";
                    else
                        cout<<"Incompatibil cu un patrat.\n";
                    cout<<"----------------------------------------------------------------\n";
                }
                else if(s == "romb")
                {
                    cout<<"Romb:\n";
                    Romb R;
                    cin>>R;
                    cout<<R;
                    cout<<"Arie: "<<R.arie()<<"  Perimetru: "<<R.perimetru()<<endl;
                    if( R.compatibilitateRBlaPat() != 0)
                        cout<<"Compatibil cu un patrat.\n";
                    else
                        cout<<"Incompatibil cu un patrat.\n";
                    cout<<"----------------------------------------------------------------\n";
                }
                else if(s == "paralelogram")
                {
                    cout<<"Paralelogram:\n";
                    Paralelogram Par;
                    cin>>Par;
                    cout<<Par;
                    cout<<"Arie: "<<Par.arie()<<"  Perimetru: "<<Par.perimetru()<<endl;
                    Punct P(Par.gettcolt_opus_x(),Par.gettcolt_opus_y());
                    Paralelogram *G = (Paralelogram*) new Dreptunghi;
                    G = &Par;
                    if( G->Dreptunghi::compatibilitatePARlaD(P) != 0)
                        cout<<"Compatibil cu un dreptunghi.\n";
                    else
                        cout<<"Incompatibil cu un dreptunghi.\n";
                    float lat = Par.gettlatura2();
                    Paralelogram *G1 = (Paralelogram*) new Romb;
                    G1 = &Par;
                    if ( G1->Romb::compatibilitatePARlaRB(lat) != 0 )
                        cout<<"Compatibil cu un romb.\n";
                    else
                        cout<<"Incompatibil cu un romb.\n";
                    cout<<"----------------------------------------------------------------\n";
                }
                else if( s == "trapez")
                {
                    cout<<"Trapez:\n";
                    Trapez T;
                    cin>>T;
                    cout<<T;
                    cout<<"Arie: "<<T.arie()<<"  Perimetru: "<<T.perimetru()<<endl;
                    cout<<"Incompatibil cu alte figuri geometrice.\n";
                    cout<<"----------------------------------------------------------------\n";
                }
                else
                    throw 1;
            }
            catch( int i )
            {
                cout<<"\nNu ati introdus o figura valida. Incercati patrat, dreptunghi, romb, paralelogram sau trapez.\n\n ";
            }
        }
        break;
        case 0:
            option = 0;
            break;
        default:
            cout<<"\nSelectie invalida!\n\n";
            break;
        }
        system("pause");
        system("CLS");

    }
    while(option != 0);
}

int main()
{
    menu();
    return 0;
}
