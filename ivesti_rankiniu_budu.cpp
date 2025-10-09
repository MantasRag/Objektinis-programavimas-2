#include "ivesti_rankiniu_budu.h"
#include <iostream>
#include <limits>       // std::numeric_limits
#include "ivesk.h"      // Studentų duomenų įvedimui

using namespace std;

void ivesti_rankiniu_budu(vector<Studentas>& Grupe) {
    int kiek;
    
    // Tikriname studentų skaičiaus įvedimą
    while (true) {
        cout << "\nKiek studentų yra grupėje? ";
        if (cin >> kiek && kiek > 0) {
            break;                                                          // Teisingas įvedimas
        } else {
            cout << "Klaida: studentų skaičius turi būti teigiamas skaičius! Įvesti dar kartą.\n";
            cin.clear();                                                    // Nuima failbit
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Išvalo blogą įvestį
        }
    }
    for (int j = 0; j < kiek; j++) {
        cout << "Įveskite " << j + 1 << " studentą:\n";
        Grupe.push_back(ivesk());
    }
}