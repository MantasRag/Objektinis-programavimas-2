#pragma once
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>
#include "studentas.h"              // Studentų duomenų struktūrai
#include "pagalbines_funkcijos.h"   // Pagalbinėms funkcijoms

using std::vector;

template <typename Container>
void skaiciuoti_rezultatus(Container& Grupe, int skaiciavimo_metodas) {
    if (skaiciavimo_metodas == 1 || skaiciavimo_metodas == 3) {
        // Vidurkis
        for (auto &st : Grupe) {
            if (!st.paz.empty()) {
                int sum = 0;
                for (int nd : st.paz) sum += nd;
                st.rez_vid = st.egzas * 0.6f + (float(sum) / st.paz.size()) * 0.4f;
            }
        }
    }

    if (skaiciavimo_metodas == 2 || skaiciavimo_metodas == 3) {
        // Mediana
        for (auto &st : Grupe) {
            if (!st.paz.empty()) {
                float mediana = sk_mediana(st.paz);
                st.rez_med = st.egzas * 0.6f + mediana * 0.4f;
            }
        }
    }
}

void spausdinti_rezultatus(const std::vector<Studentas>& Grupe, int skaiciavimo_metodas);

// Nauja funkcija rankinio įvedimo rezultatams su atminties adresais
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
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(18) << fixed << setprecision(2) << st.rez_vid
                 << " | " << left << &st
                 << endl;
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
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(18) << fixed << setprecision(2) << st.rez_med
                 << " | " << left << &st
                 << endl;
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
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(18) << fixed << setprecision(2) << st.rez_vid
                 << "  | " << setw(18) << fixed << setprecision(2) << st.rez_med
                 << " | " << left << &st
                 << endl;
        }
    }
}