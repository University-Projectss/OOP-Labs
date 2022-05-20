#ifndef _ANIMALS_H_
#define _ANIMALS_H_
#include <string>

//Sablon de proiectare: Mostenire

class Animal {
protected:
    std::string specie;
public:
    Animal() {
        specie = "";
    }
    Animal(std::string s) : specie(s) {}

    virtual void citire(std::istream& is) {
        is >> specie;
    }
    friend std::istream& operator>>(std::istream& is, Animal& obj) {
        obj.citire(is);
        return is;
    }

    virtual ~Animal() = default; 
};


class Nevertebrate : public Animal {
public:
    Nevertebrate(std::string s = "") : Animal(s) {};

    void citire(std::istream& is) {
        is >> specie;
    }

    friend std::ostream& operator<<(std::ostream& os, Nevertebrate& obj) {
        os << obj.specie;

        return os;
    }

    ~Nevertebrate() = default;
};


class Vertebrate : public Animal {
public:
    Vertebrate(std::string s) : Animal(s) {};
    Vertebrate(Vertebrate& obj) : Animal(obj.getSpecie()) {
        specie = obj.getSpecie();
    }

    std::string getSpecie() {
        return specie;
    }

    virtual int getLungime() {return 0;}

    friend std::ostream& operator<<(std::ostream& os, Vertebrate& obj) {
        os << obj.specie;

        return os;
    }

    ~Vertebrate() = default;
};

class Peste : public Vertebrate {
    int lungime;
public:
    Peste(std::string s, int l) : Vertebrate(s), lungime(l) {};

    int getLungime() override {
        return lungime;
    }

    ~Peste() = default;
};

class Pasare : public Vertebrate {
public:
    Pasare(std::string s) : Vertebrate(s) {};

    ~Pasare() = default;
};

class Reptila : public Vertebrate {
public:
    Reptila(std::string s) : Vertebrate(s) {};

    ~Reptila() = default;
};

class Mamifer : public Vertebrate {
public:
    Mamifer(std::string s) : Vertebrate(s) {};

    ~Mamifer() = default;
};

#endif