#include "Abonat.h"
#include <string>
#include <iostream>

Abonat::Abonat(std::string nr_telefon_, int id_, std::string nume_) :
Persoana(id_, nume_) {
    std::cout << "Constructor Abonat\n";
    nr_telefon = nr_telefon_;
}

std::string Abonat::getPhoneNumber() const {
    return nr_telefon;
}