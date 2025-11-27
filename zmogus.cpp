#include "zmogus.h"

Zmogus::Zmogus() : vard_(""), pav_("") {}                               // Konstruktorius be parametrų
Zmogus::Zmogus(const std::string& vardas, const std::string& pavarde)   // Konstruktorius su parametrais
    : vard_(vardas), pav_(pavarde) {}

Zmogus::Zmogus(const Zmogus& other)                                     // Kopijavimo konstruktorius
    : vard_(other.vard_), pav_(other.pav_) {}

Zmogus& Zmogus::operator=(const Zmogus& other) {                        // Kopijos priskyrimo operatorius
    if (this != &other) {
        vard_ = other.vard_;
        pav_ = other.pav_;
    }
    return *this;
}

// Destruktorius
Zmogus::~Zmogus() {
    vard_.clear();
    pav_.clear();
}

// Set'eriai
void Zmogus::setVard(const std::string& vardas) {
    vard_ = vardas;
}

void Zmogus::setPav(const std::string& pavarde) {
    pav_ = pavarde;
}