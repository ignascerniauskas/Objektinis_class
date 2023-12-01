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
    friend void apskaiciuotiMedianaf(studentas stud) {
        std::list<int> sorted_paz = stud.getPaz();
        sorted_paz.sort();

        int n = sorted_paz.size();
        auto iter = sorted_paz.begin();
        std::advance(iter, n / 2);

        if (n % 2 == 0) {
            int vidurys1 = *std::prev(iter);
            int vidurys2 = *iter;
            stud.setMedGalutinis(0.4 * (vidurys1 + vidurys2) / 2.0 + 0.6 * stud.getEgzaminas());
        } else {
            int vidurys = *iter;
            stud.setMedGalutinis(0.4 * vidurys + 0.6 * stud.getEgzaminas());
        }
}

    friend void apskaiciuotiVidurkif(studentas& stud) {
        float vidurkis = 0;
        for (int pazymys : stud.getPaz()) {
            vidurkis += pazymys;
        }
        vidurkis /= stud.getPaz().size();
        double galutinis = 0.4 * vidurkis + 0.6 * stud.getEgzaminas();
        stud.setvidGalutinis(galutinis);
    }


public:
    // Default
    studentas() : egz(0), vidGalutinis(0), medGalutinis(0) {}
    studentas(istream& is);
    istream& readstudentas(istream&);
    void clearPazymiai() { paz.clear(); }

    void copyPaz(const list<int>& source){
        paz = source;
   }


    // II. Copy constructor
    studentas(const studentas& other){
        vard = other.vard;
        pav = other.pav;
        paz = other.paz;
        egz = other.egz;
        vidGalutinis = other.vidGalutinis;
        medGalutinis = other.medGalutinis;
    }

    // III. Copy assignment operator
    studentas& operator=(const studentas& other) {
        if (this != &other) {
            vard = other.vard;
            pav = other.pav;
            paz = other.paz;
            egz = other.egz;
            vidGalutinis = other.vidGalutinis;
            medGalutinis = other.medGalutinis;
        }
        return *this;
    }

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


    friend istream& operator>>(istream& is, studentas& student) {
        cout << "Iveskite studento Varda ir Pavarde: ";
        is >> student.vard >> student.pav;

        cout << "Iveskite studento pazymius: ";
        int pazymys;
        while (is >> pazymys) {
                    try {
                        if (pazymys < 0 || pazymys > 10) {
                            throw runtime_error("Klaida: Pazimys turi buti nuo 0 iki 10.");
                        }
                        student.addPazymys(pazymys);
                    } catch (const exception& e) {
                        cerr << "Klaida: " << e.what() << endl;
                    }
                    if (is.peek() == '\n') {
                        is.ignore();
                        break;
                    }
                }

        do {
        cout << "Iveskite egzamino rezultata (nuo 0 iki 10): ";
        is >> student.egz;

        if (is.fail() || student.egz < 0 || student.egz > 10) {
            cerr << "Klaida: Egzamino rezultatas turi buti nuo 0 iki 10." << endl;
            is.clear();
            }
        } while (student.egz < 0 || student.egz > 10);

        apskaiciuotiVidurkif(student);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, studentas& student) {
        apskaiciuotiVidurkif(student);

        os << left << setw(20) << student.pav<< setw(20) << student.vard<< fixed << setprecision(2)<< setw(5) << student.vidGalutinis;

        return os;

    }

    // I. Destructor
    ~studentas() {
        paz.clear();
        //cout<<"objektas sunaikintas"<<endl;
    }

};

void duomenuIvedimas(list<studentas>& grupe);
void duomenuIvedimas_class(list<studentas>& grupe);
void rezultatuIsvendimasEkrane(list<studentas>& grupe);
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
