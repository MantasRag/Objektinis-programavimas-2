#include "padalinti_i_grupes.h"  // Studentų grupavimui
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

void padalinti_i_grupes(const vector<Studentas>& Grupe, int skaiciavimo_metodas,
                        vector<Studentas>& maziau5, vector<Studentas>& daugiaulygu5) {
    if (Grupe.empty()) {
        cout << "Klaida. Studentų vektorius tuščias.\n";
        return;
    }

    int tipas = skaiciavimo_metodas;
    if (skaiciavimo_metodas == 3) {
        cout << "\nDalinti pagal:\n";
        cout << "1. Galutinį (vidurkis)\n";
        cout << "2. Galutinį (mediana)\n";
        while (!(cin >> tipas) || (tipas != 1 && tipas != 2)) {
            cout << "Klaida. Įveskite 1 arba 2\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    maziau5.clear();
    daugiaulygu5.clear();

    for (const auto& st : Grupe) {
        float rezultatas = (tipas == 1 ? st.rez_vid : st.rez_med);
        if (rezultatas < 5.0f)
            maziau5.push_back(st);
        else
            daugiaulygu5.push_back(st);
    }

    cout << "\nStudentai suskirstyti pagal galutinį pažymį (" 
         << (tipas == 1 ? "vidurkis" : "mediana") << "):\n";
    cout << "Studentų su < 5: " << maziau5.size() << endl;
    cout << "Studentų su ≥ 5: " << daugiaulygu5.size() << endl;
}