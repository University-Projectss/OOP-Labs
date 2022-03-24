#include <iostream>
using namespace std;

class Circuit {
private:
    

public:

}

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
public:   
    Dacia() : Car() {
        cout << "\nConstructor Dacia\n";
    };
};

class Toyota : public Car {   
public:   
    Toyota() : Car() {
        cout << "\nConstructor Toyota\n";
    };
};

class Renault : public Car {   
public:
    Renault() : Car() {
        cout << "\nConstructor Renault\n";
    };
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

    return 0;
}