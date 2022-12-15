# v0.1

Šioje versijoje prašoma vartotojo įvesti vardą, pavardę, namų darbų ir egzamino rezultatus. Įvesdamas duomenis, vartotojas turi galimybę pasirinkti egzamino bei namų darbų rezultatų atsitiktinį sugeneravimą. Programoje įvedimas veikia tol, kol vartotojas įveda prie vardo 0.  Pasibaigus duomenų įvedimui yra skaičiuojami kiekvieno studento galutiniai balai. Vartotojas gali pasirinkti, pagal ką nori, kad galutinis balas būtų skaičiuojamas: pagal medianą ar pagal vidurkį. Rezultatai parodomi ekrane. Iš viso programa yra realizuota dviem būdais: saugant duomenis masyve ir vektoriuje. Studentų duomenų saugojimui naudojamos struktūros.

# v0.2

Programa realizuota tik su vektoriaus tipo konteineriu. Šioje versijoje vartotojas jau gali ne tik pats įvesti duomenis, tačiau ir pasirinkti juos nuskaityti iš failo. Pasirinkus nuskaitymą iš failo, nuskaityti duomenys yra apdorojami: suskaičiuojami galutiniai rezultatai pagal medianą ir vidurkį. Galiausiai studentai yra išrūšiuojami pagal vardus (jei jie sutampa, pagal pavardes). Studento vardas, pavardė, galutiniai rezultatai išvedami į failą. Programos veikimas yra apsaugotas nuo vartotojo klaidingų įvesčių naudojant išimtis.

# v0.3

V0.3 versijoje papildyta galimybė vartotojui pasirinkti automatinį failų sukūrimą. Pasirinkus šią funkciją yra sukuriami 5 failai, susidedantys iš 1000, 10000, 100000, 1000000, 10000000 duomenų. Failai yra pirmiausia automatiškai užpildomi duomenimis ir po to nuskaitomi. Duomenys, kaip ir kitose versijose, susideda iš studento vardo, pavardės, namų darbų ir egzamino rezultatų. Namų darbų pažymių skaičius sugeneruojamas atsitiktinai (intervale nuo 4 iki 8). Vėliau programoje apskaičiuojami kiekvieno studento pažymių vidurkio ir medianos galutiniai balai, studentai suskirstomi pagal galutinį balą į dvi grupes „vargšiukai“ ir „galvočiai“. Studentai, turintys galutinį balą, mažesnį nei 5, patenka į „vargšiukų“ grupę, likę į „galvočių“. Galiausiai, yra sukuriami 2 failai, į kuriuos išvedami į „vargšiukų“ arba į „galvočių“ grupes patekę studentai.


**Lentelėje pateikta programos greičio analizė:**

|                                                             | Failų sukūrimas | Failų nuskaitymas | Failų surūšiavimas | Išvedimas į 2 naujus failus |
| -----------------------------------------|:-----------------:|:--------------------:|:--------------------:|:-----------------------------------:|
| 1000 duomenų (4 namų darbai)         | 0.0244968 s        | 0.0576413 s             | 0.008792 s                |            0.0144583 s               |
| 10000 duomenų (5 namų darbai)       | 0.264452 s          |  0.588737 s  | 0.0811146 s | 0.136569 s |
| 100000 duomenų (6 namų darbai)     | 2.87692 s           | 6.29517 s | 1.05182 s | 1.38304 s |
| 1000000 duomenų (4 namų darbai)   | 23.816 s               | 55.9998 s | 11.6267 s | 13.8139 s |
| 10000000 duomenų (6 namų darbai) | 289.097 s             | 633.95 s | 102.025 s | 139.571 s |


# v0.4

V0.4 versijoje yra papildytos programos testavimo parinktys. Vartotojas pačioje pradžioje gali pasirinkti ar nori, jog programa būtų testuojama. Pasirinkus programos testavimą yra galimybė sugeneruoti 5 atstiktinius duomenų failus, susidedančius iš 1000, 10000, 100000, 1000000, 10000000 duomenų. Nepasirinkus šios funkcijos duomenys yra testuojami su jau sukurtais 5 failais. Galiausiai vartotojas gali rinktis ar nori, jog būtų palyginti duomenų nuskaitymo ir surūšiavimo greičiai tarp vektoriaus ir list. Nepasirinkus šios funkcijos yra skaičiuojamas failo sukūrimo, nuskaitymo, surūšiavimo ir išvedimo į failą laikas naudojant vektorių.


**Nuskaitymo greičio palyginimas** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.0346628s     | 0.0407722s   |                                
| 10000 duomenų    | 0.347568s       | 0.324748s      |
| 100000 duomenų    | 3.58709s      | 3.18747s     |
| 1000000 duomenų    | 35.0725s      | 31.914s      |
| 10000000 duomenų    | 356.754s       | 318.079s          |

**Surūšiavimo greičio palyginimas** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.007319s | 0.0047511s  |
| 10000 duomenų    | 0.0684899s       | 0.052476s      |
| 100000 duomenų    | 0.912451s      | 0.517059s    |
| 1000000 duomenų    | 10.6915s     |  5.29333s     |
| 10000000 duomenų    | 88.8615s      | 53.5549s          |

Tiek surūšiuojant (padalijant į dvi grupes), tiek nuskaitant "list" konteineris buvo greitesnis už "vector"

**Sistemos parametrai:**

**CPU:** AMD Ryzen 5 5600H with Radeon Graphics 3.30 GHz
**RAM:** 2x8 GB, speed: 3200 MHz
**SSD:** 1TB, sequential read: 3500 MB/s, sequential write: 3200MB/s, random read: 250,000 IOPS, random write: 440,000 IOPS

# v1.0

Šioje versijoje praplėstos programos testavimo galimybės . Vartotojas gali pasirinkti testuoti programą pagal strategijas. Kaip ir ankstesnėse versijose programa testuojama su 1000, 10000, 100000, 1000000 ir 10000000 duomenų. Nulinėje, pirmojoje ir antrojoje strategijose studentai, esantys „vector“ ir „list“ konteineriuose, yra suskaidomi į „vargšiukus“ ir „galvočius“. Trečiojoje strategijoje minėtas suskaidymas vyksta tik „vector“ tipo konteineryje. Kiekvienoje strategijoje studentai yra surūšiuojami pagal vidurkius.

Nulinėje strategijoje skaidymas prasideda nuo konteinerių galo. Iš pradinio studentų konteinerio nuo galo po vieną imami studentai, kiekvienas studentas priskiriamas „vargšiukų“ arba „galvočių“ grupei. Priskirtas studentas yra perkeliamas į priskirtą grupę ir ištrinamas iš pradinio konteinerio.

**Surūšiavimo greičio palyginimas 0 strategija** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.0132872s     | 0.0034968s   |                                
| 10000 duomenų    | 0.121878s       | 0.0376046s      |
| 100000 duomenų    | 1.29671s      | 0.426073s     |
| 1000000 duomenų    | 15.7868s      | 4.58445s      |
| 10000000 duomenų    | 162.357s       | 51.0265s          |

Pirmojoje strategijoje skaidymo metu duomenys apie kiekvieną studentą lieka tiek pradiniame „list“ arba „vector“ tipo konteineryje, tiek naujuose („vargšiukai“ ir „galvočiai“) konteineriuose. Tokiu būdu skaidymas vyksta gana efektyviai tiek „vector“ tipo, tiek „list“ tipo konteineryje, tačiau bereikalingai naudojama atmintis. Su kiekvienais duomenimis greičiausiai grupavimas vyksta "list" tipo konteineryje.

**Surūšiavimo greičio palyginimas 1 strategija** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.0124179s     | 0.0032327s   |                                
| 10000 duomenų    | 0.128164s       | 0.0380096s      |
| 100000 duomenų    | 1.41409s      | 0.457079s     |
| 1000000 duomenų    | 16.7133s      | 5.10889s      |
| 10000000 duomenų    | 173.631s       | 63.1867s          |

Antrojoje strategijoje skaidymo metu naudojamas tik vienas naujas „list“ arba „vector“ tipo konteineris „vargšiukai“. Skaidant studentai, turintys mažesnį nei 5 galutinį vidurkio balą, yra perkeliami į naują konteinerį „vargšiukai“. Studentai, kurie buvo perkelti į konteinerį „vargšiukai“ yra ištrinami iš pradinio konteinerio. Skirstant studentus šiuo būdu atmintis yra naudojama efektyviau nei antrojoje strategijoje, tačiau „vector“ tipo konteineryje grupavimas labai suletėja.

**Surūšiavimo greičio palyginimas 2 strategija** (namų darbų skaičius: 5)
|  | Vector | List |
| :---         |     :---:      |          :---: |
| 1000 duomenų   | 0.129969s     | 0.0014597s   |                                
| 10000 duomenų    | 13.6024s       | 0.0161018s      |
| 100000 duomenų    | 2058.53s      | 0.205447s     |
| 1000000 duomenų    | -      | 2.57958s      |
| 10000000 duomenų    |  -      | 30.3356s          |

Trečiojoje strategijoje grupavimui panaudojama „copy_if()“ funkcija. Tokiu būdu visi „vargšiukai“ perkeliami į naują konteinerį. Vėliau, naudojant erase() ir remove_if() funkcijas „vargšiukai“ pašalinami iš pradinio konteinerio, jame lieka tik „galvočiai“. Šiuo būdu „vector“ tipo konteineryje duomenų sugrupavimas vyksta efektyviai. 

**Surūšiavimo greičio palyginimas 3 strategija** (namų darbų skaičius: 5)
|  | Vector |
| :---         |     :---:      |
| 1000 duomenų   | 0.0120514s     |                                
| 10000 duomenų    | 0.129385s       |
| 100000 duomenų    | 1.36529s      |
| 1000000 duomenų    | 15.6844s      | 
| 10000000 duomenų    | 163.276s       | 

# Antroji_uzduotis

# v1.1

Šioje versijoje buvo atliktas struktūros pakeitimas į klasę. Buvo atliktas programos greičio palyginimas (su list) tarp struktūros ir klasės. Vėliau buvo atlikta eksperimentinė greičio analizė priklausomai nuo kompiliatoriaus optimizavimo lygio.

Klasės ir struktūros greičių palyginimas:

|         | Struct      | Class       
|---------|-------------|-------------|
| 100000  | 0.218191 s  |  0.213576 s 
| 1000000 | 2.62365 s   | 2.74975 s   


Grupavimo greičio palyginimas pagal flag'us:

|       | O1         | O2         | O3         |
|-----------|------------|------------|------------|
| 100000   | 0.153702 s | 0.154399 s | 0.151902 s |
| 1000000  | 2.00887 s  | 2.02035 s  | 2.05989 s  | 

Testavimai atlikti su 5 namų darbais. Iš gautų rezultatų galima pamatyti, jog tiek struktūroje, tiek klasėje grupavimo greitis skiriasi nedaug. Su 100000 duomenų buvo greitesnė struktūra, o su 1000000 buvo greitesnė klasė. Grupavimo greitis taip pat nedaug skyrėsi grupuojant pagal kompiliatoriaus optimizavimo lygi. Su 100000 duomenų greičiausiai buvo o3 flag'as, o su 1000000 - o1.

# v1.2
 
Atlikta reikiamų operatorių ("Rule of three") realizacija.

# v1.5

Buvusi klasė "studentas" išskaidyta į bazinę abstrakčiąją klasę "žmogus", skirtą bendrai aprašyti žmogų, ir į jos išvestinę klasę "studentas".

# 2.0

Sukurta projekto dokumentacija

# Naudojimosi instrukcija

Parsisiuntus programą paspauskite ant "run.bat" failo
