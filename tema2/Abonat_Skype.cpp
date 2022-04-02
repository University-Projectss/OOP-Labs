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