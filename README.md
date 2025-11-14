<img width="717" height="145" alt="image" src="https://github.com/user-attachments/assets/6284a93f-6fed-47bb-9637-5bbfe13ea6db" /># Objektinis-programavimas (v1.1)

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
