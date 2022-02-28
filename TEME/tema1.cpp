#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

class Vector {
private:
    int n, *v;

public:
    Vector(int nr = 0, int comp = 1) {
        // delete[] v;

        n = comp;
        int *newArray = new int[n];
        for(int i = 0; i < n; i++)
            newArray[i] = nr;

        v = newArray;
    }

    //Constructorul de initializare?
    // Vector(int dim) {
    //     n = dim;
    //     v = new int[n];
    // }

    //Constructorul de copiere?
    Vector(Vector const &w) {
        delete[] v;
        int *newArray = new int[w.n];

        for(int i = 0; i < w.n; i++)
            newArray[i] = w.v[i]; 

        v =  newArray;
    }

    ~Vector() {
        delete[] v;
    }

    // Vector operator=(Vector const &w) {
    //     delete[] v;
    //     int *newArray = new int[w.n];

    //     for(int i = 0; i < w.n; i++)
    //         newArray[i] = w[i]; 

    //     v =  newArray;
    // }

    // void actualizare(int nr, int comp) {
    //     delete[] v;
    //     n = comp;
    //     int *newArray = new int[n];

    //     for(int i = 0; i < n; i++)
    //         newArray[i] = nr; 

    //     v =  newArray;
    // }

    void Suma() {
        int suma = 0;
        for(int i = 0; i < n; i++)
            suma += v[i];

        cout << "Suma elementelor vectorului este: " << suma << endl;
    }

    void Maxim() {
        int maxim = 0, index = -1;
        for(int i = 0; i < n; i++)
            if(v[i] > maxim) 
                maxim = v[i], index = i;

        cout << "Maximul din vector este " << maxim << " ,aflat la pozitia ";
        cout << index << endl;
    }

    void Sortare() {
        sort(v, v + n);
    }

    void afisare() {
        for(int i = 0 ; i < n; i++) 
            cout << v[i] << " ";
        cout << endl;
    }

   friend class Meniu;
};

class Meniu {
private:
    char comand[12];
    bool avem;
    Vector tablou;

public:

    void run() {
        cout << "TEMA --> Implementarea clasei Vector" << endl << endl;
        cout << "              MENIU COMENZI         " << endl << endl;
        cout << "1. ADD x n - creeaza un obiect Vector cu n componente cu valoarea x" << endl;
        cout << "2. PRINT - afiseaza al n-lea obiect creat" << endl;
        cout << "3. SUM - afiseaza suma elementelor vectorului" << endl;
        cout << "4. MAX - afiseaza cel mai mare element din vector" << endl;
        cout << "5. SORT - sorteaza crescator vectorul" << endl;
        cout << "6. STOP - opreste programul" << endl;
        cout << endl;
        
        cout << "Ca sa incepeti apasati ENTER" << endl;
        

        avem = false;
        do {
            cin.get();
            cout << "Introduceti comanda si apasati ENTER --> ";
            cin.get(comand, 12);

            if( comand[0] == 'A' ) {
                avem = true;
                int n = comand[4] - '0';
                int dim = comand[6] - '0';
                Vector vct(n, dim);
                tablou = vct;
            }else if( comand[0] == 'P' ) {
                tablou.afisare();
            }


        }while( strcmp(comand, "STOP") == 0 );
        
        
    }

};

int main() {
    Meniu m;
    m.run();

    return 0;
}