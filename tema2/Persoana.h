#ifndef _PERSOANA_H_
#define _PERSOANA_H_

#include <string>

class Persoana {
private:
    int id;
    std::string nume;

public:
    Persoana();

    Persoana(int id_, std::string nume_);

    void showName() const;
};

#endif