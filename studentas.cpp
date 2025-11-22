#include "studentas.h"
#include <iomanip>

Studentas::Studentas() : egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vard_(vardas), pav_(pavarde), egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}

// Kopijavimo konstruktorius
Studentas::Studentas(const Studentas& other)
    : vard_(other.vard_), pav_(other.pav_), paz_(other.paz_),
      egzas_(other.egzas_), rez_vid_(other.rez_vid_), rez_med_(other.rez_med_) {}

// Kopijavimo priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) {
    if (this != &other) {
        vard_ = other.vard_;
        pav_ = other.pav_;
        paz_ = other.paz_;
        egzas_ = other.egzas_;
        rez_vid_ = other.rez_vid_;
        rez_med_ = other.rez_med_;
    }
    return *this;
}

// Set'eriai
void Studentas::setVard(const std::string& vardas) { vard_ = vardas; }
void Studentas::setPav(const std::string& pavarde) { pav_ = pavarde; }
void Studentas::setEgzas(int egzaminas) { egzas_ = egzaminas; }
void Studentas::addPazymys(int pazymys) { paz_.push_back(pazymys); }
void Studentas::setRezVid(float vid) { rez_vid_ = vid; }
void Studentas::setRezMed(float med) { rez_med_ = med; }
void Studentas::clearPaz() { paz_.clear(); }

// Galutinio įvertinimo skaičiavimas
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

// Destruktorius
Studentas::~Studentas() {
    vard_.clear();
    pav_.clear();
    paz_.clear();
    egzas_ = 0;
    rez_vid_ = 0.0f;
    rez_med_ = 0.0f;
}


bool lygintiVid(const Studentas& a, const Studentas& b) {
    return a.rez_vid() < b.rez_vid();
}

bool lygintiMed(const Studentas& a, const Studentas& b) {
    return a.rez_med() < b.rez_med();
}

// Išvedimo operatorius
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << "Vardas: " << s.vard_ << "\n";
    os << "Pavardė: " << s.pav_ << "\n";
    os << "Pažymiai: ";
    for (int p : s.paz_) {
        os << p << " ";
    }
    os << "\nEgzaminas: " << s.egzas_ << "\n";
    os << "Galutinis vidurkis: " << s.rez_vid_ << "\n";
    os << "Galutinė mediana: " << s.rez_med_ << "\n";
    return os;
}

// Įvedimo operatorius
std::istream& operator>>(std::istream& is, Studentas& s) {
    s.paz_.clear();
    int kiekNd, paz;

    std::cout << "Įveskite vardą: ";
    is >> s.vard_;
    std::cout << "Įveskite pavardę: ";
    is >> s.pav_;
    std::cout << "Kiek pažymių įvesite? ";
    is >> kiekNd;

    std::cout << "Įveskite pažymius: ";
    for (int i = 0; i < kiekNd; i++) {
        is >> paz;
        s.paz_.push_back(paz);
    }

    std::cout << "Įveskite egzamino pažymį: ";
    is >> s.egzas_;

    return is;
}