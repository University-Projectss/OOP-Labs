#include <bits/stdc++.h>
#include "Atlas.h"
using namespace std;

template<class A>
void showType(const A& ob) {
    std::cout << ob.getTipAnimal() << '\n';
}

int main() {
    Vertebrate a("Leu");

    showType(a);

    return 0;
}