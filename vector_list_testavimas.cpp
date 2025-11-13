#include "vector_list_testavimas.h"

void testuoti_konteinerius(int skaiciavimo_metodas) {
    int pasirinkimas;
    cout << "\nPasirinkite konteineri testavimui:\n1 - vector\n2 - list\n3 - abu\n";
    cout << "Jusu pasirinkimas: ";
    while (!(cin >> pasirinkimas) || pasirinkimas < 1 || pasirinkimas > 3) {
        cout << "Klaida: iveskite skaiciu nuo 1 iki 3: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string konteinerio_pasirinkimas;
    if (pasirinkimas == 1) konteinerio_pasirinkimas = "vector";
    else if (pasirinkimas == 2) konteinerio_pasirinkimas = "list";
    else konteinerio_pasirinkimas = "abu";

    // NAUJAS KODAS - Pasirinkti strategiją
    int strategija = pasirinkti_strategija();

    //Failai testavimui
    vector<string> failai = {"stud1000.txt","stud10000.txt","stud100000.txt","stud1000000.txt", "stud10000000.txt"};
    vector<int> irasai = {1000,10000,100000,1000000, 10000000};

    if (konteinerio_pasirinkimas == "vector") {
        testuoti<vector<Studentas>>(failai, irasai, skaiciavimo_metodas, "vector", strategija);
    } else if (konteinerio_pasirinkimas == "list") {
        testuoti<list<Studentas>>(failai, irasai, skaiciavimo_metodas, "list", strategija);
    } else if (konteinerio_pasirinkimas == "abu") {
        testuoti<vector<Studentas>>(failai, irasai, skaiciavimo_metodas, "vector", strategija);
        testuoti<list<Studentas>>(failai, irasai, skaiciavimo_metodas, "list", strategija);
    } else {
        cout << "Klaida. Tokio pasirinkimo nėra.\n";
    }
}