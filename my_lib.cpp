#include "my_lib.h";

void duomenu_ivedimas(vector<studentas>& grupe){
    int stud_skaicius;
    cout<<"Iveskite studentu skaiciu: ";
    cin>>stud_skaicius;

    studentas Laik;
    for (int j=0; j<stud_skaicius; j++){
        cout<<"Iveskite "<<j+1<<"-ojo studento varda ir pavarde: ";
        cin>>Laik.vard>>Laik.pav;
        
        cout<<"Ar zinote studento namu darbu skaiciu? (T/N): ";
        char atsakymas;
        cin>>atsakymas;
        if(atsakymas== 'T' || atsakymas== 't'){
            cout<<"Kiek pazymiu turi studentas?: ";
            int n;
            cin>>n;
            for (int i=0;i<n;i++){
                int k;
                cout<<"Iveskite "<<i+1<<" pazymi: ";
                cin>>k;
                if(k>=0 && k<=10) Laik.paz.push_back(k);
                else {
                        cout<<"Pazimys negalimas. Iveskite "<<i+1<<" pazymi: ";
                        cin>>k;
                        Laik.paz.push_back(k);
                    }
            }
        }
        else {
             cout << "Iveskite namu darbu rezultatus atskirtus tarpais (baigti su Enter): ";
            int pazymys;
            while (cin >> pazymys) {
                if (pazymys >= 0 && pazymys <= 10) {
                    Laik.paz.push_back(pazymys);
                } else {
                    cout << "Pazimys negalimas. Iveskite pazymi nuo 0 iki 10." << endl;
                }
                // ivedinejame, kol rasime naujos eilutes simboli '\n'
                if (cin.peek() == '\n') {
                    cin.ignore();
                    break;
                }
            }
        }
        
        cout<<"Iveskite egzamina: ";
        cin>>Laik.egz;
        if(Laik.egz>=0 && Laik.egz<=10) grupe.push_back(Laik);
        else{
                cout<<"Egzamino reiksme negalima. Ivesite egzamina: ";
                cin>>Laik.egz;
                grupe.push_back(Laik);
            }
        Laik.paz.clear();
    }
}

//galutinis pagal vidurki
float apskaiciuotivid(const studentas& stud) {
    float vidurkis = 0;
    for (int pazymys : stud.paz) {
        vidurkis += pazymys;
    }
    vidurkis /= stud.paz.size();
    return 0.4 * vidurkis + 0.6 * stud.egz;
}

//galutinis pagal mediana
float apskaiciuotimed(const studentas& stud) {
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

void spausdinti(vector<studentas>& grupe, bool naudotividurki){
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
    cout << "------------------------------------------------" << endl;

    for (const auto& a : grupe) {
        float galutinis = naudotividurki ? apskaiciuotivid(a) : apskaiciuotimed(a);
        cout << setw(20) << a.pav << setw(20) << a.vard << setw(20) << fixed << setprecision(2) << galutinis << endl;
    }
}
