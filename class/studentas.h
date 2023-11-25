#include <iostream>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <chrono>

#ifndef STUDENTAS_H
#define STUDENTAS_H

using namespace std::chrono;


using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::list;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::cerr;
using std::ifstream;
using std::istream;
using std::ofstream;
using std::runtime_error;
using std::exception;


class studentas {
private:
    string vard, pav;
    list<int> paz;
    int egz;
    float vidGalutinis;
    float medGalutinis;

public:
    // Default
    studentas() : egz(0), vidGalutinis(0), medGalutinis(0) {}
    studentas(istream& is);
    istream& readstudentas(istream&);
    void clearPazymiai() { paz.clear(); }

    ~studentas(){}
    
    // seterei
    void setVard(const string& v) { vard = v; }
    void setPav(const string& p) { pav = p; }
    void setEgzaminas(int egzaminas) { egz = egzaminas; }
    void setvidGalutinis(float vid) { vidGalutinis = vid; }
    void setMedGalutinis(float med) { medGalutinis = med; }
    void addPazymys(int pazymys) { paz.push_back(pazymys); }


    // geterei
    inline string getVard() const { return vard; }
    inline string getPav() const { return pav; }
    float getvidGalutinis() const { return vidGalutinis; }
    float getmedGalutinis() const { return medGalutinis; }
    int getEgzaminas() const { return egz; }
    const list<int>& getPaz() const {return paz;}

};

void duomenuIvedimas(list<studentas>& grupe);
void rezultatuIsvendimasEkrane(list<studentas>& grupe, bool naudotividurki);
void apskaiciuotiVidurki(studentas& stud);
void apskaiciuotiMediana(studentas stud);
void generuotiPazymius(studentas& stud);
void generuotiPazymius1(studentas& stud, int nd_sk);
void generuotiEgzamina(studentas& stud);
void generuotiStudentuSarasa(list<studentas>& grupe, int studentuSkaicius);
void skaitytiFaila(const string& failopav, list<studentas>& grupe);
void isvedimasFaile (list<studentas>& grupe, const string& failoPavadinimas);
void irasytiIFaila(const list<studentas>& grupe, const string& failoPavadinimas);
bool palyginti(const string& a, const string& b);
void suskirstymas(list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& varksiukai);
void matuotiLaika(const string& failoPavadinimas, list<studentas>& grupe, int stud_skaicius,list<studentas>& moksliukai, list<studentas>& varksiukai, char pasirinkimas, char generavimas);

#endif // STUDENTAS_H


