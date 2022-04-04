#include "Abonat_Skype.h"
#include <iostream>

int main() {
    Abonat_Skype p("12", "0712312312", 16, "Robert");

    std::cout << p.getPhoneNumber() << '\n';
    std::cout << p.getIdSkype() << '\n';
    p.showName();

    std::cout << '\n';

    Abonat_Skype_Romania r("rbt@mail.ro", "13", "07123123", 19, "Keanu");
    std::cout << r.getPhoneNumber() << '\n';
    std::cout << r.getIdSkype() << '\n';
    std::cout << r.getEmail() << '\n';
    r.showName();

    std::cout << '\n';

    Abonat_Skype_Extern e("Congo", "14", "071343123", 56, "Babbu");
    std::cout << e.getPhoneNumber() << '\n';
    std::cout << e.getIdSkype() << '\n';
    std::cout << e.getCountry() << '\n';
    e.showName();

    return 0;
}