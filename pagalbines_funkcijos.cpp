#include "pagalbines_funkcijos.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

using namespace std;

void arTestiDarba() {
    char testi;
    cout << "\nAr norite testi darba su programa? (t/n): ";
    cin >> testi;
    if (testi == 'n' || testi == 'N') {
        cout << "Programa baigiama.\n";
        exit(0);
    }
    cout << "\n";
}

float sk_mediana(std::vector<int> paz) {
    std::sort(paz.begin(), paz.end());
    int n = paz.size();
    if (n % 2 == 0) {
        return (paz[n/2 - 1] + paz[n/2]) / 2.0;
    } else {
        return paz[n/2];
    }
}

void rodyti_menu() {
    cout << "-----------------------------------------\n";
    cout << "Funkciju meniu:\n";
    cout << "1. Ivesti studentu rezultatus rankiniu budu\n";
    cout << "2. Ivesti studentu rezultatus is txt failo\n";
    cout << "3. Studentu rezultatus generuoti atsitiktinius\n";
    cout << "4. Generuoti testavimo failus (5 failai)\n";
    cout << "5. Testuoti konteinerius (vector ir list)\n";
    cout << "6. Iseiti is programos\n";
    cout << "-----------------------------------------\n";
}

int pasirinkti_skaiciavimo_metoda() {
    int metodas;
    cout << "Pasirinkite galutinio pazymio skaiciavimo metoda:\n";
    cout << "1. Naudoti vidurki\n";
    cout << "2. Naudoti mediana\n";
    cout << "3. Rodyti abu (vidurkis ir mediana)\n";
    
    while (true) {
        cout << "Jusu pasirinkimas (1-3): ";
        if (cin >> metodas && metodas >= 1 && metodas <= 3) {
            cout << "\n";
            return metodas;
        } else {
            cout << "Klaida: pasirinkite skaiciu nuo 1 iki 3\n";
            cin.clear();                                                    // Nuima failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Išvalo blogą įvestį
        }
    }
}