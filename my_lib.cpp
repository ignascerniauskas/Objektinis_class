#include "my_lib.h";

void duomenuIvedimas(list<studentas>& grupe) {
    int stud_skaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> stud_skaicius;
    cout << '\n';

    studentas Laik;
    for (int j = 0; j < stud_skaicius; j++) {
        cout << "Iveskite " << j + 1 << "-ojo studento varda ir pavarde: ";
        cin >> Laik.vard >> Laik.pav;

        char atsakymas;
        do {
            cout << "Ar norite namu darbu rezultatus generuoti atsitiktine tvarka? (T/N): ";
            cin >> atsakymas;
            if (atsakymas != 'T' && atsakymas != 't' && atsakymas != 'N' && atsakymas != 'n') {
                cerr << "Klaida: Ivesta netinkama reiksme. Iveskite 'T', 't', 'N' arba 'n'." << endl;
            }
        } while (atsakymas != 'T' && atsakymas != 't' && atsakymas != 'N' && atsakymas != 'n');

        if (atsakymas == 'T' || atsakymas == 't') {
            char zinome;
            do {
                cout << "Ar zinome studento namu darbu skaiciu? (T/N): ";
                cin >> zinome;
                if (zinome != 'T' && zinome != 't' && zinome != 'N' && zinome != 'n') {
                    cerr << "Klaida: Ivesta netinkama reiksme. Iveskite 'T', 't', 'N' arba 'n'." << endl;
                }
            } while (zinome != 'T' && zinome != 't' && zinome != 'N' && zinome != 'n');

            try {
                if (zinome == 'T' || zinome == 't') {
                    int nd_sk;
                    do {
                        cout << "Iveskite namu darbu skaiciu: ";
                        cin >> nd_sk;

                        if (nd_sk <= 0) {
                            throw runtime_error("Klaida: Namu darbu skaicius turi buti teigiamas skaicius.");
                        }
                    } while (nd_sk <= 0);

                    generuotiPazymius1(Laik, nd_sk);
                } else {
                    generuotiPazymius(Laik);
                }
            } catch (const runtime_error& e) {
                cerr << "Klaida: " << e.what() << endl;
                continue; // Pereiti prie kito studento įvedimo
            }
        } else {
            char zinome;
            do {
                cout << "Ar zinome studento namu darbu skaiciu? (T/N): ";
                cin >> zinome;
                if (zinome != 'T' && zinome != 't' && zinome != 'N' && zinome != 'n') {
                    cerr << "Klaida: Ivesta netinkama reiksme. Iveskite 'T', 't', 'N' arba 'n'." << endl;
                }
            } while (zinome != 'T' && zinome != 't' && zinome != 'N' && zinome != 'n');

            if (zinome == 'T' || zinome == 't') {
                int n;
                do {
                    cout << "Kiek pazymiu turi studentas?: ";
                    cin >> n;

                    if (n <= 0) {
                        cerr << "Klaida: Pazymiu skaicius turi buti teigiamas skaicius." << endl;
                    }
                } while (n <= 0);

                for (int i = 0; i < n; i++) {
                    int k;
                    cout << "Iveskite " << i + 1 << " pazymi: ";
                    cin >> k;
                    try {
                        if (k < 0 || k > 10) {
                            throw runtime_error("Klaida: Pazimys turi buti nuo 0 iki 10.");
                        }
                        Laik.paz.push_back(k);
                    } catch (const exception& e) {
                        cerr << "Klaida: " << e.what() << endl;
                        i--;
                    }
                }
            } else {
                cout << "Iveskite namu darbu rezultatus atskirtus tarpais (baigti su Enter): ";
                int pazymys;
                while (cin >> pazymys) {
                    try {
                        if (pazymys < 0 || pazymys > 10) {
                            throw runtime_error("Klaida: Pazimys turi buti nuo 0 iki 10.");
                        }
                        Laik.paz.push_back(pazymys);
                    } catch (const exception& e) {
                        cerr << "Klaida: " << e.what() << endl;
                    }
                    if (cin.peek() == '\n') {
                        cin.ignore();
                        break;
                    }
                }
            }
        }

        char ats;
        do {
            cout << "Ar norite egzamino rezultata generuoti atsitiktine tvarka? (T/N): ";
            cin >> ats;
            if (ats != 'T' && ats != 't' && ats != 'N' && ats != 'n') {
                cerr << "Klaida: Ivesta netinkama reiksme. Iveskite 'T', 't', 'N' arba 'n'." << endl;
            }
        } while (ats != 'T' && ats != 't' && ats != 'N' && ats != 'n');

        if (ats == 'N' || ats == 'n') {
            int egz_rezultatas;
            do {
                cout << "Iveskite egzamino rezultata: ";
                cin >> egz_rezultatas;
                if (egz_rezultatas < 0 || egz_rezultatas > 10) {
                    cerr << "Klaida: Egzamino rezultatas turi buti nuo 0 iki 10." << endl;
                }
            } while (egz_rezultatas < 0 || egz_rezultatas > 10);
            Laik.egz = egz_rezultatas;
            grupe.push_back(Laik);
        } else {
            generuotiEgzamina(Laik);
            grupe.push_back(Laik);
        }

        Laik.paz.clear();
        cout << '\n';
    }
    for(auto& studentas: grupe){
        apskaiciuotiMediana(studentas);
        apskaiciuotiVidurki(studentas);

    }
}

//atsitiktinis pazymiu generavimas
void generuotiPazymius(studentas& stud){
    stud.paz.clear();
    int pazymiuskaicius = rand() % 15 + 1; //generuojama nuo 0 iki 15 pazymiu
    for (int i=0; i<pazymiuskaicius; i++){
        int pazymys=rand() % 11; //generuojami pazymmiai nuo 0 iki 10
        stud.paz.push_back(pazymys);
    }
    cout<<pazymiuskaicius<<" pazymiai sugeneruoti atsitiktinai, jie yra: ";
    for (int pazymys : stud.paz) {
        cout<<pazymys<<" ";
    }
    cout<<'\n';
}

void generuotiPazymius1(studentas& stud, int nd_sk) {
    stud.paz.clear();
    int pazymiuSkaicius=nd_sk;
    for (int i=0; i<pazymiuSkaicius; i++) {
        int pazymys=rand() % 11; //generuojami pazymiai nuo 0 iki 10
        stud.paz.push_back(pazymys);
    }

}

//atsitiktinio egzamino rezultato generavimas
void generuotiEgzamina(studentas& stud){
    stud.egz = rand() % 11; //generuojamas egzamino rezultatas nuo 0 iki 10

}
//galutinis pagal vidurki
void apskaiciuotiVidurki(studentas& stud) {
    float vidurkis=0;
    for (int pazymys : stud.paz) {
        vidurkis += pazymys;
    }
    vidurkis /= stud.paz.size();
    stud.vidGalutinis = 0.4 * vidurkis + 0.6 * stud.egz;
}

//galutinis pagal mediana
void apskaiciuotiMediana(studentas& stud) {
    std::list<int> sorted_paz = stud.paz;
    sorted_paz.sort();

    int n = sorted_paz.size();
    auto iter = sorted_paz.begin();
    std::advance(iter, n / 2);

    if (n % 2 == 0) {
        int vidurys1 = *std::prev(iter);
        int vidurys2 = *iter;
        stud.medGalutinis = 0.4 * (vidurys1 + vidurys2) / 2.0 + 0.6 * stud.egz;
    } else {
        int vidurys = *iter;
        stud.medGalutinis = 0.4 * vidurys + 0.6 * stud.egz;
    }
}

//apskaiciuotu rezultatu isvedimas ekrane
void rezultatuIsvendimasEkrane(list<studentas>& grupe, bool naudotividurki){
    string kriterijus;
    if (naudotividurki){kriterijus="Galutinis(Vid.)";}
    else{kriterijus="Galutinis(Med.)";}
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << kriterijus << setw(20)<<"Vieta atmintyje" <<endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (const auto& studentas : grupe) {
        float galutinis = naudotividurki ? studentas.vidGalutinis : studentas.medGalutinis;
        cout << setw(20) << studentas.pav << setw(20) << studentas.vard << setw(20) << fixed << setprecision(2) << galutinis<<setw(20)<<&studentas << endl;
    }
}

//failo skaitymas
void skaitytiFaila(const string& failopav, list<studentas>& grupe) {
    grupe.clear();
    ifstream failas(failopav);
    if (!failas){
        cerr<<"Klaida atidarant faila: "<< failopav<<endl;
        return;
    }

    string stulpeliuPavadinimai;
    getline(failas, stulpeliuPavadinimai);//perskaitome stulpeliu antrastes

    studentas Laik;
    string eilute;
    while (std::getline(failas,eilute)){
        std::istringstream iss(eilute);
        iss>>Laik.pav>>Laik.vard;

        int pazymys;
        while (iss>>pazymys){
            if (pazymys>=0 && pazymys<= 10){
                Laik.paz.push_back(pazymys);
            }
            else{
                cerr<<"Netinkamas pazymys: "<<pazymys<<endl;
                return;
            }
        }

        if (!Laik.paz.empty()){
            //paskutinis skaicius yra egzamino rezultatas
            Laik.egz=Laik.paz.back();
            Laik.paz.pop_back(); //pasaliname egzamino rezultata is pazymiu
            grupe.push_back(Laik);
        }
        Laik.paz.clear();
    }
    
     for(auto& studentas : grupe){
        apskaiciuotiVidurki(studentas);
        apskaiciuotiMediana(studentas);
    }
    
    failas.close();
}

//apskaiciuotu rezultatu ivedimas faile
void isvedimasFaile (list<studentas>& grupe, const string& failoPavadinimas){
    ofstream f(failoPavadinimas);
    f<<left<<setw(20)<<"Pavarde"<<setw(20)<<"Vardas"<<setw(20)<<"Galutinis(Vid.)"<<endl;
    f<<"----------------------------------------------------------------------------"<<endl;
    for (auto& studentas : grupe) {
        apskaiciuotiVidurki(studentas);
        f<<setw(20)<<studentas.pav<<setw(20)<<studentas.vard<<setw(20)<<fixed<<setprecision(2)<<studentas.vidGalutinis<<endl;
    }
    f.close();

}

bool palyginti(const string& a, const string& b) {
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (isdigit(a[i]) && isdigit(b[j])) {
            int numA = 0, numB = 0;
            while (i < a.size() && isdigit(a[i])) {
                numA = numA * 10 + (a[i] - '0');
                i++;
            }
            while (j < b.size() && isdigit(b[j])) {
                numB = numB * 10 + (b[j] - '0');
                j++;
            }
            if (numA != numB) {
                return numA < numB;
            }
        } else {
            if (a[i] != b[j]) {
                return a[i] < b[j];
            }
            i++;
            j++;
        }
    }
    return a.size() < b.size();
}

//skirtingo dydzio failo studentu duomenu generavimas
void generuotiStudentuSarasa(list<studentas>& grupe, int studentuSkaicius) {
    grupe.clear();
    for (int i = 0; i < studentuSkaicius; ++i) {
        studentas Laik;
        Laik.vard = "Vardas" + std::to_string(i + 1);
        Laik.pav = "Pavarde" + std::to_string(i + 1);
        generuotiPazymius1(Laik,5);
        generuotiEgzamina(Laik);
        grupe.push_back(Laik);
    }
}

//studentu duomenu irasymo i failla funkcija
void irasytiIFaila(const list<studentas>& grupe, const string& failoPavadinimas) {
    ofstream outFile(failoPavadinimas);
    outFile<<left<<setw(17)<<"Pavarde"<<setw(17)<<"Vardas"<<setw(17)<<"ND1"<<setw(17)<<"ND2"<<setw(17)<<"ND3"<<setw(17)<<"ND4"<<setw(17)<<"ND5"<<setw(17)<<"Egz."<<endl;
    if (outFile.is_open()) {
        for (const auto& studentas : grupe) {
            outFile<<setw(17)<<studentas.pav <<setw(17)<<studentas.vard<< setw(17);
            for (int pazymys : studentas.paz) {
                outFile <<setw(17)<< pazymys;
            }
            outFile <<setw(17)<< studentas.egz << endl;
        }
        outFile.close();
    } else {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
    }
}

void suskirstymas(list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& varksiukai) {
    moksliukai.clear();
    varksiukai.clear();
    for (auto& studentas : grupe) {
        if (studentas.vidGalutinis < 5) {
            varksiukai.push_back(studentas);
        }
        else {
            moksliukai.push_back(studentas);
        }
    }
}

void matuotiLaika(const string& failoPavadinimas, list<studentas>& grupe, int stud_skaicius, list<studentas>& moksliukai, list<studentas>& varksiukai, char pasirinkimas) {
    auto pradziaGeneravimo = high_resolution_clock::now();
    generuotiStudentuSarasa(grupe, stud_skaicius);
    auto pabaigaGeneravimo = high_resolution_clock::now();
    auto trukmeGeneravimo = duration<double>(pabaigaGeneravimo - pradziaGeneravimo);
    cout <<std::to_string(stud_skaicius)<<" studentu generavimo laikas: " << trukmeGeneravimo.count() << " s" << endl;

    irasytiIFaila(grupe, std::to_string(stud_skaicius)+"_"+failoPavadinimas);
    isvedimasFaile(grupe,"rez_"+std::to_string(stud_skaicius)+"_"+failoPavadinimas);

    auto pradziaNuskaitymas = high_resolution_clock::now();
    skaitytiFaila(std::to_string(stud_skaicius)+"_"+failoPavadinimas, grupe);
    auto pabaigaNuskaitymas = high_resolution_clock::now();
    auto trukmeNuskaitymas = duration<double>(pabaigaNuskaitymas - pradziaNuskaitymas);
    cout << "Failo " << std::to_string(stud_skaicius)+"_"+failoPavadinimas << " nuskaitymo laikas: " << trukmeNuskaitymas.count() << " s" << endl;

    auto pradziaRikiavimas = high_resolution_clock::now();
    if('V' == toupper(pasirinkimas)){
        grupe.sort([](const studentas& a, const studentas& b) {return palyginti(a.vard, b.vard);});
    }
    else if (toupper(pasirinkimas)== 'P'){
        grupe.sort([](const studentas& a, const studentas& b) {return palyginti(a.pav, b.pav);});
    }
    else if(toupper(pasirinkimas)=='G'){
        grupe.sort([](const studentas& a, const studentas& b) {return a.vidGalutinis < b.vidGalutinis;});
    }

    auto pabaigaRikiavimas = high_resolution_clock::now();
    auto trukmeRikiavimas = duration<double>(pabaigaRikiavimas - pradziaRikiavimas);
    cout << "Rikiavimo laikas: " << trukmeRikiavimas.count() << " s" << endl;


    auto pradziaSuskirstymas = high_resolution_clock::now();
    suskirstymas(grupe, moksliukai, varksiukai);
    auto pabaigaSuskirstymas = high_resolution_clock::now();
    auto trukmeSuskirstymas = duration<double>(pabaigaSuskirstymas - pradziaSuskirstymas);
    cout << "Suskirstyti studentus i dvi grupes laikas : " << trukmeSuskirstymas.count() << " s" << endl;


    auto pradziaVarksiukai= high_resolution_clock::now();
    isvedimasFaile(varksiukai, "varksiukai_"+std::to_string(stud_skaicius)+"_"+failoPavadinimas);
    auto pabaigaVarksiukai = high_resolution_clock::now();
    auto trukmeVarksiukai = duration<double>(pabaigaVarksiukai - pradziaVarksiukai);
    cout << "Varksiuku studentu irasymo i faila laikas: "<< trukmeVarksiukai.count() << " s" << endl;

    auto pradziaMoksliukai= high_resolution_clock::now();
    isvedimasFaile(moksliukai, "moksliukai_" + std::to_string(stud_skaicius)+ "_"+ failoPavadinimas);
    auto pabaigaMoksliukai = high_resolution_clock::now();
    auto trukmeMoksliukai = duration<double>(pabaigaMoksliukai - pradziaMoksliukai);
    cout << "Moksliuku studentu irasymo i faila laikas: "<< trukmeMoksliukai.count() << " s" << endl;


    auto trukmeBendras = trukmeNuskaitymas+trukmeSuskirstymas+trukmeRikiavimas+trukmeMoksliukai+trukmeVarksiukai;
    cout<<'\n';
    cout<<"Bendras darbo laikas prie failo: "<<trukmeBendras.count()<<" s"<<endl;
    cout <<"-----------------------------------------------------------"<<endl;
}
