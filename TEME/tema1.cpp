#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
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
    Vector(const Vector &w) {
        int *newArray = new int[w.n];
        n = w.n;

        for(int i = 0; i < w.n; i++)
            newArray[i] = w.v[i]; 

        v =  newArray;
    }

    ~Vector() {
        delete[] v;
    }

    int operator[](int poz) const {
        return v[poz];
    }

    Vector& operator=(const Vector &w) {
        delete[] v;
        int *newArray = new int[w.n];
        n = w.n;

        for(int i = 0; i < w.n; i++)
            newArray[i] = w[i]; 

        v =  newArray;

        return *this;
    }

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

    //un fel de setter
    void change(int poz, int val) {
        if(poz >= n) 
            cout << "Segmentation fault! Ai iesit din vector.";
        else
            v[poz] = val;
    }

    //un fel de getter
    int getSize() {
        return n;   
    }

    friend ostream& operator<<(ostream &os, Vector &rhs) {
        os << "Vectorul la momentul curent: ";
        for(int i = 0; i < rhs.n; i++)
            os << rhs[i] << " ";
        os << endl;

        return os;
    }

    // void afisare() {
    //     for(int i = 0 ; i < n; i++) 
    //         cout << v[i] << " ";
    //     cout << endl;
    // }

//    friend class Meniu;
};

class Meniu {
private:
    char comand[15];
    // bool avem;
    Vector tablou;

public:

    void run() {
        cout << "TEMA --> Implementarea clasei Vector" << endl << endl;
        cout << "              MENIU COMENZI         " << endl << endl;
        cout << "1. ADD x n - creeaza un obiect Vector cu n componente cu valoarea x" << endl;
        cout << "2. CHANGE x n - atribuie valoarea n lui v[x]" << endl;
        cout << "3. PRINT - afiseaza vectorul" << endl;
        cout << "4. SUM - afiseaza suma elementelor vectorului" << endl;
        cout << "5. MAX - afiseaza cel mai mare element din vector" << endl;
        cout << "6. SORT - sorteaza crescator vectorul" << endl;
        cout << "7. STOP - opreste programul" << endl;
        cout << endl;

        cout << "*vectorul este indexat de la 0";
        cout << endl;
        cout << endl;
        
        cout << "Ca sa incepeti apasati ENTER" << endl;
        

        // avem = false;
        do {
            cin.get();
            cout << "Introduceti comanda si apasati ENTER --> ";
            cin.get(comand, 12);

            if( comand[0] == 'A' ) {
                // avem = true;
                // int n = comand[4] - '0';
                // int dim = comand[6] - '0';

                int n, dim;
                char *p;
                p = strtok(comand, " ");

                p = strtok(NULL, " ");
                if(*p == '0')
                    n = 0;
                else
                    n = atoi(p);

                p = strtok(NULL, " ");
                if(*p == '0')
                    dim = 0;
                else
                    dim = atoi(p);

                Vector vct(n, dim);
                tablou = vct;
            } else if( comand[0] == 'P' ) {
                cout << tablou;
            } else if( comand[1] == 'U' ) {
                tablou.Suma();
            } else if( comand[0] == 'M' ) {
                tablou.Maxim();
            } else if( comand[1] == 'O' ) {
                tablou.Sortare();
                cout << tablou;
            } else if( comand[0] == 'C' ) {
                // int x = comand[7] - '0';
                // int n = comand[9] - '0';

                int x, n;
                char *p;
                p = strtok(comand, " ");

                p = strtok(NULL, " ");
                if(*p == '0')
                    x = 0;
                else
                    x = atoi(p);

                p = strtok(NULL, " ");
                if(*p == '0')
                    n = 0;
                else
                    n = atoi(p);

                tablou.change(x, n);
            } 

            cout << endl;

        }while( strcmp(comand, "STOP") != 0 );
        
    }

};

int main() {
    Meniu m;
    m.run();

    return 0;
}