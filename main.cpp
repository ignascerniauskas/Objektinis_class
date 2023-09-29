#include "my_lib.h";

int main() {

    srand(static_cast<unsigned>(time(0)));
    vector<studentas> grupe;
    
    char arSkaityti;
    cout<<"Ar norite nuskaityti duomenis is failo? (T/N): ";//Pasirenkame, ar norime skaityti duomenis is failo
    cin>>arSkaityti;
    if(arSkaityti=='T' || arSkaityti=='t'){
        string failoPavadinimas;
        cout<<"Iveskite failo pavadinima: ";
        cin>>failoPavadinimas;
        skaitytiFaila(failoPavadinimas,grupe); //nuskaitome duomenis is failo
        sort(grupe.begin(), grupe.end(), rikiavimas);//surikiuojame
        isvedimasFaile(grupe); //irasome rezultatus i faila 'rez.txt'
    }
    else{
       cout<<'\n';
       duomenuIvedimas(grupe); //jei nenorime skaityti duomenu is failo duomenis ivedime
       char pasirinkimas;
       cout << "Jei norite naudoti vidurki, spauskite 'V' arba 'v', jei norite naudoti mediana spauskite 'M' arba 'm': ";
       cin >> pasirinkimas;
       bool naudotividurki = (pasirinkimas=='V' || pasirinkimas=='v');
       rezultatuIsvendimasEkrane(grupe, naudotividurki);

    }

    return 0;
}

