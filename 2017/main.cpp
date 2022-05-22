#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <memory>
#include <exception>
#include <algorithm>
using namespace std;

struct date {
    int zi, luna, an;
};

class Stream {
public:
    virtual void afisare(ostream& os) = 0;
    virtual void citire(istream& is) = 0;
};


class MyException : public exception {
public:
    MyException() = default;

    char* what() {
        return "Input invalid!!";
    }
};

class Persoana : public Stream {
    string nume, cnp;
public:
    Persoana();
    Persoana(string n, string c);

     void citire(istream& is) {
        is.get();
        cout << "Nume: ";getline(is, nume);
        cout << "CNP: ";is >> cnp;
        if(cnp.length() != 13) {
            cnp = "";
            nume = "";
            throw MyException();
        }
    }
    friend istream& operator>>(istream& is, Persoana& p);

     void afisare(ostream& os);
    friend ostream& operator<<(ostream& os, Persoana& p);

    const int getYear() const {
        return cnp[1] - '0';
    }

    const string getName() const;
    void setName(string n);

    virtual ~Persoana() = default;
};
Persoana::Persoana(string n, string c) : nume(n), cnp(c) {}
Persoana::Persoana() {
    nume = "necunoscut";
    cnp = "necunoscut";
}
istream& operator>>(istream& is, Persoana& p) {
    p.citire(is);
    return is;
}
const string Persoana::getName() const {
    return nume;
}
void Persoana::setName(string n) {
    nume = n;
}
void Persoana::afisare(ostream& os) {
    os << "Nume: " << nume << " ";
    os << "CNP: " << cnp << '\n';
}
ostream& operator<<(ostream& os, Persoana& p) {
    p.afisare(os);
    return os;
}


class Activitate {
protected:
    string denumire;
    date data;
    vector< shared_ptr<Persoana> > participanti;
public:
    Activitate();
    Activitate(string d, int z, int l, int a, vector< shared_ptr<Persoana> > v);
    Activitate(string s);

    virtual void add(shared_ptr<Persoana>) = 0;
    void setDate(int z, int l, int a);

    void sort();
    virtual void afisare(ostream& os) const;
    friend ostream& operator<<(ostream& os, Activitate& a);

    virtual ~Activitate() = default;
};
Activitate::Activitate() {
    denumire = "necunoscuta";
    data.zi = data.luna = data.an = 0;
    participanti = vector< shared_ptr<Persoana> >();
}
Activitate::Activitate(string s) : denumire(s){}
Activitate::Activitate(string d, int z, int l, int a, vector< shared_ptr<Persoana> > v)
: denumire(d) {
    participanti = v;
    data.zi = z;
    data.luna = l;
    data.an = a;
}
void Activitate::sort() {
    for(int i = 0; i < participanti.size() - 1; i++)
        for(int j = i + 1; j < participanti.size(); j++) {
            if( participanti[i]->getName().compare(participanti[j]->getName()) > 0 ) {
                string aux = participanti[i]->getName();
                participanti[i]->setName( participanti[j]->getName() );
                participanti[j]->setName( aux );
            }
        }    
}
void Activitate::afisare(ostream& os) const {
    os << "~" << denumire << "~\n";
    for(int i = 0; i < participanti.size(); i++)
        os << *participanti[i] << " ";
}
ostream& operator<<(ostream& os, Activitate& a) {
    a.afisare(os);
    return os;
}
void Activitate::setDate(int z, int l, int a) {
    data.zi = z;
    data.luna = l;
    data.an = a;
}


class Curs : public Activitate {
    int credite;
public:
    Curs();
    Curs(string d);
    Curs(int c, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v);
    void add(shared_ptr<Persoana> p); 
    ~Curs() = default;
};
Curs::Curs() : Activitate() {
    credite = 0;
}
Curs::Curs(string d) : Activitate(d){}
Curs::Curs(int c, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v)
: Activitate(d, z, l, a, v), credite(c) {

}
void Curs::add(shared_ptr<Persoana> p) {
    if(p->getYear() > 2)
        this->participanti.push_back(p);
    else cout << "Nu este profesor\n";
}

class Concurs : public Activitate {
    vector< shared_ptr<Persoana> > premianti;
public:
    Concurs();
    Concurs(string d);
    Concurs(vector< shared_ptr<Persoana> > p, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v);

    void add(shared_ptr<Persoana> p) {

    };

    ~Concurs() = default;
};
Concurs::Concurs() : Activitate() {
    premianti = vector< shared_ptr<Persoana> >();
}
Concurs::Concurs(string d) : Activitate(d){}
Concurs::Concurs(vector< shared_ptr<Persoana> > p, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v)
: Activitate(d, z, l, a, v) {
    premianti = p;
}

class ConcursOnLine : public Concurs {
    string site;
public:
    ConcursOnLine();
    ConcursOnLine(string d);
    ConcursOnLine(string s, vector< shared_ptr<Persoana> > p, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v);

    ~ConcursOnLine() = default;
};
ConcursOnLine::ConcursOnLine() : Concurs() {
    site = "necunoscut";
}
ConcursOnLine::ConcursOnLine(string d): Concurs(d) {}
ConcursOnLine::ConcursOnLine(string s, vector< shared_ptr<Persoana> > p, string d, int z, int l, int a, vector< shared_ptr<Persoana> > v)
: Concurs(p, d, z, l, a, v), site(s) {}

int main() {    
    int n;
    cout << "Cati participanti? ";cin >> n;
    string sir;
    cout << "Ce activitate? ";cin >> sir;

    shared_ptr<Concurs> concurs = make_shared<Concurs>("Concurs");
    shared_ptr<Curs> curs = make_shared<Curs>("Curs");
    shared_ptr<ConcursOnLine> concursOnline = make_shared<ConcursOnLine>("Concurs Online");

    while(n--) {
        shared_ptr<Persoana> pers = make_shared<Persoana>();
        try {
            cin >> *pers;

            if(sir.compare("curs") == 0) {
                curs->add(pers);
            }
        }catch(MyException& e){
            cout << e.what() << '\n';
            n++;
        };
    }

    curs->sort();
    cout << *dynamic_pointer_cast<Activitate>(curs) << '\n';
    

    return 0;
}