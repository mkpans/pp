#include <iostream>
using namespace std;

struct Cena
{
    int zl;
    int gr;
};

Cena utworz_cene(int zl, int gr)
{
    if (gr >= 100)
    {
        zl += gr / 100;
        gr = gr % 100;
    }
    Cena c = {zl, gr};
    return c;
}

void wyswietl_cene(Cena c)
{
    cout << c.zl << " zl i " << c.gr << " gr";
}

Cena operator+(Cena c1, Cena c2)
{
    return utworz_cene(c1.zl + c2.zl, c1.gr + c2.gr);
}

Cena pobierz_cene()
{
    int zl;
    cout << "Podaj liczbe zl: ";
    cin >> zl;
    int gr;
    cout << "Podaj liczbe gr: ";
    cin >> gr;
    while (zl < 0 || gr < 0)
    {
        cout << "Bledna cena. Wpisz ponownie.\n";
        cout << "Podaj liczbe zl: ";
        cin >> zl;
        cout << "Podaj liczbe gr: ";
        cin >> gr;
    }
    return utworz_cene(zl, gr);
}

Cena operator*(Cena c, double liczba)
{
    int cena_w_gr = (c.zl * 100 + c.gr) * liczba;
    return utworz_cene(0, cena_w_gr);
}

Cena operator*(double liczba, Cena c)
{
    return c * liczba;
}

bool operator<(Cena c1, Cena c2)
{
    return c1.zl * 100 + c1.gr < c2.zl * 100 + c2.gr;
}

bool operator>(Cena c1, Cena c2)
{
    return c1.zl * 100 + c1.gr > c2.zl * 100 + c2.gr;
}

bool operator==(Cena c1, Cena c2)
{
    return c1.zl * 100 + c1.gr == c2.zl * 100 + c2.gr;
}

int main()
{
    Cena cena_1 = utworz_cene(2, 99);  // 2 zł, 99 gr
    Cena cena_2 = utworz_cene(2, 150); // 3 zł, 50 gr

    wyswietl_cene(cena_1);
    cout << endl;
    wyswietl_cene(cena_2);
    cout << endl;

    Cena c1 = pobierz_cene();
    Cena c2 = pobierz_cene();

    Cena suma_cen = c1 + c2;

    cout << "suma cen: ";
    wyswietl_cene(suma_cen);
    cout << endl;

    // Podwyżka o 20%. Wynik zaokrąglony do pełnych groszy w dół
    Cena cena_po_podwyzce = c1 * 1.2;

    cout << "cena po podwyzce o 20%: ";
    wyswietl_cene(cena_po_podwyzce);
    cout << endl;

    if (c1 < c2) {
        cout << "Pierwsza cena jest niższa.\n";
    } else if (c1 == c2) {
        cout << "Ceny sa równe.\n";
    }
    else {
        cout << "Druga cena jest niższa.\n";
    }
}
