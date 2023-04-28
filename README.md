# objektinis-pr

V0.1:

Sukurti dvi 0.1 laboratorinio darbo versijos: viena pavadinimu 0.1.cpp naudoja vektorius, o kita pavadinta 0,1 masyvai.cpp naudoja masyvus, įvykdyti reikalavimus.

V0.2:

Papildymas pirmos versijos (0.1) vektorių failas. Sukurta skait funkcija, kuri skaito visus duomenis iš failo kursiokai.txt, išvedant duomenis jie yra surikiuoti pagal vardą.

V0.3:

Pakeistas (0.2 versijos) failas, v0.3 versijos faile palikta tik main funkcija, funkcijos perdėtos į Mylibfunc.h header'io failą. Funkcijų antraštės aprašytos functions.cpp faile. Mylib.h failas turi visas reikalingas bibliotekas. Pridėtas tikrinimas failo, reakcija, kas nutiktų jei failas būtų tuščias.

V0.4:

Sugeneruoti trys nauji failai: sukurtas1.txt, sukurtas2.txt, sukurtas3.txt Padaryta, taip, kad sukurtas1.txt faile būtų sugeneruojama studento vardas, pavardė, 5 atsitiktiniai namų darbų pažymiai ir atsitiktinis egzamino pažymys Šio failo duomenys nuskaitomi, po to apskaičiuojami kiekvieno žmogaus galutiniai vidurkiai, žmogaus kurio galutinis vidurkis yra didesnis už 5 yra įdedamas į vektorių pavadinimu pirmunai, o kiti į vektorių abejingi. Pirmunu vektorius yra atspausdinamas sukurtas2.txt, o abejingų - sukurtas3.txt Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus.

V0.5:

Patobulinta v0.4 versija, apskaičiuojamas laikas kiek trunka tam tikri procesai kaip failo sukūrimas ir generavimas, failo, nuskaitymas, studentų ir abejingų rūšiavimas, pirmūnų įrašymas, abejingų įrašymas ir bendras laikas. Visi jie yra apskaičiuojami naudojant tris skirtingus konteinerius: 1 - vector, 2 - deque, 3 - list.
Apačioje pateikiamas matavimų laikas.

Laikas sekundėmis, kurį užtruko programa darant tam tikrus dalykus naudojant Vector:

| Vector  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Failo nuskaitymas | 0.031199 | 0.229992 | 2.57409 | 24.8619 | 257.7845 |
| Studentų rūsiavimas pagal vidurkius | 0.009162 | 0.088798 | 0.93408 | 8.94001 | 90.7895 |
| Pirmūnų ir abejingų skirstymas | 0.005727 | 0.073684 | 0.666984 | 6.235 | 61.1687 |
| Bendras laikas  | 0.046088 | 0.392474 | 4.175150| 40.4369 | 409.7427 |

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

V1.0:

Deque, list, vector konteinerius naudojančios programos padarytos atskiruose failuose, v0.5 versijoje buvo vienoje. Kiekviena versija dabar naudoja dvi skirtingas strategijas studentų rūšiavimui, pirma strategija naudoja skirstymą iš pagrindinio konteinerio į du atskirus konteinerius ir juos atspausdina, o antra strategija iš pagrindinio konteinerio ištrina „abejingus“, t.y, kurių vidurkis <5, ir juos perkelia į kitą konteinerį, vėliau šie vektoriai yra atspausdinami.Taip pat visų šių konteinerių efektyvumas yra optimizuotas. Šių strategijų programos veikimo laikas yra palygintas:

| Vector  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudonant pirmą strategiją | 0.005699 | 0.067477 | 0.649836 | 6.37876 | 67.145677 |
| Pirmūnų ir abejingų skirstymas naudonant antrą strategiją | 0.002787 | 0.02959 | 0.32028 | 3.57024 | 31.78414 |

| Deque  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudonant pirmą strategiją | 0.002712 | 0.026349 | 0.27013 | 2.81263 | 29.17567 |
| Pirmūnų ir abejingų skirstymas naudonant antrą strategiją | 0.006756 | 0.066774 | 0.0697 | 7.53816 | 69.14874 |

| List  | 1000  | 10000  | 100000  | 1000000  | 10000000  |
|---|---|---|---|---|---|
|||||
| Pirmūnų ir abejingų skirstymas naudonant pirmą strategiją | 0.005413 | 0.053223 | 0.568018 | 6.15839 | 60.73289 |
| Pirmūnų ir abejingų skirstymas naudonant antrą strategiją | 0.002226 | 0.025487 | 0.254313 | 2.80341 | 27.43984 |

1 strategijos naudojama atmintis 10000000 failam nuo 2GB iki 2.5GB 
2 strategijos naudojama atmintis 10000000 failam nuo 1.4GB iki 1.9GB
Kaip matome iš rezultatų - antra strategija yra efektyvesnė.

Naudojimosi instrukcija:

Parsisiųskite priklausomai kurį norite konteinerio tipo programą (pvz. jei norite naudoti vector tipo konteinerio programą parsisiųskite 1.0Vector.cpp, vector.func.cpp, Vector.h, vector.lib.h), jei norite kito tipo konteinerio, naudokite atitankamai pavadintus failus.
Sudėjus šiuos failus į vieną projektą, kodas turi veikti. Jei norite naudoti funkciją, kuri perskaito duomenis iš duoto failo, įsidėkite kursiokai.txt ir kursiokai1.txt, kitu atveju, jei prašysite programos perskaityti duomenis iš failo, programa parodys, kad nėra duotų failų. PS. funkcija kuri generuoja ir skaito duomenis veiks ir be šių failų.

Naudotos sistemos parametrai:
RAM: 8GB
CPU: Intel(R) Core(TM) i5-8300H CPU @ 2.30GHz   2.30 GHz
SSD: 512 GB
