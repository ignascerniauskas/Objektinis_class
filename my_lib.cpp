#include "my_lib.h";

void duomenuIvedimas(vector<studentas>& grupe){
    int stud_skaicius;
    cout<<"Iveskite studentu skaiciu: ";
    cin>>stud_skaicius;
    cout<<'\n';

    studentas Laik;
    for (int j=0; j<stud_skaicius; j++){
        cout<<"Iveskite "<<j+1<<"-ojo studento varda ir pavarde: ";
        cin>>Laik.vard>>Laik.pav;
        
        cout<<"Ar norite namu darbu rezultatus generuoti atsitiktine tvarka? (T/N): ";
        char atsakymas;
        cin>>atsakymas;
        if(atsakymas== 'T' || atsakymas== 't'){
            char zinome;
            cout<<"Ar zinome studento namu darbu skaiciu? (T/N): ";
            cin>>zinome;
            if(zinome == 'T' || zinome == 't'){
                int nd_sk;
                cout<<"Iveskite namu darbu skaiciu: ";
                cin>>nd_sk;
                generuotiPazymius1(Laik,nd_sk);
            }
            else{
                generuotiPazymius(Laik);
            }
        }
        else {
            cout<<"Ar zinote studento namu darbu skaiciu? (T/N): ";
            char zinome;
            cin>>zinome;
            if(zinome=='T' || zinome=='t'){
                cout<<"Kiek pazymiu turi studentas?: ";
                int n;
                cin>>n;
                for (int i=0;i<n;i++){
                int k;
                cout<<"Iveskite "<<i+1<<" pazymi: ";
                cin>>k;
                Laik.paz.push_back(k);
                }
            }
            else{
                cout<<"Iveskite namu darbu rezultatus atskirtus tarpais (baigti su Enter): ";
                int pazymys;
                while (cin>>pazymys) {
                    Laik.paz.push_back(pazymys);
                    if (cin.peek() == '\n') {
                        cin.ignore();
                        break;
                    }
                }
            }
            }
           
        char ats;
        cout<<"Ar norite egzamino rezultata generuoti atsitiktine tvarka? (T/N): ";
        cin>>ats;
        if(ats=='N' || ats=='n'){
            cout<<"Iveskite egzamino rezultata: ";
            cin>>Laik.egz;
            grupe.push_back(Laik);
        }else{
            generuotiEgzamina(Laik);
            grupe.push_back(Laik);
        }
        
        Laik.paz.clear();
        cout<<'\n';
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
        //cout<<pazymys<<" ";
    }
    cout<<"Pazymiai sugeneruoti atsitiktinai, jie yra: ";
    for (int pazymys : stud.paz) {
        cout<<pazymys<<" ";
    }
    cout<<'\n';
}

//atsitiktinio egzamino rezultato generavimas
void generuotiEgzamina(studentas& stud){
    stud.egz = rand() % 11; //generuojamas egzamino rezultatas nuo 0 iki 10
    cout << "Egzamino rezultatas sugeneruotas atsitiktine tvarka, jis yra: " << stud.egz << endl;
}

//galutinis pagal vidurki
float apskaiciuotiVidurki(const studentas& stud) {
    float vidurkis = 0;
    for (int pazymys : stud.paz) {
        vidurkis += pazymys;
    }
    vidurkis /= stud.paz.size();
    return 0.4 * vidurkis + 0.6 * stud.egz;
}

//galutinis pagal mediana
float apskaiciuotiMediana(const studentas& stud) {
    vector<int> sorted_paz = stud.paz;
    sort(sorted_paz.begin(), sorted_paz.end());

    int n = sorted_paz.size();
    if (n % 2 == 0) {
        int vidurys1 = sorted_paz[n / 2 - 1];
        int vidurys2 = sorted_paz[n / 2];
        return 0.4 * (vidurys1 + vidurys2) / 2.0 + 0.6 * stud.egz;
    } else {
        int vidurys = sorted_paz[n / 2];
        return 0.4 * vidurys + 0.6 * stud.egz;
    }
}

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



