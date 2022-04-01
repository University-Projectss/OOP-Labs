#include "Persoana.h"
#include <string>
#include <iostream>

Persoana::Persoana(int id_, std::string nume_) {
    id = id_;
    nume = nume_;
}

void Persoana::showName() const {
    std::cout << "Numele meu este: " << nume << '\n';
}