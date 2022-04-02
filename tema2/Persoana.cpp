#include "Persoana.h"
#include <string>
#include <iostream>

Persoana::Persoana() {
    std::cout << "Constructor Persoana no-param\n";
    id = 0;
    nume = "ARICI";
}

Persoana::Persoana(int id_, std::string nume_) {
    std::cout << "Constructor Persoana\n";
    id = id_;
    nume = nume_;
}

void Persoana::showName() const {
    std::cout << "Numele meu este: " << nume << '\n';
}