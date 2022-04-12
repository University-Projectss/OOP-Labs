#ifndef _PERSOANA_H_
#define _PERSOANA_H_

#include <string>
#include <memory>

class Persoana {
private:
    int id;
    std::string nume;

public:
    Persoana();

    Persoana(int id_, std::string nume_);

    std::string getName() const;
    int getId() const;

    void setName(std::string name_);
    void setId(int id_);

    friend std::ostream& operator<<(std::ostream& os, std::shared_ptr<Persoana> pers_);

    ~Persoana() = default;
};

#endif