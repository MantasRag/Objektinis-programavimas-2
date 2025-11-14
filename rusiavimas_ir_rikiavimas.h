#pragma once
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include "studentas.h"

using namespace std;

void rikiavimo_budas(int &tipas, int &tvarka);
int dalijimo_budas();
int pasirinkti_strategija();

template <typename Container>
void rusiuoti_studentus(Container& Grupe, int skaiciavimo_metodas, int tipas, int tvarka);

template <typename Container>
void padalinti_i_grupes_strategija1(const Container& Grupe, int tipas,
                                    Container& maziau5, Container& daugiaulygu5);

template <typename Container>
void padalinti_i_grupes_strategija2(Container& Grupe, int tipas,
                                    Container& maziau5, Container& daugiaulygu5);

template <typename Container>
void padalinti_i_grupes_strategija3(Container& Grupe, int tipas,
                                    Container& maziau5, Container& daugiaulygu5);

// Template implementacijos
template <typename Container>
void rusiuoti_studentus(Container& Grupe, int skaiciavimo_metodas, int tipas, int tvarka) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentu vektorius tuscias.\n";
        return;
    }
    if (skaiciavimo_metodas == 1 || (skaiciavimo_metodas == 3 && tipas == 1)) {
        if (tvarka == 1)
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_vid() < b.rez_vid(); });
        else
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_vid() > b.rez_vid(); });
    } else {
        if (tvarka == 1)
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_med() < b.rez_med(); });
        else
            Grupe.sort([](const Studentas& a, const Studentas& b) { return a.rez_med() > b.rez_med(); });
    }
}

// Specializacija vektoriui
template <>
inline void rusiuoti_studentus<vector<Studentas>>(vector<Studentas>& Grupe, 
                                                  int skaiciavimo_metodas, int tipas, int tvarka) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentu vektorius tuscias.\n";
        return;
    }
    if (skaiciavimo_metodas == 1 || (skaiciavimo_metodas == 3 && tipas == 1)) {
        if (tvarka == 1)
            sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_vid() < b.rez_vid(); });
        else
            sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_vid() > b.rez_vid(); });
    } else {
        if (tvarka == 1)
            sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_med() < b.rez_med(); });
        else
            sort(Grupe.begin(), Grupe.end(),
                 [](const Studentas& a, const Studentas& b) { return a.rez_med() > b.rez_med(); });
    }
}

// STRATEGIJA 1
template <typename Container>
void padalinti_i_grupes_strategija1(const Container& Grupe, int tipas,
                                    Container& maziau5, Container& daugiaulygu5) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (const auto& st : Grupe) {
        float rezultatas = (tipas == 1 ? st.rez_vid() : st.rez_med());
        if (rezultatas < 5.0f)
            maziau5.push_back(st);
        else
            daugiaulygu5.push_back(st);
    }
    
    cout << "\n[STRATEGIJA 1] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentu su < 5: " << maziau5.size() << endl;
    cout << "Studentu su >= 5: " << daugiaulygu5.size() << endl;
}

// STRATEGIJA 2 - Vektoriams
template <>
inline void padalinti_i_grupes_strategija2<vector<Studentas>>(
    vector<Studentas>& Grupe,
    int tipas,
    vector<Studentas>& maziau5,
    vector<Studentas>& daugiaulygu5) 
{
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (auto it = Grupe.begin(); it != Grupe.end(); ) {
        float rezultatas = (tipas == 1 ? it->rez_vid() : it->rez_med());
        
        if (rezultatas < 5.0f) {
            maziau5.push_back(*it);
            it = Grupe.erase(it);
        } else {
            ++it;
        }
    }
    
    daugiaulygu5 = Grupe;
    
    cout << "\n[STRATEGIJA 2] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentu su < 5: " << maziau5.size() << endl;
    cout << "Studentu su >= 5: " << daugiaulygu5.size() << endl;
}

// STRATEGIJA 2 - List'ams
template <>
inline void padalinti_i_grupes_strategija2<list<Studentas>>(
    list<Studentas>& Grupe,
    int tipas,
    list<Studentas>& maziau5,
    list<Studentas>& daugiaulygu5) 
{
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (auto it = Grupe.begin(); it != Grupe.end(); ) {
        float rezultatas = (tipas == 1 ? it->rez_vid() : it->rez_med());
        
        if (rezultatas < 5.0f) {
            maziau5.push_back(*it);
            it = Grupe.erase(it);
        } else {
            ++it;
        }
    }
    
    daugiaulygu5 = Grupe;
    
    cout << "\n[STRATEGIJA 2] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentu su < 5: " << maziau5.size() << endl;
    cout << "Studentu su >= 5: " << daugiaulygu5.size() << endl;
}

// STRATEGIJA 3 - Vektoriams
template <>
inline void padalinti_i_grupes_strategija3<vector<Studentas>>(
    vector<Studentas>& Grupe,
    int tipas,
    vector<Studentas>& maziau5,
    vector<Studentas>& daugiaulygu5) 
{
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    auto riba = stable_partition(Grupe.begin(), Grupe.end(),
        [tipas](const Studentas& st) { 
            float rezultatas = (tipas == 1 ? st.rez_vid() : st.rez_med());
            return rezultatas < 5.0f;
        });
    
    maziau5.assign(Grupe.begin(), riba);
    daugiaulygu5.assign(riba, Grupe.end());
    
    cout << "\n[STRATEGIJA 3] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentu su < 5: " << maziau5.size() << endl;
    cout << "Studentu su >= 5: " << daugiaulygu5.size() << endl;
}

// STRATEGIJA 3 - List'ams
template <>
inline void padalinti_i_grupes_strategija3<list<Studentas>>(
    list<Studentas>& Grupe,
    int tipas,
    list<Studentas>& maziau5,
    list<Studentas>& daugiaulygu5) 
{
    if (Grupe.empty()) {
        cout << "Klaida. Studentu sarasas tuscias.\n";
        return;
    }

    maziau5.clear();
    daugiaulygu5.clear();

    auto it = Grupe.begin();
    while (it != Grupe.end()) {
        float rezultatas = (tipas == 1 ? it->rez_vid() : it->rez_med());
        
        if (rezultatas < 5.0f) {
            auto current = it++;
            maziau5.splice(maziau5.end(), Grupe, current);
        } else {
            ++it;
        }
    }
    
    daugiaulygu5.splice(daugiaulygu5.end(), Grupe);
    
    cout << "\n[STRATEGIJA 3] Studentai suskirstyti i grupes pagal " 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentu su < 5: " << maziau5.size() << endl;
    cout << "Studentu su >= 5: " << daugiaulygu5.size() << endl;
}