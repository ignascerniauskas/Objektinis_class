#include "studentas.h"


int main() {

    srand(static_cast<unsigned>(time(0)));
    list<studentas> grupe;
    list<studentas> grupe1000, grupe10000, grupe100000, grupe1000000, grupe10000000;
    list<studentas> moksliukai, varksiukai;

    char arMatuoti,pasirinkimas, generavimas;
    cout<<"Ar norite matuoti laika (T/N): ";
    cin>>arMatuoti;
    if (toupper(arMatuoti)=='T'){
        cout<<"Pasirinkite rusiavimo tvarka: (Vardas-V/v, Pavarde-P/p, Galutinis balas- G/g)";
        cin>>pasirinkimas;
        cout<<"Ar norite generuoti atsitiktinius rezultatus (ar naudoti jau esancius) (T/N): ";
        cin>>generavimas;
        int n;
        cout<<"Iveskite studentu skaiciu: ";
        cin>>n;

        matuotiLaika("studentai.txt",grupe1000,n,moksliukai,varksiukai,pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe10000,10000,moksliukai, varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe100000,100000,moksliukai,varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe1000000,1000000,moksliukai,varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe10000000,10000000,moksliukai,varksiukai, pasirinkimas,generavimas);

    }
    else{
        cout<<'\n';
        char ivedimas, isvedimas;
        string failo_pav;
        cout<<"Kokiu budu noretumete ivesti duomenis: (Rankanis-R, Is failo-F)";
        cin>>ivedimas;
        if(toupper(ivedimas)=='R'){
            duomenuIvedimas_class(grupe);
        }
        else if (toupper(ivedimas)=='F'){
            cout<<"Iveskite failo pavadinima: ";
            cin>>failo_pav;
            skaitytiFaila(failo_pav,grupe);
        }

        cout<<"Kokiu budu noretumete gauti rezultatus: (Ekrane-E, Faile-F) ";
        cin>>isvedimas;
        if(toupper(isvedimas)=='E'){
            rezultatuIsvendimasEkrane(grupe);
        }
        else{
            isvedimasFaile(grupe,"rez.txt");
            cout<<"Duomenys isaugoti faile 'rez.txt'"<<endl;
        }

    }



    return 0;

}

