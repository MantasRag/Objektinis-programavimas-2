#include "studentas.h"

Studentas::Studentas() : egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vard_(vardas), pav_(pavarde), egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}

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
