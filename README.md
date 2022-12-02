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
