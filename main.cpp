#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <numeric>
using namespace std;

struct forma {
    char tip_baza[15];
    int caracteristici[4];
    int inaltime;

};

vector<forma> forme;
vector<int> volume;
vector<int> arii;

int main() {
    char comanda[10];

    cout << "Apasati ENTER ca sa incepeti" << endl;

    do {
        
        cin.get();
        cout << "Introduceti comanda: ";
        cin.get(comanda, 10);

        if( strcmp(comanda, "ADD") == 0 ) {
           struct forma a;
            cout << "Tipul bazei: ";
            cin >> a.tip_baza;

            if(a.tip_baza[0] == 'c') {
                cout << "Raza: ";
                cin >> a.caracteristici[0];
            } else if(a.tip_baza[0] == 'p') {
                cout << "Latura: ";
                cin >> a.caracteristici[0];
            } else if(a.tip_baza[0] == 'd') {
                cout << "Latime si lungime: ";
                cin >> a.caracteristici[0] >> a.caracteristici[1];
            } else if(a.tip_baza[0] == 't') {
                cout << "Cateta mica si cateta mare: ";
                cin >> a.caracteristici[0] >> a.caracteristici[1];
            }

            cout << "Inaltimea formei de copt: ";
            cin >> a.inaltime;

            int volum, arie_lat;
            if(a.tip_baza[0] == 'c') {
                volum = 3 * a.caracteristici[0] * a.caracteristici[0] * a.inaltime * 2;
                volume.push_back(volum);
                arie_lat = 6 * a.caracteristici[0] * a.inaltime;
                arii.push_back(arie_lat);

                cout << "Folosim " << volum << "g de gem si " << arie_lat << "g de frisca" << endl;
            } else if(a.tip_baza[0] == 'p') {
                volum = a.caracteristici[0] * a.caracteristici[0] * a.inaltime * 2;
                volume.push_back(volum);
                arie_lat = a.caracteristici[0] * 4 * a.inaltime;
                arii.push_back(arie_lat);

                cout << "Folosim " << volum << "g de gem si " << arie_lat << "g de frisca" << endl;
            } else if(a.tip_baza[0] == 'd') {
               volum = a.caracteristici[0] * a.caracteristici[0] * a.inaltime * 2;
               volume.push_back(volum);
                arie_lat = (a.caracteristici[0] * 2 + a.caracteristici[1] * 2) * a.inaltime;
                arii.push_back(arie_lat);

               cout << "Folosim " << volum << "g de gem si " << arie_lat << "g de frisca" << endl;
            } else if(a.tip_baza[0] == 't') {
                volum = (a.caracteristici[0] * a.caracteristici[1] / 2) * a.inaltime * 2;
               volume.push_back(volum);
               arie_lat = (a.caracteristici[0] + a.caracteristici[1] + sqrt(a.caracteristici[0] * a.caracteristici[0] + a.caracteristici[1] * a.caracteristici[1])) * a.inaltime;
                arii.push_back(arie_lat);
                
                cout << "Folosim " << volum << "g de gem si " << arie_lat << "g de frisca" << endl;
            }

            forme.push_back(a);

        } else if(strcmp(comanda, "REMOVE") == 0) {
            int nr = comanda[7];
            cout << "Eliminam forma " << nr << endl;

            forme.erase(forme.begin() + nr - 1);
            volume.erase(volume.begin() + nr - 1);
            arii.erase(arii.begin() + nr - 1);
        } else if(strcmp(comanda, "TOTAL") == 0) {
            cout << "Necesarul curent total: " << endl;
            int s = 0;
            cout << "Gem: " << accumulate(volume.begin(), volume.end(), s) << endl;
            
            s = 0;
            cout << "Frisca: " << accumulate(arii.begin(), arii.end(), s) << endl;

        }

    } while(strcmp(comanda, "STOP") != 0);
    

    return 0;
}
