# Objektinis programavimas (v1.2)

## v1.2 versijos atnaujinimai

Šioje versijoje pilnai realizuota "Rule of Three" bei perdengti įvesties/išvesties operatoriai, užtikrinant saugų atmintis valdymą ir intuityvų objektų naudojimą.
Pagrindiniai pakeitimai:
- Realizuotas destruktorius, kopijavimo konstruktorius ir kopijavimo priskyrimo operatorius;
- Perdengtі operator>> (įvestis) ir operator<< (išvestis);
- Išlaikyta v1.1 programos logika ir funkcionalumas;
- Užtikrintas saugus objektų kopijavimas ir atmintis valdymas.

## 1. Rule of three

- C++ programavimo kalboje egzistuoja esminis objektinio programavimo principas, vadinamas Rule of Three. Ši taisyklė teigia, kad jeigu klasei reikia bent vieno iš šių trijų specialiųjų metodų, tikėtina, kad jai reikia visų trijų:
1. Destruktorius (~Studentas())
2. Kopijavimo konstruktorius (Studentas(const Studentas&))
3. Kopijavimo priskyrimo operatorius (operator=)

### 1.1. Destruktorius

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

### 1.2. Kopijavimo konstruktorius

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


### 1.3. Kopijos priskyrimo konstruktorius

- Kopijos priskyrimo konstruktorius, tai metodas, kuris kviečia komandą: a=b. Priskiriamos vieno jau egzistuojančio objekto reikšmės kitam.
- Tikslas: Priskirti vieno egzistuojančio objekto reikšmes kitam, saugiai išvalant seną atmintį ir sukuriant naują.

Kopijos priskyrimo konstruktoriaus deklaravimas (studentas.h):

<img width="632" height="27" alt="image" src="https://github.com/user-attachments/assets/38cf0722-7767-4548-bd36-23b72bfc1962" />


Kopijos priskyrimo konstruktoriaus implementacija (studentas.cpp):

<img width="575" height="291" alt="image" src="https://github.com/user-attachments/assets/57cf2e80-476c-4e56-a062-3cb23abf8b10" />

- Šiuo atveju kopijos priskyrimo konstruktorius priskiria naujam objektui naują vardą, pavardę, pažymius, egzamino pažymį, galutinį įvertinimą pagal vidurkį ir medianą. Tai daroma su sąlyga, kad reikšmės nebus priskiriamas sau pačiam (t.y. kad nebūtų studentas1=studentas1).

## 2. Įvedimo/išvedimo operatoriai

### 2.1. Įvedimo operatorius

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

### 2.2. Išvedimo operatorius

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
