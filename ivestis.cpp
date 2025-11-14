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
    
    string vardas, pavarde;
    cout << "Įveskite studento vardą: "; 
    cin >> vardas;
    Laik.setVard(vardas);
    
    cout << "Įveskite studento pavardę: "; 
    cin >> pavarde;
    Laik.setPav(pavarde);
    
    cin.ignore();
    
    cout << "Įveskite namų darbų pažymius (1-10). Norėdami baigti, spauskite ENTER tuščiai eilutei:\n";
    string line;
    int pazymys_num = 1;
    
    while (true) {
        cout << "Įveskite " << pazymys_num << " pažymį (arba ENTER jei baigėte): ";
        getline(cin, line);
        
        if (line.empty()) {
            if (Laik.paz().empty()) {
                cout << "Klaida: reikia įvesti bent vieną pažymį!\n";
                continue;
            }
            break;
        }
        
        istringstream iss(line);
        int pazymys;
        
        if (iss >> pazymys && iss.eof()) {
            if (pazymys >= 1 && pazymys <= 10) {
                Laik.addPazymys(pazymys);
                pazymys_num++;
            } else {
                cout << "Klaida: pažymys turi būti nuo 1 iki 10. Įveskite dar kartą.\n";
            }
        } else {
            cout << "Klaida: įveskite teisingą skaičių (1-10) arba ENTER jei baigėte.\n";
        }
    }
    
    int egzaminas;
    do {
        cout << "Iveskite egzamino rezultata (1-10): ";
        cin >> egzaminas;
        if (egzaminas < 1 || egzaminas > 10) {
            cout << "Klaida: egzamino ivertinimas turi būti nuo 1 iki 10. Ivertinima ivesti dar karta.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (egzaminas < 1 || egzaminas > 10);
    
    Laik.setEgzas(egzaminas);
    
    // Skaičiuojame rezultatus
    std::vector<int> paz_copy = Laik.paz();
    float mediana = sk_mediana(paz_copy);
    
    int sum = 0;
    for (int nd : Laik.paz()) sum += nd;
    float rez_vid = egzaminas * 0.6f + float(sum) / Laik.paz().size() * 0.4f;
    float rez_med = egzaminas * 0.6f + mediana * 0.4f;
    
    Laik.setRezVid(rez_vid);
    Laik.setRezMed(rez_med);
    
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