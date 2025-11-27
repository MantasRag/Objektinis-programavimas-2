#include "demonstracijos.h"
#include "studentas.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void demonstruoti_abstrakcia_klase() {
    cout << "Demonstracija irodanti, kad Zmogus klase yra abstrakti: \n";
    
    cout << "1. Bandymas sukurti Zmogus objekta:\n";
    cout << "Zmogus zmogus1;\n";
    cout << "Zmogus zmogus2(\"Jonas\", \"Jonaitis\");\n";
    cout << "Klaidos, nes Zmogus yra abstrakti klase (virtual void spausdinti()) \n";
    
    // Zmogus zmogus1;
    // Zmogus zmogus2("Jonas", "Jonaitis");
    
    cout << "2. Irodymas, kad pavyksta sukurti isvestines klases Studentas objektus:\n";
    Studentas studentas1("Petras", "Petraitis");
    studentas1.addPazymys(8);
    studentas1.addPazymys(9);
    studentas1.setEgzas(10);
    
    cout << "Studentas studentas1(\"Petras\", \"Petraitis\");\n";
    cout << "Vardas: " << studentas1.vard() << " (is Zmogus klases)\n";
    cout << "Pavarde: " << studentas1.pav() << " (is Zmogus klases)\n";
    cout << "Pazymiai: ";
    for (int p : studentas1.paz()) cout << p << " ";
    cout << "\n";
    cout << "Egzamino ivertinimas: " << studentas1.egzas() << "\n\n";
}