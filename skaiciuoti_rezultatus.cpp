#include "skaiciuoti_rezultatus.h"  // Studentų rezultatų skaičiavimui
#include "studentas.h"              // Studentų duomenų struktūrai
#include "mediana.h"                // Medianos skaičiavimui
#include <vector>

void skaiciuoti_rezultatus(vector<Studentas>& Grupe, int skaiciavimo_metodas) {
    if (skaiciavimo_metodas == 1 || skaiciavimo_metodas == 3) {
        // Vidurkis
        for (auto &st : Grupe) {
            if (!st.paz.empty()) {
                int sum = 0;
                for (int nd : st.paz) sum += nd;
                st.rez_vid = st.egzas * 0.6f + (float(sum) / st.paz.size()) * 0.4f;
            }
        }
    }
    if (skaiciavimo_metodas == 2 || skaiciavimo_metodas == 3) {
        // Mediana
        for (auto &st : Grupe) {
            if (!st.paz.empty()) {
                float mediana = sk_mediana(st.paz);
                st.rez_med = st.egzas * 0.6f + mediana * 0.4f;
            }
        }
    }
}