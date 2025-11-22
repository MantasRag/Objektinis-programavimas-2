#pragma once
#include <string>
#include <vector>
#include <iostream>

class Studentas {
private:
    std::string vard_;
    std::string pav_;
    std::vector<int> paz_;
    int egzas_;
    float rez_vid_;
    float rez_med_;

public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde);

    // Rule of three
    Studentas(const Studentas& other);            // copy constructor
    Studentas& operator=(const Studentas& other); // copy assignment
    ~Studentas();                                 // Destruktorius

    // Get'eriai - gražina klasės narių reikšmes
    inline std::string vard() const { return vard_; }
    inline std::string pav() const { return pav_; }
    inline const std::vector<int>& paz() const { return paz_; }
    inline int egzas() const { return egzas_; }
    inline float rez_vid() const { return rez_vid_; }
    inline float rez_med() const { return rez_med_; }

    // Set'eriai - nustato klasės narių reikšmes
    void setVard(const std::string& vardas);
    void setPav(const std::string& pavarde);
    void setEgzas(int egzaminas);
    void addPazymys(int pazymys);
    void setRezVid(float vid);
    void setRezMed(float med);
    void clearPaz();

    // Member funkcija rezultatų skaičiavimui
    void skaiciuotiRezultatus(int metodas, float mediana);

    // Operatoriai
    friend std::ostream& operator<<(std::ostream& os, const Studentas& s);
    friend std::istream& operator>>(std::istream& is, Studentas& s);
};

bool lygintiVid(const Studentas& a, const Studentas& b);
bool lygintiMed(const Studentas& a, const Studentas& b);
