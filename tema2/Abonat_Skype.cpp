#include "Abonat_Skype.h"
#include <string>
#include <iostream>

int Abonat_Skype::nr_abonati = 0;   //initializarea variabile statice

Abonat_Skype::Abonat_Skype() {
    id_skype = "-1";
    nr_abonati++;
}

Abonat_Skype::Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat(nr_telefon_, id_, nume_) {
    id_skype = id_skype_;
    nr_abonati++;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    id_skype = ab.id_skype;
}

int Abonat_Skype::getNrAbonati() {
    return nr_abonati;
}

std::string Abonat_Skype::getIdSkype() const {
    return id_skype;
}

void Abonat_Skype::setIdSkype(std::string idSkype_) {
    id_skype = idSkype_;
}

void Abonat_Skype::showAbonat() {
    std::cout << "skype\n";
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype* abS_) {

    Abonat* ptr = abS_;
    os << ptr;
    os << " Id_Skype: " << abS_->id_skype << '\n';

    return os;
}

Abonat_Skype Abonat_Skype::operator=(Abonat_Skype& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    id_skype = ab.id_skype;
}


///////////////////////////////////////////////////////////////////////////////////////////


    const char* MyException::what() {
        return "Email invalid!";
    }


Abonat_Skype_Romania::Abonat_Skype_Romania() {
    adresa_mail = "no mail";
}

Abonat_Skype_Romania::Abonat_Skype_Romania(std::string adresa_mail_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {

    adresa_mail = adresa_mail_;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    setIdSkype( ab.getIdSkype() );
    setEmail( ab.getEmail() );
}

std::string Abonat_Skype_Romania::getEmail() const {
    return adresa_mail;
}

void Abonat_Skype_Romania::setEmail(std::string email_) {
    adresa_mail = email_;
}

void Abonat_Skype_Romania::showAbonat()  {
    std::cout << "romania\n";
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype_Romania& abS_) {

    Abonat_Skype* ptr = &abS_;
    os << ptr;
    os << " Email: " << abS_.adresa_mail << '\n';

    return os;
}

std::istream& operator>>(std::istream& os, Abonat_Skype_Romania& abS_) {
    std::string n, t, m, is;
    int i;
    std::cout << " Nume: "; os >> n;
    std::cout << " Id:   "; os >> i;
    std::cout << " Telefon:   "; os >> t;
    std::cout << " Id Skype: "; os >> is;
    std::cout << " Email:   "; os >> m;

    bool ok = 0;
    for( int i = 0; i < m.length(); i++ )
        if( m[i] == '@' ) {
            ok = 1;
            break;
        }

    if( !ok ) {
        throw MyException();
    }

    abS_.setName(n);
    abS_.setId(i);
    abS_.setPhoneNumber(t);
    abS_.setIdSkype(is);
    abS_.setEmail(m);

    return os;
}

Abonat_Skype_Romania Abonat_Skype_Romania::operator=(Abonat_Skype_Romania& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    setIdSkype( ab.getIdSkype() );
    setEmail( ab.getEmail() );
}

///////////////////////////////////////////////////////////////////////////////////////////

Abonat_Skype_Extern::Abonat_Skype_Extern() {
    tara = "no country";
}

Abonat_Skype_Extern::Abonat_Skype_Extern(std::string tara_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {
    tara = tara_;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    setIdSkype( ab.getIdSkype() );
    setCountry( ab.getCountry() );
}

std::string Abonat_Skype_Extern::getCountry() const {
    return tara;
}

void Abonat_Skype_Extern::setCountry(std::string tara_) {
    tara = tara_;
}

void Abonat_Skype_Extern::showAbonat()  {
    std::cout << "extern\n";
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype_Extern& abS_) {

    Abonat_Skype* ptr = &abS_;
    os << ptr;
    os << " Tara: " << abS_.tara << '\n';

    return os;
}

std::istream& operator>>(std::istream& os, Abonat_Skype_Extern& abS_) {
    std::string n, t, tr, is;
    int i;
    std::cout << " Nume: "; os >> n;
    std::cout << " Id:   "; os >> i;
    std::cout << " Telefon:   "; os >> t;
    std::cout << " Id Skype: "; os >> is;
    std::cout << " Tara:   "; os >> tr;

    abS_.setName(n);
    abS_.setId(i);
    abS_.setPhoneNumber(t);
    abS_.setIdSkype(is);
    abS_.setCountry(tr);

    return os;
}

Abonat_Skype_Extern Abonat_Skype_Extern::operator=(Abonat_Skype_Extern& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    setIdSkype( ab.getIdSkype() );
    setCountry( ab.getCountry() );
}