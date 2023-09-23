#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;

struct studentas {
  string vard, pav;
  vector <int> paz;
  int egz;
  float vidGalutinis;
  float medGalutinis;
};

void duomenu_ivedimas(vector<studentas>& grupe);
float apskaiciuotivid(const studentas& stud);
float apskaiciuotimed(const studentas& stud);
void spausdinti(vector<studentas>& grupe, bool naudotividurki);
void generuotipazymius(studentas& stud);
void generuotiegzamina(studentas& stud);
