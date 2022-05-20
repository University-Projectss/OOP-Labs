#ifndef _ATLAS_H_
#define _ATLAS_H_
#include "Animals.h"
#include <iostream>
#include <list>
#include <vector>
#include <typeinfo>

//Sablon de proiectare: Agregare

template<class A>
class AtlasZoologic {
    int nrAnimale;
    std::list<A> catalog;
    std::vector<std::string> pestiRapitori;
public:
    AtlasZoologic() {
        nrAnimale = 0;
        pestiRapitori.push_back("stiuca");
        pestiRapitori.push_back("somn");
        pestiRapitori.push_back("salau");
        pestiRapitori.push_back("pastrav");
        pestiRapitori.push_back("lostrita");
        pestiRapitori.push_back("lipan");
        pestiRapitori.push_back("fantanel");
        pestiRapitori.push_back("clean");
        pestiRapitori.push_back("biban");
        pestiRapitori.push_back("avat");
    }

    int size() {
        return nrAnimale;
    }

    friend std::ostream& operator<<(std::ostream& os, AtlasZoologic& atlas) {
        for(typename std::list<A>::iterator i = atlas.catalog.begin(); i != atlas.catalog.end(); i++) {
            os << **i << " ";
        }
        return os;
    }

    void operator+=(A a) {
        catalog.push_back(a);
        nrAnimale++;
        std::cout << "Animal adaugat\n";
    }

    template<class T>
    int catiPestiRapitori() {
        std::cout << "\nNu avem pesti in acest atlas\n";
    }

    template<>
    int catiPestiRapitori<Vertebrate*>() {
        int cnt = 0;
        for(typename std::list<Vertebrate*>::iterator i = catalog.begin(); i != catalog.end(); i++) {
            for(int j = 0; j < 10; j++) {
                Vertebrate o(**i);
                if( pestiRapitori[j].compare(o.getSpecie()) == 0 ) {
                    Peste* p = dynamic_cast<Peste*>(*i); 
                    if(p->getLungime() > 1) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }


    ~AtlasZoologic() = default;
};

#endif