#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

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
using std::ofstream;
using std::runtime_error;
using std::exception;


struct studentas {
  string vard, pav;
  list <int> paz;
  int egz;
  float vidGalutinis;
  float medGalutinis;
};

void duomenuIvedimas(list<studentas>& grupe);
void apskaiciuotiVidurki(studentas& stud);
void apskaiciuotiMediana(studentas& stud);
void rezultatuIsvendimasEkrane(list<studentas>& grupe, bool naudotividurki);
void generuotiPazymius(studentas& stud);
void generuotiPazymius1(studentas& stud, int nd_sk);
void generuotiEgzamina(studentas& stud);
void generuotiStudentuSarasa(list<studentas>& grupe, int studentuSkaicius);
void skaitytiFaila(const string& failopav, list<studentas>& grupe);
void isvedimasFaile (list<studentas>& grupe, const string& failoPavadinimas);

bool palyginti(const string& a, const string& b);

void irasytiIFaila(const list<studentas>& grupe, const string& failoPavadinimas);
void suskirstymas1(list<studentas>& grupe, list<studentas>& moksliukai, list<studentas>& varksiukai);
void suskirstymas2(list<studentas>& grupe, list<studentas>& varksiukai);
void suskirstymas3(list<studentas>& grupe, list<studentas>& varksiukai);

void matuotiLaika(const string& failoPavadinimas, list<studentas>& grupe, int stud_skaicius,list<studentas>& moksliukai, list<studentas>& varksiukai, char pasirinkimas, char generavimas, char startegija);


