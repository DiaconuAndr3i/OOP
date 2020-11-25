#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <ctime>
#include <windows.h>

using namespace std;

class Automobil
{
protected:
    float pret;
    int an_fabricatie;
    static int nr;
public:
    virtual ~Automobil() = 0;
    virtual void citire(istream &in) = 0;
    virtual void afisare(ostream &out) = 0;
    Automobil &operator = (Automobil &A);
    friend istream& operator >> (istream &, Automobil&);
    friend ostream& operator << (ostream &, Automobil&);
    static int nr_automobile()
    {
        return nr;
    }
};

Automobil::~Automobil() {};

Automobil &Automobil::operator=(Automobil& A)
{
    if (this!=&A)
    {
        A = A;
    }
    return *this;
}

istream& operator>> (istream& in, Automobil& A)
{
    A.citire(in);
    return in;
}
ostream& operator<< (ostream& out, Automobil &A)
{
    A.afisare(out);
    return out;
}


class Masina:public Automobil
{
protected:
    string utilitate;
    float dimensiune;
    float capacitate_cilindrica;
    float spatiu_interior;
public:
    Masina(float, int, string, float, float, float);
    ~Masina()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream &, Masina&);
    friend ostream& operator>>(ostream &, Masina&);
    Masina &operator = (Masina &M);
    int fct()
    {
        return spatiu_interior;
    }
};

int Automobil::nr;

Masina::Masina(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0)
{
    utilitate = utilitate_m;
    try
    {
        if (dimensiune < 0)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Dimensiunea masinii nu poate fi negativa.\n";
        exit(EXIT_FAILURE);
    }
    this->dimensiune = dimensiune;
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    this->pret = pret;
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    this->an_fabricatie = an_fabricatie;
    try
    {
        if ( capacitate_cilindrica < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Capacitatea cilindrica nu poate fi negativa.\n";
        exit(EXIT_FAILURE);
    }
    this->capacitate_cilindrica = capacitate_cilindrica;
    try
    {
        if ( spatiu_interior < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Spatiul interior nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    this->spatiu_interior = spatiu_interior;
    nr++;
}

void Masina::citire(istream& in)
{
    cout<<"Specificati pentru ce e folosita masina: ";
    getline(in,utilitate);
    cout<<"Specificati dimensiunea masinii(m): ";
    in>>dimensiune;
    cout<<"Specificati pretul masinii: ";
    in>>pret;
    cout<<"Specificati anul fabricatiei: ";
    in>>an_fabricatie;
    cout<<"Specificati capacitatea cilindrica(cmc): ";
    in>>capacitate_cilindrica;
    cout<<"Specificati spatiul interior(mp): ";
    in>>spatiu_interior;
}

void Masina::afisare(ostream& out)
{
    out<<"Utilizata pentru ";
    out<<utilitate;
    out<<endl<<"Dimensiune: ";
    out<<dimensiune;
    out<<endl<<"Pret: ";
    out<<pret;
    out<<endl<<"An fabricatie: ";
    out<<an_fabricatie;
    out<<endl<<"Capacitate cilindrica: ";
    out<<capacitate_cilindrica;
    out<<endl<<"Spatiu interior: ";
    out<<spatiu_interior;
}

istream& operator>> (istream& in, Masina& M)
{
    M.citire(in);
    return in;
}

ostream& operator<< (ostream& out, Masina& M)
{
    M.afisare(out);
    return out;
}

Masina& Masina::operator = (Masina& M)
{
    if (this!=&M)
    {
        utilitate = M.utilitate;
        dimensiune = M.dimensiune;
        pret = M.pret;
        an_fabricatie = M.an_fabricatie;
        capacitate_cilindrica = M.capacitate_cilindrica;
        spatiu_interior = M.spatiu_interior;
    }
    return *this;
}

class Mini:public Masina
{
private:
    bool nou;
    const float max_cap_cil;
    const float max_sp_int;
public:
    Mini(float, int, string, float, float, float, bool);
    ~Mini()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream &, Mini&);
    friend ostream& operator>>(ostream &, Mini&);
    Mini &operator = (Mini &mini);
};

Mini::Mini(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false)
    :Masina(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica, spatiu_interior),max_cap_cil(2000),max_sp_int(3)
{
    this->nou = nou;
}

void Mini::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Specificati statutul masinii(sh-0/noua-1): ";
    in>>nou;
    try
    {
        if(dimensiune<0 || dimensiune >=4)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Dimensiune eronata, nu poate fi inregistrata ca tip mini!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if(utilitate != "oras")
            throw 1;
    }
    catch(int i)
    {
        cout<<"Utilitate eronata,nu poate fi inregistrata ca tip mini!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( capacitate_cilindrica < 0 || capacitate_cilindrica > max_cap_cil)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare capacitate cilindrica, nu poate fi inregistrata ca tip mini!.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( spatiu_interior < 0 || spatiu_interior > max_sp_int )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare, spatiul interior ori este negativ ori este mare pentru un astfel de model!";
        exit(EXIT_FAILURE);
    }
}

istream& operator>>(istream& in, Mini& mini)
{
    mini.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Mini& mini)
{
    mini.afisare(out);
    return out;
}

void Mini::afisare(ostream &out)
{
    out<<"Masina mini:\n";
    out<<"------------------\n";
    Masina::afisare(out);
    out<<endl;
    if( nou == false )
        out<<"Statut: sh \n";
    else
        out<<"Statut: nou \n";
}

Mini& Mini::operator = (Mini& mini)
{
    if (this!=&mini)
    {
        utilitate = mini.utilitate;
        dimensiune = mini.dimensiune;
        pret = mini.pret;
        an_fabricatie = mini.an_fabricatie;
        capacitate_cilindrica = mini.capacitate_cilindrica;
        nou = mini.nou;
        spatiu_interior = mini.spatiu_interior;
    }

    return *this;
}

class Mica:public Masina
{
private:
    bool nou;
    const float max_cap_cil;
    const float min_sp_int;
    const float max_sp_int;
public:
    Mica(float, int, string, float, float, float, bool);
    ~Mica()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream &, Mica&);
    friend ostream& operator>>(ostream &, Mica&);
    Mica &operator = (Mica &mica);
};

Mica::Mica(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false)
    :Masina(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica),max_cap_cil(2500), min_sp_int(3), max_sp_int(6)
{
    this->nou = nou;
}

void Mica::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Specificati statutul masinii(sh-0/noua-1): ";
    in>>nou;
    try
    {
        if(dimensiune<3.85 || dimensiune >=4.1)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Dimensiune eronata, nu poate fi inregistrata ca tip mica!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if(utilitate != "oras")
            throw 1;
    }
    catch(int i)
    {
        cout<<"Utilitate eronata,nu poate fi inregistrata ca tip mica!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( capacitate_cilindrica < 0 || capacitate_cilindrica > max_cap_cil)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare capacitate cilindrica, nu poate fi inregistrata ca tip mica!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if( spatiu_interior <= min_sp_int || spatiu_interior > max_sp_int )
            throw 1;
    }
    catch(int i)
    {
        cout<<"Eroare, spatiul interior nu se incadreaza in caracteristica masinii!";
        exit(EXIT_FAILURE);
    }
}

istream& operator>>(istream& in, Mica& mica)
{
    mica.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Mica& mica)
{
    mica.afisare(out);
    return out;
}

void Mica::afisare(ostream &out)
{
    out<<"Masina mica:\n";
    out<<"------------------\n";
    Masina::afisare(out);
    out<<endl;
    if( nou == false )
        out<<"Statut: sh \n";
    else
        out<<"Statut: nou \n";
}

Mica& Mica::operator = (Mica& mica)
{
    if (this!=&mica)
    {
        utilitate = mica.utilitate;
        dimensiune = mica.dimensiune;
        pret = mica.pret;
        an_fabricatie = mica.an_fabricatie;
        capacitate_cilindrica = mica.capacitate_cilindrica;
        spatiu_interior = mica.spatiu_interior;
        nou = mica.nou;
    }

    return *this;
}

class Compacta:public Masina
{
protected:
    bool nou;
    const float max_cap_cil;
    const float min_sp_int;
    const float max_sp_int;
public:
    Compacta(float, int, string, float, float, float, bool);
    ~Compacta()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream &, Compacta&);
    friend ostream& operator>>(ostream &, Compacta&);
    Compacta &operator = (Compacta &com);
};

Compacta::Compacta(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false)
    :Masina(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica),max_cap_cil(3000), min_sp_int(6), max_sp_int(9)
{
    this->nou = nou;
}

void Compacta::citire(istream& in)
{
    Masina::citire(in);
    cout<<"Specificati statutul masinii(sh-0/noua-1): ";
    in>>nou;
    try
    {
        if(dimensiune < 4.2 || dimensiune >=4.5)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Dimensiune eronata, nu poate fi inregistrata ca tip compacta!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if( (utilitate.find("drum lung") == std::string::npos) && (utilitate.find("oras") == std::string::npos))
            throw 1;
    }
    catch(int i)
    {
        cout<<"Utilitate eronata,nu poate fi inregistrata ca tip compacta!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ.\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( capacitate_cilindrica < 0 || capacitate_cilindrica > max_cap_cil)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare capacitate cilindrica, nu poate fi inregistrata ca tip compacta!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if( spatiu_interior <= min_sp_int || spatiu_interior > max_sp_int )
            throw 1;
    }
    catch(int i)
    {
        cout<<"Eroare, spatiul interior nu se incadreaza in caracteristica masinii!";
        exit(EXIT_FAILURE);
    }
}

istream& operator>>(istream& in, Compacta& com)
{
    com.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Compacta& com)
{
    com.afisare(out);
    return out;
}

void Compacta::afisare(ostream &out)
{
    out<<"Masina compacta:\n";
    out<<"------------------\n";
    Masina::afisare(out);
    out<<endl;
    if( nou == false )
        out<<"Statut: sh \n";
    else
        out<<"Statut: nou \n";
}

Compacta& Compacta::operator = (Compacta& com)
{
    if (this!=&com)
    {
        utilitate = com.utilitate;
        dimensiune = com.dimensiune;
        pret = com.pret;
        an_fabricatie = com.an_fabricatie;
        capacitate_cilindrica = com.capacitate_cilindrica;
        spatiu_interior = com.spatiu_interior;
        nou = com.nou;
    }

    return *this;
}

class Hatchback:public Compacta
{
private:
    string tip;
public:
    Hatchback(float, int, string, float, float, float, bool, string);
    ~Hatchback()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream&,Hatchback& );
    friend ostream& operator<<(ostream&,Hatchback& );
    Hatchback &operator = (Hatchback& hat);
};

Hatchback::Hatchback(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false, string tipp = "")
    :Compacta(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica, spatiu_interior, nou)
{
    this->tip = tip;
}

void Hatchback::citire(istream& in)
{
    Compacta::citire(in);
    cout<<"Specificati (din nou) tipul masinii: ";
    in>>tip;
    try
    {
        if( tip.find("hatchback") == std::string::npos )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare, nu exista un astfel de tip!";
        exit(EXIT_FAILURE);
    }
    in.get();
}

istream& operator>>(istream& in, Hatchback& hat)
{
    hat.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Hatchback& hat)
{
    hat.afisare(out);
    return out;
}

void Hatchback::afisare(ostream& out)
{
    Compacta::afisare(out);
    out<<"Tip: "<<tip<<endl;
}

Hatchback &Hatchback::operator = (Hatchback& hat)
{
    if (this!=&hat)
    {
        utilitate = hat.utilitate;
        dimensiune = hat.dimensiune;
        pret = hat.pret;
        an_fabricatie = hat.an_fabricatie;
        capacitate_cilindrica = hat.capacitate_cilindrica;
        spatiu_interior = hat.spatiu_interior;
        nou = hat.nou;
        tip = hat.tip;
    }

    return *this;
}

class Combi:public Compacta
{
private:
    string tip;
public:
    Combi(float, int, string, float, float, float, bool, string);
    ~Combi()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream&,Combi& );
    friend ostream& operator<<(ostream&,Combi& );
    Combi &operator = (Combi& combi);
};

Combi::Combi(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false, string tipp = "")
    :Compacta(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica, spatiu_interior, nou)
{
    this->tip = tip;
}

void Combi::citire(istream& in)
{
    Compacta::citire(in);
    cout<<"Specificati (din nou) tipul masinii: ";
    in>>tip;
    try
    {
        if( tip.find("combi") == std::string::npos )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare, nu exista un astfel de tip!";
        exit(EXIT_FAILURE);
    }
}

istream& operator>>(istream& in, Combi& combi)
{
    combi.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Combi& combi)
{
    combi.afisare(out);
    return out;
}

void Combi::afisare(ostream& out)
{
    Compacta::afisare(out);
    out<<"Tip: "<<tip<<endl;
}

Combi &Combi::operator = (Combi& combi)
{
    if (this!=&combi)
    {
        utilitate = combi.utilitate;
        dimensiune = combi.dimensiune;
        pret = combi.pret;
        an_fabricatie = combi.an_fabricatie;
        capacitate_cilindrica = combi.capacitate_cilindrica;
        spatiu_interior = combi.spatiu_interior;
        nou = combi.nou;
        tip = combi.tip;
    }

    return *this;
}

class Sedan:public Compacta
{
private:
    string tip;
public:
    Sedan(float, int, string, float, float, float, bool, string);
    ~Sedan()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream&,Sedan& );
    friend ostream& operator<<(ostream&,Sedan& );
    Sedan &operator = (Sedan& sedan);
};

Sedan::Sedan(float pret = 0, int an_fabricatie =0, string utilitate_m = "", float dimensiune = 0, float capacitate_cilindrica = 0, float spatiu_interior = 0, bool nou = false, string tipp = "")
    :Compacta(pret, an_fabricatie, utilitate_m, dimensiune, capacitate_cilindrica, spatiu_interior, nou)
{
    this->tip = tip;
}

void Sedan::citire(istream& in)
{
    Compacta::citire(in);
    cout<<"Specificati (din nou) tipul masinii: ";
    in>>tip;
    try
    {
        if( tip.find("sedan") == std::string::npos )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Eroare, nu exista un astfel de tip!";
        exit(EXIT_FAILURE);
    }
    in.get();
}

istream& operator>>(istream& in, Sedan& sedan)
{
    sedan.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Sedan& sedan)
{
    sedan.afisare(out);
    return out;
}

void Sedan::afisare(ostream& out)
{
    Compacta::afisare(out);
    out<<"Tip: "<<tip<<endl;
}

Sedan &Sedan::operator = (Sedan& sedan)
{
    if (this!=&sedan)
    {
        utilitate = sedan.utilitate;
        dimensiune = sedan.dimensiune;
        pret = sedan.pret;
        an_fabricatie = sedan.an_fabricatie;
        capacitate_cilindrica = sedan.capacitate_cilindrica;
        spatiu_interior = sedan.spatiu_interior;
        nou = sedan.nou;
        tip = sedan.tip;
    }

    return *this;
}

int time_month()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1 + ltm->tm_mon;
}

int time_year()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return 1900 + ltm->tm_year;
}

class Monovolume:public Automobil
{
private:
    int nr_locuri;
    bool nou;
    float dimensiune;
    float capacitate_cilindrica;
    const int min_dimensiune;
public:
    Monovolume(float, int, int, bool, float, float);
    ~Monovolume()
    {
        nr--;
    };
    void citire(istream& in);
    void afisare(ostream &out);
    friend istream& operator>>(istream&, Monovolume& );
    friend ostream& operator<<(ostream&, Monovolume& );
    Monovolume &operator =(Monovolume& mon);
    float Valoare_discount()const;
    bool nou_sh()const
    {
        return nou;
    }
    float val_pret()
    {
        return pret;
    }
};

Monovolume::Monovolume(float pret = 0, int an_fabricatie = 0, int nr_locuri = 5, bool nou = false, float dimensiune = 5, float capacitate_cilindrica = 0)
    :min_dimensiune(5)
{
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ!\n";
        exit(EXIT_FAILURE);
    }
    this->pret = pret;
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ!\n";
        exit(EXIT_FAILURE);
    }
    this->an_fabricatie = an_fabricatie;
    try
    {
        if (nr_locuri < 5 || nr_locuri > 7)
            throw 1;
    }
    catch ( int i )
    {
        cout<<"Eroare, numarul de locuri nepotrivit pentru acest model!\n";
        exit(EXIT_FAILURE);
    }
    this->nr_locuri = nr_locuri;
    this->nou = nou;
    try
    {
        if( dimensiune < 0 || dimensiune < min_dimensiune )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Dimensiune eronata pentru un VAN!\n";
        exit(EXIT_FAILURE);
    }
    this->dimensiune = dimensiune;
    try
    {
        if (capacitate_cilindrica < 0)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Capacitatea cilindrica nu poate fi negativa!\n";
        exit(EXIT_FAILURE);
    }
    this->capacitate_cilindrica = capacitate_cilindrica;
    nr++;
}

float Monovolume::Valoare_discount()const
{
    const int st_v= 6;
    const int sf_v= 8;
    if( time_month() >= st_v && time_month() <= sf_v )
        return 10;
    return time_year() - an_fabricatie - 1;
}

void Monovolume::citire(istream& in)
{
    cout<<"Specificati dimensiunea VAN-ului(m): ";
    in>>dimensiune;
    cout<<"Specificati capacitatea cilindrica(cmc): ";
    in>>capacitate_cilindrica;
    cout<<"Specificati numarul de locuri: ";
    in>>nr_locuri;
    cout<<"Specificati anul fabricatiei: ";
    in>>an_fabricatie;
    cout<<"Specificati statutul masinii(sh-0/noua-1): ";
    in>>nou;
    cout<<"Specificati pretul VAN-ului: ";
    in>>pret;
    try
    {
        if ( pret < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Pretul nu poate fi negativ!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if ( an_fabricatie < 0)
            throw 1;
    }
    catch (int i)
    {
        cout<<"Anul fabricatiei nu poate fi negativ!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if (nr_locuri < 5 || nr_locuri > 7)
            throw 1;
    }
    catch ( int i )
    {
        cout<<"Eroare, numarul de locuri nepotrivit pentru acest model!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if( dimensiune < 0 || dimensiune < min_dimensiune )
            throw 1;
    }
    catch (int i)
    {
        cout<<"Dimensiune eronata pentru un VAN!\n";
        exit(EXIT_FAILURE);
    }
    try
    {
        if (capacitate_cilindrica < 0)
            throw 1;
    }
    catch(int i)
    {
        cout<<"Capacitatea cilindrica nu poate fi negativa!\n";
        exit(EXIT_FAILURE);
    }
}

void Monovolume::afisare(ostream& out)
{
    out<<"Monovolume tip VAN:\n";
    out<<"----------------------\n";
    out<<"Dimensiune: "<<dimensiune;
    out<<endl<<"Capacitate cilindrica: "<<capacitate_cilindrica;
    out<<endl<<"Numar locuri: "<<nr_locuri;
    out<<endl<<"An fabricatie: "<<an_fabricatie;
    cout<<endl;
    if( nou == false )
    {
        out<<"Statut: sh \n";
        if(Valoare_discount() == 10)
            out<<"Pret: " << pret - pret * 0.1 <<"\n";
        else
            out<<"Pret: "<< pret - ((Valoare_discount()+1)/100) * pret <<"\n";
    }
    else
    {
        out<<"Statut: nou \n";
        out<<"Pret: "<<pret<<endl;
    }

}

istream& operator>>(istream& in, Monovolume& mon)
{
    mon.citire(in);
    return in;
}

ostream& operator<<(ostream& out, Monovolume& mon)
{
    mon.afisare(out);
    return out;
}

Monovolume &Monovolume::operator=(Monovolume &mon)
{
    if(this!=&mon)
    {
        dimensiune = mon.dimensiune;
        capacitate_cilindrica = mon.capacitate_cilindrica;
        nr_locuri = mon.nr_locuri;
        an_fabricatie = mon.an_fabricatie;
        nou = mon.nou;
        pret = mon.pret;
    }
    return *this;
}

template <class T>class Vanzare
{
private:
    pair<int,int> tranzactionare;
    vector<T> automobile_stoc;
    vector<T> automobile_vandute;
public:
    Vanzare() {};

    Vanzare( vector<T>a_stoc )
    {
        for(int i =0; i<a_stoc.size(); i++)
        {
            automobile_stoc[i] = a_stoc[i];
        }
    }

    ~Vanzare()
    {
        automobile_stoc.clear();
        automobile_vandute.clear();
    }

    void adauga_la_vanzare()
    {
        cout<<"Adaugati masinile pentru vanzare: \n";
        cout<<"Numarul acestora: ";
        int n;
        cin>>n;
        cin.get();
        cout<<endl;
        for(int i =0; i<n; i++)
        {
            T t;
            cin>>t;
            automobile_stoc.push_back(t);
            tranzactionare.first++;
            cin.get();
        }
    }

    void realizare_tranzactie()
    {
        cout<<"Alegeti masina care va fi vanduta: \n";
        for(int i =0; i<automobile_stoc.size(); i++)
            cout<<i+1<<") "<<automobile_stoc[i]<<endl;
        cout<<endl;
        int n;
        cout<<"Nr = ";
        cin>>n;
        try
        {
            if(n<=0)
                throw 1;
        }
        catch( int i)
        {
            cout<<"\nAlegere eronata!\n";
            exit(EXIT_FAILURE);
        }
        automobile_stoc -= automobile_stoc[n-1];
        tranzactionare.first--;
        tranzactionare.second++;
        automobile_vandute.push_back(automobile_stoc[n-1]);
    }

    void masini_pe_stoc()
    {
        for(int i =0; i<automobile_stoc.size(); i++)
            cout<<automobile_stoc[i]<<endl;
    }

    void masini_vandute()
    {
        for(int i =0; i<automobile_vandute.size(); i++)
            cout<<automobile_vandute[i]<<endl;
    }

    int nr_masini_stoc()
    {
        return tranzactionare.first;
    }
    int nr_vandute()
    {
        return tranzactionare.second;
    }
};

template<class Tip> vector<Tip>& operator-=(vector<Tip>& U,Tip &b)
{
    for (int i =0; i<U.size(); i++)
        if(&U[i] == &b)
            U.erase(U.begin() + i);
}

template <> class Vanzare <Monovolume>
{
private:
    pair<int,int> tranzactionare;
    vector<Monovolume> automobile_stoc;
    vector<Monovolume> automobile_vandute;
    set< pair<float,float> > pret_tipizat; ///se retine pretul initial pana la aplicarea reducerii
public:
    Vanzare() {};

    Vanzare( vector<Monovolume>a_stoc )
    {
        for(int i =0; i<a_stoc.size(); i++)
        {
            automobile_stoc[i] = a_stoc[i];
        }
    }

    ~Vanzare()
    {
        automobile_stoc.clear();
        automobile_vandute.clear();
    }

    void adauga_la_vanzare()
    {
        cout<<"Adaugati VAN-urile pentru vanzare: \n";
        cout<<"Numarul acestora: ";
        int n;
        cin>>n;
        cin.get();
        Monovolume *Mon = new Monovolume[n];
        cout<<endl;
        for(int i =0; i<n; i++)
        {
            cin>>Mon[i];
            automobile_stoc.push_back(Mon[i]);
            if(Mon[i].nou_sh() == false)
            {
                if(Mon[i].Valoare_discount() == 10)
                    pret_tipizat.insert(make_pair(Mon[i].val_pret(),10));
                else
                    pret_tipizat.insert(make_pair(Mon[i].val_pret(),(Mon[i].Valoare_discount())+1));
            }
            else
                pret_tipizat.insert(make_pair(0,0));
            tranzactionare.first++;
            cin.get();
        }

    }

    void realizare_tranzactie()
    {
        cout<<"Alegeti masina care va fi vanduta: \n";
        for(int i =0; i<automobile_stoc.size(); i++)
            cout<<i+1<<") "<<automobile_stoc[i]<<endl;
        cout<<endl;
        int n;
        cout<<"Nr = ";
        cin>>n;
        try
        {
            if(n<=0)
                throw 1;
        }
        catch( int i)
        {
            cout<<"\nAlegere eronata!\n";
            exit(EXIT_FAILURE);
        }
        set< pair<float,float> >::iterator it;
        it = pret_tipizat.begin();
        for(int i =0; i<n-1; i++)
            it++;
        pret_tipizat.erase(it);
        automobile_stoc -= automobile_stoc[n-1];
        tranzactionare.first--;
        tranzactionare.second++;
        automobile_vandute.push_back(automobile_stoc[n-1]);
    }

    void masini_pe_stoc()
    {
        set < pair<float,float> >::iterator it;
        it = pret_tipizat.begin();
        for(int i =0; i<automobile_stoc.size(); i++)
        {
            cout<<automobile_stoc[i];
            if( automobile_stoc[i].nou_sh() == false)
            {
                if( time_month()>= 6 && time_month()<=8 )
                    cout<<"Pretul a fost redus de la "<<it->first<<" cu un discount de "<<it->second<<"%, de vara"<<endl<<endl;
                else
                    cout<<"Pretul a fost redus de la "<<it->first<<" cu un discount de "<<it->second<<"%, raportat la vechime"<<endl<<endl;
            }
            it++;
        }

    }

    void masini_vandute()
    {
        for(int i =0; i<automobile_vandute.size(); i++)
            cout<<automobile_vandute[i]<<endl;
    }

    int nr_masini_stoc()
    {
        return tranzactionare.first;
    }
    int nr_vandute()
    {
        return tranzactionare.second;
    }
};

void menu_output1()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - Tema 4 - Parc Auto"<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n======================================================\n";
    cout<<endl;
    cout<<"1. Introduceti informatii depre automobile";
    cout<<"\n";
    cout<<"2. Vanzare template: mini, mica, compacta etc";
    cout<<"\n";
    cout<<"3. Vanzare template, specializare MONOVOLUM";
    cout<<"\n";
    cout<<"4. Contorizare automobile";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}

void mono(vector<Monovolume>&vect)
{
    Monovolume MON;
    cin>>MON;
    vect.push_back(MON);
}

void tip( Masina *&M, int i, vector<Monovolume>&vect)
{
et:
    string s;
    cout<<endl;
    cout<<"Introduceti tipul masinii "<<i+1<<": ";
    cin>>s;
    try
    {
        if( s == "mini" )
        {
            M = new Mini;
            cin.get();
            cin>>*M;
        }
        else if( s == "mica" )
        {
            M = new Mica;
            cin.get();
            cin>>*M;
        }
        else if( s == "compacta" )
        {
            M = new Compacta;
            cin.get();
            cin>>*M;
        }
        else if( s == "hatchback" )
        {
            M = new Hatchback;
            cin.get();
            cin>>*M;
        }
        else if( s == "combi" )
        {
            M = new Combi;
            cin.get();
            cin>>*M;
        }
        else if( s == "sedan" )
        {
            M = new Sedan;
            cin.get();
            cin>>*M;
        }
        else if( s == "van" )
        {
            M = new Masina;
            mono(vect);
        }
        else
            throw 1;
    }
    catch( bad_alloc a )
    {
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j)
    {
        cout<<"Nu ati introdus un tip de masina valid. Incercati mini, mica, compacta, hatchback, combi, sedan sau van.\n";
        goto et;
    }
}

void menu_output2()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - Tema 4 - Parc Auto"<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n======================================================\n";
    cout<<endl;
    cout<<"1. Adaugare automobile disponibile pentru vanzare";
    cout<<"\n";
    cout<<"2. Realizare tranzactie";
    cout<<"\n";
    cout<<"3. Afisare masini pe stoc";
    cout<<"\n";
    cout<<"4. Afisare masini vandute";
    cout<<"\n";
    cout<<"0. Revenire la meniul principal";
    cout<<"\n";
}

void menu_output3()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - Tema 4 - Parc Auto"<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n======================================================\n";
    cout<<endl;
    cout<<"1. Adaugare MONOVOLUME disponibile pentru vanzare";
    cout<<"\n";
    cout<<"2. Realizare tranzactie";
    cout<<"\n";
    cout<<"3. Afisare masini pe stoc";
    cout<<"\n";
    cout<<"4. Afisare masini vandute";
    cout<<"\n";
    cout<<"0. Revenire la meniul principal";
    cout<<"\n";
}

void menu()
{
    int option, option2 = 0, option3 = 0;
    option = 0;
    int n = 0;
    Masina **M;
    vector<Monovolume>vect;
    do
    {
        menu_output1();
        cout<<"\nIntroduceti numarul actiunii: ";
        cin>>option;
        switch(option)
        {
        case 1:
        {
            cout<<"Introduceti numarul de masini citite: ";
            cin>>n;
            try
            {
                if(n<=0)
                    throw 1;
            }
            catch(int u )
            {
                cout<<"Ati introdus un numar <= 0!";
                exit(EXIT_FAILURE);
            }
            M = new Masina*[n];
            for(int i =0; i < n; i++)
                tip(M[i],i,vect);
            cout<<"\nAfisare automobile: \n";
            for(int i =0; i<n; i++)
            {
                if( M[i]->fct() != 0 )
                {
                    cout<<"\n"<<*M[i];
                    cout<<"--------------------------\n";
                }
            }
            for(int i =0; i<vect.size(); i++)
            {
                cout<<endl<<vect[i];
                cout<<"--------------------------\n";
            }
            system("pause");
            break;
        }
        case 2:
        {
et1:
            system("CLS");
            menu_output2();
            cout<<endl;
            string s;
            cout<<"Introduceti tipul masinii pentru tranzactie: ";
            cin>>s;
            if( s == "mini" )
            {
                Vanzare<Mini>M;
                bool ok = 0;
                do
                {
et2:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et2;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et2;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et2;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else if(s == "mica")
            {
                Vanzare<Mica>M;
                bool ok = 0;
                do
                {
et3:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et3;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et3;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et3;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else if(s == "compacta")
            {
                Vanzare<Compacta>M;
                bool ok = 0;
                do
                {
et4:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et4;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et4;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et4;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else if(s == "sedan")
            {
                Vanzare<Sedan>M;
                bool ok = 0;
                do
                {
et5:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et5;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et5;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et5;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else if(s == "hatchback")
            {
                Vanzare<Hatchback>M;
                bool ok = 0;
                do
                {
et6:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et6;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et6;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et6;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else if(s == "combi")
            {
                Vanzare<Combi>M;
                bool ok = 0;
                do
                {
et7:
                    system("CLS");
                    menu_output2();
                    cout<<"\nIntroduceti numarul actiunii: ";
                    cin>>option2;
                    switch(option2)
                    {
                    case 1:
                        M.adauga_la_vanzare();
                        ok = 1;
                        break;
                    case 2:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et7;
                        }
                        M.realizare_tranzactie();
                        system("pause");
                        break;
                    case 3:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et7;
                        }
                        M.masini_pe_stoc();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 4:
                        if( ok == 0 )
                        {
                            cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                            system("pause");
                            goto et7;
                        }
                        M.masini_vandute();
                        cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                        cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                        system("pause");
                        break;
                    case 0:
                        option2 = 0;
                        break;
                    default:
                        cout<<"Selectie invalida!";
                        system("pause");
                        break;
                    }
                }
                while(option2!=0);
                system("cls");
            }
            else
            {
                cout<<"Eroare, incercati mini, mica, compacta, combi, hatchback, sedan!\n\n";
                system("pause");
                goto et1;
            }
            break;
        }
        case 3:
        {
            Vanzare<Monovolume>M;
            bool ok = 0;
            do
            {
et8:
                system("cls");
                menu_output3();
                cout<<"\nIntroduceti numarul actiunii: ";
                cin>>option3;
                switch(option3)
                {
                case 1:
                    M.adauga_la_vanzare();
                    ok = 1;
                    break;
                case 2:
                    if( ok == 0 )
                    {
                        cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                        system("pause");
                        goto et8;
                    }
                    M.realizare_tranzactie();
                    system("pause");
                    break;
                case 3:
                    if( ok == 0 )
                    {
                        cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                        system("pause");
                        goto et8;
                    }
                    M.masini_pe_stoc();
                    cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                    cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                    system("pause");
                    break;
                case 4:
                    if( ok == 0 )
                    {
                        cout<<"Nu se poate realiza tranzactia, nu exista masini pe stoc!"<<endl;
                        system("pause");
                        goto et8;
                    }
                    M.masini_vandute();
                    cout<<endl<<"Nr masini stoc: "<<M.nr_masini_stoc()<<endl;
                    cout<<"Nr masini vandute: "<<M.nr_vandute()<<endl;
                    system("pause");
                    break;
                case 0:
                    option2 = 0;
                    break;
                default:
                    cout<<"Selectie invalida!";
                    system("pause");
                    break;
                }


            }
            while(option3!=0);


            break;
        }
        case 4:
        {
            int N_mini = 0,N_mica = 0,N_compacta = 0, N_sedan = 0, N_combi = 0, N_hatchback = 0;
            if (n>0)
            {
                for(int i=0; i<n; i++)
                {
                    if( M[i]->fct() != 0 )
                    {
                        Mini *p1=dynamic_cast<Mini*>(M[i]);
                        Mica *p2=dynamic_cast<Mica*>(M[i]);
                        Compacta *p3=dynamic_cast<Compacta*>(M[i]);
                        Sedan *p4=dynamic_cast<Sedan*>(M[i]);
                        Hatchback *p5=dynamic_cast<Hatchback*>(M[i]);
                        Combi *p6=dynamic_cast<Combi*>(M[i]);
                        if (p1)
                            N_mini++;
                        if (p2)
                            N_mica++;
                        if (p3)
                            N_compacta++;
                        if (p4)
                            N_sedan++;
                        if (p5)
                            N_hatchback++;
                        if (p6)
                            N_combi++;
                    }
                }
                cout<<"Numarul tip mini: "<<N_mini<<"\n";
                cout<<"Numarul tip mica: "<<N_mica<<"\n";
                cout<<"Numarul tip compacta: "<<N_compacta<<"\n";
                cout<<"Numarul tip sedan: "<<N_sedan<<"\n";
                cout<<"Numarul tip hatchback: "<<N_hatchback<<"\n";
                cout<<"Numarul tip combi: "<<N_combi<<"\n";
                cout<<"Numarul tip van: "<<vect.size()<<"\n";
                system("pause");
            }
            else
            {
                cout<<"Nu s-au citit automobile. Reveniti la actiunea 1.\n";
                system("pause");
            }
            break;
        }

        case 0:
            option = 0;
            break;
        default:
            cout<<"Selectie invalida!"<<endl;
            system("pause");
            break;
        }
        system("cls");
    }
    while(option!=0);
}

int main()
{
    menu();
}
