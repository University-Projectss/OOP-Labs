#include <bits/stdc++.h>
using namespace std;

class Vehicle {
public:
    Vehicle() {
        cout << "Merge, sunt un vehicul!!" << endl;
    }
};

class Car: public Vehicle {

};


int main()
{

    Car bmw;

    return 0;
}