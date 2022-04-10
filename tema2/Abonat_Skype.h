#ifndef _ABONAT_SKYPE_H_
#define _ABONAT_SKYPE_H_

#include <string>
#include "Abonat.h"

class Abonat_Skype : public Abonat {
private:
    std::string id_skype;
    static int nr_abonati;

public:
    Abonat_Skype();

    Abonat_Skype(std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    Abonat_Skype(const Abonat_Skype& ab);

    static int getNrAbonati() {
        return nr_abonati;
    }

    std::string getIdSkype() const;

    void setIdSkype(std::string idSkype_);

     void showAbonat() override;

    friend std::ostream& operator<<(std::ostream& os, Abonat_Skype* abS_);
    Abonat_Skype operator=(Abonat_Skype& ab);

    ~Abonat_Skype() = default;
};

///////////////////////////////////////////////////////////////////////////////////////////


class Abonat_Skype_Romania : public Abonat_Skype {
private:
    std::string adresa_mail;
public:
    Abonat_Skype_Romania();

    Abonat_Skype_Romania(std::string adresa_mail_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    Abonat_Skype_Romania(const Abonat_Skype_Romania& ab);

    std::string getEmail() const;

    void setEmail(std::string email_);

     void showAbonat() override;

    friend std::ostream& operator<<(std::ostream& os, Abonat_Skype_Romania& abS_);
    friend std::istream& operator>>(std::istream& os, Abonat_Skype_Romania& abS_);
    Abonat_Skype_Romania operator=(Abonat_Skype_Romania& ab);
};

///////////////////////////////////////////////////////////////////////////////////////////


class Abonat_Skype_Extern : public Abonat_Skype {
private:
    std::string tara;
public:
    Abonat_Skype_Extern();

    Abonat_Skype_Extern(std::string tara_, std::string id_skype_, std::string nr_telefon_, int id_, std::string nume_);

    Abonat_Skype_Extern(const Abonat_Skype_Extern& ab);

    std::string getCountry() const;

    void setCountry(std::string tara_);

     void showAbonat() override;

    friend std::ostream& operator<<(std::ostream& os, Abonat_Skype_Extern& abS_);
    friend std::istream& operator>>(std::istream& os, Abonat_Skype_Extern& abS_);
    Abonat_Skype_Extern operator=(Abonat_Skype_Extern& ab);
};

#endif