#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
    int speed;

public:
    Car() {
        cout << "Constructor Car";
    
        speed = 60 + (rand() % 100);
    }

    int getSpeed() {
        return speed;
    }
};

class Dacia : public Car {
private:
    string brand = "Dacia";

public:   
    Dacia() : Car() {
        cout << "\nConstructor Dacia\n";
    };

    void getCar() {
        cout << "\n" << brand << "\n";
    }
};

class Toyota : public Car {
    string brand = "Toyota";

public:   
    Toyota() : Car() {
        cout << "\nConstructor Toyota\n";
    };

    void getCar() {
        cout << "\n" << brand << "\n";
    }
};

class Renault : public Car {   
    string brand = "Renault";

public:
    Renault() : Car() {
        cout << "\nConstructor Renault\n";
    };

    void getCar() {
        cout << "\n" << brand << "\n";
    }
};


class Circuit {
private:
    vector<Car*> v;
    int n;                  //nr de masini introduse

public:
    Circuit() {
        cout << "\nConstructor Circuit\n";
        n = 0;
    }

    void addCar(Car* obj) {
        v.push_back(obj);
        n++;
    }

    void showCars() {
        for(int i = 0; i < n; i++) {
            cout << v[i]->getSpeed() << '\n';
        }
    }

};


int main() {
    srand(time(NULL));

    Dacia c1;
    cout << c1.getSpeed() << '\n';
    cout << '\n';

    Toyota c2;
    cout << c2.getSpeed() << '\n';
    cout << '\n';

    Renault c3;
    cout << c3.getSpeed() << '\n';



    cout << "\n\nAdaugarea masinilor pe Circuit:\n";
    Circuit C;
    C.addCar(&c1);
    C.addCar(&c2);
    C.addCar(&c3);

    C.showCars();

    return 0;
}