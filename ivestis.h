#pragma once
#include <vector>
#include <list>
#include "studentas.h"
#include <string>
#include <limits>
#include <iostream>

Studentas ivesk();

template <typename Container>
void ivesti_rankiniu_budu(Container& Grupe);

void ivesti_is_failo(std::vector<Studentas>& Grupe, const std::string& failo_vardas);
int pasirinkti_konteinerio_tipa();

// Template implementacija
template <typename Container>
void ivesti_rankiniu_budu(Container& Grupe) {
    int kiek;
    
    while (true) {
        std::cout << "\nKiek studentu yra grupeje? ";
        if (std::cin >> kiek && kiek > 0) {
            break;
        } else {
            std::cout << "Klaida: studentu skaičius turi buti teigiamas skaicius. Ivesti dar karta.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    for (int j = 0; j < kiek; j++) {
        std::cout << "\nIveskite " << j + 1 << " studenta:\n";
        Studentas st = ivesk();
        Grupe.push_back(st);
    }
}