#include <bits/stdc++.h>
#include <memory>
using namespace std;

class IDCustom {
    static int id;
public:
    IDCustom() = delete;
    static int getNextId();
};

int IDCustom::id = 1;

int IDCustom::getNextId() {
    return id++;
}

class Produs {
    int pret, cantitate, id;
public:
    Produs(int p = 0, int c = 0, int i = 0);

    void setPret(int p);
    void setCantitate(int p);
    void setId(int p);
};

void Produs::setCantitate(int p) {
    cantitate = p;
};
void Produs::setPret(int p) {
    pret = p;
};
void Produs::setId(int p) {
    id = p;
};

Produs::Produs(int p, int c, int i) :
pret(p), cantitate(c), id(i) {};

//////////////////////////////////////

class Carte : public Produs {
    string titlu, editura;
    vector<string> autori;
public:
    Carte();
    Carte(string t, string e,vector<string> a, int p, int c, int i);
    friend istream& operator>>(istream& os, Carte& obj);

    void setTitlu(string t);
    void setEditura(string t);
    void setAutori(vector<string> t);
};

void Carte::setAutori(vector<string> t) {
    autori = t;
}
void Carte::setTitlu(string t) {
    titlu = t;
};
void Carte::setEditura(string t) {
    editura = t;
};

istream& operator>>(istream& os, Carte& obj) {
    string t, e;
    int n, p, c;
    vector<string> a;
    cout << "Titlu: ";getline(os, t);
    cout << "Pret: ";os >> p;
    cout << "Cantitate: ";os >> c;
    cout << "Editura: ";os >> e;
    cout << "Numar autori: ";os >> n;
    cout << "Autorii(ENTER dupa fiecare):\n";
    while(n--) {
        os >> e;
        a.push_back(e);
    }

    obj.setTitlu(t);
    obj.setEditura(e);
    obj.setAutori(a);
    obj.setPret(p);
    obj.setCantitate(c);
    obj.setId(IDCustom::getNextId());

    return os;
}

Carte::Carte() {
    titlu = "";
    editura = "";
    autori = vector<string>();
}

Carte::Carte(string t, string e, vector<string> a, int p, int c, int i) :  Produs(p, c, i), titlu(t), editura(e), autori(a.size()) {
    autori = a;
};

//////////////////////////////////////

class DVD : public Produs {
    int minute;
public:
    DVD(int m = 0);
};

DVD::DVD(int m) : minute(m) {};

//////////////////////////////////////

class DVDdeMuzica : public DVD {
    string numeAlbum;
    vector<string> interpreti;
public:
    DVDdeMuzica(string n, const vector<string> i, int m);
};

DVDdeMuzica::DVDdeMuzica(string n, const vector<string> i, int m) : DVD(m), numeAlbum(n), interpreti(i.size()) {
    interpreti = i;
};

//////////////////////////////////////

class DVDdeFilme : public DVD {
    string numeFilm, gen;
public:
    DVDdeFilme(string n = "", string g = "");
};

DVDdeFilme::DVDdeFilme(string n, string g) : numeFilm(n), gen(g) {};

//////////////////////////////////////

class ObiectDeColectie : public Produs {
    string denumire;
public:
    ObiectDeColectie(string d = "");
};

ObiectDeColectie::ObiectDeColectie(string d) : denumire(d) {};

//////////////////////////////////////

class ObiectDeColectieFigurina : public Produs {
    string categorieColectie, brand, material;
public:
    ObiectDeColectieFigurina(string c = "", string b = "", string m = "");
};

ObiectDeColectieFigurina::ObiectDeColectieFigurina(string c, string b, string m) : 
categorieColectie(c), brand(b), material(m) {};

//////////////////////////////////////

class ObiectDeColectiePoster : public Produs {
    string format;
public:
    ObiectDeColectiePoster(string f = "");
};

ObiectDeColectiePoster::ObiectDeColectiePoster(string f) : format(f) {};

//////////////////////////////////////


int main() {
    vector< Produs* > catalog;
    int n;
    string produs;

    cout << "Cate produse primim astazi? ";cin >> n;
    cout << "\n\n";

    while(n--) {
        cout << "Ce produs citim? (carte, dvd-muzica, dvd-film, figurina, poster)\n";
        cin >> produs;
        cin.get();

        if(produs.compare("carte") == 0) {
            Produs* c = new Carte();
            cin >> *(Carte*)c;
            catalog.push_back(c);
        }
    }

    return 0;
}