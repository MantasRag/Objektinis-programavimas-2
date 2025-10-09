#include "ivesti_is_failo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void ivesti_is_failo(vector<Studentas>& Grupe, const string& failo_vardas) {
    std::ifstream fin(failo_vardas);
    if (!fin.is_open()) {
        cout << "Nepavyko atidaryti failo " << failo_vardas << "\n";
        return;
    }

    string eilute;
    Grupe.clear();
    Grupe.reserve(1000000);                     // Iš anksto rezervuoja vietą (spartesniam nuskaitymui)

    bool pirma_eilute = true;
    int kiek_stud = 0;

    while (std::getline(fin, eilute)) {
        if (pirma_eilute) { pirma_eilute = false; continue; }
        if (eilute.empty()) continue;

        Studentas st;
        st.paz.clear();

        const char* p = eilute.c_str();
        // Vardas
        while (*p == ' ') ++p;
        const char* q = p;
        while (*q && *q != ' ') ++q;
        st.vard.assign(p, q - p);

        // Pavardė
        p = q;
        while (*p == ' ') ++p;
        q = p;
        while (*q && *q != ' ') ++q;
        st.pav.assign(p, q - p);

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

        st.egzas = paz.back();
        paz.pop_back();
        st.paz = std::move(paz);

        st.rez_vid = 0.0f;
        st.rez_med = 0.0f;

        Grupe.push_back(std::move(st));
        ++kiek_stud;
    }

    fin.close();
    cout << "Failas nuskaitytas. Įkelta " << kiek_stud << " studentų.\n";
}