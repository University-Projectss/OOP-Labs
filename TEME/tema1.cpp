#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Vector {
private:
    int n, *v;

public:
    Vector(int nr, int comp) {
        delete[] v;

        n = comp;
        int *newArray = new int[n];
        for(int i = 0; i < n; i++)
            newArray[i] = nr;

        v = newArray;
    }

    //Constructorul de initializare?
    Vector(int dim) {
        n = dim;
        v = new int[n];
    }

    //Constructorul de copiere?
    Vector(Vector w) {
        delete[] v;
        int *newArray = new int[w.n];

        for(int i = 0; i < w.n; i++)
            newArray[i] = w[i]; 

        v =  newArray;
    }

    ~Vector() {
        delete[] v;
    }

    Vector operator=(Vector const &w) {
        delete[] v;
        int *newArray = new int[w.n];

        for(int i = 0; i < w.n; i++)
            newArray[i] = w[i]; 

        v =  newArray;
    }

    void actualizare(int nr, int comp) {
        delete[] v;
        n = comp
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
   
};

int main() {
   
   Vector victor()

    return 0;
}