#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Numar_Complex {
private:
    double real, imaginar;

public:
    Numar_Complex(double real_, double imaginar_) { //construct init
        real = real_;
        imaginar = imaginar_
    }

    Numar_Complex(Numar_Complex nr_) {              //construct copy
        real = nr_.real;
        imaginar = nr_.imaginar;
    }

    void setImaginar(double imaginar_) {
        imaginar = imaginar_;
    }

    void setReal(double real_) {
        real = real_;
    }

    void afisare() {
        if (real == 0 && imaginar == 0) {
            cout << 0 << endl;
        } else if( real == 0 ) {
            if( imaginar < 0 ) {
                cout << "-i" << abs(imaginar) << endl;
            } else {
                cout << "i" << imaginar << endl;
            }
        } else if(imaginar == 0) {
            cout << real << endl;
        } else {
            if( imaginar < 0 ) {
                cout << real << "-i" << abs(imaginar) << endl;
            } else {
                cout << real << "+i" << imaginar << endl;
            }
        }
    }

    double getModule() {
        return sqrt(real*real + imaginar*imaginar);
    }

    Numar_Complex operator+(Numar_Complex const &obj) {
        Numar_Complex res;
        res.real = real + obj.real;
        res.imaginar = imaginar + obj.imaginar;

        return res;
    }

    Numar_Complex operator*(Numar_Complex const &obj) {
        Numar_Complex res;

        res.real = real * obj.real - imaginar * obj.imaginar;
        res.imaginar = real * obj.imaginar + imaginar * obj.real;

        return res;
    }

    Numar_Complex operator/(Numar_Complex const &obj) {
        Numar_Complex res;

        res.real = (real * obj.real + imaginar * obj.imaginar) / (obj.real * obj.real + obj.imaginar * obj.imaginar);
        res.imaginar = (imaginar * obj.real - real * obj.imaginar) / (obj.real * obj.real + obj.imaginar * obj.imaginar);

        return res;
    }

};

int main() {

    return 0;
}