#include "rezultatai.h"
#include "studentas.h"
#include "pagalbines_funkcijos.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void spausdinti_rezultatus(const vector<Studentas>& Grupe, int skaiciavimo_metodas) {
    const vector<Studentas>& temp = Grupe;
    cout << "           STUDENTU REZULTATAI          \n";

    if (skaiciavimo_metodas == 1) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(15) << "Galutinis (vid.)"
             << endl;
        cout << string(50, '-') << endl;

        for (auto &st : temp)
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(15) << fixed << setprecision(2) << st.rez_vid
                 << endl;
    }
    else if (skaiciavimo_metodas == 2) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(15) << "Galutinis (med.)"
             << endl;
        cout << string(50, '-') << endl;

        for (auto &st : temp)
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(15) << fixed << setprecision(2) << st.rez_med
                 << endl;
    }
    else if (skaiciavimo_metodas == 3) {
        cout << left << setw(15) << "Vardas"
             << "| " << setw(15) << "Pavardė"
             << "| " << right << setw(15) << "Galutinis (vid.)"
             << " | " << setw(15) << "Galutinis (med.)"
             << endl;
        cout << string(70, '-') << endl;

        for (auto &st : temp)
            cout << left << setw(15) << st.vard
                 << "| " << setw(15) << st.pav
                 << "| " << right << setw(15) << fixed << setprecision(2) << st.rez_vid
                 << "  | " << setw(15) << fixed << setprecision(2) << st.rez_med
                 << endl;
    }
}