#include "Abonat_Skype.h"
#include <string>
#include <iostream>

Abonat_Skype::Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat(nr_telefon_, id_, nume_) {
    std::cout << "Constructor Abonat_Skype\n";
    id_skype = id_skype_;
}

std::string Abonat_Skype::getIdSkype() const {
    return id_skype;
}

///////////////////////////////////////////////////////////////////////////////////////////

Abonat_Skype_Romania::Abonat_Skype_Romania(std::string adresa_mail_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {
    std::cout << "Constructor Abonat_Skype_Romania\n";
    adresa_mail = adresa_mail_;
}

std::string Abonat_Skype_Romania::getEmail() const {
    return adresa_mail;
}


///////////////////////////////////////////////////////////////////////////////////////////

Abonat_Skype_Extern::Abonat_Skype_Extern(std::string tara_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_) :
Abonat_Skype(id_skype_, nr_telefon_, id_, nume_) {
    std::cout << "Constructor Abonat_Skype_Extern\n";
    tara = tara_;
}

std::string Abonat_Skype_Extern::getCountry() const {
    return tara;
}