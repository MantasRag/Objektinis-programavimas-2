/**
 * @file studentas.cpp
 * @brief Studentas klasės implementacija
 */

#include "studentas.h"
#include <iomanip>
#include <sstream>
#include <limits>

/**
 * @brief Numatytasis konstruktorius
 * Inicializuoja visus laukus nulinėmis reikšmėmis
 */
Studentas::Studentas() : Zmogus(), egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}

/**
 * @brief Konstruktorius su parametrais
 * @param vardas Studento vardas
 * @param pavarde Studento pavardė
 */
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : Zmogus(vardas, pavarde), egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}

/**
 * @brief Kopijavimo konstruktorius
 * @param other Kitas Studentas objektas
 */
Studentas::Studentas(const Studentas& other)
    : Zmogus(other), paz_(other.paz_),
      egzas_(other.egzas_), rez_vid_(other.rez_vid_), rez_med_(other.rez_med_) {}

/**
 * @brief Priskyrimo operatorius
 * @param other Kitas Studentas objektas
 * @return Nuoroda į šį objektą
 */
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        Zmogus::operator=(other);
        paz_ = other.paz_;
        egzas_ = other.egzas_;
        rez_vid_ = other.rez_vid_;
        rez_med_ = other.rez_med_;
    }
    return *this;
}

/**
 * @brief Destruktorius
 * Išvalo pažymių vektorių ir nustato nulines reikšmes
 */
Studentas::~Studentas() {
    paz_.clear();
    egzas_ = 0;
    rez_vid_ = 0.0f;
    rez_med_ = 0.0f;
}

/**
 * @brief Nustatyti egzamino įvertinimą
 * @param egzaminas Egzamino pažymys
 */
void Studentas::setEgzas(int egzaminas) { 
    egzas_ = egzaminas; 
}

/**
 * @brief Pridėti pažymį į vektorių
 * @param pazymys Namų darbų pažymys
 */
void Studentas::addPazymys(int pazymys) { 
    paz_.push_back(pazymys); 
}

/**
 * @brief Nustatyti galutinį rezultatą (vidurkis)
 * @param vid Galutinis rezultatas
 */
void Studentas::setRezVid(float vid) { 
    rez_vid_ = vid; 
}

/**
 * @brief Nustatyti galutinį rezultatą (mediana)
 * @param med Galutinis rezultatas
 */
void Studentas::setRezMed(float med) { 
    rez_med_ = med; 
}

/**
 * @brief Išvalyti visus pažymius
 */
void Studentas::clearPaz() { 
    paz_.clear(); 
}

/**
 * @brief Skaičiuoti galutinį rezultatą
 * @param metodas 1-vidurkis, 2-mediana, 3-abu
 * @param mediana Namų darbų pažymių mediana
 * 
 * Formulė: Galutinis = 0.6 * Egzaminas + 0.4 * ND
 */
void Studentas::skaiciuotiRezultatus(int metodas, float mediana) {
    if ((metodas == 1 || metodas == 3) && !paz_.empty()) {
        int sum = 0;
        for (int nd : paz_) sum += nd;
        rez_vid_ = egzas_ * 0.6f + (float(sum) / paz_.size()) * 0.4f;
    }
    if ((metodas == 2 || metodas == 3) && !paz_.empty()) {
        rez_med_ = egzas_ * 0.6f + mediana * 0.4f;
    }
}

/**
 * @brief Spausdinti studento duomenis
 * @param os Išvesties srautas
 * 
 * Išveda vardą, pavardę ir galutinį rezultatą
 */
void Studentas::spausdinti(std::ostream& os) const {
    os << std::left << std::setw(15) << vard_
       << "| " << std::setw(15) << pav_
       << "| ";
    
    if (rez_vid_ > 0.0f && rez_med_ > 0.0f) {
        os << std::right << std::setw(18) << std::fixed << std::setprecision(2) << rez_vid_
           << "  | " << std::setw(18) << std::fixed << std::setprecision(2) << rez_med_;
    } else if (rez_vid_ > 0.0f) {
        os << std::right << std::setw(18) << std::fixed << std::setprecision(2) << rez_vid_;
    } else if (rez_med_ > 0.0f) {
        os << std::right << std::setw(18) << std::fixed << std::setprecision(2) << rez_med_;
    }
}

/**
 * @brief Palyginti pagal vidurkį
 * @param a Pirmas studentas
 * @param b Antras studentas
 * @return true, jei a.rez_vid() < b.rez_vid()
 */
bool lygintiVid(const Studentas& a, const Studentas& b) {
    return a.rez_vid() < b.rez_vid();
}

/**
 * @brief Palyginti pagal medianą
 * @param a Pirmas studentas
 * @param b Antras studentas
 * @return true, jei a.rez_med() < b.rez_med()
 */
bool lygintiMed(const Studentas& a, const Studentas& b) {
    return a.rez_med() < b.rez_med();
}

/**
 * @brief Išvesties operatorius
 * @param os Išvesties srautas
 * @param s Studentas objektas
 * @return Išvesties srautas
 * 
 * Naudoja spausdinti() funkciją
 */
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    s.spausdinti(os);
    return os;
}

/**
 * @brief Įvesties operatorius
 * @param is Įvesties srautas
 * @param s Studentas objektas
 * @return Įvesties srautas
 * 
 * Interaktyviai prašo įvesti vardą, pavardę, pažymius ir egzaminą
 */
std::istream& operator>>(std::istream& is, Studentas& s) {
    s.paz_.clear();
    
    std::string vardas;
    std::cout << "Iveskite studento varda: ";
    is >> vardas;
    s.setVard(vardas);
    
    std::string pavarde;
    std::cout << "Iveskite studento pavarde: ";
    is >> pavarde;
    s.setPav(pavarde);
    
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout << "Iveskite namu darbu pazymius (1-10). Noredami baigti, spauskite ENTER tusciai eilutei:\n";
    std::string line;
    int pazymys_num = 1;
    
    while (true) {
        std::cout << "Iveskite " << pazymys_num << " pazymi (arba ENTER jei baigete): ";
        std::getline(is, line);
        
        if (line.empty()) {
            if (s.paz_.empty()) {
                std::cout << "Klaida: reikia ivesti bent viena pazymi!\n";
                continue;
            }
            break;
        }
        
        std::istringstream iss(line);
        int pazymys;
        
        if (iss >> pazymys && iss.eof()) {
            if (pazymys >= 1 && pazymys <= 10) {
                s.addPazymys(pazymys);
                pazymys_num++;
            } else {
                std::cout << "Klaida: pazymys turi buti nuo 1 iki 10. Iveskite dar karta.\n";
            }
        } else {
            std::cout << "Klaida: iveskite teisinga skaiciu (1-10) arba ENTER jei baigete.\n";
        }
    }
    
    int egzaminas;
    do {
        std::cout << "Iveskite egzamino rezultata (1-10): ";
        is >> egzaminas;
        if (egzaminas < 1 || egzaminas > 10) {
            std::cout << "Klaida: egzamino ivertinimas turi buti nuo 1 iki 10. Ivertinima ivesti dar karta.\n";
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (egzaminas < 1 || egzaminas > 10);
    
    s.setEgzas(egzaminas);
    
    return is;
}