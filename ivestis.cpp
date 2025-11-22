#include "ivestis.h"
#include "pagalbines_funkcijos.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

Studentas ivesk() {
    Studentas Laik;
    
    // Naudojamas įvesties operatorius
    cin >> Laik; 
    return Laik;
}

int pasirinkti_konteinerio_tipa() {
    int tipas;
    cout << "\nKonteinerio tipas:\n";
    cout << "1. Vector\n";
    cout << "2. List\n";
    cout << "Renkamasi: ";
    
    while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
        cout << "Klaida. Ivesti 1 arba 2\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Renkamasi: ";
    }
    return tipas;
}

void ivesti_is_failo(vector<Studentas>& Grupe, const string& failo_vardas) {
    std::ifstream fin(failo_vardas);
    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo " << failo_vardas << "\n";
        return;
    }

    string eilute;
    Grupe.clear();
    Grupe.reserve(1000000);

    bool pirma_eilute = true;
    int kiek_stud = 0;

    while (std::getline(fin, eilute)) {
        if (pirma_eilute) { pirma_eilute = false; continue; }
        if (eilute.empty()) continue;

        Studentas st;

        const char* p = eilute.c_str();
        // Vardas
        while (*p == ' ') ++p;
        const char* q = p;
        while (*q && *q != ' ') ++q;
        st.setVard(string(p, q - p));

        // Pavardė
        p = q;
        while (*p == ' ') ++p;
        q = p;
        while (*q && *q != ' ') ++q;
        st.setPav(string(p, q - p));

        // Pažymiai
        p = q;
        int val = 0;
        bool skaitomas = false;
        vector<int> paz;

        for (; *p; ++p) {
            if (*p >= '0' && *p <= '9') {
                val = val * 10 + (*p - '0');
                skaitomas = true;
            } else if (skaitomas) {
                paz.push_back(val);
                val = 0;
                skaitomas = false;
            }
        }
        if (skaitomas) paz.push_back(val);

        if (paz.empty()) continue;

        st.setEgzas(paz.back());
        paz.pop_back();
        
        for (int p : paz) {
            st.addPazymys(p);
        }

        Grupe.push_back(std::move(st));
        ++kiek_stud;
    }

    fin.close();
    cout << "Ikelta " << kiek_stud << " studentu.\n";
}