#ifndef _ATLAS_H_
#define _ATLAS_H_
#include "Animals.h"
#include <iostream>
#include <list>

//Sablon de proiectare: Agregare

template<class A = int>
class AtlasZoologic {
    int nrAnimale;
    std::list<A*>;
public:
    AtlasZoologic() {
        nrAnimale = 0;
        std::cout << "Constructor Atlas\n";
    }


    ~AtlasZoologic() = default;
};

#endif