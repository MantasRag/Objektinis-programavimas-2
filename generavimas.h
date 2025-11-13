#pragma once
#include <vector>
#include "studentas.h"  // Studentų duomenų struktūrai

int kiek_generuoti();
void generuoti_atsitiktinius(std::vector<Studentas>& Grupe);
void generuoti_i_txt(int stud_skaicius, int nd_skaicius);