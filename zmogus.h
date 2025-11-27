#pragma once
#include <string>
#include <iostream>

class Zmogus {
protected:
    std::string vard_;
    std::string pav_;

public:
    // Konstruktoriai
    Zmogus();
    Zmogus(const std::string& vardas, const std::string& pavarde);
    
    // Rule of three
    Zmogus(const Zmogus& other);
    Zmogus& operator=(const Zmogus& other);
    virtual ~Zmogus();
    
    // Get'eriai
    inline std::string vard() const { return vard_; }
    inline std::string pav() const { return pav_; }
    
    // Set'eriai
    void setVard(const std::string& vardas);
    void setPav(const std::string& pavarde);
    
    virtual void spausdinti(std::ostream& os) const = 0;  // Virtuali funkcija - daro klasę abstrakčia
};