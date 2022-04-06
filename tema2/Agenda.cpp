#include "Agenda.h"
#include <string>
#include <iostream>

Agenda::Agenda() {
    // std::cout << "Agenda dumneavoastra este goala\n";
}

void Agenda::showAgenda() const {
    if( !lista.size() )
        std::cout << "Nu exista niciun Abonat\n";

    for(int i = 0; i < lista.size(); i++)
         lista[i]->showName();
}

void Agenda::addAbonat(Abonat* ab) {
    lista.push_back(ab);
}

Abonat Agenda::operator[](const std::string nume_) {
    for(int i = 0; i < lista.size(); i++) 
        if (nume_.compare( lista[i]->getName() ) == 0)
            return *lista[i];
}