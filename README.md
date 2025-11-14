# Objektinis programavimas (v1.1)

## 1. Programų veikimo laikų palyginimas.
* Lyginami v1.0 ir v1.1 programų veikimo laikai, kai praleidžiami .txt failai su 100 000 ir 1 000 000 įrašų ("stud100000.txt", "stud1000000.txt"). v1.0 naudojama struct Studentas (), v1.1 naudojama class Studentas ().
* Programoje naudojama 3 startegija sąrašams (list).

### 1.1. Bandymai su 100 000 įrašų.
#### 1.1.1. v1.0 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.208       | 0.066        | 0.061      | 0.014       | 0.086          | 0.148           | 0.583          |
| 2 | 0.206       | 0.060        | 0.056      | 0.012       | 0.079          | 0.129           | 0.542          |
| 3 | 0.218       | 0.069        | 0.066      | 0.014       | 0.084          | 0.120           | 0.571          |
| 4 | 0.204       | 0.062        | 0.056      | 0.012       | 0.084          | 0.118           | 0.536          |
| 5 | 0.201       | 0.064        | 0.057      | 0.013       | 0.085          | 0.101           | 0.521          |

#### 1.1.2. v1.1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.270       | 0.068        | 0.062      | 0.014       | 0.083          | 0.128           | 0.625          |
| 2 | 0.278       | 0.066        | 0.062      | 0.013       | 0.089          | 0.106           | 0.614          |
| 3 | 0.277       | 0.067        | 0.063      | 0.014       | 0.084          | 0.149           | 0.654          |
| 4 | 0.271       | 0.068        | 0.064      | 0.015       | 0.085          | 0.128           | 0.631          |
| 5 | 0.271       | 0.067        | 0.062      | 0.014       | 0.083          | 0.108           | 0.605          |

#### 1.1.3. Palyginimas.

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

### 1.2. Bandymai su 1 000 000 įrašų.
#### 1.2.1. v1.0 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 2.193       | 0.601        | 1.067      | 0.171       | 0.671          | 1.018           | 5.721          |
| 2 | 1.943       | 0.602        | 1.072      | 0.173       | 0.806          | 1.100           | 5.696          |
| 3 | 1.932       | 0.598        | 1.058      | 0.169       | 0.684          | 1.105           | 5.546          |
| 4 | 2.056       | 0.621        | 1.050      | 0.169       | 0.842          | 1.127           | 5.865          |
| 5 | 1.910       | 0.606        | 1.043      | 0.142       | 0.654          | 1.026           | 5.381          |

#### 1.2.2. v1.1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 2.636       | 0.656        | 1.139      | 0.185       | 0.735          | 1.138           | 6.489          |
| 2 | 2.718       | 0.660        | 1.085      | 0.184       | 0.716          | 1.040           | 6.403          |
| 3 | 2.759       | 0.680        | 1.120      | 0.160       | 0.865          | 1.155           | 6.739          |
| 4 | 2.623       | 0.662        | 1.096      | 0.186       | 0.719          | 1.116           | 6.402          |
| 5 | 2.623       | 0.655        | 1.102      | 0.182       | 0.722          | 1.093           | 6.377          |

#### 1.2.3. Palyginimas.

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

## 2. Programos eksperimentinė analizė naudojant skirtingus kompiliatoriaus optimizavimo lygius.
* Programa v1.1 bus tikrinama O1, O2 ir O3 kompiliavimo flag'ais. Bs leidžiama programa su "stud100000.txt" (100 000 įrašų), "stud1000000.txt" (1 000 000 įrašų), naudojama 3 strategija list konteineriui.

### 2.1. Bandymai su 100 000 įrašų.
#### 2.1.1. O1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.123       | 0.027        | 0.028      | 0.008       | 0.084          | 0.101           | 0.371          |
| 2 | 0.119       | 0.027        | 0.024      | 0.008       | 0.077          | 0.119           | 0.374          |
| 3 | 0.122       | 0.026        | 0.027      | 0.009       | 0.082          | 0.103           | 0.369          |

#### 2.1.2. O2 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.117       | 0.027        | 0.028      | 0.009       | 0.081          | 0.103           | 0.365          |
| 2 | 0.115       | 0.026        | 0.028      | 0.008       | 0.092          | 0.110           | 0.379          |
| 3 | 0.116       | 0.027        | 0.027      | 0.009       | 0.079          | 0.103           | 0.361          |

#### 2.1.3. O3 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.120       | 0.025        | 0.029      | 0.008       | 0.078          | 0.117           | 0.377          |
| 2 | 0.129       | 0.029        | 0.029      | 0.007       | 0.071          | 0.114           | 0.379          |
| 3 | 0.114       | 0.027        | 0.024      | 0.008       | 0.081          | 0.102           | 0.356          |

#### 2.1.4. Palyginimas.

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

### 2.2. Bandymai su 1 000 000 įrašų.
#### 2.2.1. O1 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.119       | 0.263        | 0.569      | 0.094       | 0.706          | 1.002           | 3.753          |
| 2 | 1.079       | 0.254        | 0.578      | 0.103       | 0.667          | 0.926           | 3.607          |
| 3 | 1.112       | 0.254        | 0.662      | 0.129       | 0.643          | 1.072           | 3.872          |

#### 2.2.2. O2 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.054       | 0.271        | 0.588      | 0.109       | 0.681          | 0.941           | 3.644          |
| 2 | 1.069       | 0.268        | 0.580      | 0.099       | 0.680          | 1.009           | 3.705          |
| 3 | 1.060       | 0.259        | 0.585      | 0.106       | 0.692          | 0.942           | 3.644          |

#### 2.2.3. O3 duomenys.

|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.062       | 0.283        | 0.604      | 0.102       | 0.803          | 0.910           | 3.764          |
| 2 | 1.101       | 0.262        | 0.562      | 0.107       | 0.684          | 1.125           | 3.841          |
| 3 | 1.041       | 0.259        | 0.567      | 0.102       | 0.665          | 0.917           | 3.551          |

#### 2.2.4. Palyginimas.

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

