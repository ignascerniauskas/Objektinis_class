#include "my_lib.h";

int main() {

    vector<studentas> grupe;
    //duomenu ivedimas
    duomenu_ivedimas(grupe);

    //rodyti pagal vidurki ar mediana?
    char pasirinkimas;
    cout << "Jei norite naudoti vidurki, spauskite 'V' arba 'v', jei norite naudoti mediana spauskite 'M' arba 'm': ";
    cin >> psairinkimas;
    bool naudotividurki = (pasirinkimas=='V' || pasirinkimas=='v');
    
    //spausdinimas
    spausdinti(grupe);
    return 0;
}

