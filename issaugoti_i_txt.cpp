#include "issaugoti_i_txt.h"
#include "studentas.h"          // Studentų duomenų struktūrai
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void issaugoti_i_txt(const std::vector<Studentas>& Grupe, const std::string& txt_pavadinimas, int skaiciavimo_metodas) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius yra tuščias.\n";
        return;
    }

    string failo_vardas = txt_pavadinimas + ".txt";
    ofstream fout(failo_vardas);

    if (!fout) {
        cout << "Klaida. Nesukurtas failas '" << failo_vardas << "'\n";
        return;
    }

    if (skaiciavimo_metodas==1) {
        fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (vid.)" << "\n";

        for (const auto& st : Grupe) {
            fout << left << setw(15) << st.vard
                 << setw(15) << st.pav
                 << setw(20) << fixed << setprecision(2) << st.rez_vid << "\n";
        }
    } else if (skaiciavimo_metodas==2) {
        fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (med.)" << "\n";

        for (const auto& st : Grupe) {
            fout << left << setw(15) << st.vard
                 << setw(15) << st.pav
                 << setw(20) << fixed << setprecision(2) << st.rez_med << "\n";
        }
    } else if (skaiciavimo_metodas==3) {
        // Antraštė
        fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde"
             << setw(20) << "Galutinis (vid.)" << setw(20) << "Galutinis (med.)" << "\n";

        // Studentai
        for (const auto& st : Grupe) {
            fout << left << setw(15) << st.vard
                 << setw(15) << st.pav
                 << setw(20) << fixed << setprecision(2) << st.rez_vid
                 << setw(20) << fixed << setprecision(2) << st.rez_med << "\n";
        }
    }

    fout.close();
    cout << "Duomenys įrašyti į failą '" << failo_vardas << "'\n";
}