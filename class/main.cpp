#include "studentas.h"


int main() {

    //zmogus jonas;   //negalima sugurti objekto is klases zmogus

    studentas s;

    s.setVard("Jonas");
    s.setPav("Jonaitis");
    s.displayInfo();
    cout<<"-------------------"<<endl;

    studentas obj1;
    obj1.setVard("Antanas");
    obj1.setPav("Antanaitis");
    obj1.addPazymys(2);
    obj1.addPazymys(3);
    obj1.addPazymys(5);
    obj1.addPazymys(1);
    obj1.setEgzaminas(6);

    studentas obj2 = obj1;
    studentas obj3;
    obj3 = obj1;

    cout<<"Informacija apie obj1: "<<obj1<<endl;
    cout<<"Informacija apie obj2: "<<obj2<<endl;
    obj3.displayInfo();

    //----------------------

    srand(static_cast<unsigned>(time(0)));
    list<studentas> grupe;
    list<studentas> grupe1000, grupe10000, grupe100000, grupe1000000, grupe10000000;
    list<studentas> moksliukai, varksiukai;

    char arMatuoti,pasirinkimas, generavimas;
    cout<<"Ar norite matuoti laika (T/N): ";
    cin>>arMatuoti;
    if (toupper(arMatuoti)=='T'){
        cout<<"Pasirinkite rusiavimo tvarka: (Vardas-V/v, Pavarde-P/p, Galutinis balas- G/g)"<<endl;
        cin>>pasirinkimas;
        cout<<"Ar norite generuoti atsitiktinius rezultatus (ar naudoti jau esancius) (T/N): "<<endl;
        cin>>generavimas;

        matuotiLaika("studentai.txt",grupe1000,1000,moksliukai,varksiukai,pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe10000,10000,moksliukai, varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe100000,100000,moksliukai,varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe1000000,1000000,moksliukai,varksiukai, pasirinkimas,generavimas);
        //matuotiLaika("studentai.txt",grupe10000000,10000000,moksliukai,varksiukai, pasirinkimas,generavimas);

    }
    else{
        cout<<'\n';
        char ivedimas, isvedimas;
        string failo_pav;
        cout<<"Kokiu budu noretumete ivesti duomenis: (Rankanis-R, Is failo-F)"<<endl;
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

