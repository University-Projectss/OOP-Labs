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
                // Abonat_Skype_Romania ken;
                Abonat* ptr = new Abonat_Skype_Romania();
                try {

                    std::cin >> *dynamic_cast< Abonat_Skype_Romania* >(ptr);
                    Ag.addAbonat(ptr);
                    // addRo(ken);
                }
                catch (MyException& e) {
                    std::cout << '\n' << e.what() << '\n';
                }

            } else if( command == '2' ) {
                Abonat* ptr = new Abonat_Skype_Extern();
                std::cin >> *dynamic_cast< Abonat_Skype_Extern* >(ptr);
                Ag.addAbonat(ptr);
                // addEx(ken);
            }

            std::cout << '\n';
       

    }while(command != 'x');
}

void Meniu::addRo(Abonat_Skype_Romania &abonat_) {
    Abonat* ptr = &abonat_;
    // Abonat* ptr = dynamic_cast<Abonat*> (&abonat_);
    // ptr->showAbonat();
    Ag.addAbonat(ptr);
}

void Meniu::addEx(Abonat_Skype_Extern &abonat_) {
    Abonat* ptr = &abonat_;
    Ag.addAbonat(ptr);
}