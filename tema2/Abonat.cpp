#include "Abonat.h"
#include <string>
#include <iostream>

Abonat::Abonat() {
    nr_telefon = "000000000";
}

Abonat::Abonat(std::string nr_telefon_, int id_, std::string nume_) :
Persoana(id_, nume_) {
    nr_telefon = nr_telefon_;
}

Abonat::Abonat(const Abonat& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    nr_telefon = ab.getPhoneNumber();
}

std::string Abonat::getPhoneNumber() const {
    return nr_telefon;
}

void Abonat::setPhoneNumber(std::string nr_telefon_) {
    nr_telefon = nr_telefon_;
}

std::ostream& operator<<(std::ostream& os, Abonat* ab_) {
    os << "\n";
    Persoana* ptr = ab_;
    os << ptr;
    os << "Telefon: " << ab_->nr_telefon << '\n';

    return os;
}

