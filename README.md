<img width="753" height="97" alt="image" src="https://github.com/user-attachments/assets/3a6c25e7-da70-4bb4-94ae-b571ec7f9e8d" />Objektinis-programavimas
Objektinio programavimo užduotys (programa).

v0.3
**1. Testuota su nešiojamu kompiuteriu (laptop)**
CPU: Intel(R) Core(TM) i5-10210U @ 1.60GHz
RAM: 8 GB
SSD: NVMe INTEL SSDPEKNW512G8

**2. Konteinerių testavimo rezultatai**
**2.1. 1 000 įrašų**
*2.1.1. Vektorius*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.005       | 0.000        | 0.002      | 0.001       | 0.002          | 0.003           | 0.013          |
| 2 | 0.003       | 0.000        | 0.001      | 0.001       | 0.005          | 0.003           | 0.013          |
| 3 | 0.002       | 0.000        | 0.001      | 0.001       | 0.002          | 0.006           | 0.012          |

*2.1.2. List*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.006       | 0.000        | 0.000      | 0.001       | 0.003          | 0.006           | 0.016          |
| 2 | 0.003       | 0.000        | 0.000      | 0.001       | 0.004          | 0.010           | 0.018          |
| 3 | 0.004       | 0.001        | 0.000      | 0.001       | 0.001          | 0.006           | 0.013          |

*2.1.3. Palyginimas*

**2.2. 10 000 įrašų**
*2.2.1. Vektorius*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.024       | 0.006        | 0.023      | 0.008       | 0.010          | 0.013           | 0.084          |
| 2 | 0.028       | 0.006        | 0.023      | 0.009       | 0.009          | 0.012           | 0.087          |
| 3 | 0.021       | 0.005        | 0.022      | 0.007       | 0.010          | 0.011           | 0.076          |

*2.2.2. List*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.023       | 0.006        | 0.003      | 0.007       | 0.010          | 0.012           | 0.061          |
| 2 | 0.022       | 0.006        | 0.004      | 0.006       | 0.011          | 0.014           | 0.063          |
| 3 | 0.035       | 0.005        | 0.003      | 0.012       | 0.011          | 0.015           | 0.081          |

*2.2.3. Palyginimas*
**2.3. 100 000 įrašų**
*2.3.1. Vektorius*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.197       | 0.055        | 0.273      | 0.053       | 0.070          | 0.093           | 0.741          |
| 2 | 0.190       | 0.058        | 0.271      | 0.049       | 0.071          | 0.115           | 0.754          |
| 3 | 0.196       | 0.056        | 0.278      | 0.053       | 0.069          | 0.101           | 0.753          |

*2.3.2. List*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 0.236       | 0.064        | 0.067      | 0.064       | 0.077          | 0.103           | 0.611          |
| 2 | 0.210       | 0.065        | 0.070      | 0.059       | 0.076          | 0.107           | 0.587          |
| 3 | 0.212       | 0.064        | 0.067      | 0.060       | 0.073          | 0.133           | 0.609          |

*2.3.3. Palyginimas*

**2.4. 1 000 000 įrašų**
*2.4.1. Vektorius*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 1.780       | 0.531        | 3.589      | 0.567       | 0.743          | 0.858           | 8.068          |
| 2 | 1.808       | 0.528        | 3.738      | 0.589       | 0.625          | 0.880           | 8.168          |
| 3 | 1.826       | 0.553        | 3.701      | 0.603       | 0.629          | 1.066           | 8.378          |

*2.4.2. List*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 2.136       | 0.614        | 1.117      | 0.735       | 0.634          | 1.014           | 6.250          |
| 2 | 1.986       | 0.634        | 1.035      | 0.600       | 0.697          | 0.952           | 5.904          |
| 3 | 2.176       | 0.686        | 1.054      | 0.604       | 0.824          | 0.976           | 6.320          |

*2.4.3. Palyginimas*

**2.5. 1 0000 000 įrašų**
*2.5.1. Vektorius*
|   | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| - | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1 | 28.066      | 5.424        | 44.473     | 7.230       | 7.104          | 10.875          | 103.172        |
| 2 | 20.859      | 5.271        | 44.968     | 6.348       | 13.486         | 23.127          | 114.059        |
| 3 | 23.532      | 5.059        | 53.048     | 6.894       | 6.318          | 8.693           | 104.544        |

*2.5.2. List*
| Nr. | Nuskaitymas | Skaičiavimas | Rikiavimas | Padalinimas | Išvedimas (<5) | Išvedimas (>=5) | Bendras laikas |
| --- | ----------- | ------------ | ---------- | ----------- | -------------- | --------------- | -------------- |
| 1   | 22.161      | 6.238        | 15.856     | 7.497       | 6.852          | 8.999           | 67.603         |
| 2   | 24.172      | 6.925        | 16.045     | 7.822       | 8.012          | 15.817          | 78.793         |
| 3   | 22.748      | 6.158        | 15.657     | 8.087       | 6.744          | 21.868          | 81.262         |

*2.5.3. Palyginimas*


**3. Nuotraukos**
- Įkeltos pirmo bandymo nuotraukos. Kitų bandymų rezultatai pateikiami lentelėse.

***Vector su 1 000 įrašų:***

<img width="443" height="340" alt="image" src="https://github.com/user-attachments/assets/01f13f38-856a-4c91-b5ee-75201f366bcc" />

***Vector su 10 000 įrašų:***

<img width="436" height="337" alt="image" src="https://github.com/user-attachments/assets/23f605ab-ba5a-4380-8ded-3075b26329c0" />

***Vector su 100 000 įrašų:***

<img width="451" height="386" alt="image" src="https://github.com/user-attachments/assets/47395e22-d9f6-4d16-9d7b-7d447f7a25a2" />

***Vector su 1 000 000 įrašų:***

<img width="455" height="382" alt="image" src="https://github.com/user-attachments/assets/ff82b40e-a6a2-42ff-ac15-fadba3365901" />

***Vector su 10 000 000 įrašų:***

<img width="470" height="335" alt="image" src="https://github.com/user-attachments/assets/efe09628-0ce0-4d04-9c99-ef1e92a6e673" />

***List su 1 000 įrašų:***

<img width="438" height="380" alt="image" src="https://github.com/user-attachments/assets/acd148c9-05cd-41c9-8b54-09b0937ad3f8" />

***List su 10 000 įrašų:***

<img width="562" height="478" alt="image" src="https://github.com/user-attachments/assets/5dcffacc-5c86-485c-b2f1-307961423485" />

***List su 100 000 įrašų:***

<img width="442" height="340" alt="image" src="https://github.com/user-attachments/assets/dfe6a8dd-42d6-413e-8a41-a03576627bd5" />

***List su 1 000 000 įrašų:***

<img width="438" height="337" alt="image" src="https://github.com/user-attachments/assets/1f40a0fa-752b-4eb0-a699-9ac04af8685f" />

***List su 10 000 000 įrašų:***

<img width="448" height="382" alt="image" src="https://github.com/user-attachments/assets/02f74b2a-9f43-428d-8eaf-22473f85e50f" />

