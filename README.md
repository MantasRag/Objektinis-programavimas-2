# Objektinis programavimas (v1.2)


## 1. Rule of three

- C++ programavimo principas: jei klasei reikia bent vieno iš trijų specialių metodų, greičiausiai jai reikia visų trijų:
1. Destruktorius (~Studentas())
2. Kopijavimo konstruktorius (Studentas(const Studentas&))
3. Kopijavimo priskyrimo operatorius (operator=)

### 1.1. Destruktorius

- Destruktorius yra specialus klasės metodas, kuris automatiškai iškviečiamas objektui pasibaigus jo gyvavimo laikui (pvz., pasibaigus funkcijai, sunaikinus objektą, baigus darbą su konteineriu).
- Tikslas: išvalyti objekto užimamą atmintį.
- Destruktorius buvo sukurtas v1.1 programos metu ir jis reikalingas įgyvendinant "Rule of three".

Destruktoriaus deklaravimas (studentas.h):

<img width="608" height="27" alt="image" src="https://github.com/user-attachments/assets/a669af94-5c22-4d32-ab67-e1174206e371" />


Destruktoriaus implementacija (studentas.cpp):

<img width="262" height="221" alt="image" src="https://github.com/user-attachments/assets/28e011ba-dedc-4e1b-97cd-ab999a961add" />


### 1.2. Kopijavimo konstruktorius

- Tikslas: Sukurti naują objektą kaip kito objekto gilią kopiją.
- Kopijavimo konstruktorius sukuriamas, kai reikia sukurti naują objektą kaip kito objekto kopiją.

Kopijavimo konstruktoriaus deklaravimas (studentas.h):

<img width="650" height="22" alt="image" src="https://github.com/user-attachments/assets/6b9a5b08-3db9-4c71-a435-0265ba9a1ad3" />


Kopijavimo konstruktoriaus implementacija (studentas.cpp):

<img width="791" height="108" alt="image" src="https://github.com/user-attachments/assets/26e95c00-62be-4877-8c0d-2c5682a432ed" />


### 1.3. Kopijos priskyrimo konstruktorius

- Kopijos priskyrimo konstruktorius, tai metodas, kuris kviečia komandą: a=b.
- Tikslas: Priskirti vieno egzistuojančio objekto reikšmes kitam.

Kopijos priskyrimo konstruktoriaus deklaravimas (studentas.h):

<img width="632" height="27" alt="image" src="https://github.com/user-attachments/assets/38cf0722-7767-4548-bd36-23b72bfc1962" />


Kopijos priskyrimo konstruktoriaus implementacija (studentas.cpp):

<img width="575" height="291" alt="image" src="https://github.com/user-attachments/assets/57cf2e80-476c-4e56-a062-3cb23abf8b10" />

## 2. Įvedimo/išvedimo operatoriai
