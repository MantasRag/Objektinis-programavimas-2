#include "generuoti_i_txt.h"
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <iostream>
#include <random>

using namespace std;


void generuoti_i_txt() {
    int nd_skaicius;

    // Namų darbų skaičiaus įvedimas
    while (true) {
        cout << "\nKiek namų darbų pažymių generuoti kiekvienam studentui? ";
        if (cin >> nd_skaicius && nd_skaicius > 0) {
            break;
        } else {
            cout << "Klaida: namų darbų skaičius turi būti teigiamas skaičius! Įveskite dar kartą.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Studentų kiekiai kiekvienam failui
    vector<int> studentu_kiekiai = {1000, 10000, 100000, 1000000, 10000000};
    
    // Atsitiktinių skaičių generatoriaus nustatymas
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> pazymys_dis(1, 10);
    
    cout << "\nGeneruojami failai\n";
    
    // Generuojame kiekvieną failą
    for (int stud_skaicius : studentu_kiekiai) {
        string failo_vardas = "stud" + to_string(stud_skaicius) + ".txt";
        ofstream fout(failo_vardas);
        
        if (!fout) {
            cout << "Klaida: nepavyko sukurti failo '" << failo_vardas << "'!\n";
            continue;
        }
        
        // Įrašome antraštę
        fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde";
        for (int i = 1; i <= nd_skaicius; i++) {
            fout << setw(5) << ("ND" + to_string(i));
        }
        fout << setw(5) << "Egz." << "\n";
        
        // Generuojami studentai ir jų pažymiai
        for (int i = 1; i <= stud_skaicius; i++) {                  // Vardas, pavardė
            fout << left << setw(15) << ("Vardas" + to_string(i))
                 << setw(15) << ("Pavarde" + to_string(i));
            
            for (int j = 0; j < nd_skaicius; j++) {                 // Namų darbų pažymiai
                fout << setw(5) << pazymys_dis(gen);
            }

            fout << setw(5) << pazymys_dis(gen) << "\n";            // Egzamino įvertinimas
        }
        
        fout.close();
        cout << "Failas '" << failo_vardas << "' sukurtas (" << stud_skaicius << " studentų)\n";
    }
    
    cout << "\nVisi failai sukurti.\n";
}