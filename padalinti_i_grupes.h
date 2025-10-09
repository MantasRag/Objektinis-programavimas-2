#pragma once
#include <vector>
#include "studentas.h"  // Studentų duomenų struktūrai

void padalinti_i_grupes(const std::vector<Studentas>& Grupe, int skaiciavimo_metodas,
                        std::vector<Studentas>& maziau5, std::vector<Studentas>& daugiaulygu5);