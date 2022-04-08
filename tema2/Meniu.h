#ifndef _MENIU_H_
#define _MENIU_H_

#include <string>
#include <vector>
#include "Agenda.h"



class Meniu {
private:
    Agenda Ag;
    char command;

public:
    Meniu();

    void addRo(Abonat_Skype_Romania &abonat_);

    void addEx(Abonat_Skype_Extern &abonat_);
};

#endif