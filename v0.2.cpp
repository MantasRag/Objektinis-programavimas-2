// v0.2
#include <iostream>         // Leidžia naudoti cin ir cout
#include <iomanip>          // Leidžia formatuoti išvestį
#include <vector>           // Leidžia įvesti vektorius
#include <string>           // Leidžia įvesti string tipo kintamuosius
#include <limits>           // Naudojama valyti įvesties srautą
#include <chrono>           // Laiko matavimui

#include "arTestiDarba.h"           // Patikrina ar vartotojas nori tęsti darbą su programa
#include "dalijimo_budas.h"         // Studentų dalijimo būdo pasirinkimui
#include "generuoti_atsitiktinius.h" // Studentų duomenų generavimui
#include "generuoti_i_txt.h"        // Testavimo failų generavimui
#include "issaugoti_i_txt.h"        // Duomenų išsaugojimui į txt failą
#include "ivesk.h"                  // Studentų duomenų įvedimui
#include "ivesti_is_failo.h"        // Studentų duomenų įvedimui iš failo
#include "ivesti_rankiniu_budu.h"   // Studentų duomenų įvedimui rankiniu būdu
#include "kiek_generuoti.h"         // Kiek pažymių generuoti kiekvienam studentui
#include "mediana.h"                // Medianos skaičiavimui
#include "padalinti_i_grupes.h"     // Studentų grupavimui
#include "pasirinkti_skaiciavimo_metoda.h" // Galutinio pažymio skaičiavimo metodo pasirinkimui
#include "rodyti_menu.h"            // Meniu rodymui
#include "rikiavimo_budas.h"        // Rikiavimo būdo pasirinkimui
#include "rusiuoti_studentus.h"     // Studentų rikiavimui
#include "skaiciuoti_rezultatus.h"  // Studentų rezultatų skaičiavimui
#include "spausdinti_rezultatus.h"  // Studentų rezultatų spausdinimui konsolės lange
#include "studentas.h"              // Studentų duomenų struktūrai

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
    
    while (true) {
        rodyti_menu();
        cout << "Pasirinkite veiksma (1-6): ";
        if (cin >> pasirinkimas) {
            switch (pasirinkimas) {
                case 1:
                    ivesti_rankiniu_budu(Grupe);
                    if (!Grupe.empty()) {
                        skaiciuoti_rezultatus(Grupe, skaiciavimo_metodas);
                        spausdinti_rezultatus(Grupe, skaiciavimo_metodas);
                        arTestiDarba();
                    }
                    break;
                case 2:
                    ivesti_is_failo(Grupe, "stud10000.txt");
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
                case 5: {
                    if (skaiciavimo_metodas == 3) {
                        rikiavimo_budas(tipas1, tvarka);
                        tipas2 = dalijimo_budas();
                    }
                    
                    vector<string> failai = {"stud1000.txt", "stud10000.txt", "stud100000.txt", "stud1000000.txt", "stud10000000.txt"};
                    vector<int> irasu_skaicius = {1000, 10000, 100000, 1000000, 10000000};
                    
                    for (size_t i = 0; i < failai.size(); i++) {
                        Grupe.clear();
                        maziau5.clear();
                        daugiaulygu5.clear();
                        
                        cout << "Testuojmas failas su " << irasu_skaicius[i] << " irasu";
                        
                        auto start_ivedimas = high_resolution_clock::now();
                        ivesti_is_failo(Grupe, failai[i]);
                        auto end_ivedimas = high_resolution_clock::now();
                        
                        skaiciuoti_rezultatus(Grupe, skaiciavimo_metodas);
                    
                        auto start_rikiavimas = high_resolution_clock::now();
                        rusiuoti_studentus(Grupe, skaiciavimo_metodas, tipas1, tvarka);
                        auto end_rikiavimas = high_resolution_clock::now();
                    
                        auto start_padalinimas = high_resolution_clock::now();
                        padalinti_i_grupes(Grupe, tipas2, maziau5, daugiaulygu5);
                        auto end_padalinimas = high_resolution_clock::now();
                        
                        auto start_issaugojimas = high_resolution_clock::now();
                        issaugoti_i_txt(maziau5, "Maziau_5", skaiciavimo_metodas);
                        auto end_issaugojimas = high_resolution_clock::now();
                        
                        auto start_issaugojimas2 = high_resolution_clock::now();
                        issaugoti_i_txt(daugiaulygu5, "Daugiau_lygu_5", skaiciavimo_metodas);
                        auto end_issaugojimas2 = high_resolution_clock::now();
                        
                        double ivedimo_laikas = duration_cast<milliseconds>(end_ivedimas - start_ivedimas).count() / 1000.0;
                        double rikiavimo_laikas = duration_cast<milliseconds>(end_rikiavimas - start_rikiavimas).count() / 1000.0;
                        double padalinimo_laikas = duration_cast<milliseconds>(end_padalinimas - start_padalinimas).count() / 1000.0;
                        double issaugojimo_laikas = duration_cast<milliseconds>(end_issaugojimas - start_issaugojimas).count() / 1000.0;
                        double issaugojimo2_laikas = duration_cast<milliseconds>(end_issaugojimas2 - start_issaugojimas2).count() / 1000.0;
                        double bendras_laikas = ivedimo_laikas + rikiavimo_laikas + padalinimo_laikas + 
                                            issaugojimo_laikas + issaugojimo2_laikas;
                        
                        cout << fixed << setprecision(3);
                        cout << "  Failo su " << irasu_skaicius[i] << " irasu nuskaitymo laikas: " << ivedimo_laikas << " s\n";
                        cout << "  " << irasu_skaicius[i] << " irasu rikiavimo laikas: " << rikiavimo_laikas << " s\n";
                        cout << "  " << irasu_skaicius[i] << " irasu padalinimo i grupes laikas: " << padalinimo_laikas << " s\n";
                        cout << "  Issaugojimo i faila (maziau 5) laikas " << irasu_skaicius[i] << " irasu: " << issaugojimo_laikas << " s\n";
                        cout << "  Issaugojimo i faila (daugiau/lygu 5) laikas " << irasu_skaicius[i] << " irasu: " << issaugojimo2_laikas << " s\n";
                        cout << "  " << irasu_skaicius[i] << " irasu bendras laikas: " << bendras_laikas << " s\n\n";
                    }
                    arTestiDarba();
                    break;
                }
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
