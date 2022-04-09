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

std::string Persoana::getName() const {
    return nume;
}

int Persoana::getId() const {
    return id;
}

void Persoana::setId(int id_) {
    id = id_;
}

void Persoana::setName(std::string name_) {
    nume = name_;
}

std::ostream& operator<<(std::ostream& os, const Persoana* pers_) {
    os << " Nume: " << pers_->nume;
    os << "\n Id:   " << pers_->id;
    os << '\n';

    return os;
}
