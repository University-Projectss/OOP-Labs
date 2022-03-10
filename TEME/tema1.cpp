//Tema 3 --> Clasa 'Vector'
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
    //adevaratul constructor de initializare
    Vector(int nr, int comp) {
        // delete[] v;

        n = comp;
        int *newArray = new int[n];
        for(int i = 0; i < n; i++)
            newArray[i] = nr;

        v = newArray;
    }

    // Constructorul de initializare?
    Vector() {
        n = 1;
        v = new int[n];
    }

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

    void actualizare(int nr, int comp) {
        delete[] v;
        n = comp;
        int *newArray = new int[n];

        for(int i = 0; i < n; i++)
            newArray[i] = nr; 

        v =  newArray;
    }

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
    int getSize() const {
        return n;   
    }

    friend istream& operator>>(istream &os, Vector &vct) {
        int nr, elem;
            cout << "n (nr. elemente) = ";
            os >> nr;
            cout << "Elementele vectorului: " << endl;

            vct.n = nr;

            for(int i = 0; i < nr; i++) {
                os >> elem;
                vct.change(i, elem);
            }
        return os;
    }

    friend ostream& operator<<(ostream &os, vector<Vector> &rhs) {
        os << endl;

        if( rhs.size() == 0 ) {
            cout << "cri...cri...Nu exista niciun obiect creat.";
        } else {
            for(int i = 0; i < rhs.size(); i++) {
            cout << "Obiectul " << i << endl;
            os << "n =  " << rhs[i].getSize() << endl << "v: ";
            for(int j = 0; j < rhs[i].n; j++)
                os << rhs[i].v[j] << " ";
            os << endl;
            os << endl;
            }
        }

        return os;
    }

//    friend class Meniu;
};

class Meniu {
private:
    char comand[15];
    // bool avem;
    Vector tablou;
    vector<Vector> bigV;

public:

    void afisare() {
        cout << bigV;
    }

    void citire(Vector &rhs) {
        cin >> rhs;
    }

    void run() {
        cout << "TEMA --> Implementarea clasei Vector" << endl << endl;
        cout << "              MENIU COMENZI         " << endl << endl;
        cout << "1. ADD x n    - creeaza un obiect nou cu n componente cu valoarea x" << endl;
        cout << "2. READ       - citeste de la tastatura un obiect nou" << endl;
        cout << "3. CHANGE x n - atribuie valoarea n lui v[x]" << endl;
        cout << "4. UPDATE x n - reactualizeaza nr de componente cu n, toate fiind egale cu x" << endl;
        cout << "5. PRINT      - afiseaza toate obiectele create" << endl;
        cout << "6. SUM        - afiseaza suma elementelor vectorului" << endl;
        cout << "7. MAX        - afiseaza cel mai mare element din vector" << endl;
        cout << "8. SORT       - sorteaza crescator vectorul" << endl;
        cout << "9. STOP       - opreste programul" << endl;
        cout << endl;

        cout << "*vectorul este indexat de la 0";
        cout << endl;
        cout << "*comenzile 3, 4, 6, 7 modifica ultimul obiect creat";
        cout << endl;
        cout << "*programul nu este case sensitive, dar pentru a il opri ";
        cout << "trebuie scris STOP";
        cout << endl;
        cout << endl;
        
        cout << "Ca sa incepeti apasati ENTER" << endl;
        

        // avem = false;
        do {
            cin.get();
            cout << "Introduceti comanda si apasati ENTER --> ";
            cin.get(comand, 12);

            if( toupper(comand[0]) == 'A' ) {
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
                bigV.push_back(tablou);
            } else if(toupper(comand[0]) == 'R') {

                Vector vct;
                
                citire(vct);

                tablou = vct;
                bigV.push_back(tablou);
            } else if(toupper(comand[0]) == 'U') {
                
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

                bigV[bigV.size() - 1].actualizare(x, n);

            } else if( toupper(comand[0]) == 'P' ) {
                afisare();
            } else if( toupper(comand[1]) == 'U' ) {
                bigV[bigV.size() - 1].Suma();
            } else if( toupper(comand[0]) == 'M' ) {
                bigV[bigV.size() - 1].Maxim();
            } else if( toupper(comand[1]) == 'O' ) {
                bigV[bigV.size() - 1].Sortare();
                // cout << bigV[bigV.size() - 1];
            } else if( toupper(comand[0]) == 'C' ) {
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

                bigV[bigV.size() - 1].change(x, n);
            }else if( strcmp(comand, "STOP") != 0 )
                cout << "Comanda gresita!";

            cout << endl;

        }while( strcmp(comand, "STOP") != 0 );
        
    }

};

int main() {
    Meniu m;
    m.run();

    return 0;
}
