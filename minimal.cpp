#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IDCustom {
    static int id;
public:
    IDCustom() = delete;

    static int getId() {
        return id++;
    }
};
int IDCustom::id = 0;


class Produs {
    string denProdus;
    float pretProd;
public:
    Produs(string d = "", float p = 0);
    const string getDenProdus() const {
        return denProdus;
    }
    const float getPretProd() const {
        return pretProd;
    }
    void setDenProdus(string t) {
        denProdus = t;
    }
    void setPretProd(float t) {
        pretProd = t;
    }
    
    Produs& operator=(const Produs& p) {
        denProdus = p.getDenProdus();
        pretProd = p.getPretProd();
    }

    friend ostream& operator<<(ostream& os,const Produs& p) {
        os << p.getDenProdus() << " " << p.getPretProd() << " ";
        return os;
    }

};
Produs::Produs(string d, float p) : denProdus(d), pretProd(p) {};


class Comanda {
    Produs Prod;
    int Num, nrPortii;
    struct date {
        int zi, luna, an;
    }data;
public:
    Comanda(string s = "", int p = 0, int z = 31, int l = 5, int a = 2016) 
    : nrPortii(p) {
        Prod.setDenProdus(s);
        data.zi = z;
        data.luna = l;
        data.an = a;
        Num = IDCustom::getId();
    }

    Comanda(Comanda& c) {
        Prod = c.Prod;
        nrPortii = c.getNrPortii();
        data = c.getData();
    }

    const int getNum() const {
        return Num;
    }

    const int getNrPortii() const {
        return nrPortii;
    }
    
    const date getData() const {
        return data;
    }

    const Produs getProd() const {
        return Prod;
    }

    void del() {
        nrPortii = 0;
    }

    Comanda& operator=( Comanda& c) {
        Num = c.getNum();
        nrPortii = c.getNrPortii();
        data = c.getData();
        Prod = c.getProd();

        return *this;
    }

    Comanda& operator+(int n) {
        nrPortii += n;
        return *this;
    }

    Comanda& operator++() {
        nrPortii++;
        return *this;
    }

    Comanda& operator++(int) {
        Comanda aux = *this;
        ++*this;
        return aux;
    }

    friend istream& operator>>(istream& is, Comanda& c) {
        string t;
        cout << "Produs: ";is >> t;
        c.Prod.setDenProdus(t);
        cout << "Nr portii";is >> c.nrPortii;
        return is;
    }

    friend ostream& operator<<(ostream& os, Comanda& c) {
        os << c.getProd() << " " << c.getNrPortii() << " ";
        os << c.data.zi << "-" << c.data.luna << "-" << c.data.an << " ";
        return os;
    }
};


int main() {
    Comanda c1("frigarui", 2, 31, 5, 2016), c2("cola",3), c3("cafea",1), c4 = c2, c5; 
    

    return 0;
}