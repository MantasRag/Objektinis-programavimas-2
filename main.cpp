#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <limits>
#include <chrono>

#include "pagalbines_funkcijos.h"
#include "vector_list_testavimas.h"
#include "rezultatai.h"
#include "rusiavimas_ir_rikiavimas.h"
#include "generavimas.h"
#include "ivestis.h"
#include "isvedimas.h"
#include "studentas.h"
#include "zmogus.h"
#include "demonstracijos.h"

using namespace std;
using namespace std::chrono;

int main() {
    // Demonstruojame abstrakčią klasę
    demonstruoti_abstrakcia_klase();
    
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
        cout << "Pasirinkite veiksma (1-6): ";
        if (cin >> pasirinkimas) {
            switch (pasirinkimas) {
                case 1: {
                    int konteinerio_tipas = pasirinkti_konteinerio_tipa();
                    
                    if (konteinerio_tipas == 1) {
                        vector<Studentas> GrupeVec;
                        ivesti_rankiniu_budu(GrupeVec);
                        if (!GrupeVec.empty()) {
                            skaiciuoti_rezultatus(GrupeVec, skaiciavimo_metodas);
                            spausdinti_rezultatus1(GrupeVec, skaiciavimo_metodas);
                            arTestiDarba();
                        }
                    } else {
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
                    cout << "Klaida: pasirinkite skaiciu nuo 1 iki 6.\n\n";
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