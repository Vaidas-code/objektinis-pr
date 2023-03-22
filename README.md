# objektinis-pr
Patobulinta v0.4 versija:
Apskaičiuojamas laikas kiek trunka tam tikri procesai kaip failo sukūrimas ir generavimas, failo, nuskaitymas, studentų ir abejingų rūšiavimas, pirmūnų įrašymas, abejingų įrašymas ir bendras laikas. Visi jie yra apskaičiuojami naudojant tris skirtingus konteinerius: 1 - vector, 2 - deque, 3 - list.
Apačioje pateikiamas matavimų laikas.

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Vector:

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo sukurimas ir generavimas  | 0.038147 | 0.256753 | 2.56139 | 25.367 | 251,8334 |
| Failo nuskaitymas | 0.024917 | 0.234419 | 2.60287 | 23.9331 | 210.7845 |
| Studentu rusiavimas pagal vidurkius | 0.010195 | 0.090712 | 0.881442 | 9.63709 | 90.7895 |
| Pirmūnų ir abejingų rūšiavimas  | 0.005934 | 0.072241 | 0.686834 | 6.818 | 65.1002 |
| Pirmūnų įrašymas | 0.003517 | 0.033959 | 0.336809 | 3.34304 | 33.7894 |
| Abejingų įrašymas | 0.002437| 0.023083 | 0.2318 | 2.3688 | 23.487 |
| Bendras laikas  | 0.074952 | 0.620455 | 6.4197 | 61.83 | 675.784 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Deque:

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo sukurimas ir generavimas  | x | x1 | x2 | x3 | x4 |
| Failo nuskaitymas | x | x1 |x2 | x3 | x4 |
| Studentu rusiavimas pagal vidurkius | x | x1 | x2 | x3 | x4 |
| Pirmūnų ir abejingų rūšiavimas  | x | x1 | x2 | x3 | x4 |
| Pirmūnų įrašymas | x | x1 | x2 | x3 | x4 |
| Abejingų įrašymas | x | x1 | x2 | x3 | x4 |
| Bendras laikas  | x | x1 | x2 | x3 | x4 |

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant List:

|   | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo sukurimas ir generavimas  | x | x1 | x2 | x3 | x4 |
| Failo nuskaitymas | x | x1 |x2 | x3 | x4 |
| Studentu rusiavimas pagal vidurkius | x | x1 | x2 | x3 | x4 |
| Pirmūnų ir abejingų rūšiavimas  | x | x1 | x2 | x3 | x4 |
| Pirmūnų įrašymas | x | x1 | x2 | x3 | x4 |
| Abejingų įrašymas | x | x1 | x2 | x3 | x4 |
| Bendras laikas  | x | x1 | x2 | x3 | x4 | 

Sistemos parametrai:
RAM: 8GB
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz
SSD: 512 GB
