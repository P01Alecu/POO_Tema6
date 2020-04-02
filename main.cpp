#include <iostream>
#include <windows.h>


using namespace std;
//////////////////////////////persoana
class persoana{
protected:
    int id;
    string nume;
    string cnp;
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

};
persoana::persoana(int id = 0, string nume = "", string cnp = ""){
    this->id = id;
    this->nume = nume;
    this->cnp = cnp;
}

persoana::~persoana(){
    id = 0;
    nume = "";
    cnp = "";
}
persoana::persoana(persoana& p){
    this->id = p.id;
    this->nume = p.nume;
    this->cnp = p.cnp;
}

void persoana::set(int id = 0, string nume = "", string cnp = ""){
    this->id = id;
    this->nume = nume;
    this->cnp = cnp;
}
void persoana::set(const persoana& p){
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

/////////////////////////////////////////////abonat
class abonat:public persoana{
    string nr_telefon;
public:
    abonat(int, string, string, string);
    ~abonat();
    abonat(abonat&);
    void set(int, string, string, string);
    void set(abonat&);

    void citire(istream& in);
    friend istream& operator>>(istream& in, abonat& p);
    void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, abonat& p);
    void operator=(const abonat&);
};

abonat::abonat(int id = 0, string nume = "", string cnp = "" ,string nr_telefon = ""):persoana(id, nume, cnp){
    this->nr_telefon = nr_telefon;
}
abonat::~abonat(){
    nr_telefon = "";
}
abonat::abonat(abonat& p){
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
}

void abonat::set(int id, string nume, string cnp, string nr_telefon){
    persoana::set(id, nume, cnp);
    this->nr_telefon = nr_telefon;
}

void abonat::set(abonat& p){
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
}

void abonat::citire(istream& in){
    persoana::citire(in);
    cout << "Numarul de telefon al abonatului: ";
    in >> nr_telefon;
}
istream& operator>>(istream& in, abonat& p){
    p.citire(in);
    return in;
}

void abonat::afisare(ostream& out){
    persoana::afisare(out);
    cout << "Numar telefon: " << nr_telefon << "\t\t";
}

ostream& operator<<(ostream& out, abonat& p){
    p.afisare(out);
    return out;
}
void abonat::operator=(const abonat& p){
    persoana::set(p);
    this->nr_telefon = p.nr_telefon;
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

    void citire(istream& in);
    friend istream& operator>>(istream& in, abonament& p);
    void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, abonament& p);
    void operator=(const abonament&);
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
};

abonament_premium::abonament_premium(string nume_abonament = "", float pret = 0, int perioada = 0, int reducere = 0):abonament(nume_abonament, pret, perioada){
    this->reducere = reducere;
}

abonament_premium::~abonament_premium(){
    reducere = 0;
}
void abonament_premium::set(string nume_abonament, float pret, int perioada, int reducere){
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

/////////////////////////////////////////////////////////////////clienti
class clienti{
    abonat* a;
    abonament* ab;
    abonament_premium* abp;
public:
    clienti(abonat&);
};




int main()
{
    persoana a;
    persoana b;
    a.set(1, "nume", "cnp");
    b=a;
    cout<<b<<endl;

    abonat a1;
    abonat b1;
    a1.set(12, "nume", "cnp", "tel");
    b1=a1;
    cout<<b1;


    return 0;
}
