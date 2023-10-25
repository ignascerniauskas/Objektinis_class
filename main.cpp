#include "my_lib.h";

int main() {

    srand(static_cast<unsigned>(time(0)));
    list<studentas> grupe;
    list<studentas> grupe1000, grupe10000, grupe100000, grupe1000000, grupe10000000;
    list<studentas> moksliukai, varksiukai;


    char arMatuoti;
    cout<<"Ar norite matuti laika? (T/N): ";
    cin>>arMatuoti;
    if(arMatuoti=='T' || arMatuoti=='t'){
    cout<<"Pasirinkite rusiavimo tvarka: (Vardas-V/v, Pavarde-P/p, Galutinis balas- G/g)"<<endl;
    char pasirinkimas;
    cin>>pasirinkimas;

    matuotiLaika("studentai.txt",grupe1000,1000,moksliukai,varksiukai,pasirinkimas);
    matuotiLaika("studentai.txt",grupe10000,10000,moksliukai, varksiukai, pasirinkimas);
    matuotiLaika("studentai.txt",grupe100000,100000,moksliukai,varksiukai, pasirinkimas);
    matuotiLaika("studentai.txt",grupe1000000,1000000,moksliukai,varksiukai, pasirinkimas);
    matuotiLaika("studentai.txt",grupe10000000,10000000,moksliukai,varksiukai, pasirinkimas);
    }
    else{
       cout<<'\n';
       duomenuIvedimas(grupe);
       char pasirinkimas;
       cout << "Jei norite naudoti vidurki, spauskite 'V' arba 'v', jei norite naudoti mediana spauskite 'M' arba 'm': ";
       cin >> pasirinkimas;
       bool naudotividurki = (pasirinkimas=='V' || pasirinkimas=='v');
       rezultatuIsvendimasEkrane(grupe, naudotividurki);
    }


    return 0;
}

