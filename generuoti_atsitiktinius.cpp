#include "generuoti_atsitiktinius.h"
#include "mediana.h"
#include <iostream>
#include <limits>
#include <vector>
#include <random>

using namespace std;

void generuoti_atsitiktinius(vector<Studentas>& Grupe) {
    int stud_skaicius, nd_skaicius;
    
    // Atsitiktinių skaičių generatoriaus nustatymas
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys_dis(1, 10);   // Pažymių diapazonas nuo 1 iki 10
    
    // Studentų skaičiaus įvedimas
    while (true) {
        cout << "\nKiek studentų generuoti? ";
        if (cin >> stud_skaicius && stud_skaicius > 0) {
            break;
        } else {
            cout << "Klaida: studentų skaičius turi būti teigiamas skaičius! Įveskite dar kartą.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Namų darbų skaičiaus įvedimas
    while (true) {
        cout << "Kiek namų darbų pažymių generuoti kiekvienam studentui? ";
        if (cin >> nd_skaicius && nd_skaicius > 0) {
            break;
        } else {
            cout << "Klaida: namų darbų skaičius turi būti teigiamas skaičius! Įveskite dar kartą.\n";
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
    cout << "Sukurta studentų: " << stud_skaicius << endl;
}