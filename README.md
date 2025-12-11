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

### v1.1

#### 1. Programų veikimo laikų palyginimas.
* Lyginami v1.0 ir v1.1 programų veikimo laikai, kai praleidžiami .txt failai su 100 000 ir 1 000 000 įrašų ("stud100000.txt", "stud1000000.txt"). v1.0 naudojama struct Studentas (), v1.1 naudojama class Studentas ().
* Programoje naudojama 3 startegija sąrašams (list).

##### 1.1. Bandymai su 100 000 įrašų.
###### 1.1.1. v1.0 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.208       | 0.066        | 0.061      | 0.014       | 0.086          | 0.148           | 0.583          |
| 2 | 0.206       | 0.060        | 0.056      | 0.012       | 0.079          | 0.129           | 0.542          |
| 3 | 0.218       | 0.069        | 0.066      | 0.014       | 0.084          | 0.120           | 0.571          |
| 4 | 0.204       | 0.062        | 0.056      | 0.012       | 0.084          | 0.118           | 0.536          |
| 5 | 0.201       | 0.064        | 0.057      | 0.013       | 0.085          | 0.101           | 0.521          |

###### 1.1.2. v1.1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.270       | 0.068        | 0.062      | 0.014       | 0.083          | 0.128           | 0.625          |
| 2 | 0.278       | 0.066        | 0.062      | 0.013       | 0.089          | 0.106           | 0.614          |
| 3 | 0.277       | 0.067        | 0.063      | 0.014       | 0.084          | 0.149           | 0.654          |
| 4 | 0.271       | 0.068        | 0.064      | 0.015       | 0.085          | 0.128           | 0.631          |
| 5 | 0.271       | 0.067        | 0.062      | 0.014       | 0.083          | 0.108           | 0.605          |

###### 1.1.3. Palyginimas.

| Stulpelis       | Vidurkis v1.0 | Vidurkis v1.1 | Greitesnė versija |
| --------------- | ------------- | ------------- | ----------------- |
| Nuskaitymas     | 0.2074        | 0.2734        | **v1.0**          |
| Skaičiavimas    | 0.0642        | 0.0672        | **v1.0**          |
| Rikiavimas      | 0.0592        | 0.0626        | **v1.0**          |
| Padalinimas     | 0.0130        | 0.0140        | **v1.0**          |
| Išvedimas (<5)  | 0.0836        | 0.0848        | **v1.0**          |
| Išvedimas (>=5) | 0.1232        | 0.1238        | **v1.0**          |
| Bendras laikas  | 0.5506        | 0.6258        | **v1.0**          |

* Visuose matuojamuose aspektuose v1.0 veikia greičiau už v1.1, nors skirtumas kai kuriuose stulpeliuose yra nedidelis.
* Bendras laikas v1.1 buvo apie 13.7 % ilgesnis nei v1.0.

##### 1.2. Bandymai su 1 000 000 įrašų.
###### 1.2.1. v1.0 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 2.193       | 0.601        | 1.067      | 0.171       | 0.671          | 1.018           | 5.721          |
| 2 | 1.943       | 0.602        | 1.072      | 0.173       | 0.806          | 1.100           | 5.696          |
| 3 | 1.932       | 0.598        | 1.058      | 0.169       | 0.684          | 1.105           | 5.546          |
| 4 | 2.056       | 0.621        | 1.050      | 0.169       | 0.842          | 1.127           | 5.865          |
| 5 | 1.910       | 0.606        | 1.043      | 0.142       | 0.654          | 1.026           | 5.381          |

###### 1.2.2. v1.1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 2.636       | 0.656        | 1.139      | 0.185       | 0.735          | 1.138           | 6.489          |
| 2 | 2.718       | 0.660        | 1.085      | 0.184       | 0.716          | 1.040           | 6.403          |
| 3 | 2.759       | 0.680        | 1.120      | 0.160       | 0.865          | 1.155           | 6.739          |
| 4 | 2.623       | 0.662        | 1.096      | 0.186       | 0.719          | 1.116           | 6.402          |
| 5 | 2.623       | 0.655        | 1.102      | 0.182       | 0.722          | 1.093           | 6.377          |

###### 1.2.3. Palyginimas.

| Stulpelis       | Vidurkis v1.0 | Vidurkis v1.1 | Greitesnė versija |
| --------------- | ------------- | ------------- | ----------------- |
| Nuskaitymas     | 1.8068        | 2.6718        | **v1.0**          |
| Skaičiavimas    | 0.6056        | 0.6626        | **v1.0**          |
| Rikiavimas      | 1.0580        | 1.1084        | **v1.0**          |
| Padalinimas     | 0.1648        | 0.1794        | **v1.0**          |
| Išvedimas (<5)  | 0.7314        | 0.7514        | **v1.0**          |
| Išvedimas (>=5) | 1.0752        | 1.1084        | **v1.0**          |
| Bendras laikas  | 5.6418        | 6.4820        | **v1.0**          |

* Bendras laikas v1.1 buvo apie 14.9% ilgesnis nei v1.0.

#### 2. Programos eksperimentinė analizė naudojant skirtingus kompiliatoriaus optimizavimo lygius.
* Programa v1.1 bus tikrinama O1, O2 ir O3 kompiliavimo flag'ais. Bs leidžiama programa su "stud100000.txt" (100 000 įrašų), "stud1000000.txt" (1 000 000 įrašų), naudojama 3 strategija list konteineriui.

##### 2.1. Bandymai su 100 000 įrašų.
###### 2.1.1. O1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.123       | 0.027        | 0.028      | 0.008       | 0.084          | 0.101           | 0.371          |
| 2 | 0.119       | 0.027        | 0.024      | 0.008       | 0.077          | 0.119           | 0.374          |
| 3 | 0.122       | 0.026        | 0.027      | 0.009       | 0.082          | 0.103           | 0.369          |

* **.exe dydis: 211 KB.**

###### 2.1.2. O2 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.117       | 0.027        | 0.028      | 0.009       | 0.081          | 0.103           | 0.365          |
| 2 | 0.115       | 0.026        | 0.028      | 0.008       | 0.092          | 0.110           | 0.379          |
| 3 | 0.116       | 0.027        | 0.027      | 0.009       | 0.079          | 0.103           | 0.361          |

* **.exe dydis: 186 KB.**

###### 2.1.3. O3 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.120       | 0.025        | 0.029      | 0.008       | 0.078          | 0.117           | 0.377          |
| 2 | 0.129       | 0.029        | 0.029      | 0.007       | 0.071          | 0.114           | 0.379          |
| 3 | 0.114       | 0.027        | 0.024      | 0.008       | 0.081          | 0.102           | 0.356          |

* **.exe dydis: 205 KB.**

###### 2.1.4. Palyginimas.

| Stulpelis       | O1     | O2     | O3     | Greitesnė versija |
| --------------- | ------ | ------ | ------ | ----------------- |
| Nuskaitymas     | 0.1213 | 0.1160 | 0.1210 | **O2**            |
| Skaičiavimas    | 0.0267 | 0.0267 | 0.0270 | **O1 / O2**       |
| Rikiavimas      | 0.0263 | 0.0277 | 0.0273 | **O1**            |
| Padalinimas     | 0.0083 | 0.0087 | 0.0077 | **O3**            |
| Išvedimas (<5)  | 0.0810 | 0.0840 | 0.0767 | **O3**            |
| Išvedimas (>=5) | 0.1077 | 0.1053 | 0.1110 | **O2**            |
| Bendras laikas  | 0.3713 | 0.3683 | 0.3707 | **O2**            |

* Greičiausia vidutinė programa pagal bendrą laiką yra O2 (0.368 s), nors skirtumas su O1 ir O3 nėra didelis (~0.003–0.004 s).
* Skirtumas tarp O1, O2 ir O3 yra nedidelis – tik ~0.8 % greičiau O2 ir ~0.16 % greičiau O3 lyginant su O1.

##### 2.2. Bandymai su 1 000 000 įrašų.
###### 2.2.1. O1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.119       | 0.263        | 0.569      | 0.094       | 0.706          | 1.002           | 3.753          |
| 2 | 1.079       | 0.254        | 0.578      | 0.103       | 0.667          | 0.926           | 3.607          |
| 3 | 1.112       | 0.254        | 0.662      | 0.129       | 0.643          | 1.072           | 3.872          |

* **.exe dydis: 211 KB.**

###### 2.2.2. O2 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.054       | 0.271        | 0.588      | 0.109       | 0.681          | 0.941           | 3.644          |
| 2 | 1.069       | 0.268        | 0.580      | 0.099       | 0.680          | 1.009           | 3.705          |
| 3 | 1.060       | 0.259        | 0.585      | 0.106       | 0.692          | 0.942           | 3.644          |

* **.exe dydis: 186 KB.**

###### 2.2.3. O3 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.062       | 0.283        | 0.604      | 0.102       | 0.803          | 0.910           | 3.764          |
| 2 | 1.101       | 0.262        | 0.562      | 0.107       | 0.684          | 1.125           | 3.841          |
| 3 | 1.041       | 0.259        | 0.567      | 0.102       | 0.665          | 0.917           | 3.551          |

* **.exe dydis: 205 KB.**

###### 2.2.4. Palyginimas.

| Stulpelis       | O1     | O2     | O3     | Greitesnė versija |
| --------------- | ------ | ------ | ------ | ----------------- |
| Nuskaitymas     | 1.1033 | 1.0610 | 1.0683 | **O2**            |
| Skaičiavimas    | 0.2573 | 0.2660 | 0.2680 | **O1**            |
| Rikiavimas      | 0.6030 | 0.5847 | 0.5777 | **O3**            |
| Padalinimas     | 0.1087 | 0.1047 | 0.1037 | **O3**            |
| Išvedimas (<5)  | 0.6720 | 0.6843 | 0.7173 | **O1**            |
| Išvedimas (>=5) | 1.0000 | 0.9833 | 0.9840 | **O2**            |
| Bendras laikas  | 3.744  | 3.664  | 3.719  | **O2**            |

* Eksperimentas parodė, kad kompiliatoriaus optimizacijos flag’ai O1, O2 ir O3 turi nedidelį, bet matomą poveikį programos našumui. Bendras vidutinis laikas buvo mažiausias naudojant O2 flag’ą (3.664 s), kuris buvo apie 2,1 % greitesnis nei O1 ir šiek tiek pranašesnis už O3. Skirtumai tarp optimizacijos lygių yra gana nedideli, todėl programos našumas iš esmės stabilus visais flag’ais, o O2 suteikia lengvą pranašumą bendroje spartoje.

### v1.2

Šioje versijoje pilnai realizuota "Rule of Three" bei perdengti įvesties/išvesties operatoriai, užtikrinant saugų atmintis valdymą ir intuityvų objektų naudojimą.
Pagrindiniai pakeitimai:
- Realizuotas destruktorius, kopijavimo konstruktorius ir kopijavimo priskyrimo operatorius;
- Perdengtі operator>> (įvestis) ir operator<< (išvestis);
- Išlaikyta v1.1 programos logika ir funkcionalumas;
- Užtikrintas saugus objektų kopijavimas ir atmintis valdymas.

#### 1. Rule of three

- C++ programavimo kalboje egzistuoja esminis objektinio programavimo principas, vadinamas Rule of Three. Ši taisyklė teigia, kad jeigu klasei reikia bent vieno iš šių trijų specialiųjų metodų, tikėtina, kad jai reikia visų trijų:
1. Destruktorius (~Studentas())
2. Kopijavimo konstruktorius (Studentas(const Studentas&))
3. Kopijavimo priskyrimo operatorius (operator=)

##### 1.1. Destruktorius

- Destruktorius yra specialus klasės metodas, kuris automatiškai iškviečiamas objektui pasibaigus jo gyvavimo laikui.
- Destruktorius iškviečiamas, kai:
1. Objektas išeina iš scope'o (uždaromas });
2. Konteineris sunaikina elementus (pvz. vektorius.clear(), vektorius.erase());
3. Programa baigia darbą ir kitais atvejais.
 
- Tikslas: išvalyti objekto užimamą atmintį.
- Destruktorius buvo sukurtas v1.1 programos metu ir jis reikalingas įgyvendinant "Rule of three".

Destruktoriaus deklaravimas (studentas.h):

<img width="608" height="27" alt="image" src="https://github.com/user-attachments/assets/a669af94-5c22-4d32-ab67-e1174206e371" />


Destruktoriaus implementacija (studentas.cpp):

<img width="262" height="221" alt="image" src="https://github.com/user-attachments/assets/28e011ba-dedc-4e1b-97cd-ab999a961add" />

- Šiuo atveju destruktorius išvalo studento vardą, pavardę, pažymius, nustato egzamino įvertinimą į 0, galutinį pagal vidurkį ir pagal medianą įvertinimus nutato į 0.0. 

##### 1.2. Kopijavimo konstruktorius

- Kopijavimo konstruktorius sukuria naują objektą kaip kito objekto gilią kopiją (deep copy).
- Tikslas: Sukurti naują objektą kaip kito objekto gilią kopiją.
- Kopijavimo konstruktorius kviečiamas, kai naudojama;
1. push_back() - objektas kopijuojamas į konteinerį;
2. Inicializacija metu (pvz. Studentas st2=st1);
3. Perdavimas į funkciją pagal reikšmę - void f(Studentas s) ir kitais atvejais.

Kopijavimo konstruktoriaus deklaravimas (studentas.h):

<img width="650" height="22" alt="image" src="https://github.com/user-attachments/assets/6b9a5b08-3db9-4c71-a435-0265ba9a1ad3" />


Kopijavimo konstruktoriaus implementacija (studentas.cpp):

<img width="791" height="108" alt="image" src="https://github.com/user-attachments/assets/26e95c00-62be-4877-8c0d-2c5682a432ed" />


##### 1.3. Kopijos priskyrimo konstruktorius

- Kopijos priskyrimo konstruktorius, tai metodas, kuris kviečia komandą: a=b. Priskiriamos vieno jau egzistuojančio objekto reikšmės kitam.
- Tikslas: Priskirti vieno egzistuojančio objekto reikšmes kitam, saugiai išvalant seną atmintį ir sukuriant naują.

Kopijos priskyrimo konstruktoriaus deklaravimas (studentas.h):

<img width="632" height="27" alt="image" src="https://github.com/user-attachments/assets/38cf0722-7767-4548-bd36-23b72bfc1962" />


Kopijos priskyrimo konstruktoriaus implementacija (studentas.cpp):

<img width="575" height="291" alt="image" src="https://github.com/user-attachments/assets/57cf2e80-476c-4e56-a062-3cb23abf8b10" />

- Šiuo atveju kopijos priskyrimo konstruktorius priskiria naujam objektui naują vardą, pavardę, pažymius, egzamino pažymį, galutinį įvertinimą pagal vidurkį ir medianą. Tai daroma su sąlyga, kad reikšmės nebus priskiriamas sau pačiam (t.y. kad nebūtų studentas1=studentas1).

#### 2. Įvedimo/išvedimo operatoriai

##### 2.1. Įvedimo operatorius

- Programa palaiko tris studentų duomenų įvedimo būdus:
1. Rankinis duomenų įvedimas ivesk();
2. Duomenų nuskaitymas iš .txt failo ivesti_is_failo();
3. Atsitiktinių duomenų generavimas generuoti_atsitiktinius().

- Dėl skirtingų duomenų gavimo būdų nebuvo galima pritaikyti įvedimo operatorių kiekvienam įvesties būdui, nes reikėtų keisti jų pačių duomenų įvedimo logikas.
- Dabartinis įvesties operatorius yra pritaikytas rankiniam duomenų įvedimui (įgyvendinats pagal ivesk() funkcijos logiką).
1. Operatorius nereikalauja, kad pažymių skaičius būtų žinomas iš anksto - operatorius reaguoja į dvigubą ENTER reiškiantį, kad visi pažymiai jau įvesti ir vartotojas nukreipiamas į egzamino įvertinimo įvedimą.
2. Operatorius yra interaktyvus, reikalauja vartotojo veiksmo kaskart įvedant reikšmes (taip kaip ir buvo ivesk() funkcijos atveju). Kas kart įvedus reikšmmes (duomenis) terminale vartotojas mato nurodymus, ko iš jo toliau reikalauja programa duomenų įvedimo metu.

Norint pritaikyti įvesties operatorių ivesti_is_failo() ar generuoti_atsitiktinius() funkcijoms reiktų keisti patį operatorių, kad atitiktų tam tikrą vieną universalią logiką visiems įvedimo būdams. Tektų keisti ivesk() logiką, kad ji nebūtų tokia interaktyvi kaip buvo iki šiol. Duomenų įvedimo iš failo metu duomenys yra surašyti eilutėmis, tad generavimo funkcija turėtų būti keičiama, kad jai tiktų ir būsimas operatorius. Ivesk() funkcijoje dinktų interaktyvumas, vartotojo būtų prašoma įvesti visus duomenis viena eilute (imituojant tekstinio failo struktūrą).

Ivedimo operatoriaus deklaravimas (studentas.h):

<img width="637" height="27" alt="image" src="https://github.com/user-attachments/assets/f9629286-7463-4ee3-a6d5-e24e9dda55b5" />

Įvesties operatoriaus veikimas ivesk() funkcijos atveju (operatorius išsaugojo visą ivesk() funkcijos logiką):

<img width="786" height="247" alt="image" src="https://github.com/user-attachments/assets/6bd7d614-f5c5-47cd-9eef-1947c82cbe9f" />

Įvedimo operatoriaus panaudojimas kode:

<img width="391" height="167" alt="image" src="https://github.com/user-attachments/assets/79817966-4494-4016-a818-870c486931a3" />

##### 2.2. Išvedimo operatorius

- Programa palaiko du išvedimo būdus:
1. Išvedimas į .txt failą issaugoti_i_txt();
2. Išvedimas į terminalą (su duomenų saugojimo vieta (spausdinti_rezultatus()) arba be jos (spausdinti_rezultatus1())).

- Dabartinis išvedimo operatorius yra pritaikytas duomenų išvedimui į terminalą, kai duomenys išvedami be duomenų saugojimo vietos. Operatorius pritaikytas funkcijai spausdinti_rezultatus() ir turi visą jos logiką, formatus, lygiavimus.
- Duomenų išvedimas į terminalą vyksta lentelės formatu (nurodomi lentelės kontūrai), išvedimas į .txt failą taip pat lentelės formatu, tačiau nenurodomi lentelės kontūrai. Norint, kad išvedimo operatorius veiktų abiejų išvedimų būdų, reiktų suvienodinti formatus, be to reiktų atsisakyti funkcijos spausdinti_rezultatus1() - nes jai reikia papildomo kintamojo, kurio nėra kitose dvejose funkcijose (duomenų saugojimo vietos parodymas).

Išvedimo operatoriaus deklaravimas (studentas.h):

<img width="687" height="28" alt="image" src="https://github.com/user-attachments/assets/deab24cb-e269-4956-a339-d17e4c701f62" />

Išvedimo operatoriaus veikimas spausdinti_rezultatus() funkcijos atveju (operatorius turi visą spausdinti_rezultatus() funkcijos logiką):
(išvedima yra lentelės kontūrai, kurie kuriami pačio operatoriaus)

<img width="687" height="223" alt="image" src="https://github.com/user-attachments/assets/12c2b2e2-fbfa-43b6-b971-7bf40a3df68e" />

(su spausdinti_rezultatus() papildomu kodu)

<img width="682" height="286" alt="image" src="https://github.com/user-attachments/assets/ffcaf77b-7f24-4fa9-947a-5b7405ea2597" />


Išvedimo operatoriaus panaudojimas kode (kodo fragmentas):

<img width="861" height="382" alt="image" src="https://github.com/user-attachments/assets/691fd19b-86c3-4b8f-94d5-1b209872b533" />

### v1.5

- Versija v1.5 įgyvendina objektinio programavimo paveldėjimo ir abstrakcijos principus, pertvarkant programos architektūrą pagal klasių hierarchijos modelį. Šioje versijoje sukurta abstrakti bazinė klasė Zmogus, kuri apibrėžia bendrus visų žmonių atributus (vardas, pavardė) ir metodų sąsają. Iš šios bazinės klasės išvedama Studentas klasė, kuri paveldi bendrus atributus ir prideda studento specifinę informaciją - namų darbų pažymius, egzamino rezultatus ir galutinių įvertinimų skaičiavimo logiką.

- Pagrindinė v1.5 versijos naujovė - Zmogus klasė yra abstrakti, tai reiškia, kad jos objektų sukurti tiesiogiai negalima. Tai pasiekiama naudojant grynai virtualią funkciją (virtual void spausdinti() = 0), kuri privalo būti implementuota išvestinėse klasėse. Toks sprendimas užtikrina, kad sistema dirbtų tik su konkrečiais žmonių tipais (studentais, dėstytojais ir pan.), o ne su abstrakčiu "žmogumi".

Abi klasės - ir Zmogus, ir Studentas - pilnai įgyvendina "Rule of Three" taisyklę, kuri yra fundamentalus C++ programavimo principas dirbant su dinamine atmintimi ir objektų kopijomis. Tai reiškia, kad abi klasės turi:
- Kopijavimo konstruktorių (Copy Constructor) - leidžia korektiškai sukurti objekto kopiją;
- Priskyrimo operatorių (Copy Assignment Operator) - leidžia priskirti vieno objekto reikšmes kitam;
- Destruktorių (Destructor) - užtikrina tinkamą resursų atlaisvinimą.

Programa pradedama demonstracijos režimu, kuris parodo, kad:
- Zmogus objektų sukurti neįmanoma (kompiliatorius grąžina klaidą);
- Studentas objektus kurti galima ir jie pilnai veikia;
- Paveldėjimas veikia korektiškai - Studentas objektas gali naudoti Zmogus metodus.

#### Testavimas

- v1.5 versijos testavimas atliekamas naudojant funkciją demonstuotiu_abstrakcia_klase().
- Ši funkcija automatiškai paleidžiama programos pradžioje ir vizualiai demonstruoja, kad "Zmogus" klasė yra abstrakti ir jos objektų sukurti negalima, tuo tarpu derived "Studentas" klasės objektus kurti galima be problemų.

Testavimo eiga:
1. Įrodoma, kad klasė Zmogus yra abstrakti. Ekrane išspausdinamos dvi kodo eilutės, kurios bandytų sukurti Zmogus objektus. Kadangi klasė Zmogus yra abstrakti, tai terminale gausime klaidas. Šios eilutės yra:
- Zmogus zmogus1;
- Zmogus zmogus2 ("Jonas", "Jonaitis");

2. Parodoma, kad derived klasė Studentas yra veiksni, galima kurti objektus.
- Sėkmingai sukuriamas Studentas objektas su vardu "Petras" ir pavarde "Petraitis";
- Pridedami pažymiai (8 ir 9) bei egzamino įvertinimas (10).

Rodoma, kad Studentas paveldi metodus iš Zmogus:
- studentas1.vard() - metodas iš bazinės Zmogus klasės;
- studentas1.pav() - metodas iš bazinės Zmogus klasės;
- studentas1.paz() - metodas iš Studentas klasės;
- studentas1.egzas() - metodas iš Studentas klasės.

Ekrano kopija (funkcija demonstruoti_abstrajcia_klase()):

<img width="863" height="597" alt="image" src="https://github.com/user-attachments/assets/85a9a2c1-a6e1-49da-8cd2-6413159874c9" />

Ekrano kopija (terminalas su išvesta informacija):

<img width="662" height="245" alt="image" src="https://github.com/user-attachments/assets/220d8a47-d42c-461f-9677-9b7f1f24128d" />

### v2.0

#### v2.0 atnaujinimai:
- Sukurta Doxygen html programos dokumentacija. Plačiai aprašytos Studentas() ir Zmogus() klasės. Dokumentacijoje taip pat galima rasti kitas programos funkcijas (visas, kurios buvo naudotos), lengvai randami jų kodai.
- Realizuuoti unit testai klasėms Studentas() ir Zmogus() naudojant "Google test". Testų paleidimams sukurti atskiri nuo pagrindinės programos .exe failai (test_studentas.exe, test_zmogus.exe), kurie sukuriami su bendru build.bat failu, o paleidžiami du kartus paspaudus tuos .exe failus arba cmd terminale paleidus run_tests.bat failą.
Studentas klasės testai (8):
1. 
Zmogus klasės testai (4):

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
