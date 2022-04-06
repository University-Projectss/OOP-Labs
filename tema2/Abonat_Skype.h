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

///////////////////////////////////////////////////////////////////////////////////////////

class Abonat_Skype_Romania : public Abonat_Skype {
private:
    std::string adresa_mail;
public:
    Abonat_Skype_Romania(std::string adresa_mail_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    std::string getEmail() const;
};

///////////////////////////////////////////////////////////////////////////////////////////

class Abonat_Skype_Extern : public Abonat_Skype {
private:
    std::string tara;
public:
    Abonat_Skype_Extern(std::string tara_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    std::string getCountry() const;
};

#endif