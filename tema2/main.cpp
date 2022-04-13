#include "Agenda.h"
#include "Meniu.h"
#include <iostream>

int main() {
    int nr;
    std::cout << "\nTastati 0 si ENTER pentru a incepe programul.\n\n";
    if( !(std::cin >> nr) ) return 0;

    Meniu m;
    return 0;
}

/*
g++ -o main -w main.cpp Meniu.cpp Persoana.cpp Agenda.cpp Abonat.cpp Abonat_Skype.cpp
*/