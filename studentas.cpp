#include "studentas.h"

Studentas::Studentas() : egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}
Studentas::Studentas(const std::string& vardas, const std::string& pavarde)
    : vard_(vardas), pav_(pavarde), egzas_(0), rez_vid_(0.0f), rez_med_(0.0f) {}

// Get'eriai
std::string Studentas::vard() const { return vard_; }
std::string Studentas::pav() const { return pav_; }
const std::vector<int>& Studentas::paz() const { return paz_; }
int Studentas::egzas() const { return egzas_; }
float Studentas::rez_vid() const { return rez_vid_; }
float Studentas::rez_med() const { return rez_med_; }

// Set'eriai
void Studentas::setVard(const std::string& vardas) { vard_ = vardas; }
void Studentas::setPav(const std::string& pavarde) { pav_ = pavarde; }
void Studentas::setEgzas(int egzaminas) { egzas_ = egzaminas; }
void Studentas::addPazymys(int pazymys) { paz_.push_back(pazymys); }
void Studentas::setRezVid(float vid) { rez_vid_ = vid; }
void Studentas::setRezMed(float med) { rez_med_ = med; }
void Studentas::clearPaz() { paz_.clear(); }
