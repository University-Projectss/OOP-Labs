#ifndef _AGENDA_H_
#define _AGENDA_H_

#include <string>
#include <vector>
#include "Abonat_Skype.h"

class Agenda {
private:
    std::vector<Abonat*> lista;

public:
    Agenda();

    // void showAgenda() const;

    void addAbonat(Abonat* ab);

    Abonat operator[](const std::string nume_);

    friend std::ostream& operator<<(std::ostream& os, Agenda& ag_);
};

#endif