# objektinis-pr
Patobulinta v0.4 versija:
Apskaičiuojamas laikas kiek trunka tam tikri procesai kaip failo sukūrimas ir generavimas, failo, nuskaitymas, studentų ir abejingų rūšiavimas, pirmūnų įrašymas, abejingų įrašymas ir bendras laikas. Visi jie yra apskaičiuojami naudojant tris skirtingus konteinerius: 1 - vector, 2 - deque, 3 - list.
Apačioje pateikiamas matavimų laikas.

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Vector:

| Vector  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.031199 | 0.229992 | 2.57409 | 24.8619 | 257.7845 |
| Studentų rūsiavimas pagal vidurkius | 0.009162 | 0.088798 | 0.93408 | 8.94001 | 90.7895 |
| Pirmūnų ir abejingų skirstymas | 0.005727 | 0.073684 | 0.666984 | 6.235 |
| Bendras laikas  | 0.046088 | 0.392474 | 4.175150| 40.4369 | 354.809 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Deque:

| Deque  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.026916 | 0.268572 | 3.07978 | 34.1083 | 362.4897 |
| Studentų rūsiavimas pagal vidurkius | 0.011449 | 0.109969 | 1.02035 | 13.3648 | 141.4897 |
| Pirmūnų ir abejingų skirstymas  | 0.00656 | 0.065672 | 0.690727 | 8.89532 | 95.1287 |
| Bendras laikas  | 0.044925 | 0.444213 | 4.79086 | 56.3684 | 599.1081 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant List:

| List  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.030746 | 0.228811 | 2.42725 | 22.8714 | 232.2569 |
| Studentų rūsiavimas pagal vidurkius | 0.000226 | 0.003286 | 0.051877 | 0.719292 | 6.48965 |
| Pirmūnų ir abejingų skirstymas  | 0.004719 | 0.059477 | 0.590061 | 5.99157 | 57.12398 |
| Bendras laikas  | 0.035691 | 0.291574 | 3.06919 | 29.5822 | 295.87053 | 

Sistemos parametrai:
RAM: 8GB
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz
SSD: 512 GB
