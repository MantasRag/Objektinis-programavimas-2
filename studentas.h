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
}