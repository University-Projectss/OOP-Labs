#include "Agenda.h"
#include <string>
#include <iostream>

Agenda::Agenda() {
    std::cout << "Agenda dumneavoastra este goala\n";
}

void Agenda::showAgenda() const {
    for(int i = 0; i < lista.size(); i++)
         lista[i]->showName();
}

void Agenda::addAbonat(Abonat* ab) {
    lista.push_back(ab);
}