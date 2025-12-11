/**
 * @file studentas.h
 * @brief Studento klasė, paveldi Zmogus
 */

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "zmogus.h"

/**
 * @class Studentas
 * @brief Studento duomenų klasė
 * 
 * Paveldi Zmogus klasę ir prideda studento specifinę informaciją:
 * pažymius, egzamino rezultatą ir galutinius įvertinimus.
 * 
 * Galutinis įvertinimas: 0.4 * ND + 0.6 * Egzaminas
 */
class Studentas : public Zmogus {
private:
    std::vector<int> paz_;  ///< Namų darbų pažymiai
    int egzas_;             ///< Egzamino įvertinimas
    float rez_vid_;         ///< Galutinis (vidurkis)
    float rez_med_;         ///< Galutinis (mediana)

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Studentas();
    
    /**
     * @brief Konstruktorius su parametrais
     * @param vardas Studento vardas
     * @param pavarde Studento pavardė
     */
    Studentas(const std::string& vardas, const std::string& pavarde);

    /**
     * @brief Kopijavimo konstruktorius
     * @param other Kitas Studentas objektas
     */
    Studentas(const Studentas& other);
    
    /**
     * @brief Priskyrimo operatorius
     * @param other Kitas Studentas objektas
     * @return Nuoroda į šį objektą
     */
    Studentas& operator=(const Studentas& other);
    
    /**
     * @brief Destruktorius
     */
    ~Studentas();

    /**
     * @brief Gauti pažymių vektorių
     * @return Pažymių vektorius
     */
    inline const std::vector<int>& paz() const { return paz_; }
    
    /**
     * @brief Gauti egzamino įvertinimą
     * @return Egzamino pažymys
     */
    inline int egzas() const { return egzas_; }
    
    /**
     * @brief Gauti galutinį (vidurkis)
     * @return Galutinis rezultatas pagal vidurkį
     */
    inline float rez_vid() const { return rez_vid_; }
    
    /**
     * @brief Gauti galutinį (mediana)
     * @return Galutinis rezultatas pagal medianą
     */
    inline float rez_med() const { return rez_med_; }

    /**
     * @brief Nustatyti egzamino įvertinimą
     * @param egzaminas Egzamino pažymys (1-10)
     */
    void setEgzas(int egzaminas);
    
    /**
     * @brief Pridėti pažymį
     * @param pazymys Namų darbų pažymys (1-10)
     */
    void addPazymys(int pazymys);
    
    /**
     * @brief Nustatyti galutinį (vidurkis)
     * @param vid Galutinis rezultatas
     */
    void setRezVid(float vid);
    
    /**
     * @brief Nustatyti galutinį (mediana)
     * @param med Galutinis rezultatas
     */
    void setRezMed(float med);
    
    /**
     * @brief Išvalyti pažymių vektorių
     */
    void clearPaz();

    /**
     * @brief Skaičiuoti galutinį rezultatą
     * @param metodas 1-vidurkis, 2-mediana, 3-abu
     * @param mediana Pažymių mediana
     * 
     * Formulė: Galutinis = 0.4 * ND + 0.6 * Egzaminas
     */
    void skaiciuotiRezultatus(int metodas, float mediana);

    /**
     * @brief Spausdinti studento duomenis
     * @param os Išvesties srautas
     * 
     * Override iš Zmogus klasės
     */
    virtual void spausdinti(std::ostream& os) const override;

    /**
     * @brief Išvesties operatorius
     * @param os Išvesties srautas
     * @param s Studentas objektas
     * @return Išvesties srautas
     */
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    
    /**
     * @brief Įvesties operatorius
     * @param is Įvesties srautas
     * @param s Studentas objektas
     * @return Įvesties srautas
     */
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

/**
 * @brief Palyginti studentus pagal vidurkį
 * @param a Pirmas studentas
 * @param b Antras studentas
 * @return true, jei a < b
 */
bool lygintiVid(const Studentas& a, const Studentas& b);

/**
 * @brief Palyginti studentus pagal medianą
 * @param a Pirmas studentas
 * @param b Antras studentas
 * @return true, jei a < b
 */
bool lygintiMed(const Studentas& a, const Studentas& b);