#ifndef _ANIMALS_H_
#define _ANIMALS_H_
#include <string>

//Sablon de proiectare: Mostenire

class Animal {
    std::string name;
public:
    Animal() {
        std::cout << "Constructor Animal\n";
    }

    void setName(std::string n) {
        name = n;
    }

    virtual ~Animal() = default; 
};


class Nevertebrate : public Animal {
public:
    Nevertebrate() {};

    ~Nevertebrate() = default;
};


class Vertebrate : public Animal {
public:
    Vertebrate() {};

    ~Vertebrate() = default;
};



#endif