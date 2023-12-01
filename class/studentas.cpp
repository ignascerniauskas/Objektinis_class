#include "studentas.h"

studentas::studentas(std::istream& is) : egz(0), vidGalutinis(0), medGalutinis(0) {
    readstudentas(is);
}

istream& studentas::readstudentas(istream& is){
    is>>vard>>pav>>egz;
    float nd;
    while(is >> nd){
        paz.push_back(nd);
    }
    return is;
}

void duomenuIvedimas_class(list<studentas>& grupe){
    int stud_skaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> stud_skaicius;
    cout << '\n';

    studentas Laik;
    for (int j = 1; j < stud_skaicius+1; j++)
    {
        cout << "Iveskite " << j <<" studento duomenis: "<<endl;
        cin>>Laik;
        cout<<'\n';
        apskaiciuotiVidurki(Laik);
        grupe.push_back(Laik);
        Laik.clearPazymiai();
    }

}

void duomenuIvedimas(list<studentas>& grupe) {
    int stud_skaicius;
    cout << "Iveskite studentu skaiciu: ";
    cin >> stud_skaicius;
    cout << '\n';

    studentas Laik;
    for (int j = 0; j < stud_skaicius; j++) {
        cout << "Iveskite " << j + 1 << "-ojo studento varda ir pavarde: ";
        string vard,pav;
        cin >> vard >> pav;
        Laik.setVard(vard);
        Laik.setPav(pav);

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
                        Laik.addPazymys(k);
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
                        Laik.addPazymys(pazymys);
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
            Laik.setEgzaminas(egz_rezultatas);
            grupe.push_back(Laik);
        } else {
            generuotiEgzamina(Laik);
            grupe.push_back(Laik);
        }

        Laik.clearPazymiai();
        cout << '\n';
    }
    for(auto& studentas: grupe){
        apskaiciuotiMediana(studentas);
        apskaiciuotiVidurki(studentas);

    }
}

void rezultatuIsvendimasEkrane(list<studentas>& grupe){
    string kriterijus;
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" <<endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (auto& studentas : grupe) {
        apskaiciuotiVidurki(studentas);
        cout << studentas<<endl;
    }
}

void apskaiciuotiVidurki(studentas& stud) {
        float vidurkis = 0;
        for (int pazymys : stud.getPaz()) {
            vidurkis += pazymys;
        }
        vidurkis /= stud.getPaz().size();
        double galutinis = 0.4 * vidurkis + 0.6 * stud.getEgzaminas();
        stud.setvidGalutinis(galutinis);
}

void apskaiciuotiMediana(studentas stud) {
        std::list<int> sorted_paz = stud.getPaz();
        sorted_paz.sort();

        int n = sorted_paz.size();
        auto iter = sorted_paz.begin();
        std::advance(iter, n / 2);

        if (n % 2 == 0) {
            int vidurys1 = *std::prev(iter);
            int vidurys2 = *iter;
            stud.setMedGalutinis(0.4 * (vidurys1 + vidurys2) / 2.0 + 0.6 * stud.getEgzaminas());
        } else {
            int vidurys = *iter;
            stud.setMedGalutinis(0.4 * vidurys + 0.6 * stud.getEgzaminas());
        }
}

void skaitytiFaila(const string& failopav, list<studentas>& grupe) {
    grupe.clear();
    ifstream failas(failopav);
    if (!failas) {
        cerr << "Klaida atidarant faila: " << failopav << endl;
        return;
    }

    string stulpeliuPavadinimai;
    getline(failas, stulpeliuPavadinimai);

    string eilute;
    while (getline(failas, eilute)) {
        std::istringstream iss(eilute);

        string pav, vard;
        int nd1, nd2, nd3, nd4, nd5, egz;

        if (iss >> pav >> vard >> nd1 >> nd2 >> nd3 >> nd4 >> nd5 >> egz) {
            studentas Laik;

            Laik.setPav(pav);
            Laik.setVard(vard);
            Laik.addPazymys(nd1);
            Laik.addPazymys(nd2);
            Laik.addPazymys(nd3);
            Laik.addPazymys(nd4);
            Laik.addPazymys(nd5);
            Laik.setEgzaminas(egz);

            grupe.push_back(Laik);
        } else {
            cerr << "Netinkamas failo formatas eiluteje: " << eilute << endl;
        }
    }
    for(auto& studentas : grupe){
        apskaiciuotiVidurki(studentas);
        apskaiciuotiMediana(studentas);
    }

    failas.close();
}

//atsitiktinis pazymiu generavimas
void generuotiPazymius(studentas& stud){
    stud.clearPazymiai();
    int pazymiuskaicius = rand() % 15 + 1; //generuojama nuo 0 iki 15 pazymiu
    for (int i=0; i<pazymiuskaicius; i++){
        int pazymys=rand() % 11; //generuojami pazymmiai nuo 0 iki 10
        stud.addPazymys(pazymys);
    }
    cout<<pazymiuskaicius<<" pazymiai sugeneruoti atsitiktinai, jie yra: ";
    for (int pazymys : stud.getPaz()) {
        cout<<pazymys<<" ";
    }
    cout<<'\n';
}

void generuotiPazymius1(studentas& stud, int nd_sk) {
    stud.clearPazymiai();
    int pazymiuSkaicius=nd_sk;
    for (int i=0; i<pazymiuSkaicius; i++) {
        int pazymys=rand() % 11; //generuojami pazymiai nuo 0 iki 10
        stud.addPazymys(pazymys);
    }

}

//atsitiktinio egzamino rezultato generavimas
void generuotiEgzamina(studentas& stud){
    stud.setEgzaminas(rand() % 11); //generuojamas egzamino rezultatas nuo 0 iki 10

}

//apskaiciuotu rezultatu ivedimas faile
void isvedimasFaile (list<studentas>& grupe, const string& failoPavadinimas){
    ofstream f(failoPavadinimas);
    f<<left<<setw(20)<<"Pavarde"<<setw(20)<<"Vardas"<<setw(20)<<"Galutinis(Vid.)"<<endl;
    f<<"----------------------------------------------------------------------------"<<endl;
    for (auto& studentas : grupe) {
        apskaiciuotiVidurki(studentas);
        f<<studentas<<endl;
    }
    f.close();

}

//skirtingo dydzio failo studentu duomenu generavimas
void generuotiStudentuSarasa(list<studentas>& grupe, int studentuSkaicius) {
    grupe.clear();
    for (int i = 0; i < studentuSkaicius; ++i) {
        studentas Laik;
        Laik.setVard("Vardas" + std::to_string(i + 1));
        Laik.setPav("Pavarde" + std::to_string(i + 1));
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
            outFile<<setw(17)<<studentas.getPav() <<setw(17)<<studentas.getVard()<< setw(17);
            for (int pazymys : studentas.getPaz()) {
                outFile <<setw(17)<< pazymys;
            }
            outFile <<setw(17)<< studentas.getEgzaminas() << endl;
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
        apskaiciuotiVidurki(studentas);
    }

    for (auto& studentas : grupe) {
        apskaiciuotiVidurki(studentas);
        if (studentas.getvidGalutinis() <= 5) {
            varksiukai.push_back(studentas);
        } else {
            moksliukai.push_back(studentas);
        }
    }
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

void matuotiLaika(const string& failoPavadinimas, list<studentas>& grupe, int stud_skaicius, list<studentas>& moksliukai, list<studentas>& varksiukai, char pasirinkimas, char generavimas) {
    if ('T'==toupper(generavimas)){
    auto pradziaGeneravimo = high_resolution_clock::now();
    generuotiStudentuSarasa(grupe, stud_skaicius);
    auto pabaigaGeneravimo = high_resolution_clock::now();
    auto trukmeGeneravimo = duration<double>(pabaigaGeneravimo - pradziaGeneravimo);
    cout <<std::to_string(stud_skaicius)<<" studentu generavimo laikas: " << trukmeGeneravimo.count() << " s" << endl;
    irasytiIFaila(grupe, std::to_string(stud_skaicius)+"_"+failoPavadinimas);
    isvedimasFaile(grupe,"rez_"+std::to_string(stud_skaicius)+"_"+failoPavadinimas);

    }

    auto pradziaNuskaitymas = high_resolution_clock::now();
    skaitytiFaila(std::to_string(stud_skaicius)+"_"+failoPavadinimas, grupe);
    auto pabaigaNuskaitymas = high_resolution_clock::now();
    auto trukmeNuskaitymas = duration<double>(pabaigaNuskaitymas - pradziaNuskaitymas);
    cout <<std::to_string(stud_skaicius)<<" studentu nuskaitymo laikas: " << trukmeNuskaitymas.count() << " s" << endl;


    auto pradziaRikiavimas = high_resolution_clock::now();
    if (toupper(pasirinkimas) == 'V') {
        grupe.sort([](const studentas& a, const studentas& b) { return palyginti(a.getVard(),b.getVard()) ;});
    }
    else if (toupper(pasirinkimas) == 'P') {
        grupe.sort([](const studentas& a, const studentas& b) { return palyginti(a.getVard(),b.getVard()) ;});
    }
    else if (toupper(pasirinkimas) == 'G') {
       grupe.sort([](const studentas& a, const studentas& b) { return a.getvidGalutinis() < b.getvidGalutinis(); });
    }

    auto pabaigaRikiavimas = high_resolution_clock::now();
    auto trukmeRikiavimas = duration<double>(pabaigaRikiavimas - pradziaRikiavimas);
    cout << "Rikiavimo laikas: " << trukmeRikiavimas.count() << " s" << endl;


    auto pradziaSuskirstymas= high_resolution_clock::now();
    suskirstymas(grupe, moksliukai, varksiukai);
    auto pabaigaSuskirstymas = high_resolution_clock::now();
    auto trukmeSuskirstymas = duration<double>(pabaigaSuskirstymas - pradziaSuskirstymas);
    cout << "Suskirstymo laikas: "<< trukmeSuskirstymas.count() << " s" << endl;

    auto pradziaMoksliukai= high_resolution_clock::now();
    isvedimasFaile(moksliukai, "moksliukai_" + std::to_string(stud_skaicius) + "_" + failoPavadinimas);
    auto pabaigaMoksliukai = high_resolution_clock::now();
    auto trukmeMoksliukai = duration<double>(pabaigaMoksliukai - pradziaMoksliukai);

    auto pradziaVarksiukai= high_resolution_clock::now();
    isvedimasFaile(varksiukai, "varksiukai_" + std::to_string(stud_skaicius) + "_" + failoPavadinimas);
    auto pabaigaVarksiukai = high_resolution_clock::now();
    auto trukmeVarksiukai = duration<double>(pabaigaVarksiukai - pradziaVarksiukai);
    cout << "Varksiuku studentu irasymo i faila laikas: "<< trukmeVarksiukai.count() << " s" << endl;
    cout << "Moksliuku studentu irasymo i faila laikas: "<< trukmeMoksliukai.count() << " s" << endl;

    auto trukmeBendras = trukmeNuskaitymas+trukmeSuskirstymas+trukmeRikiavimas+trukmeVarksiukai+trukmeMoksliukai;
    cout<<'\n';
    cout<<"Bendras darbo laikas prie failo: "<<trukmeBendras.count()<<" s"<<endl;
    cout <<"-----------------------------------------------------------"<<endl;
}


