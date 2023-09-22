#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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
  float rez;
};

void duomenu_ivedimas(vector<studentas>& grupe);
float Galutinis(const studentas& stud);
void spausdinti(vector<studentas>& grupe);
