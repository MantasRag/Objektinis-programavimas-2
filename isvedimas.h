#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "studentas.h"

template <typename Container>
void issaugoti_i_txt(const Container& Grupe, const std::string& txt_pavadinimas, 
                     int skaiciavimo_metodas) {
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentu vektorius yra tuscias.\n";
        return;
    }

    std::string failo_vardas = txt_pavadinimas + ".txt";
    std::ofstream fout(failo_vardas);

    if (!fout) {
        std::cout << "Klaida. Nesukurtas failas '" << failo_vardas << "'\n";
        return;
    }

    if (skaiciavimo_metodas==1) {
        fout << std::left << std::setw(15) << "Vardas" 
             << std::setw(15) << "Pavarde" 
             << std::setw(20) << "Galutinis (vid.)" << "\n";

        for (const auto& st : Grupe) {
            fout << std::left << std::setw(15) << st.vard
                 << std::setw(15) << st.pav
                 << std::setw(20) << std::fixed << std::setprecision(2) << st.rez_vid << "\n";
        }
    } else if (skaiciavimo_metodas==2) {
        fout << std::left << std::setw(15) << "Vardas" 
             << std::setw(15) << "Pavarde" 
             << std::setw(20) << "Galutinis (med.)" << "\n";

        for (const auto& st : Grupe) {
            fout << std::left << std::setw(15) << st.vard
                 << std::setw(15) << st.pav
                 << std::setw(20) << std::fixed << std::setprecision(2) << st.rez_med << "\n";
        }
    } else if (skaiciavimo_metodas==3) {
        fout << std::left << std::setw(15) << "Vardas" 
             << std::setw(15) << "Pavarde"
             << std::setw(20) << "Galutinis (vid.)" 
             << std::setw(20) << "Galutinis (med.)" << "\n";

        for (const auto& st : Grupe) {
            fout << std::left << std::setw(15) << st.vard
                 << std::setw(15) << st.pav
                 << std::setw(20) << std::fixed << std::setprecision(2) << st.rez_vid
                 << std::setw(20) << std::fixed << std::setprecision(2) << st.rez_med << "\n";
        }
    }

    fout.close();
    std::cout << "Duomenys irasyti i: '" << failo_vardas << "'\n";
}