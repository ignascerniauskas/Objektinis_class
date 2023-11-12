#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std::chrono;


using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::cerr;
using std::ifstream;
using std::ofstream;
using std::runtime_error;
using std::exception;
using std::pair;


struct studentas {
  string vard, pav;
  vector <int> paz;
  int egz;
  float vidGalutinis;
  float medGalutinis;
};

void duomenuIvedimas(vector<studentas>& grupe);
void apskaiciuotiVidurki(studentas& stud);
void apskaiciuotiMediana(studentas& stud);
void rezultatuIsvendimasEkrane(vector<studentas>& grupe, bool naudotividurki);
void generuotiPazymius(studentas& stud);
void generuotiPazymius1(studentas& stud, int nd_sk);
void generuotiEgzamina(studentas& stud);
void generuotiStudentuSarasa(vector<studentas>& grupe, int studentuSkaicius);
void skaitytiFaila(const string& failopav, vector<studentas>& grupe);
void isvedimasFaile (vector<studentas>& grupe, const string& failoPavadinimas);

bool palyginti(const string& a, const string& b);
void irasytiIFaila(const vector<studentas>& grupe, const string& failoPavadinimas);

void suskirstymas1(vector<studentas>& grupe, vector<studentas>& moksliukai, vector<studentas>& varksiukai);
void suskirstymas2(vector<studentas>& grupe, vector<studentas>& varksiukai);
void suskirstymas3(vector<studentas>& grupe, vector<studentas>& varksiukai);

void matuotiLaika(const string& failoPavadinimas, vector<studentas>& grupe, int stud_skaicius,vector<studentas>& moksliukai, vector<studentas>& varksiukai, char pasirinkimas, char generavimas, char strategija);




