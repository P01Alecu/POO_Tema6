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

    static void nr_pers(){
        cout << numar;
    }
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
    numar++;
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
    static int nr_p;
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
    static void numar_ab(){
        cout << nr_p;}
};
int abonat::nr_p;
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
    clienti(int, string, string, string, string, float, int, int);
    clienti(clienti&);
    ~clienti();
    void ad(abonat&);

    void citire(istream&);
    void afisare(ostream&);
    friend istream& operator>>(istream& in, clienti& p);
    friend ostream& operator<<(ostream& out, clienti& p);
    void operator=(const clienti&);
    int ab_premium();
    float venit(int);
};

clienti::clienti(int id = 0, string nume = "", string cnp = "" ,string nr_telefon = "", string n_ab = "", float pret = 0, int perioada = 0, int reducere = 0 ){
    if(id == 0)
        nr_clienti = 0;
    else{
        nr_clienti = 1;
        pers = new abonat[nr_clienti];
        pers[nr_clienti-1].set(id, nume, cnp, nr_telefon, n_ab, pret, perioada, reducere);
    }
}
clienti::clienti(clienti& p){
    if(p.nr_clienti > 0){
        nr_clienti = p.nr_clienti;
        pers = new abonat[p.nr_clienti];
        for(int i = 0; i < p.nr_clienti; i++){
            pers[i] = p.pers[i];
        }
    }
}
void clienti::operator=(const clienti& p){
    if(p.nr_clienti > 0){
        if(nr_clienti > 0 )
            delete[] pers;
        nr_clienti = p.nr_clienti;
        pers = new abonat[p.nr_clienti];
        for(int i =0 ; i < p.nr_clienti; i++)
            pers[i] = p.pers[i];
    }
}

clienti::~clienti(){
    if(nr_clienti > 0)
        delete[] pers;
    nr_clienti = 0;
}
void clienti::ad(abonat& p){
    if (nr_clienti > 0){
        abonat *temp = new abonat[nr_clienti];
        for(int i=0; i<nr_clienti; i++)
            temp[i] = pers[i];

        nr_clienti ++;
        delete[] pers;
        pers = new abonat[nr_clienti];
        for(int i = 0; i < nr_clienti - 1; i++)
            pers[i] = temp[i];
        pers[nr_clienti-1] = p;
        delete[] temp;
    }
    else{
        nr_clienti++;
        pers = new abonat[nr_clienti];
        pers[nr_clienti-1] = p;
    }
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
        delete[] temp;
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

/////////////////////////// meniu interactiv
void menu_output()
{
	cout << "\n Alecu Florin Gabriel - Grupa 211 - 6 \n";
	cout << "\n\t MENIU:";
	cout << "\n===========================================\n";
	cout << "\n";
	cout << "1. Adauga clienti.\n";
	cout << "2. Afisaza clientii.\n";
	cout << "3. Vezi cati clienti au abonament premium.\n";
	cout << "4. Vezi venitul pe o perioada de timp.\n";
	cout << "5. Vezi de cate ori s-a creat o persoana.\n";
    cout << "6. Citeste si afisaza un abonat.(exemplificare upcast)\n";
	cout << "0. Iesire.\n";
}

void menu()
{
	int option;///optiunea aleasa din meniu
	option = 0;

	clienti a;
	do
	{
		menu_output();

		cout << "\nIntroduceti numarul actiunii: ";
		cin >> option;

		if (option == 1)
		{
            int n;
            cout<< "Cati clienti vrei sa citesti? ";
            cin >> n;
            cout<<"\n";
            if(n>0){
                for(int i = 0; i < n; i++)
                    cin >> a;
            }
		}
        if (option == 2){
            cout << a;
        }
        if (option == 3){
            cout << a.ab_premium() << " au abonamente premium.\n";
        }
        if (option == 4){
            int n;
            cout << "Pe ce perioada de timp (in luni) doresti sa fie calculat venitul? ";
            cin >> n;
            cout << "Venitul de pe " << n << " luni este: " << a.venit(n);
        }
        if (option == 5){
            cout << "Au fost create ";
        persoana::nr_pers();
        cout << " persoane. (in clasa clienti au fost folosite 'persoane' auxiliare pentru citire, si de aceea numarul acesta va fi mai mare decat numarul efectiv de persoane memorate)\n";
        }
        if (option == 6){
            persoana *p = new abonat;
            cin >> *p;
            cout << *p;
        }
		if (option == 0)
		{
			cout << "\nEXIT!\n";
		}
		if (option < 0 || option>6)
		{
			cout << "\nSelectie invalida\n";
		}
		cout << "\n";
		system("pause"); ///Pauza - Press any key to continue...
		system("cls");   ///Sterge continutul curent al consolei
	} while (option != 0);
}
int main()
{
    menu();
    return 0;
}
