#ifndef _ABONAT_H_
#define _ABONAT_H_

#include <string>
#include "Persoana.h"

class Abonat : public Persoana {
private: 
    std::string nr_telefon;

public:

    Abonat(std::string nr_telefon_, int id_, std::string nume_);

    std::string getPhoneNumber() const;

};

#endif