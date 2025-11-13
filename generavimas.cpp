#include "generavimas.h"
#include "pagalbines_funkcijos.h"
#include <iostream>
#include <limits>
#include <vector>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int kiek_generuoti() {
                int nd_skaicius;
                while (true) {
                    cout << "\nKiek namu darbu pazymiu generuoti kiekvienam studentui? ";
                    if (cin >> nd_skaicius && nd_skaicius > 0) {
                        return nd_skaicius;
                    } else {
                        cout << "Klaida: iveskite teigiama skaicių\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    }
                }

void generuoti_atsitiktinius(vector<Studentas>& Grupe) {
    int stud_skaicius, nd_skaicius;
    
    // Atsitiktinių skaičių generatoriaus nustatymas
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys_dis(1, 10);   // Pažymių diapazonas nuo 1 iki 10
    
    // Studentų skaičiaus įvedimas
    while (true) {
        cout << "\nKiek studentu generuoti? ";
        if (cin >> stud_skaicius && stud_skaicius > 0) {
            break;
        } else {
            cout << "Klaida: studentu skaicius turi buti teigiamas skaičics. Iveskite dar karta.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Namų darbų skaičiaus įvedimas
    while (true) {
        cout << "Kiek namu darbu pazymiu generuoti kiekvienam studentui? ";
        if (cin >> nd_skaicius && nd_skaicius > 0) {
            break;
        } else {
            cout << "Klaida: namu darbu skaicius turi buti teigiamas skaicius. Iveskite dar karta.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Studentų duomenų generavimas
    for (int i = 0; i < stud_skaicius; i++) {
        Studentas st;
        st.vard = "Vardas" + std::to_string(i + 1);
        st.pav = "Pavarde" + std::to_string(i + 1);
        
        // Namų darbų pažymių generavimas
        int sum = 0;
        st.paz.clear();
        for (int j = 0; j < nd_skaicius; j++) {
            int pazymys = pazymys_dis(gen);
            st.paz.push_back(pazymys);
            sum += pazymys;
        }
        
        st.egzas = pazymys_dis(gen);    // Egzamino pažymio generavimas
        Grupe.push_back(st);
    }
    cout << "Sukurta studentu: " << stud_skaicius << endl;
}

void generuoti_i_txt(int stud_skaicius, int nd_skaicius) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys_dis(1, 10);

    string failo_vardas = "stud" + to_string(stud_skaicius) + ".txt";
    ofstream fout(failo_vardas);

    if (!fout) {
        cout << "Klaida: nepavyko sukurti failo '" << failo_vardas << "'!\n";
        return;
    }

    fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
    for (int i = 1; i <= nd_skaicius; i++) {
        fout << setw(5) << ("ND" + to_string(i));
    }
    fout << setw(5) << "Egz." << "\n";

    for (int i = 1; i <= stud_skaicius; i++) {
        fout << left << setw(15) << ("Vardas" + to_string(i))
             << setw(15) << ("Pavarde" + to_string(i));

        for (int j = 0; j < nd_skaicius; j++) {
            fout << setw(5) << pazymys_dis(gen);
        }

        fout << setw(5) << pazymys_dis(gen) << "\n";
    }

    fout.close();
    cout << "Failas '" << failo_vardas << "' sukurtas (" 
         << stud_skaicius << " studentu, po " << nd_skaicius << " pazymius)\n";
}