#include "rezultatai.h"
#include "studentas.h"
#include "pagalbines_funkcijos.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// Spausdina rezultatus be atmintės adresų (tik vektoriams)
void spausdinti_rezultatus(const vector<Studentas>& Grupe, int skaiciavimo_metodas) {
    cout << "           STUDENTU REZULTATAI          \n";

    if (skaiciavimo_metodas == 1) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(18) << "Galutinis (vid.)"
             << endl;
        cout << string(52, '-') << endl;

        // Naudojame išvesties operatorių
        for (const auto &st : Grupe) {
            cout << st << endl;
        }
    }
    else if (skaiciavimo_metodas == 2) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(18) << "Galutinis (med.)"
             << endl;
        cout << string(52, '-') << endl;

        // Naudojame išvesties operatorių
        for (const auto &st : Grupe) {
            cout << st << endl;
        }
    }
    else if (skaiciavimo_metodas == 3) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(18) << "Galutinis (vid.)"
             << " | " << setw(18) << "Galutinis (med.)"
             << endl;
        cout << string(72, '-') << endl;

        // Naudojame išvesties operatorių
        for (const auto &st : Grupe) {
            cout << st << endl;
        }
    }
}