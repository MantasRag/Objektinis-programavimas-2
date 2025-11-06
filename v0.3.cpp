// v0.3
#include <iostream>         // Leidžia naudoti cin ir cout
#include <iomanip>          // Leidžia formatuoti išvestį
#include <vector>           // Leidžia įvesti vektorius
#include <string>           // Leidžia įvesti string tipo kintamuosius
#include <limits>           // Naudojama valyti įvesties srautą
#include <chrono>           // Laiko matavimui

#include "pagalbines_funkcijos.h"       // Pagalbinėms funkcijoms
#include "vector_list_testavimas.h"     // Konteinerių testavimui !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include "rezultatai.h"                 // Rezultatų skaičiavimui, parodymui terminale
#include "rusiavimas_ir_rikiavimas.h"   // Rikiavimo ir rūšiavimo funkcijoms
#include "generavimas.h"                // Duomenų generavimui, generavimui į .txt failus
#include "ivestis.h"                    // Duomenų įvedimui iš failo ir rankiniu būdu
#include "isvedimas.h"                  // Duomenų išvedimui į .txt failus
#include "studentas.h"                  // Studentų duomenų struktūrai

using namespace std;
using namespace std::chrono;

int main() {
    vector<Studentas> Grupe;
    vector<Studentas> maziau5;
    vector<Studentas> daugiaulygu5;
    int pasirinkimas;
    int skaiciavimo_metodas = pasirinkti_skaiciavimo_metoda();
    int tipas1, tvarka;
    int tipas2 = skaiciavimo_metodas;
    string pav1="Maziau_5_", pav2="Daugiau_lygu_5_";
    
    while (true) {
        rodyti_menu();
        cout << "Pasirinkite veiksma (1-7): ";
        if (cin >> pasirinkimas) {
            switch (pasirinkimas) {
                case 1: {
                    int konteinerio_tipas = pasirinkti_konteinerio_tipa();
                    
                    if (konteinerio_tipas == 1) {
                        // Vector konteineris
                        vector<Studentas> GrupeVec;
                        ivesti_rankiniu_budu(GrupeVec);
                        if (!GrupeVec.empty()) {
                            skaiciuoti_rezultatus(GrupeVec, skaiciavimo_metodas);
                            spausdinti_rezultatus1(GrupeVec, skaiciavimo_metodas);
                            arTestiDarba();
                        }
                    } else {
                        // List konteineris
                        list<Studentas> GrupeList;
                        ivesti_rankiniu_budu(GrupeList);
                        if (!GrupeList.empty()) {
                            skaiciuoti_rezultatus(GrupeList, skaiciavimo_metodas);
                            spausdinti_rezultatus1(GrupeList, skaiciavimo_metodas);
                            arTestiDarba();
                        }
                    }
                    break;
                }
                case 2:
                    ivesti_is_failo(Grupe, "stud1000.txt");
                    if (!Grupe.empty()) {
                        skaiciuoti_rezultatus(Grupe, skaiciavimo_metodas);
                        spausdinti_rezultatus(Grupe, skaiciavimo_metodas);
                        arTestiDarba();
                    }
                    break;
                case 3:
                    generuoti_atsitiktinius(Grupe);
                    if (!Grupe.empty()) {
                        skaiciuoti_rezultatus(Grupe, skaiciavimo_metodas);
                        spausdinti_rezultatus(Grupe, skaiciavimo_metodas);
                        arTestiDarba();
                    }
                    break;
                case 4: {
                    int nd_kiekis = kiek_generuoti();
                    auto start_generavimas = high_resolution_clock::now();
                    generuoti_i_txt(1000, nd_kiekis);
                    auto end_generavimas = high_resolution_clock::now();
                    auto start_generavimas2 = high_resolution_clock::now();
                    generuoti_i_txt(10000, nd_kiekis);
                    auto end_generavimas2 = high_resolution_clock::now();
                    auto start_generavimas3 = high_resolution_clock::now();
                    generuoti_i_txt(100000, nd_kiekis);
                    auto end_generavimas3 = high_resolution_clock::now();
                    auto start_generavimas4 = high_resolution_clock::now();
                    generuoti_i_txt(1000000, nd_kiekis);
                    auto end_generavimas4 = high_resolution_clock::now();
                    auto start_generavimas5 = high_resolution_clock::now();
                    generuoti_i_txt(10000000, nd_kiekis);
                    auto end_generavimas5 = high_resolution_clock::now();

                    cout << "\nGeneravimo spartos analize\n";
                    cout << "Generavimo laikas 1000 studentu: " << duration_cast<milliseconds>(end_generavimas - start_generavimas).count() / 1000.0 << " s\n";
                    cout << "Generavimo laikas 10000 studentu: " << duration_cast<milliseconds>(end_generavimas2 - start_generavimas2).count() / 1000.0 << " s\n";
                    cout << "Generavimo laikas 100000 studentu: " << duration_cast<milliseconds>(end_generavimas3 - start_generavimas3).count() / 1000.0 << " s\n";
                    cout << "Generavimo laikas 1000000 studentu: " << duration_cast<milliseconds>(end_generavimas4 - start_generavimas4).count() / 1000.0 << " s\n";
                    cout << "Generavimo laikas 10000000 studentu: " << duration_cast<milliseconds>(end_generavimas5 - start_generavimas5).count() / 1000.0 << " s\n\n";
                    break;
                }
                case 5:
                    testuoti_konteinerius(skaiciavimo_metodas);
                    arTestiDarba();
                    break;
                case 6:
                    cout << "Programa baigta.\n";
                    return 0;
                default:
                    cout << "Klaida: pasirinkite skaiciu nuo 1 iki 5.\n\n";
                    break;
            }
        } else {
            cout << "Klaida: iveskite teisinga skaiciu.\n\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return 0;
}