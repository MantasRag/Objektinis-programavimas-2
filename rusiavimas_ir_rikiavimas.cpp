#include "rusiavimas_ir_rikiavimas.h"
#include <iostream>
#include <limits>

using namespace std;

void rikiavimo_budas(int &tipas, int &tvarka) {
    cout << "\nRikiuoti pagal:\n";
    cout << "1. Galutini (vidurkis)\n";
    cout << "2. Galutini (mediana)\n";
    cout << "Pasirinkimas: ";
    while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
        cout << "Klaida. Iveskite 1 arba 2\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Pasirinkimas: ";
    }

    cout << "\nPasirinkite rikiavimo tvarka:\n";
    cout << "1. Didejimo tvarka\n";
    cout << "2. Mazejimo tvarka\n";
    while (!(cin >> tvarka) || (tvarka != 1 && tvarka != 2)) {
        cout << "Klaida. Iveskite 1 arba 2\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int dalijimo_budas() {
    int tipas;
    cout << "\nDalinti pagal:\n";
    cout << "1. Galutini (vidurkis)\n";
    cout << "2. Galutini (mediana)\n";

    while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
        cout << "Klaida. Iveskite 1 arba 2\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return tipas;
}

int pasirinkti_strategija() {
    int strategija;
    cout << "\nPASIRINKITE STRATEGIJA\n";
    cout << "1. STRATEGIJA 1 - Kopijuojami iš pagrindinio į du kitus konteinerius (Copy+Paste)\n\n";
    cout << "2. STRATEGIJA 2 - Iskerpama is pagrindinio i nauja konteineri (Cut+Paste)\n\n";
    cout << "Pasirinkite strategija (1 arba 2): ";
    
    while (!(cin >> strategija) || (strategija != 1 && strategija != 2)) {
        cout << "Klaida. Iveskite 1 arba 2: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    return strategija;
}