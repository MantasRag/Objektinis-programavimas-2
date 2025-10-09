#include "rusiuoti_studentus.h"  // Studentų rikiavimui
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

void rusiuoti_studentus(vector<Studentas>& Grupe, int skaiciavimo_metodas) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }
    cout << "\nPasirinkite rikiavimo tvarką (įvesti 1 arba 2):\n";
    cout << "1. Didėjančia tvarka (nuo mažiausio iki didžiausio)\n";
    cout << "2. Mažėjančia tvarka (nuo didžiausio iki mažiausio)\n";
    
    int tvarka;
    while (!(cin >> tvarka) || (tvarka != 1 && tvarka != 2)) {
        cout << "Klaida. Įveskite 1 arba 2\n";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Rikiavimas
    if (skaiciavimo_metodas == 1) {
        // Pagal vidurkį
        if (tvarka == 1)
            sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_vid < b.rez_vid; });
        else
            sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_vid > b.rez_vid; });
    } 
    else if (skaiciavimo_metodas == 2) {
        // Pagal medianą
        if (tvarka == 1)
            sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_med < b.rez_med; });
        else
            sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_med > b.rez_med; });
    } 
    else if (skaiciavimo_metodas == 3) { // Jei skaičiavimo metodas yra 3, tai vartotojas turi pasirinkti pagal ką rikiuoti (vidurkį ar medianą)
        int tipas;
        cout << "\nRikiuoti pagal:\n";
        cout << "1. Galutinį (vidurkis)\n";
        cout << "2. Galutinį (mediana)\n";
        cout << "Pasirinkimas: ";
        while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
            cout << "Klaida. Įveskite 1 arba 2\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Pasirinkimas: ";
        }

        if (tipas == 1) {
            if (tvarka == 1)
                sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_vid < b.rez_vid; });
            else
                sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_vid > b.rez_vid; });
        } else {
            if (tvarka == 1)
                sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_med < b.rez_med; });
            else
                sort(Grupe.begin(), Grupe.end(), [](const Studentas& a, const Studentas& b) { return a.rez_med > b.rez_med; });
        }
    }
    cout << "Studentai sėkmingai surikiuoti.\n\n";
}