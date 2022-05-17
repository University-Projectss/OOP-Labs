#include <bits/stdc++.h>
#include "Atlas.h"
#include <memory>
#include <string>
#include <iostream>
using namespace std;

template<class A>
void readAnimal(A ob) {
    std::string name;
    std::cout << "What animal is this? ";std::cin >> name;

    ob->setName(name);
}

int main() {
    AtlasZoologic< std::shared_ptr<Animal> > atlas;
    std::shared_ptr<Animal> a = std::make_shared<Animal>();
    readAnimal(a);

    atlas += a;

    return 0;
}