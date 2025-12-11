/**
 * @file zmogus.h
 * @brief Bazinė abstrakti Žmogaus klasė
 */

#pragma once
#include <string>
#include <iostream>

/**
 * @class Zmogus
 * @brief Abstrakti bazinė klasė žmogaus duomenims saugoti
 * 
 * Saugo vardą ir pavardę.
 */
class Zmogus {
protected:
    std::string vard_;  // Žmogaus vardas
    std::string pav_;   // Žmogaus pavardė

public:
    /**
     * @brief Numatytasis konstruktorius
     */
    Zmogus();
    
    /**
     * @brief Konstruktorius su parametrais
     * @param vardas Vardas
     * @param pavarde Pavardė
     */
    Zmogus(const std::string& vardas, const std::string& pavarde);
    
    /**
     * @brief Kopijavimo konstruktorius
     * @param other Kitas Zmogus objektas
     */
    Zmogus(const Zmogus& other);
    
    /**
     * @brief Priskyrimo operatorius
     * @param other Kitas Zmogus objektas
     * @return Nuoroda į šį objektą
     */
    Zmogus& operator=(const Zmogus& other);
    
    /**
     * @brief Virtualus destruktorius
     */
    virtual ~Zmogus();
    
    /**
     * @brief Gauti vardą
     * @return Vardas
     */
    inline std::string vard() const { return vard_; }
    
    /**
     * @brief Gauti pavardę
     * @return Pavardė
     */
    inline std::string pav() const { return pav_; }
    
    /**
     * @brief Nustatyti vardą
     * @param vardas Naujas vardas
     */
    void setVard(const std::string& vardas);
    
    /**
     * @brief Nustatyti pavardę
     * @param pavarde Nauja pavardė
     */
    void setPav(const std::string& pavarde);
    
    /**
     * @brief "Grynoji" virtuali funkcija spausdinimui
     * @param os Išvesties srautas
     * 
     * Daro klasę abstrakčia - turi būti realizuota išvestinėse klasėse.
     */
    virtual void spausdinti(std::ostream& os) const = 0;
};