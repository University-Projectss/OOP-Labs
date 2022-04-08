#include "Abonat_Skype.h"
#include <string>
#include <iostream>

Abonat_Skype::Abonat_Skype() {
    id_skype = "-1";
}

Abonat_Skype::Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat(nr_telefon_, id_, nume_) {
    id_skype = id_skype_;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    setPhoneNumber( ab.getPhoneNumber() );
    id_skype = ab.id_skype;
}

std::string Abonat_Skype::getIdSkype() const {
    return id_skype;
}

void Abonat_Skype::setIdSkype(std::string idSkype_) {
    id_skype = idSkype_;
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

std::ostream& operator<<(std::ostream& os, Abonat_Skype_Extern& abS_) {

    Abonat_Skype* ptr = &abS_;
    os << ptr;
    os << " Tara: " << abS_.tara << '\n';

    return os;
}