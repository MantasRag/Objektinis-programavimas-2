#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "studentas.h"
#include "pagalbines_funkcijos.h"

using std::vector;

template <typename Container>
void skaiciuoti_rezultatus(Container& Grupe, int skaiciavimo_metodas);

void spausdinti_rezultatus(const std::vector<Studentas>& Grupe, int skaiciavimo_metodas);

template <typename Container>
void spausdinti_rezultatus1(const Container& Grupe, int skaiciavimo_metodas);

// Skaičiuoja rezultatus visiems studentams konteinyje
template <typename Container>
void skaiciuoti_rezultatus(Container& Grupe, int skaiciavimo_metodas) {
    for (auto &st : Grupe) {
        if (!st.paz().empty()) {
            std::vector<int> paz_copy = st.paz();
            float mediana = sk_mediana(paz_copy);
            st.skaiciuotiRezultatus(skaiciavimo_metodas, mediana);
        }
    }
}

// Spausdina rezultatus su atmintės adresais (template - veikia su vector ir list)
template <typename Container>
void spausdinti_rezultatus1(const Container& Grupe, int skaiciavimo_metodas) {
    using namespace std;
    
    cout << "           STUDENTU REZULTATAI          \n";

    if (skaiciavimo_metodas == 1) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavarde"
             << "| " << right << setw(18) << "Galutinis (vid.)"
             << " | " << left << setw(20) << "Atminties adresas"
             << endl;
        cout << string(85, '-') << endl;

        for (const auto &st : Grupe) {
            cout << st << " | " << &st << endl;
        }
    }
    else if (skaiciavimo_metodas == 2) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavarde"
             << "| " << right << setw(18) << "Galutinis (med.)"
             << " | " << left << setw(20) << "Atminties adresas"
             << endl;
        cout << string(85, '-') << endl;

        for (const auto &st : Grupe) {
            cout << st << " | " << &st << endl;
        }
    }
    else if (skaiciavimo_metodas == 3) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavarde"
             << "| " << right << setw(18) << "Galutinis (vid.)"
             << " | " << setw(18) << "Galutinis (med.)"
             << " | " << left << setw(20) << "Atminties adresas"
             << endl;
        cout << string(105, '-') << endl;

        for (const auto &st : Grupe) {
            cout << st << " | " << &st << endl;
        }
    }
}