#ifndef _ABONAT_SKYPE_H_
#define _ABONAT_SKYPE_H_

#include <string>
#include "Abonat.h"

class Abonat_Skype : public Abonat {
private:
    std::string id_skype;

public:
    Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    std::string getIdSkype() const;
};

#endif