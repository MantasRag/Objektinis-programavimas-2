/**
 * @file zmogus.cpp
 * @brief Zmogus klasės implementacija
 */

#include "zmogus.h"

/**
 * @brief Numatytasis konstruktorius
 * Inicializuoja tuščiomis reikšmėmis
 */
Zmogus::Zmogus() : vard_(""), pav_("") {}

/**
 * @brief Konstruktorius su parametrais
 * @param vardas Žmogaus vardas
 * @param pavarde Žmogaus pavardė
 */
Zmogus::Zmogus(const std::string& vardas, const std::string& pavarde)
    : vard_(vardas), pav_(pavarde) {}

/**
 * @brief Kopijavimo konstruktorius
 * @param other Kitas Zmogus objektas
 */
Zmogus::Zmogus(const Zmogus& other)
    : vard_(other.vard_), pav_(other.pav_) {}

/**
 * @brief Priskyrimo operatorius
 * @param other Kitas Zmogus objektas
 * @return Nuoroda į šį objektą
 */
Zmogus& Zmogus::operator=(const Zmogus& other) {
    if (this != &other) {
        vard_ = other.vard_;
        pav_ = other.pav_;
    }
    return *this;
}

/**
 * @brief Destruktorius
 * Išvalo vardą ir pavardę
 */
Zmogus::~Zmogus() {
    vard_.clear();
    pav_.clear();
}

/**
 * @brief Nustatyti vardą
 * @param vardas Naujas vardas
 */
void Zmogus::setVard(const std::string& vardas) {
    vard_ = vardas;
}

/**
 * @brief Nustatyti pavardę
 * @param pavarde Nauja pavardė
 */
void Zmogus::setPav(const std::string& pavarde) {
    pav_ = pavarde;
}