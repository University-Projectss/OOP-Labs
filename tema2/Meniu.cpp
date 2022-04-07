#include "Meniu.h"
#include <string>
#include <iostream>

Meniu::Meniu() {
    std::cout << "\n                Bine ati venit la Tema2 de POO\n";
    std::cout <<"  Avem o Agenda, momentan goala, in care puteam adauga Abonati Skype.\n";
    std::cout <<"                        Iata comenzile:\n\n\n";

    std::cout << "  0. Vedeti Abonatii din Agenda\n";
    std::cout << "  1. Adaugam un nou Abonat din Romania\n";
    std::cout << "  2. Adaugam un nou Abonat Extern\n";

    do {
        std::cin.get();
        std::cout << "Introduceti comanda si apasati ENTER --> ";
        std::cin >> command;

        
        
        if( command == '0' )
            std::cout << Ag << '\n';
        else if( command == '1' ) {
            std::string nume, id_skype, mail, telefon;
            int id;
            std::cout<< "Nume: ";
            std::cin.get();
            std::getline(std::cin, nume);

            std::cout<< "Mail: ";
            std::cin >> mail;

            std::cout<< "Telefon: ";
            std::cin >> telefon;

            std::cout<< "Id Skype: ";
            std::cin >> id_skype;

            std::cout << "Id Abonat: ";
            std::cin >> id;

            Abonat_Skype_Romania ken(mail, id_skype, telefon, id, nume);
            addRo(ken);
        } else if( command == '2' ) {
            std::string nume, id_skype, tara, telefon;
            int id;
            std::cout<< "Nume: ";
            std::cin.get();
            std::getline(std::cin, nume);

            std::cout<< "Tara: ";
            std::cin >> tara;

            std::cout<< "Telefon: ";
            std::cin >> telefon;

            std::cout<< "Id Skype: ";
            std::cin >> id_skype;

            std::cout << "Id Abonat: ";
            std::cin >> id;

            Abonat_Skype_Extern ken(tara, id_skype, telefon, id, nume);
            addEx(ken);
        }
        
        std::cout << '\n';

    }while(command != 'x');
}

void Meniu::addRo(Abonat_Skype_Romania &abonat_) {
    Abonat* ptr = &abonat_;
    Ag.addAbonat(ptr);
}

void Meniu::addEx(Abonat_Skype_Extern &abonat_) {
    Abonat* ptr = &abonat_;
    Ag.addAbonat(ptr);
}