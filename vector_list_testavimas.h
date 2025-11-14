#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <chrono>
#include "studentas.h"
#include "ivestis.h"
#include "rezultatai.h"
#include "rusiavimas_ir_rikiavimas.h"
#include "isvedimas.h"

using namespace std;
using namespace std::chrono;

template <typename Container>
void testuoti(const vector<string>& failai, const vector<int>& irasu_skaicius, 
              int skaiciavimo_metodas, const string& konteinerio_tipas, int strategija);

void testuoti_konteinerius(int skaiciavimo_metodas);

// Template implementacija
template <typename Container>
void testuoti(const vector<string>& failai, const vector<int>& irasu_skaicius, 
              int skaiciavimo_metodas, const string& konteinerio_tipas, int strategija) {
    cout << "\nTESTUOJAMAS KONTEINERIS: " << konteinerio_tipas << "\n";
    cout << "STRATEGIJA: " << strategija << "\n\n";
    int tipas1 = 1, tvarka = 1, tipas2 = 1;

    for (size_t i = 0; i < failai.size(); i++) {
        Container Grupe;
        Container maziau5;
        Container daugiaulygu5;

        cout << "Failas su " << irasu_skaicius[i] << " irasais\n";

        // NUSKAITYMAS
        auto start_ivedimas = high_resolution_clock::now();
        vector<Studentas> tempVector;
        ivesti_is_failo(tempVector, failai[i]);
        Grupe.insert(Grupe.end(), tempVector.begin(), tempVector.end());
        auto end_ivedimas = high_resolution_clock::now();

        // SKAIČIAVIMAS
        auto start_skaiciavimas = high_resolution_clock::now();
        skaiciuoti_rezultatus(Grupe, skaiciavimo_metodas);
        auto end_skaiciavimas = high_resolution_clock::now();

        // RIKIAVIMAS
        auto start_rikiavimas = high_resolution_clock::now();
        rusiuoti_studentus(Grupe, skaiciavimo_metodas, tipas1, tvarka);
        auto end_rikiavimas = high_resolution_clock::now();

        // PADALINIMAS pagal strategiją
        auto start_padalinimas = high_resolution_clock::now();
        if (strategija == 1) {
            const Container& GrupeConst = Grupe;
            padalinti_i_grupes_strategija1(GrupeConst, tipas2, maziau5, daugiaulygu5);
        } else if (strategija == 2) {
            padalinti_i_grupes_strategija2(Grupe, tipas2, maziau5, daugiaulygu5);
        } else if (strategija == 3) {
            padalinti_i_grupes_strategija3(Grupe, tipas2, maziau5, daugiaulygu5);
        }
        auto end_padalinimas = high_resolution_clock::now();

        // IŠSAUGOJIMAS
        auto start_issaug = high_resolution_clock::now();
        issaugoti_i_txt(maziau5, 
            "Maziau5_" + to_string(irasu_skaicius[i]) + "_" + konteinerio_tipas + "_s" + to_string(strategija), 
            skaiciavimo_metodas);
        auto end_issaug = high_resolution_clock::now();

        auto start_issaug2 = high_resolution_clock::now();
        issaugoti_i_txt(daugiaulygu5, 
            "Daugiau5_" + to_string(irasu_skaicius[i]) + "_" + konteinerio_tipas + "_s" + to_string(strategija), 
            skaiciavimo_metodas);
        auto end_issaug2 = high_resolution_clock::now();

        // REZULTATAI
        double t_ivedimas = duration_cast<milliseconds>(end_ivedimas - start_ivedimas).count() / 1000.0;
        double t_skaiciavimas = duration_cast<milliseconds>(end_skaiciavimas - start_skaiciavimas).count() / 1000.0;
        double t_rikiavimas = duration_cast<milliseconds>(end_rikiavimas - start_rikiavimas).count() / 1000.0;
        double t_padal = duration_cast<milliseconds>(end_padalinimas - start_padalinimas).count() / 1000.0;
        double t_isv1 = duration_cast<milliseconds>(end_issaug - start_issaug).count() / 1000.0;
        double t_isv2 = duration_cast<milliseconds>(end_issaug2 - start_issaug2).count() / 1000.0;
        double bendras = t_ivedimas + t_skaiciavimas + t_rikiavimas + t_padal + t_isv1 + t_isv2;

        cout << fixed << setprecision(3)
             << "Nuskaitymas: " << t_ivedimas << " s\n"
             << "Skaiciavimas: " << t_skaiciavimas << " s\n"
             << "Rikiavimas: " << t_rikiavimas << " s\n"
             << "Padalinimas: " << t_padal << " s\n"
             << "Isvedimas (< 5): " << t_isv1 << " s\n"
             << "Isvedimas (>= 5): " << t_isv2 << " s\n"
             << "BENDRAS LAIKAS: " << bendras << " s\n\n";
    }
}