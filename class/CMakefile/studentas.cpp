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

std::istream& operator>>(istream& is, studentas& student){

        cout << "Iveskite studento varda ir pavarde: ";
        string vard,pav;
        cin >> vard >> pav;
        student.setVard(vard);
        student.setPav(pav);

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

                    generuotiPazymius1(student, nd_sk);
                } else {
                    generuotiPazymius(student);
                }
            } catch (const runtime_error& e) {
                cerr << "Klaida: " << e.what() << endl;
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
                        student.addPazymys(k);
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
                        student.addPazymys(pazymys);
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
            student.setEgzaminas(egz_rezultatas);
        } else {
            generuotiEgzamina(student);
        }

        apskaiciuotiVidurkif(student);

        cout << '\n';

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
        apskaiciuotiVidurkif(Laik);
        grupe.push_back(Laik);
        Laik.clearPazymiai();
    }

}


void rezultatuIsvendimasEkrane(list<studentas>& grupe){
    string kriterijus;
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" <<endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    for (auto& studentas : grupe) {
        cout << studentas<<endl;
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
    getline(failas, stulpeliuPavadinimai); // Perskaitome stulpeliu antrastes

    studentas Laik;

    string eilute;
    while (getline(failas, eilute)) {
        std::istringstream iss(eilute);

        string vard, pav;
        if (iss >> vard >> pav) {
            Laik.setVard(vard);
            Laik.setPav(pav);

            int pazymys;
            while (iss >> pazymys) {
                if (pazymys >= 0 && pazymys <= 10) {
                    Laik.addPazymys(pazymys);
                } else {
                    cerr << "Netinkamas pazymys: " << pazymys << endl;
                    return;
                }
            }

            if (!Laik.getPaz().empty()) {
                // Paskutinis skaicius yra egzamino rezultatas
                Laik.setEgzaminas(Laik.getPaz().back());
                Laik.clearlast(); // Pasaliname egzamino rezultata is pazymiu
                grupe.push_back(Laik);
            }
            Laik.clearPazymiai();
        } else {
            cerr << "Netinkamas failo formatas eiluteje (vardas, pavarde): " << eilute << endl;
        }

    }

    for (auto& studentas : grupe) {
        apskaiciuotiVidurkif(studentas);
        apskaiciuotiMedianaf(studentas);
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
void irasytiIFaila( list<studentas>& grupe, const string& failoPavadinimas) {
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
        apskaiciuotiVidurkif(studentas);
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
        grupe.sort([](const studentas& a, const studentas& b) { return palyginti(a.getPav(),b.getPav()) ;});
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




