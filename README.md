# Objektinis programavimas

## 1. Visų versijų aprašai
### v0.1
Šis projektas yra C++ programa, skirta studentų namų darbų ir egzamino rezultatų tvarkymui bei galutinio balo apskaičiavimui. Projektas realizuotas pagal užduoties reikalavimus su „v.pradinė“ ir „v0.1“ versijomis.

Programa leidžia:
1. Duomenų įvedimą: studentų vardus ir pavardes (string tipo); namų darbų rezultatus ir egzamino įvertinimą (int tipo); namų darbų skaičius nėra ribojamas, studentai gali įvesti tiek, kiek reikia.
2. Galutinio balo skaičiavimą: pagal vidurkį; pagal medianą.
3. Galimybė pasirinkti, kaip bus skaičiuojamas galutinis įvertinimas: pagal vidurkį, medianą arba bus išvedami abu.
4. Duomenų saugojimą: visi studentų įrašai saugomi std::vector konteineryje; namų darbų rezultatai saugomi kaip vektorius kiekvieno studento struktūroje.
5. Atsitiktinių rezultatų generavimas: programa gali generuoti atsitiktinius studentų balus už namų darbus ir egzaminą.
6. Failų skaitymas ir įrašymas: galima įvesti studentų duomenis iš failo (pvz., kursiokai.txt).

Išvedimas rodomas tvarkingai išlygintu formatu.
Studentai gali būti surikiuoti pagal vardą arba pavardę abėcėlės didėjimo/mažėjimo.

### v0.2
Ši projekto versija (v0.2) yra v0.1 patobulinimas, skirtas dideliems studentų duomenų masyvams, failų generavimui ir spartumo analizei. Programa realizuota C++ kalba su std::vector, struct ir failų operacijomis. Projektas organizuotas keliuose .cpp ir .h failuose, kad būtų patogu palaikyti ir plėsti kodą.

Nauji funkcionalumai v0.2:
1. Atsitiktinių duomenų generavimas dideliems failams. Sugeneruoti penki studentų sąrašai su įrašų skaičiumi: 1 000, 10 000, 100 000, 1 000 000, 10 000 000. Vardai ir pavardės generuojami šabloniškai: Vardas1 Pavarde1, Vardas2 Pavarde2 ir t.t. Namų darbų ir egzamino balai generuojami atsitiktinai.
2. Studentų rūšiavimas pagal galutinį balą: studentai, kurių galutinis balas < 5, priskiriami "vargšiukų" kategorijai; studentai, kurių galutinis balas >= 5.0, priskiriami „kietiakių“ kategorijai. Surūšiuoti studentai išvedami į du naujus failus pagal kategorijas.
3. Atliktas kodo reorganizavimas (refactoring).
4. Atlikti programos veikimo spartos matavimai kiekvienam veiksmui: nuskaitymas, skaičiavimas, rikiavimas, padalinimas, išvedimai ir bendras laikas.

### v0.3
Ši versija (v0.3) yra v0.2 patobulinimas, skirtas konteinerių palyginimui ir programos spartos analizei. Programa realizuota C++ kalba, naudojant std::vector ir std::list studentų saugojimui, kad būtų įvertinta konteinerių įtaka veikimo greičiui.

Naujas funkcionalumas v0.3
1. Konteinerių testavimas: programoje studentų sąrašas gali būti saugomas tiek kaip std::vector<Student>, tiek kaip std::list<Student>.
2. Testavimas atliekamas su tais pačiais failais, kurie buvo naudojami v0.2: 1 000 įrašų, 10 000 įrašų, 100 000 įrašų, 1 000 000 įrašų, 10 000 000 įrašų.
3. Spartos matavimas: laikas matuojamas naudojant std::chrono biblioteką.
4. Rezultatai pateikiami README faile lentelėse, nurodant konteinerio tipą ir kiekvieno veiksmo trukmę.

### v1.0
Ši versija (v1.0) yra v0.3 patobulinimas, skirtas studentų dalijimo į kategorijas („vargšiukai“ ir „kietiakiai“) optimizavimui ir spartos analizei.

#### Nauji funkcionalumai.

Studentų dalijimo strategijos palyginimas:
* Strategija 1: Daugialypis kopijavimas – bendras studentų konteineris paliekamas, studentai nukopijuojami į atskirus „vargšiukų“ ir „kietiakių“ konteinerius.
* Strategija 2: Vienas naujas konteineris – „vargšiukai“ nukeliauja į naują konteinerį, o bendrame konteineryje lieka tik „kietiakai“.
* Strategija 3: Optimizuota strategija – panaudojami efektyvūs algoritmai (std::partition, std::remove_if, std::copy_if ir kt.) darbo su std::vector ir std::list spartinimui.

Efektyvumo matavimas:
* Išmatuojamas laikas visoms trims strategijoms, tiek std::vector, tiek std::list konteineriams.

Programos struktūra leidžia lengvai keisti konteinerį ir strategiją.

## 2. Programos naudojimosi instrukcija
### Pirmas žingsnis: Skaičiavimo metodo pasirinkimas.
Pačiame pirmame etape (paleidus programą) varototjo yra klausiama kokią skaičiavimo sistemą naudoti:
- Vidurkis
- Mediana
- Vidurkis ir mediana
Išvedant studentų rezultataus į ekraną terminale arba kuriant .txt failus studentų galutinį įvertinimą rodis apskaičiuotą pagal vidurkį, medianą arba abu (kaip du atskiri komponentai).

### Antras žingsnis: Menu
Programoje vartotojas gali rinktis tarp 6 funkcionalumų:
1. Įvesti studentų rezultatus rankiniu būdu.
2. Įvesti studentų rezultatus iš .txt failo.
3. Studentų rezultatus generuoti atsitiktinius.
4. Generuoti testavimo failus (5 failai).
5. Testuoti konteinerius (vector ir list).
6. Išeiti iš programos.

#### 1. Įvesti studentų rezultatus rankiniu būdu.
* Pasirinkus šį atvejį, varotojo klausiama į kokį konteinerį turi būti įrašomi studentų duomenys (vector ar list).
* Toliau vartotojas pasirenka kiek studentų yra grupėje (kiek studentų jis norės įvesti) - įveda skaičių.
* Vykdomas studentų duomenų įvedimas: įvedamas vardas, spaudžiama enter; įvedama pavardė, spaudžiama enter; įvedami studento pažymiai (1-10) - kaskart spausti enter, dvigubas enter nurodo, kad studentų pažymiai baigti įvesti; įvedamas studento egzamino pažymys (1-10), spaudžiama enter; kartojama su visais studentais; galutiniame etape terminalo lange išspauzdinami studentai ir jų galutiniai įvertinimai.
* Vartotojo klausiama ar jis nori testi darbą su programa, jo paisirinkimai: t - vartotojas perkeliamas į menu, n - programa baigiama.

#### 2. Įvesti studentų rezultatus iš .txt failo.
* Pasirinkus šį atvejį, automatiškai nuskaitomas pasirinktas .txt failas.
* Iš jo gauti duomenys apskaičiuojami ir išpostinami į terminalą taip pat kaip ir menu 1 atveju.
* Vartotojo klausiama ar jis nori testi darbą su programa, jo paisirinkimai: t - vartotojas perkeliamas į menu, n - programa baigiama.

#### 3. Studentų rezultatus generuoti atsitiktinius.
* Tai studentų duomenų generavimo priemonė.
* Pasirinkus šį atvejį, varototojo klausiama kiek studentų generuoti (vartotojas įveda bet kokį teigiamą skaičių, spaudžia enter).
* Vartotojo klausiama po kiek pažymių generuoti kiekvienam studentui (varottojas įveda bet kokį teigiamą skaičių, spaudžia enter).
* Į terminalą išvedami visi studentai (jų vardai ir pavardės) ir jų galutiniai įvertinimai.
* * Vartotojo klausiama ar jis nori testi darbą su programa, jo paisirinkimai: t - vartotojas perkeliamas į menu, n - programa baigiama.

#### 4. Generuoti testavimo failus (5 failai).
* Ši dalis skirta generuoti .txt failus, kurie gali būti naudojami testavimams (ši dalis neapskaičiuoja studentų galutinių įvertinimų).
* Pasirinkus šį atvejį, vartotojo klausiama po kiek pažymių generuoti kiekvienam studentui (varotojas įveda bet kokį teigiamą skaičių ir spaudžia enter), egzamino įvertinimas sugeneruojamas be varotojo įsikišimo.
* Į ekraną išvedami sukurtų failų pavadinimai, po kiek studentų juose yra ir po kiek pažymių turi kiekvienas studentas.
* Taip pat terminale rodoma ir generavimo spaortos analizė kiekvienam vailui (kiek laiko užtrunka vieno studento duomenų generavimas (bendras laikas padalintas iš studentų skaičiaus)).
* Visi failai bus randami Studentai_v1\Build aplanke.

#### 5. Testuoti konteinerius (vector ir list).
* Ši dalis skirta duomenų iš tekstinių failų apdorojimui, studentų skirstymui į gerus ir blogus, programos startegijų, bei konteinerių testavimas.
* Pasirinkus šį atvejį, vartotojo klausiama kokį konteinerį naudoti studentų duomenims: 1 - vektorius, 2 - sąrašas, 3 - vektorius ir sąrašas.
* Toliau vartotojas turi pasirinkti iš trijų strategijų (1. Copy+paste - studentų duomenys kopijuojami iš pagrindinio vektoriaus/list į du naujus; 2. Cut+paste - studentų, kurių galutiniai įvertinimai žemesni nei 5 iškerpami iš pagrindinio vektoriaus/list ir įkeliami į naują; 3. Optimizuota (sparčiausia) strategija - vektoriams tai lyg paspartinta 1 startegija, sąrašasms - antra strategija).
* Programa sukuria du .txt failus (Daugiaulygu5.txt ir Maziau5.txt). Ten yra tinkamai į dvi grupes suskirstyti studentai.
* Ekrane išvedami duomenys: kiek studentų su <5, >=5 galutinių įvertinimu ir nurodoma kiek trūko kiekviena operacija: nuskaitymas, skaičiavimas, rikiavimas, padalinimas, išvedimai ir bendras laikas.

#### 6. Išeiti iš programos.
* Skirta nutraukti programos darbą.

## 3. Programos įdiegimo instrukcija
1. Surasti vietą kur bus diegiama programa (pvz. C:\Programų failai - Windows naudotojams arba bet kuri kita direktorija).

<img width="577" height="63" alt="image" src="https://github.com/user-attachments/assets/bb1f9297-3e37-411b-9d25-fe36f51088c1" />

<img width="175" height="35" alt="image" src="https://github.com/user-attachments/assets/ed708e4c-9246-4ba1-82f0-b143889a43a4" />


3. Programų failai sukurti aplanką "Studentai_v1". <img width="170" height="31" alt="image" src="https://github.com/user-attachments/assets/5d6972da-95ca-471b-b2e1-e98aa8729baf" />

5. Perkelti į aplanką Studentai_v1 visus programos failus.

<img width="227" height="708" alt="image" src="https://github.com/user-attachments/assets/a26a2a65-b627-46da-9643-09d2a80d9c43" />

7. Įsijungti terminalą (cmd).

9. Pasirinkti tinkamą darbo aplinką (nurodyti visą kelią iki Studentai_v1 aplanko - pvz. cd "C:\Program files\Studentai_v1").
10. Terminale paleisti: build.bat.

<img width="483" height="27" alt="image" src="https://github.com/user-attachments/assets/29ca8b4c-d553-4177-8154-132ec4ba6731" />
  
12. Terminalui baigus darbą (pasidarius pauzei) galima jungti programą: 1 būdas - terminale parašyti run.bat; 2 būdas - aplanke C:\Program files\Studentai_v1\build surasti Studentai_v1.exe ir jį paspausti du kartus.

<img width="456" height="30" alt="image" src="https://github.com/user-attachments/assets/5441ca7e-acf1-4378-8ab5-5eaeb7e59b77" />



