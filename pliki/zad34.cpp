#include <iostream>
using namespace std;

int main() {

    int rok;
    int miesiac;
    int dzien;

    cout << "rok = ";
    cin >> rok;

    cout << "miesiac = ";
    cin >> miesiac;

    cout << "dzien = ";
    cin >> dzien;

    bool poprawna_data = true;

    if (rok < 1) {
        poprawna_data = false;
    } else {
        if ((1 > miesiac) || (miesiac > 12)) {
            poprawna_data = false;
        } else {
            int liczba_dni_w_miesiacu = 31;
            if (miesiac == 2) {
                if (rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0) {
                   liczba_dni_w_miesiacu = 29;
                } else {
                    liczba_dni_w_miesiacu = 28;
                }
            } else if (miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) {
                liczba_dni_w_miesiacu = 30;
            }
            if ((dzien < 1) || (dzien > liczba_dni_w_miesiacu)) {
                poprawna_data = false;
            }
        }
    }


    if (poprawna_data) {
        cout << "Poprawna data.\n";
        if (dzien < 10) {
            cout << "0";
        }
        cout << dzien << "/";
        if (miesiac < 10) {
            cout << "0";
        }
        cout << miesiac << "/" << rok << endl;
    } else {
        cout << "Bledna data.\n";
    }



}
