#include <iostream>
using namespace std;

int main() {
    int a, b, suma;
    cin >> a >> b;

    for (int i = a; i <= b; i++)
    {
        suma = 0;
        for (int j = 1; j < i; j++)
            if(i % j == 0)
                suma += j;

        if( suma == i) 
            cout << i << " ";
    }

    cout << endl;
    

    return 0;
}
