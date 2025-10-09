#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include "ivesk.h"
#include "mediana.h"

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
                cout << "Klaida: pažymys turi būti nuo 1 iki 10! Įveskite dar kartą.\n";
            }
        } else {
            cout << "Klaida: įveskite teisingą skaičių (1-10) arba ENTER jei baigėte.\n";
        }
    }
    
    // Egzamino įvedimas
    do {
        cout<<"Įveskite egzamino rezultatą (1-10): ";
        cin>>Laik.egzas;
        if (Laik.egzas < 1 || Laik.egzas > 10) {
            cout<<"Klaida: egzamino įvertinimas turi būti nuo 1 iki 10! Įvertinimą įvesti dar kartą.\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (Laik.egzas < 1 || Laik.egzas > 10);
    
    float mediana = sk_mediana(Laik.paz);
    
    Laik.rez_vid = Laik.egzas * 0.6 + double(sum) / double(Laik.paz.size()) * 0.4;
    Laik.rez_med = Laik.egzas * 0.6 + mediana * 0.4;
    
    return Laik;
}