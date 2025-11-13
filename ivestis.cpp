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
    int sum = 0;
    cout<<"Įveskite studento vardą: "; 
    cin>>Laik.vard;
    cout<<"Įveskite studento pavardę: "; 
    cin>>Laik.pav;
    cin.ignore(); // išvalome naują eilutės simbolį po pavardės įvedimo
    cout << "Įveskite namų darbų pažymius (1-10). Norėdami baigti, spauskite ENTER tuščiai eilutei:\n";
    string line;
    int pazymys_num = 1;
    
    while (true) {
        cout << "Įveskite " << pazymys_num << " pažymį (arba ENTER jei baigėte): ";
        getline(cin, line);
        
        // Jei įvesta tuščia eilutė, baigiame pažymių įvedimą
        if (line.empty()) {
            if (Laik.paz.empty()) {
                cout << "Klaida: reikia įvesti bent vieną pažymį!\n";
                continue;
            }
            break;
        }
        
        istringstream iss(line);
        int pazymys;
        
        if (iss >> pazymys && iss.eof()) {              // Patikriname ar visas string'as buvo skaičius
            if (pazymys >= 1 && pazymys <= 10) {
                Laik.paz.push_back(pazymys);
                sum += pazymys;
                pazymys_num++;
            } else {
                cout << "Klaida: pažymys turi būti nuo 1 iki 10. Įveskite dar kartą.\n";
            }
        } else {
            cout << "Klaida: įveskite teisingą skaičių (1-10) arba ENTER jei baigėte.\n";
        }
    }
    
    // Egzamino įvedimas
    do {
        cout<<"Iveskite egzamino rezultata (1-10): ";
        cin>>Laik.egzas;
        if (Laik.egzas < 1 || Laik.egzas > 10) {
            cout<<"Klaida: egzamino ivertinimas turi būti nuo 1 iki 10. Ivertinima ivesti dar karta.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (Laik.egzas < 1 || Laik.egzas > 10);
    
    float mediana = sk_mediana(Laik.paz);
    
    Laik.rez_vid = Laik.egzas * 0.6 + double(sum) / double(Laik.paz.size()) * 0.4;
    Laik.rez_med = Laik.egzas * 0.6 + mediana * 0.4;
    
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
    cout << "Ikelta " << kiek_stud << " studentu.\n";
}