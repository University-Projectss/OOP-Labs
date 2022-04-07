#include "Abonat_Skype.h"
#include <string>
#include <iostream>

Abonat_Skype::Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat(nr_telefon_, id_, nume_) {
    id_skype = id_skype_;
}

std::string Abonat_Skype::getIdSkype() const {
    return id_skype;
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype* abS_) {

    Abonat* ptr = abS_;
    os << ptr;
    os << " Id_Skype: " << abS_->id_skype << '\n';

    return os;
}

///////////////////////////////////////////////////////////////////////////////////////////


Abonat_Skype_Romania::Abonat_Skype_Romania(std::string adresa_mail_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {
    adresa_mail = adresa_mail_;
}

std::string Abonat_Skype_Romania::getEmail() const {
    return adresa_mail;
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype_Romania& abS_) {

    Abonat_Skype* ptr = &abS_;
    os << ptr;
    os << " Email: " << abS_.adresa_mail << '\n';

    return os;
}

///////////////////////////////////////////////////////////////////////////////////////////


Abonat_Skype_Extern::Abonat_Skype_Extern(std::string tara_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {
    tara = tara_;
}

std::string Abonat_Skype_Extern::getCountry() const {
    return tara;
}

std::ostream& operator<<(std::ostream& os, Abonat_Skype_Extern& abS_) {

    Abonat_Skype* ptr = &abS_;
    os << ptr;
    os << " Tara: " << abS_.tara << '\n';

    return os;
}