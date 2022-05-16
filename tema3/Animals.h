#ifndef _ANIMALS_H_
#define _ANIMALS_H_
#include <string>

//Sablon de proiectare: Mostenire

class Animal {
    std::string denumire;
public:
    Animal(std::string d = "Animal") {
        denumire = d;
        std::cout << "Constructor Animal\n";
    }

    virtual ~Animal() = default; 
};


class Nevertebrate : public Animal {
    const std::string tipAnimal = "Nevertebrat";
public:
    Nevertebrate(std::string d) : Animal(d) {};

    std::string getTipAnimal() const {
        return tipAnimal;
    }

    ~Nevertebrate() = default;
};


class Vertebrate : public Animal {
    const std::string tipAnimal = "Vertebrat";
public:
    Vertebrate(std::string d) : Animal(d) {};

    std::string getTipAnimal() const {
        return tipAnimal;
    }

    ~Vertebrate() = default;
};


#endif