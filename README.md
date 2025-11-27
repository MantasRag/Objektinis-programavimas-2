# Objektinis programavimas (v1.5)

## v1.5 versijos atnaujinimai

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

## Testavimas

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
