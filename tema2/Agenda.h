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

    void showAgenda() const;

    void addAbonat(Abonat* ab);
};

#endif