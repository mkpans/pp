#include <iostream>
#include <string>
// Obsługa plików
#include <fstream>

// rozpoznawanie typów znaków
#include <cctype>
// isdigit
// isspace
// isalnum
// isalpha
// islower
// isupper
// tolower
// toupper


// Tzw. "manipulatory" wejścia/wyjścia
#include <iomanip>


// cout << skipws
// cout << noskipws
// cout << setw(n)
// cout << setfill()
// cout << setprecision(n)
// cout << fixed
// cout << left
// cout << right

//  
// cout.width(int w)
// cout.fill(char c)
// cout.precision(int prec)
// cout



// namespace std


// implementacja operatorów << i >>

// Wczytanie napisu, wczytanie pojedynczego znaku
// cin.get, cin.getline, noskipws
// cin.get(char &c)
// int n = cin.get();
// cin.getline(string, char separator)

// cin.unget();
// cin.putback();
// int n = cin.peek();

// separatory
//  - wczytanie napisu i ręczne przeglądanie,
//  - wczytanie napisu z getline do separatora

// sprawdzanie błędu, resetowanie stanu, ignorowanie wejścias
// cin.good()
//   - wszystko OK
// cin.eof()
//   - koniec pliku
// cin.bad()
//   - błąd operacji, raczej nie ma sensu powtarzać operacji, bo
//   - problem jest z samym strumieniem (np. plik został zamknięty)
// cin.fail()
//   - nieudana operacja, ale strumień jest ok,
//   - można czytać dalej
// cin.clear()


// cin.ignore(n = 1, int delim = EOF)
// #include <limits>
// numeric_limits<streamsize>::max()

// if (cin) 
// if (!cin)


// Koniec pliku (Ctrl-D, Ctrl-Z)

// argc, argv
// cstdlib - exit()
// cerr, przekierowania

#include <limits>
#include <cstdlib>
int main(int argc, char *argv[])
{
    // std::ofstream file;
    std::ofstream file("wynik.txt");
    // file.open("wynik.txt");
    file << 1 << " " << 2 << std::endl;
    file.close();
    
    std::ifstream fout("wynik.txt");
    int a;
    int b;
    fout >> a >> b;
    std::cout << a << " " << b << std::endl;

}