#include <iostream>
#include <windows.h>
#include <typeinfo>

using namespace std;
//////////////////////////////persoana
class persoana{
protected:
    int id;
    string nume;
    string cnp;
    static int numar;
public:
    persoana(int, string, string);
    persoana(persoana&);
    ~persoana();
    void set(int, string, string);
    void set(const persoana&);
    virtual void citire(istream& in);
    friend istream& operator>>(istream& in, persoana& p);
    virtual void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, persoana& p);
    void operator=(const persoana&);
    static void numar_persoane(){
        cout << numar;}

};
int persoana::numar;
persoana::persoana(int id = 0, string nume = "", string cnp = ""){
    numar++;
    this->id = id;
    this->nume = nume;
    this->cnp = cnp;
}

persoana::~persoana(){
    id = 0;
    nume = "";
    cnp = "";
    numar--;
}
persoana::persoana(persoana& p){
    numar++;
    this->id = p.id;
    this->nume = p.nume;
    this->cnp = p.cnp;
}

void persoana::set(int id = 0, string nume = "", string cnp = ""){
    numar++;
    this->id = id;
    this->nume = nume;
    this->cnp = cnp;
}
void persoana::set(const persoana& p){
    numar++;
    this->id = p.id;
    this->nume = p.nume;
    this->cnp = p.cnp;
}

void persoana::citire(istream& in){
    cout << "Id persoana: ";
    in >> id;
    cout << "Nume persoana: ";
    in >> nume;
    cout << "Cnp persoana: ";
    in >> cnp;
}

istream& operator>>(istream& in, persoana& p){
    p.citire(in);
    return in;
}

void persoana::afisare(ostream& out){
    out << "Id: " << id << "\t\tNume: " << nume << "\t\tCnp: "<< cnp<<"\t\t";
}
ostream& operator<<(ostream& out, persoana& p){
    p.afisare(out);
    return out;
}
void persoana::operator=(const persoana& p){
    this->id = p.id;
    this->nume = p.nume;
    this->cnp = p.cnp;
}


//////////////////////////////////////////////////////abonament
class abonament{
protected:
    string nume_abonament;
    float pret;
    int perioada;
public:
    abonament(string, float, int);
    abonament(abonament&);
    ~abonament();

    void set(string, float, int);
    void set(const abonament&);

    virtual void citire(istream& in);
    friend istream& operator>>(istream& in, abonament& p);
    virtual void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, abonament& p);
    void operator=(const abonament&);
    int setat(){
        if(nume_abonament == "" && pret == 0)
            return 0;
        return 1;
    }
    virtual float venit(int);
};

abonament::abonament(string nume_abonament = "", float pret = 0, int perioada = 0){
    this->nume_abonament = nume_abonament;
    this->pret = pret;
    this->perioada = perioada;
}
abonament::abonament(abonament& p){
    this->nume_abonament = p.nume_abonament;
    this->pret = p.pret;
    this->perioada = p.perioada;
}
abonament::~abonament(){
    nume_abonament = "";
    pret = 0;
    perioada = 0;
}

void abonament::set(string nume_abonament, float pret, int perioada){
    this->nume_abonament = nume_abonament;
    this->pret = pret;
    this->perioada = perioada;
}
void abonament::set(const abonament& p){
    this->nume_abonament = p.nume_abonament;
    this->pret = p.pret;
    this->perioada = p.perioada;
}

void abonament::citire(istream& in){
    cout<< "Nume abonament: ";
    in >> nume_abonament;
    cout<< "Pret abonament: ";
    in >> pret;
    cout<< "Perioada(luni): ";
    in >> perioada;
}
istream& operator>>(istream& in, abonament& p){
    p.citire(in);
    return in;
}
void abonament::afisare(ostream& out){
    cout<< "Nume abonament: " << nume_abonament << "\tPret abonament: " << pret << "\tPerioada(luni): "<< perioada << "\t";
}
ostream& operator<<(ostream& out, abonament& p){
    p.afisare(out);
    return out;
}
void abonament::operator=(const abonament& p){
    this->nume_abonament = p.nume_abonament;
    this->pret = p.pret;
    this->perioada = p.perioada;
}
float abonament::venit(int perioada){
    if (this->perioada < perioada)
        perioada = this->perioada;  //nu putem calcula profitul pe o perioada mai lunga decat perioada abonamentului
    return perioada * pret;
}

//////////////////////////////////////////////////////////abonament_premium
class abonament_premium:public abonament{
    int reducere;
public:
    abonament_premium(string, float, int, int);
    ~abonament_premium();

    void set(string, float, int, int);
    void set(const abonament_premium&);

    void citire(istream& in);
    void afisare(ostream& out);
    friend istream& operator>>(istream& in, abonament_premium& p);
    friend ostream& operator<<(ostream& out, abonament_premium& p);

    void operator=(const abonament_premium& p);
    float venit(int);
};

abonament_premium::abonament_premium(string nume_abonament = "", float pret = 0, int perioada = 0, int reducere = 0):abonament(nume_abonament, pret, perioada){
    this->reducere = reducere;
}

abonament_premium::~abonament_premium(){
    reducere = 0;
}
void abonament_premium::set(string nume_abonament, float pret, int perioada, int reducere = 0){
    abonament::set(nume_abonament, pret, perioada);
    this->reducere = reducere;
}
void abonament_premium::set(const abonament_premium& p){
    abonament::set(p);
    this->reducere = p.reducere;
}

void abonament_premium::citire(istream& in){
    abonament::citire(in);
    cout << "Reducere: " << "\n";
    in >> reducere;
}
istream& operator>>(istream& in, abonament_premium& p){
    p.citire(in);
    return in;
}
void abonament_premium::afisare(ostream& out){
    abonament::afisare(out);
    out << "Reducere: " << reducere << "\n";
}
ostream& operator<<(ostream& out, abonament_premium& p){
    p.afisare(out);
    return out;
}
void abonament_premium::operator=(const abonament_premium& p){
    abonament::set(p);
    this->reducere = p.reducere;
}
float abonament_premium::venit(int perioada){
    if (this->perioada < perioada)
        perioada = this->perioada;  //nu putem calcula profitul pe o perioada mai lunga decat perioada abonamentului
    return perioada * (pret - (reducere*pret/100));
}

/////////////////////////////////////////////abonat
class abonat:public persoana{
    string nr_telefon;
    bool ok;
    abonament_premium *ab;
public:
    abonat(int, string, string, string, string, float, int, int);
    ~abonat();
    abonat(abonat&);
    void set(int, string, string, string, string, float, int, int);
    void set(abonat&);

    void citire(istream& in);
    friend istream& operator>>(istream& in, abonat& p);
    void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, abonat& p);
    void operator=(const abonat&);
    bool premium();
    float venit(int);
};

abonat::abonat(int id = 0, string nume = "", string cnp = "" ,string nr_telefon = "", string n_ab = "", float pret = 0, int perioada = 0, int reducere = 0):persoana(id, nume, cnp){
    ok = false;
    this->nr_telefon = nr_telefon;
    if(n_ab == "" && pret == 0){}  //ca sa nu se decida daca este abonament simplu sau premium
    else
    if(reducere == 0){      //daca se dau ca parametrii numele, pretul si perioada dar nu se da reducere inseamna ca este ab simplu
        ok = true;
        ab = (abonament_premium*) new abonament;
        (*ab).set(n_ab, pret, perioada);
    }
    else{                      //daca sa da si reducere inseamna ca este abonament premium
        ok = true;
        ab = new abonament_premium;
        abonament_premium temp(n_ab, pret, perioada, reducere);
        (*ab) = temp;
        //ab[0].set(n_ab, pret, perioada, reducere);
    }
}
abonat::~abonat(){
    nr_telefon = "";
    //if(ok)
      //  delete[] ab;
}
abonat::abonat(abonat& p){
    ok = false;
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
    if(ok)
        delete[] ab;
    if(strcmp(typeid(p.ab[0]).name(), "9abonament") == 0){
        ab = (abonament_premium*) new abonament;
        ok = true;
        (*ab).set(p.ab[0]);
    }
    else
    if(strcmp(typeid(p.ab[0]).name(), "17abonament_premium") == 0){
        ab = new abonament_premium;
        ok = true;
        ab[0].set(p.ab[0]);
    }
}

void abonat::set(int id, string nume, string cnp, string nr_telefon, string n_ab = "", float pret = 0, int perioada = 0, int reducere = 0){
    persoana::set(id, nume, cnp);
    this->nr_telefon = nr_telefon;
    if(ok){
        delete[] ab;
    }
    if(n_ab == "" && pret == 0){
        ok = true;
        ab = (abonament_premium*)new abonament;
    }
    else
    if(reducere == 0){      //daca se dau ca parametrii numele, pretul si perioada dar nu se da reducere inseamna ca este ab simplu
        ok = true;
        ab = (abonament_premium*)new abonament;
        ab[0].set(n_ab, pret, perioada);
    }
    else{                      //daca sa da si reducere inseamna ca este abonament premium
        ok = true;
        ab = new abonament_premium;
        abonament_premium temp(n_ab, pret, perioada, reducere);
        ab[0] = temp;
        //ab[0].set(n_ab, pret, perioada, reducere);
    }
}

void abonat::set(abonat& p){
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
    if(ok)
        delete[] ab;
    if(strcmp(typeid(p.ab[0]).name(), "9abonament") == 0){
        ab = (abonament_premium*)new abonament;
        ok = true;
        ab[0].set(p.ab[0]);
    }
    else
    if(strcmp(typeid(p.ab[0]).name(), "17abonament_premium") == 0){
        ab = new abonament_premium;
        ok = true;
        ab[0].set(p.ab[0]);
    }
}

void abonat::citire(istream& in){
    persoana::citire(in);
    cout << "Numarul de telefon al abonatului: ";
    in >> nr_telefon;
    if(ok)
        delete[] ab;
    cout << "\nAbonat premium? 1/0\t ";
    bool pr;
    in >> pr;
    if(pr){
        ab = new abonament_premium;
        ok = true;
    }
    else{
        ab = (abonament_premium*)new abonament;
        ok = true;}
    in >> (*ab);
}
istream& operator>>(istream& in, abonat& p){
    p.citire(in);
    return in;
}

void abonat::afisare(ostream& out){
    persoana::afisare(out);
    cout << "Numar telefon: " << nr_telefon << "\t\t";
    if(ok)
        cout << ab[0];
}

ostream& operator<<(ostream& out, abonat& p){
    p.afisare(out);
    return out;
}
void abonat::operator=(const abonat& p){
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
    if(ok)
        delete[] ab;
    if(strcmp(typeid(p.ab[0]).name(), "9abonament") == 0){
        ab = (abonament_premium*)new abonament;
        ok = true;
        ab[0].set(p.ab[0]);
    }
    else
    if(strcmp(typeid(p.ab[0]).name(), "17abonament_premium") == 0){
        ab = new abonament_premium;
        ok = true;
        ab[0].set(p.ab[0]);
    }
}
bool abonat::premium(){
    if(strcmp(typeid((*ab)).name(), "17abonament_premium") == 0)
        return 1;
    return 0;
}
float abonat::venit(int perioada){
    return (*ab).venit(perioada);
}

/////////////////////////////////////////////////////////////////clienti
class clienti{
    int nr_clienti;
    abonat *pers;
public:
    clienti();
    ~clienti();

    void citire(istream&);
    void afisare(ostream&);
    friend istream& operator>>(istream& in, clienti& p);
    friend ostream& operator<<(ostream& out, clienti& p);

    //void ad(abonat&);   //adauga un abonat
    int ab_premium();
    float venit(int);
};
//int clienti::nr_clienti;
clienti::clienti(){
    nr_clienti = 0;
}
clienti::~clienti(){
    if(nr_clienti > 0)
        delete[] pers;
    nr_clienti = 0;
}

void clienti::citire(istream& in){
    if (nr_clienti > 0){
        abonat *temp = new abonat[nr_clienti];
        for(int i=0; i<nr_clienti; i++)
            temp[i] = pers[i];

        nr_clienti ++;
        delete[] pers;
        pers = new abonat[nr_clienti];
        for(int i = 0; i < nr_clienti - 1; i++)
            pers[i] = temp[i];
        in >> pers[nr_clienti-1];
    }
    else{
        nr_clienti++;
        pers = new abonat[nr_clienti];
        in >> pers[nr_clienti-1];
    }
}

istream& operator>>(istream& in, clienti& p){
    p.citire(in);
    return in;
}

void clienti::afisare(ostream& out){
    if(nr_clienti>0)
        for(int i = 0; i < nr_clienti; i++)
            out << pers[i] << "\n\n";
}

ostream& operator<<(ostream& out, clienti& p){
    p.afisare(out);
    return out;
}

int clienti::ab_premium(){
    int temp = 0;
    if(nr_clienti > 0)
        for(int i = 0; i < nr_clienti; i++){
            if(pers[i].premium())
                temp++;
        }
    return temp;
}

float clienti::venit(int perioada = 0){
    float temp = 0;
    for(int i = 0; i < nr_clienti; i++){
        temp += pers[i].venit(perioada);
    }
    return temp;
}

int main()
{

    clienti a;

    cin >> a;
    cin>>a;
    cout << a;
    cout<<"\n";
    cout<<a.ab_premium()<<endl;
    cout<< a.venit(12);

    return 0;
}
