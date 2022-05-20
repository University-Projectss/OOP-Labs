#include <bits/stdc++.h>
#include "Atlas.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

template<class T> 
Vertebrate* citireVertebrat() {
    string specie;
    cout << "Numele animalului este ";cin >> specie;
    Vertebrate* ptr = new T(specie);
    return ptr;
}

template<>
Vertebrate* citireVertebrat< Peste >() {
    string specie;
    int lungime;
    cout << "Numele pestelui este ";cin >> specie;
    cout << "Avand lungime de x metri, unde x = ";cin >> lungime;
    Vertebrate* ptr = new Peste(specie, lungime);
    return ptr;
}

int main() {
    AtlasZoologic< Vertebrate* > atlas1;
    AtlasZoologic< Nevertebrate* > atlas2;
    int n;
    string sir;

    cout << "Cate animale cititi? ";cin >> n;
    cout << '\n';

    while(n--) {
        cout << "\nCe fel de animal?(vertebrat sau nevertebrat)\n";
        cin >> sir;

        if(sir.compare("vertebrat") == 0) {
             cout << "peste, pasare, reptila sau mamifer?\n";
             cin >> sir;
             if(sir.compare("peste") == 0) {
                atlas1 += citireVertebrat< Peste >();
             } else if(sir.compare("pasare") == 0) {
                 atlas1 += citireVertebrat< Pasare >();
             } else if(sir.compare("reptila") == 0) {
                 atlas1 += citireVertebrat< Reptila >();
             } else if(sir.compare("mamifer") == 0) {
                 atlas1 += citireVertebrat< Mamifer >();
             }
        } else {
            cout << "Numele animalului este ";cin >> sir;
            Nevertebrate* ptr = new Nevertebrate(sir);
            atlas2 += ptr;
        }
    }

    cout << "\n\n\n";

    cout << "Animalele introduse au fost urmatoarele: \n";
    cout << "Vertebrate: " << atlas1 << '\n';
    cout << "Nevertebrate: " << atlas2 << '\n';
    cout << "Cati pesti rapitori de lungime mai mare de 1m s-au citit?\n";
    cout << "Raspuns: " << atlas1.catiPestiRapitori< Vertebrate* >() << '\n';
    return 0;
}