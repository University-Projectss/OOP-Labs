#include "Persoana.h"
#include <string>
#include <iostream>

Persoana::Persoana() {
    id = -1;
    nume = "NULL";
}

Persoana::Persoana(int id_, std::string nume_) {
    id = id_;
    nume = nume_;
}

void Persoana::showName() const {
    std::cout << "Numele meu este: " << nume << '\n';
}

std::string Persoana::getName() const {
    return nume;
}

std::ostream& operator<<(std::ostream& os, const Persoana* pers_) {
    os << " Nume: " << pers_->nume;
    os << "\n Id:   " << pers_->id;
    os << '\n';

    return os;
}