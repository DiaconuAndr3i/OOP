#include <iostream>
#include <windows.h>

using namespace std;

class Lista;



// Clasa Nod pentru o lista
class Nod
{
private:
    int info;
    Nod *next;

public:
    Nod();
    Nod(int info,Nod* next=0);
    int getInfo();
    void setInfo(int info);
    Nod* getNext();
    void setNext(Nod* next);

    int operator == (Nod&);
    friend class Lista;
};


//Constructor implicit
Nod::Nod()
{
    next=0;
}

//Constructor de initializare
Nod::Nod(int info, Nod* next)
{
    this->info=info;
    this->next=next;
}

//Getter pt. inf. nodului
int Nod::getInfo()
{
    return info;
}


//Setter pt. inf. nodului
void Nod::setInfo(int info)
{
    this->info=info;
}


//Getter care indica urmatorul nod
Nod* Nod::getNext()
{
    return next;
}


//Setter pt. urmatorul nod
void Nod::setNext(Nod* next)
{
    this->next=next;
}



int Nod::operator == (Nod &n)
{
    return this->info==n.info;
}



// Clasa Lista simplu inlatuita

class Lista
{
private:
    Nod *prim; //primul element din lista
    Nod *ultim; //ultimul element din lista

public:
    Lista();
    ~Lista(); //Destructor pt. dezalocare de memorie
    Lista(Lista&);//Constructor de copiere
    int isEmpty(); //verificare daca lista e vida
    void addElement(Nod n);//adaugare element in lista la sfarsit
    void removeDuplicates();// eliminare duplicate
    Nod* getFirst();//intoarce primul elemnt din lista

    friend istream& operator>>(istream &in, Lista& );
    friend ostream& operator<<(ostream& out, Lista&);
    friend Lista& operator+(Lista& L1, Lista& L2);
    friend Lista& operator*(Lista& L1, Lista& L2);
    friend Lista& operator-(Lista& L1, Lista& L2);
};




Lista::Lista()
{
    prim=ultim=0;
}



Lista::~Lista()
{
    Nod *p=prim;
    Nod *q;
    //se dezaloca memoria pt. lista
    while(p!=0)
    {
        q = p;
        p = p->next;
        delete q;
    }
    prim=ultim = 0;
}


int Lista::isEmpty()
{
    return prim==0;
}



inline Lista::Lista(Lista &L)
{
    Nod *tmp = L.getFirst();
    this->prim = new Nod;
    (this->prim)->info = tmp -> info;
    (this->prim)->next = NULL;
    Nod *act = this->prim;
    tmp = tmp ->next;

    while(tmp!=NULL)
    {
        act -> next = new Nod;
        act = act -> next;
        act ->info = tmp -> info;
        act ->next = NULL;
        tmp = tmp ->next;
    }

}


void Lista::addElement(Nod n)
{
    Nod *p;
    p=new Nod(n.info,0);
    if(isEmpty())
    {
        prim=ultim=p;
    }
    else
    {
        ultim->next=p;
        ultim = p;
    }
}


void Lista::removeDuplicates()
{
    Nod *p1, *p2, *dup;
    p1 = prim;
    while(p1 != NULL && p1 ->next != NULL)
    {
        p2 = p1;

        while(p2->next != NULL)
        {
            if(p1->info == p2->next->info)
            {
                dup = p2 ->next;
                p2->next = p2->next->next;
                delete(dup);
            }
            else
                p2 = p2->next;
        }

        p1 = p1->next;

    }
}



Nod* Lista::getFirst()
{
    return prim;
}



istream& operator>>(istream &in, Lista& lista)
{
    int i;
    cout<<"Lista(urmata de 0 la terminare):"<<endl;
    while(true)
    {
        cin>>i;
        if(i == 0)
            break;
        lista.addElement(Nod(i));
    }
    return in;
}


ostream& operator<<(ostream& out, Lista& lista)
{
    Nod * p=lista.getFirst();
    while(p)
    {
        cout<<p->getInfo()<<",";
        p=p->getNext();
    }
    cout<<"\b ";
    return out;
}



inline Lista& operator+(Lista& L1, Lista& L2)
{
//Unesc cele 2 liste apoi apelez motoda removeDuplicates() si astfel se obtine reuniunea
    Lista *L = new Lista;
    Lista &L3(L1), &L4(L2);

    if (L3.isEmpty())
        L->prim = L4.getFirst();

    else if(L4.isEmpty())
        L->prim = L3.getFirst();

    else if(L3.isEmpty()&&L4.isEmpty())
        return *L;

    else
    {
        L->prim = L3.getFirst();
        Nod *p = new Nod;
        p = L->prim;
        while(p->getNext())
        {
            p = p -> getNext();
        }

        p->setNext(L4.getFirst());

        (*L).removeDuplicates();
    }
    return *L;

}

inline Lista& operator-(Lista& L1, Lista& L2)
{
    Lista *L = new Lista;
    Lista &L3(L1), &L4(L2);
    if (L3.isEmpty())
        return *L;

    else if(L4.isEmpty())
        L->prim = L3.getFirst();

    else if(L3.isEmpty()&&L4.isEmpty())
        return *L;

    else
    {
        Nod *p = new Nod;
        p = L4.getFirst();
        int nr = 0;
        while(p->getNext())    //fac un pointer spre ultimul nod din prima lista pentru a unii cu elemente din a doua
        {
            nr ++;
            p = p ->getNext();

        }
        nr++;

        Nod *l3, *l4;
        l3 = L3.getFirst();
        while(l3)
        {
            int ok =0;
            l4 = L4.getFirst();
            while(l4)
            {
                if(l3 ->getInfo() != l4 ->getInfo())
                    ok++;
                l4 = l4 ->getNext();
            }

            if (ok == nr)
                (*L).addElement(Nod(l3->getInfo()));

            l3 = l3 ->getNext();
        }
    }
    return *L;
}

inline Lista& operator*(Lista& L1, Lista& L2)
{
    Lista *L = new Lista;
    Lista &L3(L1), &L4(L2);
    if (L3.isEmpty())
        return *L;

    else if(L4.isEmpty())
        return *L;

    else if(L3.isEmpty()&&L4.isEmpty())
        return *L;

    else
    {
        *L = (L3+L4)-((L3-L4)+(L4-L3));
        return *L;
    }


}



void menu_output1()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - Clasa 'Multime_dinamic' "<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n======================================================\n";
    cout<<endl;
    cout<<"1. Introduceti numarul de liste inlantuite/ multimi";
    cout<<"\n";
    cout<<"2. Introduceti listele inlantuite";
    cout<<"\n";
    cout<<"3. Afisarea listelor";
    cout<<"\n";
    cout<<"4. Reuniune de multimi";
    cout<<"\n";
    cout<<"5. Intersectie de multimi";
    cout<<"\n";
    cout<<"6. Diferenta de multimi";
    cout<<"\n";
    cout<<"0. Iesire.";
    cout<<"\n";
}



void menu_output2()
{
    cout<<endl<<"DIACONU ANDREI 211 - Proiect - Clasa 'Multime_dinamic' "<<endl;
    cout<<"\n\tMENIU:";
    cout<<"\n======================================================\n";
    cout<<endl;
    cout<<"1. Afisarea listelor introduse";
    cout<<"\n";
    cout<<"2. Afisarea listelor ca multimi(eliminarea duplicatelor)";
    cout<<"\n";
    cout<<"0. Revenire in meniul principal.";
    cout<<"\n";
}



void menu()
{
    int option, ok = 0;
    option = 0;
    int nr_liste;
    Lista *L;

    do
    {
        menu_output1();

        cout<<"\n Introduceti numarul actiunii: ";
        cin>>option;

        switch(option)
        {

        case 1:
        {
et1:
            {}
            cout<<"\nNumar liste: ";
            cin>>nr_liste;
            if(nr_liste <= 0)
            {
                cout<<"\nEroare!";
                goto et1;
            }
            L = new Lista[nr_liste];
            ok = 1;
        }
        break;

        case 2:
        {
            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!";
                break;
            }
            for (int i = 0; i<nr_liste; i++)
            {
                L[i].~Lista();
            }

            for (int i = 0; i<nr_liste; i++)
            {
                cin>>L[i];
            }
        }
        break;

        case 3:
        {
            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!";
                break;
            }
            system("CLS");
            int op = 0;
            do
            {
                menu_output2();
                cout<<"\n Introduceti numarul actiunii: ";
                cin>>op;

                switch(op)
                {
                case 1:
                {
                    for (int i = 0; i < nr_liste; i++)
                        cout<<"Lista "<<i+1<<": "<<L[i]<<endl;
                }
                break;

                case 2:
                {
                    for (int i = 0; i < nr_liste; i++)
                    {
                        if(L[i].isEmpty())
                            cout<<"Multime "<<i+1<<": { "<<L[i]<<"}"<<endl;
                        else
                        {
                            Lista L1(L[i]);
                            L1.removeDuplicates();
                            cout<<"Multime "<<i+1<<": { "<<L1<<"}"<<endl;
                        }
                    }
                }
                break;
                case 0:
                    goto et;
                    break;
                default:
                    cout<<"\nSelectie invalida!\n";
                    break;
                }
                system("pause");
                system("CLS");
            }
            while(op != 0);
        }
        break;

        case 4:
        {
            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!";
                break;
            }
            cout<<endl;
            for (int i = 0; i < nr_liste; i++)
            {
                if(L[i].isEmpty())
                    cout<<"Multime "<<i+1<<": { "<<L[i]<<"}"<<endl;
                else
                {
                    Lista L1(L[i]);
                    L1.removeDuplicates();
                    cout<<"Multime "<<i+1<<": { "<<L1<<"}"<<endl;
                }
            }
            int v[100],n;
et4:
            {}
            cout<<"\nIntroduceti numarul multimilor care participa la reuniune: ";
            cin>>n;
            if(n <= 0 || n > nr_liste)
            {
                cout<<"\nEroare!\n";
                goto et4;
            }
            Lista L2;
            cout<<"\nIntroduceti indicii multimilor care participa la reuniune: ";
            for(int i = 0; i < n; i++)
            {
                cin>>v[i];
                L2 = L2 + L[v[i]-1];
            }
            L2.removeDuplicates();
            for(int i = 0; i < n; i++)
                cout<<"M"<<v[i]<<"+";
            cout<<"\b ="<<"{ "<<L2<<"}";
            for (int i = 0; i < nr_liste; i++ )
                L[i].~Lista();
        }
        break;
        case 5:
        {

            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!";
                break;
            }
            cout<<endl;
            for (int i = 0; i < nr_liste; i++)
            {
                if(L[i].isEmpty())
                    cout<<"Multime "<<i+1<<": { "<<L[i]<<"}"<<endl;
                else
                {
                    Lista L1(L[i]);
                    L1.removeDuplicates();
                    cout<<"Multime "<<i+1<<": { "<<L1<<"}"<<endl;
                }
            }
            int v[100],n;
et5:
            {}
            cout<<"\nIntroduceti numarul multimilor care participa la intersectie: ";
            cin>>n;
            if(n <= 0 || n>nr_liste)
            {
                cout<<"\nEroare!\n";
                goto et5;
            }
            cout<<"\nIntroduceti indicii multimilor care participa la intersectie: ";
            cin>>v[0];
            Lista L2;
            L2 = L[v[0]-1];
            for(int i = 1; i < n; i++)
            {
                cin>>v[i];
                L2 = L2 * L[v[i]-1];
            }
            L2.removeDuplicates();
            for(int i = 0; i < n; i++)
                cout<<"M"<<v[i]<<"*";
            cout<<"\b ="<<"{ "<<L2<<"}";
            for (int i = 0; i < nr_liste; i++ )
                L[i].~Lista();
        }

        break;
        case 6:

        {
            if (ok == 0)
            {
                cout<<"\nEroare, nu ati introdus numarul de liste!";
                break;
            }
            cout<<endl;
            for (int i = 0; i < nr_liste; i++)
            {
                if(L[i].isEmpty())
                    cout<<"Multime "<<i+1<<": { "<<L[i]<<"}"<<endl;
                else
                {
                    Lista L1(L[i]);
                    L1.removeDuplicates();
                    cout<<"Multime "<<i+1<<": { "<<L1<<"}"<<endl;
                }
            }
            int v[100],n;
et6:
            {}
            cout<<"\nIntroduceti numarul multimilor care participa la diferenta: ";
            cin>>n;
            if(n <= 0 || n>nr_liste)
            {
                cout<<"\nEroare!\n";
                goto et6;
            }
            cout<<"\nIntroduceti indicii multimilor care participa la diferenta: ";
            cin>>v[0];
            Lista L2;
            L2 = L[v[0]-1];
            for(int i = 1; i < n; i++)
            {
                cin>>v[i];
                L2 = L2 - L[v[i]-1];
            }
            for(int i = 0; i < n; i++)
                cout<<"M"<<v[i]<<"-";
            L2.removeDuplicates();
            cout<<"\b ="<<"{ "<<L2<<"}";
            for (int i = 0; i < nr_liste; i++ )
                L[i].~Lista();
        }

        break;
        case 0:
            goto et2;
            break;
        default:
            cout<<"\nSelectie invalida!";
            break;
        }
        cout<<endl;
        system("pause");
et:
        {}
        system("CLS");
        goto et3;
et2:
        {
            system("CLS");
            cout<<"Programul se inchide";
            Sleep(400);
            cout<<".";
            Sleep(400);
            cout<<".";
            Sleep(400);
            cout<<".";
            Sleep(400);
            system("CLS");
        }
et3:
        {}
    }
    while(option != 0);
}



int main()
{

    menu();
    return 0;
}
