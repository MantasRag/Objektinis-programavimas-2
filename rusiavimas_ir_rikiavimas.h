#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "studentas.h"

void rikiavimo_budas(int &tipas, int &tvarka);
int dalijimo_budas();
int pasirinkti_strategija();

//  Template funkcijos rikiavimui ir grupavimui (kad veiktų ir su vector ir su list)
template <typename Container>
void rusiuoti_studentus(Container& Grupe, int skaiciavimo_metodas, int tipas, int tvarka) {
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentu vektorius tuscias.\n";
        return;
    }
    // Rikiavimas pagal tipą ir tvarką
    if (skaiciavimo_metodas == 1 || (skaiciavimo_metodas == 3 && tipas == 1)) {
        if (tvarka == 1)
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_vid < b.rez_vid; });
        else
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_vid > b.rez_vid; });
    } else {
        if (tvarka == 1)
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_med < b.rez_med; });
        else
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_med > b.rez_med; });
    }
}

// Funkcija ruosiuoti duomenis iš vektorių naudojanti std::sort
template <>
inline void rusiuoti_studentus<std::vector<Studentas>>(std::vector<Studentas>& Grupe, 
                                                        int skaiciavimo_metodas, int tipas, int tvarka) {
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentu vektorius tuscias.\n";
        return;
    }
    if (skaiciavimo_metodas == 1 || (skaiciavimo_metodas == 3 && tipas == 1)) {
        if (tvarka == 1)
            std::sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_vid < b.rez_vid; });
        else
            std::sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_vid > b.rez_vid; });
    } else {
        if (tvarka == 1)
            std::sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_med < b.rez_med; });
        else
            std::sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_med > b.rez_med; });
    }
}

// 1 startegija
// 
template <typename Container>
void padalinti_i_grupes_strategija1(const Container& Grupe, int tipas,
                        Container& maziau5, Container& daugiaulygu5) {
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (const auto& st : Grupe) {
        float rezultatas = (tipas == 1 ? st.rez_vid : st.rez_med);
        if (rezultatas < 5.0f)
            maziau5.push_back(st);
        else
            daugiaulygu5.push_back(st);
    }
    
    std::cout << "\n[STRATEGIJA 1] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    std::cout << "Studentu su < 5: " << maziau5.size() << std::endl;
    std::cout << "Studentu su >= 5: " << daugiaulygu5.size() << std::endl;
}

// 2 staretgija

// Bendras template paskelbimas
template <typename Container>
void padalinti_i_grupes_strategija2(Container& Grupe, int tipas,
                        Container& maziau5, Container& daugiaulygu5);

// Vektoriams
template <>
inline void padalinti_i_grupes_strategija2<std::vector<Studentas>>(
    std::vector<Studentas>& Grupe,
    int tipas,
    std::vector<Studentas>& maziau5,
    std::vector<Studentas>& daugiaulygu5) 
{
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (auto it = Grupe.begin(); it != Grupe.end(); ) {
        float rezultatas = (tipas == 1 ? it->rez_vid : it->rez_med);
        
        if (rezultatas < 5.0f) {
            maziau5.push_back(*it);
            it = Grupe.erase(it);
        } else {
            ++it;
        }
    }
    
    daugiaulygu5 = Grupe;
    
    std::cout << "\n[STRATEGIJA 2] Studentai suskirstyti i grupes pagal " 
              << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    std::cout << "Studentu su < 5: " << maziau5.size() << std::endl;
    std::cout << "Studentu su >= 5: " << daugiaulygu5.size() << std::endl;
}

