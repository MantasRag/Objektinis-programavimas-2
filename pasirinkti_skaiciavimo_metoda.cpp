#include "pasirinkti_skaiciavimo_metoda.h"
#include <iostream>
#include <limits>       // std::numeric_limits

using namespace std;

int pasirinkti_skaiciavimo_metoda() {
    int metodas;
    cout << "========================================\n";
    cout << "Pasirinkite galutinio pažymio skaičiavimo metodą:\n";
    cout << "1. Naudoti vidurkį\n";
    cout << "2. Naudoti medianą\n";
    cout << "3. Rodyti abu (vidurkis ir mediana)\n";
    cout << "========================================\n";
    
    while (true) {
        cout << "Jūsų pasirinkimas (1-3): ";
        if (cin >> metodas && metodas >= 1 && metodas <= 3) {
            cout << "\n";
            return metodas;
        } else {
            cout << "Klaida: pasirinkite skaičių nuo 1 iki 3\n";
            cin.clear();                                                    // Nuima failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Išvalo blogą įvestį
        }
    }
}