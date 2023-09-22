#include "my_lib.h";

void duomenu_ivedimas(vector<studentas>& grupe){
    int stud_skaicius;
    cout<<"Iveskite studentu skaiciu: ";
    cin>>stud_skaicius;

    studentas Laik;
    for (int j=0; j<stud_skaicius; j++){
        cout<<"Iveskite "<<j+1<<"-ojo studento varda ir pavarde: ";
        cin>>Laik.vard>>Laik.pav;
        cout<<"Kiek paz. turi studentas? ";
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

float Galutinis(const studentas& stud) {
    float vidurkis = 0;
    for (int pazymys : stud.paz) {
        vidurkis += pazymys;
    }
    vidurkis /= stud.paz.size();
    return 0.4 * vidurkis + 0.6 * stud.egz;
}

void spausdinti(vector<studentas>& grupe){
    cout << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis(Vid.)" << endl;
    cout << "------------------------------------------------" << endl;

    for (const auto& a : grupe) {
        float galutinis = Galutinis(a);
        cout << setw(20) << a.pav << setw(20) << a.vard << setw(20) << fixed << setprecision(2) << galutinis << endl;
    }
}
