# Objektinis_prog.

Testavimų laikas su std::vector<>:
| Testavimas                          | 1000         | 10000        | 100000       | 1000000       | 10000000       |
|-------------------------------------|--------------|--------------|--------------|---------------|----------------|
| Failo nuskaitymas                   | 0.0161301 s. | 0.0150152 s. | 0.6390286 s. | 5.9425418 s.  | 57.2474174 s.  |
| Rūšiavimas                          | 0.0014783 s. | 0.0403004 s. | 0.5480623 s. | 6.4187955 s.  | 73.5052287 s.  |
| Padalinimas į dvi grupes            | 0.0013910 s. | 0.0178912 s. | 0.0533789 s. | 0.3923582 s   | 4.20718663 s.  |
| Moksliukų studentų įrašymas į failą | 0.0143645 s. | 0.0583679 s. | 0.4431161 s. | 3.9178315 s.  | 35.8384914 s.  |
| Varkšiukų studentų įrašymas į failą | 0.0156269 s. | 0.0503563 s. | 0.4228619 s. | 3.7021182 s.  | 36.0031826 s.  |
| Bendras darbo laikas                | 0.0615098 s. | 0.1819310 s. | 2.1064478 s. | 20.3736452 s. | 206.8016067 s. |

--------------------------------------------------------------------------------------------------------------------

Testavimu laikas su std::list<>:
| Testavimas                          | 1000         | 10000        | 100000       | 1000000       | 10000000       |
|-------------------------------------|--------------|--------------|--------------|---------------|----------------|
| Failo nuskaitymas                   | 0.0217746 s. | 0.1002813 s. | 0.9181412 s. | 9.4294152 s.  | 93.4659381 s.  |
| Rūšiavimas                          | 0.0012641 s. | 0.0144397 s. | 0.1002418 s. | 1.2525672 s.  | 16.8353772 s.  |
| Padalinimas į dvi grupes            | 0.0019113 s. | 0.0156034 s. | 0.1692366 s. | 1.3499539 s   | 14.6152694 s.  |
| Moksliukų studentų įrašymas į failą | 0.0154889 s. | 0.0377556 s. | 0.3541831 s. | 3.8977149 s.  | 36.7836225 s.  |
| Varkšiukų studentų įrašymas į failą | 0.0142214 s. | 0.0312423 s. | 0.3632089 s. | 3.2374803 s.  | 34.9812793 s.  |
| Bendras darbo laikas                | 0.0546603 s. | 0.1993223 s. | 1.9050116 s. | 19.1671315 s. | 196.6814865 s. |

--------------------------------------------------------------------------------------------------------------------

Parametrai:
CPU: Intel(R) Core(TM) i5-7200U CPU @ 2.50 GHz
RAM: 12 GB
SSD: Kingston SA400S37240G

--------------------------------------------------------------------------------------------------------------------


| Testavimas                          | 1000         | 10000        | 100000       | 1000000       | 10000000       |
|-------------------------------------|--------------|--------------|--------------|---------------|----------------|
| 1 strategija su List                | 0.0098732 s. | 0.0440061 s. | 0.5137565 s. | 5.1800251 s.  | 50.7912652 s.  |
| 2 strategija su List                | 0.0110668 s. | 0.0423116 s. | 0.4937260 s. | 6.0777859 s.  | 44.8620512 s.  |
| 3 strategija su List                | 0.0106287 s. | 0.0407648 s. | 0.5052481 s. | 4.7841617 s.  | 45.3173472 s.  |
| 1 strategija su Vector              | 0.0156205 s. | 0.0500919 s. | 0.4431161 s. | 4.2753459 s.  | 38.6643501 s.  |
| 2 strategija su Vector              | 0.0410633 s. | 0.4178231 s. | 4.2528619 s. | 43.212852 s.  | 468.044373 s.  |
| 3 strategija su Vector              | 0.0100884 s. | 0.0585626 s. | 0.4266371 s. | 4.0946211 s.  | 34.3562963 s.  |

-------------------------------------------------------------------------------------------------------------------
v0.1 release:

Šioje versijoje yra apdorojami studentų duomenis. Duomenų pateikimas apdorojimui yra dviem būdais, pirmasis: naudotojas įveda duomenis pats, antrasis: duomenis yra nuskaitomi iš naudotojo pateikto failo. Vartotojui pasirinkus įvesti duomenis pačiam, yra galimybė duomenis generuoti atsitiktine tvarka. Taip pat jei nežinomas studento namų darbų skaičius, duomenis galima įvedinėti iki pirmo ‚Enter‘. Įvedus duomenis yra galimybė pasirinkti pagal ką skaičiuoti studento galutinį balą (vidurkį ar medianą). Duomenis įvedus naudotojui, rezultatas išvedamas į ekraną lentelės pavidalu (Vardas, Pavarde, Galutinis balas(pagal pasirinktą kriterijų)). Duomenis nuskaičius iš failo, rezultatas įrašomas į failą ‚rez.txt‘, kuriame yra studento: vardas, pavardė, galutinis balas pagal medianą ir vidurkį.

Naudojimasis: Paleidus programa vartotojas pasirenka ar nori skaityti duomenis iš failo, jei taip – rezultatas apskaičiuojamas ir įrašomas į failą rez.txt. Jei nenorime skaityti duomenų iš failo, įvedame studentų skaičių. Tada apie kiekvieną studentą įvedame: vardą ir pavardę. Pasirenkame ar norime generuoti namų darbų rezultatus atsitiktine tvarka, jei taip įvedame studento namų darbų skaičių, nes teik atsitiktinių rezultatų bus sugeneruota. Jei nežinome namų darbų skaičiaus jis sugeneruojamas atsitiktinai. Jei generuoti rezultatų nenorime, įvedame studento namų darbų skaičių, ir kiekvieno namų darbo rezultatą, jei namų darbų skaičiaus nežinome įvedinėjame namų darbų rezultatus iki pirmo ‘Enter’. Galiausiai pasirenkame ar norime generuoti egzamino rezultatą atsitiktine tvarka, jei ne ji įvedame. Ir pasirenkame galutinio balo kriterijų (medianą arba vidurkį).

Išvados: programos veikimas priklauso nuo naudotojo, nors šioje programoje yra naudojama 'exception handling', tačiau vartotojas visada gali rasti būdą 'nulaužti' programą. Manau vienas iš galimų šios programos minusų yra toks: norint įvesti studentų duomenis reikia žinoti kiek jų yra, tai nevisada (o galnūt ir dažnai) yra nepatoku. Tarkime norint įvesti sarašą studentų reikia suskaičiuoti kiek jų yra, bet skaičiuodami galime padaryti klaidą, todėl reiktų vesti per nauja.Taip pat manau, kad šiooje programoje yra patogus tai, kad galime įvesti studento namų darbų rezultatus nežinodami jų skaičiaus (t.y. vesti iki pirmo 'Enter').  

v.02 release:

Šioje versijoje yra sugeneruojami 5 skirtinų dydžių failai, kuriame yra informacija apie studentus: vardas, pavarde penki namų darbų rezultatai ir egzamino rezultatas. Kiekvieno dydžio sugeneruota studentų grupė yra įrašoma į ‚vector‘ tipo konteinerius, šie konteineriai yra įrašomi į failas (pvz.: 1000_studentai.txt). Apskaičiuojamas kiekvieno studento galutinis balas(pagal vidurkį), šie rezultatai yra įrašomi į failus (pvz.: rez_1000_studentai.txt). Tada kiekvieno failo studentai yra dalinami į dvi kategorijas ‚moksliukai‘ (galutinis balas>=5) ir ‚varksiukai‘ (galutinis balas<5). Padalinti studentai įrašomi į skirtingus failus (pvz.: moksliukai_1000_studentai.txt, varksiukai_1000_studentai.txt). Šiuose failuose esantis studentai yra išrikiuojami pagal vieną iš trijų naudotojo pasirinktų kriterijų (vardą, pavardę arba galutinį balą). Ir galiausiai yra matuojamas laikas: failų su skirtingų dydžių studentų grupėmis generavimas, šių studentų padalinimas į dvi grupes, ‚varksiuku‘ ir ‚moksliuku‘ įrašymo į failus, ir šių failų rikiavimo laikas.

Naudojimasis: Paleidus programa yra generuojami skirtingų dydžių failai. Naudotojui reikia pasirinkti kokia tvarka jis nori, kad rezultatai būtų išrikiuoti failuose(v/V – pagal vardą, p/P - pagal pavardę, g/G – pagal galutinį balą) su ‚moksliuku‘ ir ‚varksiuku‘ vektoriais. Rezultatas - kiekvieno skirtingo dydžio failo darbo laikas t.y. kiek užtruko: generavimas(jei norime generuoti), nuskaitymas, rikiavimas, padalinimas į dvi grupes, grupių įrašymas į failus ir bendras darbo prie failo laikas.

Išvados: darbo prie failų laikas yra proporcingas, kadangi failai didėja kas 10 kartų, taip pat ir laikas didėja kas 10 kartų. Ilgiausiai veikia failo rušiavimas pagal pasirinktą parametrą. Greičiausiai veikia bendro konteinerio padalyjimas į du atsižvelgiand į stuudento galutinį balą. 'varksiuku' ir 'moksliuku' vvector konteinerių įrašymas į failus yra labai panašus nes jie yra labai panašaus dydžio.



v.03 release:

Šis releasas yra identiškas v.02 releasui tik čia vietoje ‚vector‘ yra naudojamas ‚list‘ ir pasirinktus duomenis apie studentą įvesti ranka, rodoma studento vieta kompiuterio atmintyje. Visą kitą yra tas pats kaip ir v.02 versijoje.

Naudojimasis: paleidus programa vartotojas pasirenka ar nori matuoti laiką dirbant su skirtingo dydžio failais. Jei taip, jis turi pasirinkti: rušiavimo tvarką ir ar nori generuoti naujus failus, ar naudoti jau esamus. Rezultatas - kiekvieno skirtingo dydžio failo darbo laikas t.y. kiek užtruko: generavimas(jei norime generuoti), nuskaitymas, rikiavimas, padalinimas į dvi grupes, grupių įrašymas į failus ir bendras darbo prie failo laikas. Jei nenorime matuoti laiko, duomenis duomenis vartotojas įveda pats kaip ir v.01 versijoje, pateikiame galutinio balo rezultatus pagal naudotojo pasirinktą kriterijų (vidurkį ar medianą). Taip pat pateikiame kiekvieno studento saugojimo atmintyje nuorodą.

Išvados: pakeitus vector į list, bendras darbo prie failo laikas išlieka labai panašus, tačiau list atvejų failo nuskaitymas yra lėtesnis, bet greičiau veikia rikiavimas pagal naudotojo pasirinktą parametrą. Bendro konteinerio suskirstymas i du pagal studento galutini balą yra labai panašus taip pat. 



v.1 release:

Šioje versijoje yra matuojamas darbo prie 5 skiringo dydžio failų laikas (kaip ir  v.02 ar v.03 versijose) list ir vector atvejais, priklausomai nuo studentų susiskirstymo į dvi grupes strategijos. Pirmiausia yra sugeneruojamas n studentų dydžio konteineris kuris yra įrašomas į failą, tada failas yra nuskaitomas, ir apskaičiuojama studento galitinis balas. Pagal galutinį balą studentai yra suskirstomi į dvi grupes, čia naudotojas gali pasirinkti kokią strategija jis nori naudoti šiam suskirstymui atlikti. Tada gauti du konteineriai tra įrašomi į failus. Galiausiai yra matuojamas laikas: failų su skirtingų dydžių studentų grupėmis generavimas, šių studentų padalinimas į dvi grupes, gautų grupių įrašymo į failus, ir šių failų rikiavimo laikas. Viso yra trys strategijos, lyginamas strategijų veikimo greitis, atminties naudojimas. Gauti rezultatai aprašyti lentelėje (veikimo laikas), ir pateikti nuotraukose (atminties naudojimas).

Naudojimasis: paleidus programa vartotojas pasirenka ar nori matuoti laiką dirbant su skirtingo dydžio failais. Jei taip, jis turi pasirinkti: rušiavimo tvarką, strategiją (1,2 arba 3) ir ar nori generuoti naujus failus, ar naudoti jau esamus. Rezultatas - kiekvieno skirtingo dydžio failo darbo laikas t.y. kiek užtruko: generavimas(jei norime generuoti), nuskaitymas, rikiavimas, padalinimas į dvi grupes, grupių įrašymas į failus ir bendras darbo prie failo laikas. Jei nenorime matuoti laiko, duomenis duomenis vartotojas įveda pats kaip ir v.01 versijoje, pateikiame galutinio balo rezultatus pagal naudotojo pasirinktą kriterijų (vidurkį ar medianą). Taip pat pateikiame kiekvieno studento saugojimo atmintyje nuorodą.

Išvados: list atvejų veikia 2 strategija, vector atveju pirmoji. Akivizadu, kad tai geriausiai matosi dirbant su dideliais failais. Pirmos strategijos (list aveju) laikas labai panašus, tačiau ji užima dagiau kompiuterio atminties, vector atveju 2 strategeija veikia labai ilgai. 3 strategija (list atveju patobulinta 2) veikia labai panašiai kaip antroji, šiek tiek greičiau, tačiau vector atveju 3 strategija veikia žymiai greičiau nei 2. Lyginant 2 ir trečią atrategijas, vector atveju 2 startegja veikia lečiauu, taip pat ji užima mažiau komiuterio atminties (tai labiausiai pasimato dirbant su dideliais failais), 2 strategja list atveju veikia greičiau nei 1 tačiau ne visais atvejais (kalbant apie failų dydžius). Taigi bendrai gauname kad trečia strategija yra optimaliausia, nes ji užima kompiuterio atminties panačiai kaip 2 ir ji veikia greičiausiai.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
v1.1 versija 

Testavimu laikas su list<>:
| Testavimas                          | 100000       | 1000000        | 
|-------------------------------------|--------------|----------------|
| Failo nuskaitymas                   | 1.3271412 s. | 13.3754152 s.  |
| Rūšiavimas                          | 0.1002418 s. | 1.2525672 s.   | 
| Padalinimas į dvi grupes            | 0.1692366 s. | 1.3499539 s    | 
| Moksliukų studentų įrašymas į failą | 0.4539731 s. | 4.4668949 s.   | 
| Varkšiukų studentų įrašymas į failą | 0.4197659 s. | 4.2186148 s.   | 
| Bendras darbo laikas                | 2.4703586 s. | 24.6534463 s.  | 

