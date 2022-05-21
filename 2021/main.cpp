#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct date {
    int zi, luna, an;
};

class IdSmecher {
    static int id;
public:
    IdSmecher() = delete;

    static int getId() {
        return id++;
    }
};

int IdSmecher::id = 0;

class Virus {
    float rating;
    date data;
    string nume, metodaInfectare;
    vector<string> registrii;
public:
    Virus() {
        metodaInfectare = "unknown";
    }
    Virus(float r, int zi, int luna, int an, string n, string m, vector<string> rg);

    virtual void citire(istream& is) {
        int n;
        string reg;
        cout << "Rating: ";is >> rating;
        cout << "zi: ";is >> data.zi;
        cout << "luna: ";is >> data.luna;
        cout << "an: ";is >> data.an;
        cout << "numa: ";is >> nume;
        cout << "metoda infectare: ";is >> metodaInfectare;
        cout << "cati reg afectati: ";is >> n;
        while(n--) {
            cout << "Registru: ";is >> reg;
            registrii.push_back(reg);
        }
    }

    virtual void afisare(ostream& os) {
            os << "Rating:" << rating << '\n';
            os << "Zi:" << data.zi << '\n';
            os << "Luna:" << data.luna << '\n';
            os << "An:" << data.an << '\n';
            os << "nume:" << nume << '\n';
            os << "metoda:" << metodaInfectare << '\n';
            for(int i = 0; i < registrii.size(); i++) {
                os << "Reg" << registrii[i] << '\n';
            }
        }

    friend istream& operator>>(istream& is, Virus& v) {
        v.citire(is);
        return is;
    }

    friend ostream& operator<<(ostream& os, Virus& v) {
        v.afisare(os);
        return os;
    }

    ~Virus() = default;
};
Virus::Virus(float r, int zi, int luna, int an, string n, string m, vector<string> rg) 
: rating(r), nume(n), metodaInfectare(m) {
    data.zi = zi;
    data.luna = luna;
    data.an = an;
    registrii = rg;
}

class Rootkit : public Virus {
    vector<string> importuri;
    vector<string> stringuri;
public:
    Rootkit() : Virus() {
        importuri = vector<string>();
        stringuri = vector<string>();
    } 
    Rootkit(float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b);
    void citire(istream& is) override {
        int n;
        string reg;
        
        cout << "cate impoerturi: ";is >> n;
        while(n--) {
            cout << "Import: ";is >> reg;
            importuri.push_back(reg);
        }
        cout << "cate stringuri: ";is >> n;
        while(n--) {
            cout << "string: ";is >> reg;
            stringuri.push_back(reg);
        }
    }

    void afisare(ostream& os) override {
        for(int i = 0; i < importuri.size(); i++) {
                os << "Import" << importuri[i] << '\n';
            }
        for(int i = 0; i < stringuri.size(); i++) {
                os << "String" << stringuri[i] << '\n';
            }
    }
    ~Rootkit() = default;
};
Rootkit::Rootkit(float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b) 
: Virus(r, zi, luna, an, n, m, rg) {
    importuri = a;
    stringuri = b;
}

class Keylogger : public Virus {
    vector<string> functii;
    vector<string> taste;
public:
    Keylogger();
    Keylogger(float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b);
    
    void citire(istream& is) ;
    void afisare(ostream& os) ;
    
    ~Keylogger() = default;
};
Keylogger::Keylogger(float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b) 
: Virus(r, zi, luna, an, n, m, rg) {
    functii = a;
    taste = b;
}

void Keylogger::citire(istream& is) {
        int n;
        string reg;
        
        cout << "cate functii: ";is >> n;
        while(n--) {
            cout << "functie: ";is >> reg;
            functii.push_back(reg);
        }
        cout << "cate taste: ";is >> n;
        while(n--) {
            cout << "tasta: ";is >> reg;
            taste.push_back(reg);
        }
}

void Keylogger::afisare(ostream& os) {
        for(int i = 0; i < functii.size(); i++) {
                os << "functie" << functii[i] << '\n';
            }
        for(int i = 0; i < taste.size(); i++) {
                os << "tasta" << taste[i] << '\n';
}
}

class KernelKeyLogger : public Keylogger {
    bool ascunde;
public:     
    KernelKeyLogger();
    KernelKeyLogger(bool as, float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b);
    void citire(istream& is);
    void afisare(ostream& os);
    ~KernelKeyLogger() = default;
};
KernelKeyLogger::KernelKeyLogger(bool as, float r, int zi, int luna, int an, string n, string m, vector<string> rg,vector<string> a, vector<string> b) 
: Keylogger(r, zi, luna, an, n, m, rg, a, b), ascunde(as) {}

void KernelKeyLogger::citire(istream& is) {
    string sir;
    cout << "Ascunde ?";cin >> sir;
    if(sir.compare("da") == 0) ascunde = 1;
    else ascunde = 0;
}

void KernelKeyLogger::afisare(ostream& os) {
        if(ascunde) {
            os << "Ascunde" << '\n';
        } else {
            os << "Nu ascunde" << '\n';
        }
}


class Ransomware : public Virus{
    int ratingCripare;
    float  obf;
public:
    Ransomware();
    Ransomware(float r, int zi, int luna, int an, string n, string m, vector<string> rg,int a, float b);
    void citire(istream& is) override;
    void afisare(ostream& os) override;
    ~Ransomware() = default;     
};

Ransomware::Ransomware(float r, int zi, int luna, int an, string n, string m, vector<string> rg,int a, float b)
: Virus(r, zi,  luna,  an,  n,  m,  rg), ratingCripare(a), obf(b) {}

class Computer {
    int id;
    vector<Virus> v;
    float rating;
public:
    Computer() {
        id = 0;
        v = vector<Virus>();
        rating = 0;
    }
    Computer(int i, vector<Virus> w, float r);
    ~Computer() = default;

    void setId(int i);

    friend istream& operator>>(istream& is, Computer& c);
    friend ostream& operator<<(ostream& os, Computer& c);
};
Computer::Computer(int i, vector<Virus> w, float r) : id(i), rating(r) {
    v = w;
}
void Computer::setId(int i) {
    id = i;
}

ostream& operator<<(ostream& os, Computer& c) {
        os << "Id: " << c.id << '\n';
        os << "Rating: " << c.rating << '\n';
        for(int i = 0; i < c.v.size(); i++) {
                os << "Virus " << c.v[i] << '\n';
        }
        return os;
}

istream& operator>>(istream& is, Computer& c) {
        int n;
        string sir;
        cout << "Cati virusi are? ";is >> n;
        while(n--) {
            cout << "Ce tip de virus? ";
            cin >> sir;
            if(sir.compare("rootkit") == 0) {
                Rootkit p;
                is >> p;
                c.v.push_back(p);
            }
        }
        return is;
}


int main() {
    vector<Computer> c;
    int n;
    cout << "Cate computere: ";cin >> n;
    while(n--) {
        Computer cmp;
        cin >> cmp;
        cmp.setId(IdSmecher::getId());
        c.push_back(cmp);
    }
    cout << "\n\n";
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << '\n';
    }

    return 0;
}