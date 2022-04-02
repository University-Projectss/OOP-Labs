#include "Abonat_Skype.h"
#include <iostream>

int main() {
    Abonat_Skype p("12", "0712312312", 16, "Robert");

    std::cout << p.getPhoneNumber() << '\n';
    std::cout << p.getIdSkype() << '\n';
    p.showName();

    return 0;
}