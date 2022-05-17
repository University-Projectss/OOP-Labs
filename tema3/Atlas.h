#ifndef _ATLAS_H_
#define _ATLAS_H_
#include "Animals.h"
#include <iostream>
#include <list>

//Sablon de proiectare: Agregare

template<class A>
class AtlasZoologic {
    int nrAnimale;
    std::list<A> catalog;
public:
    AtlasZoologic() {
        nrAnimale = 0;
        std::cout << "Constructor Atlas\n";
    }

    void operator+=(A a) {
        catalog.push_back(a);
        nrAnimale++;
        std::cout << "Animal adaugat\n";
    }

    ~AtlasZoologic() = default;
};

#endif