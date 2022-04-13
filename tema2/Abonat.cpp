#include "Abonat.h"
#include "Abonat_Skype.h"
#include <string>
#include <iostream>
#include <typeinfo>

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

// void Abonat::showAbonat() = 0;
void Abonat::showAbonat() {}

std::ostream& operator<<(std::ostream& os, std::shared_ptr<Abonat> ab_) {
    os << "\n";
    // Persoana* ptr = ab_;
    std::shared_ptr<Persoana> ptr = ab_;
    os << ptr;


    os << " | Telefon: " << ab_->nr_telefon << '\n';

    std::shared_ptr<Abonat_Skype_Romania> pd = std::dynamic_pointer_cast<Abonat_Skype_Romania> (ab_);
    std::shared_ptr<Abonat_Skype_Extern> pe = std::dynamic_pointer_cast<Abonat_Skype_Extern> (ab_);

    if( pd != nullptr ) {
        pd->showAbonat();
    } else {
        pe->showAbonat();
    }
    
    return os;
}

std::istream& operator>>(std::istream& os, Abonat& ab_) {
    std::string n;
    int i;
    std::cout << " Nume: "; os >> n;
    std::cout << " Id:   "; os >> i;
    std::cout << " Telefon: "; os >> ab_.nr_telefon;
    ab_.setId(i);
    ab_.setName(n);

    return os;
}

Abonat Abonat::operator=(Abonat& ab) {
    setId( ab.getId() );
    setName( ab.getName() );
    nr_telefon = ab.nr_telefon;
}