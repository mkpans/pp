#include <iostream>
using namespace std;

int main() {

    int ile_liczb;
    cout << "Ile liczb chcesz podac? ";
    cin >> ile_liczb;

    int iloczyn = 1;
    int ile_mnozen = 0;
    while (ile_mnozen < ile_liczb) {

        int liczba;
        cout << "Podaj kolejna liczbe: ";
        cin >> liczba;

        iloczyn *= liczba;

        ile_mnozen++;
    }

    cout << "Iloczyn: " << iloczyn << endl;

}


