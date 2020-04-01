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
    void set(persoana&);
    virtual void citire(istream& in);
    friend istream& operator>>(istream& in, persoana& p);
    virtual void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, persoana& p);

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
void persoana::set(persoana& p){
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
};

abonat::abonat(int id = 0, string nume = "", string cnp = "" ,string nr_telefon = ""):persoana(id, nume, cnp){
    this->nr_telefon = nr_telefon;
}
abonat::~abonat(){
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

//////////////////////////////////////////////////////abonament
class abonament{
    string nume_abonament;
    float pret;
    int perioada;
public:
    abonament(string, float, int);
    abonament(abonament&);
    ~abonament();

    void set(string, float, int);
    void set(abonament&);

    void citire(istream& in);
    friend istream& operator>>(istream& in, abonament& p);
    void afisare(ostream& out);
    friend ostream& operator<<(ostream& out, abonament& p);
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
void abonament::set(abonament& p){
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
    cout<< "Nume abonament: " << nume_abonament << "\tPret abonament: " << pret << "\tPerioada(luni): "<< perioada << "\n";
}
ostream& operator<<(ostream& out, abonament& p){
    p.afisare(out);
    return out;
}

int main()
{
    abonat ab;
    return 0;
}
