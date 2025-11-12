#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "studentas.h"

void rikiavimo_budas(int &tipas, int &tvarka);
int dalijimo_budas();
int pasirinkti_strategija(); // Funkcija strategijos pasirinkimui

// Helper funkcija, tikrina ar studentas yra vargšas (galutinis įvertinimas < 5)
inline bool ar_vargsiukas(const Studentas& st, int tipas) {
    float rezultatas = (tipas == 1 ? st.rez_vid : st.rez_med);
    return rezultatas < 5.0f;
}

//  Template funkcijos rikiavimui
template <typename Container>
void rusiuoti_studentus(Container& Grupe, int skaiciavimo_metodas, int tipas, int tvarka) {
    if (Grupe.empty()) {
        std::cout << "Klaida. Studentu vektorius tuscias.\n";
        return;
    }
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

// Specializacija vektoriui
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

// 1 STRATEGIJA - COPY+PASTE į du skirtingus failus
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

// 2 STRATEGIJA - Studentai iškerpami iš pradinio konteinerio ir perkeliami į naują
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

// List'ams
template <>
inline void padalinti_i_grupes_strategija2<std::list<Studentas>>(
    std::list<Studentas>& Grupe,
    int tipas,
    std::list<Studentas>& maziau5,
    std::list<Studentas>& daugiaulygu5) 
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

// 3 STRATEGIJA
// Vektoriui naudojama patobulinta pirma startegija
// List'ui naudojama patobulinta antra strategija
template <typename Container>
void padalinti_i_grupes_strategija3(Container& Grupe, int tipas,
                        Container& maziau5, Container& daugiaulygu5);

// Vektoriams
template <>
inline void padalinti_i_grupes_strategija3<std::vector<Studentas>>(
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

    auto riba = std::stable_partition(Grupe.begin(), Grupe.end(),
        [tipas](const Studentas& st) { return ar_vargsiukas(st, tipas); });
    
    maziau5.assign(Grupe.begin(), riba);
    daugiaulygu5.assign(riba, Grupe.end());
    
    std::cout << "\n[STRATEGIJA 3] Studentai suskirstyti i grupes pagal " 
              << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    std::cout << "Studentu su < 5: " << maziau5.size() << std::endl;
    std::cout << "Studentu su >= 5: " << daugiaulygu5.size() << std::endl;
}

