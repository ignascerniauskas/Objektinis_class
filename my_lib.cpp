#include "my_lib.h";

void duomenuIvedimas(vector<studentas>& grupe) {
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
    vector<int> sorted_paz = stud.paz;
    sort(sorted_paz.begin(), sorted_paz.end());

    int n = sorted_paz.size();
    if (n % 2 == 0) {
        int vidurys1 = sorted_paz[n / 2 - 1];
        int vidurys2 = sorted_paz[n / 2];
        stud.medGalutinis = 0.4 * (vidurys1 + vidurys2) / 2.0 + 0.6 * stud.egz;
    } else {
        int vidurys = sorted_paz[n / 2];
        stud.medGalutinis = 0.4 * vidurys + 0.6 * stud.egz;
    }
}

//apskaiciuotu rezultatu isvedimas ekrane
void rezultatuIsvendimasEkrane(vector<studentas>& grupe, bool naudotividurki){
    string kriterijus;
    if (naudotividurki){kriterijus="Galutinis(Vid.)";}
    else{kriterijus="Galutinis(Med.)";}
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << kriterijus << endl;
    cout << "------------------------------------------------" << endl;

    for (const auto& a : grupe) {
        float galutinis = naudotividurki ? apskaiciuotiVidurki(a) : apskaiciuotiMediana(a);
        cout << setw(20) << a.pav << setw(20) << a.vard << setw(20) << fixed << setprecision(2) << galutinis << endl;
    }
}

//failo skaitymas
void skaitytiFaila(const std::string& failopav, std::vector<studentas>& grupe) {
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
    failas.close();
}

//apskaiciuotu rezultatu ivedimas faile
void isvedimasFaile (vector<studentas>& grupe){
    ofstream f("rez.txt");
    f<<left<<setw(20)<<"Pavarde"<<setw(20)<<"Vardas"<<setw(20)<<"Galutinis(Vid.)"<<setw(20)<<"Galutinis(Med.)"<<endl;
    f<<"----------------------------------------------------------------------------"<<endl;
    for (const auto& a : grupe) {
        float galutinis1=apskaiciuotiVidurki(a);
        float galutinis2=apskaiciuotiMediana(a);
        f<<setw(20)<<a.pav<<setw(20)<<a.vard<<setw(20)<<fixed<<setprecision(2)<<galutinis1<<setw(20)<<fixed<<setprecision(2)<<galutinis2<<endl;
    }
    f.close();

}

//rusiavimas
bool rikiavimas(const studentas& a, const studentas& b) {
    size_t i = 0, j = 0;
    while (i < a.vard.size() && j < b.vard.size()) {
        if (isdigit(a.vard[i]) && isdigit(b.vard[j])) {
            int numA = 0, numB = 0;
            while (i < a.vard.size() && isdigit(a.vard[i])) {
                numA = numA * 10 + (a.vard[i] - '0');
                i++;
            }
            while (j < b.vard.size() && isdigit(b.vard[j])) {
                numB = numB * 10 + (b.vard[j] - '0');
                j++;
            }
            if (numA != numB)
                return numA < numB;
        }
        else {
            if (a.vard[i] != b.vard[j])
                return a.vard[i] < b.vard[j];
            i++;
            j++;
        }
    }
     i = 0, j = 0;
    while (i < a.pav.size() && j < b.pav.size()) {
        if (a.pav[i] != b.pav[j])
            return a.pav[i] < b.pav[j];
        i++;
        j++;
    }
    return a.vard.size() + a.pav.size() < b.vard.size() + b.pav.size();
}



