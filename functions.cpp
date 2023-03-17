#include "Mylib.h"
const char FILENAME[] = "kursiokai1.txt";
#define _CRT_SECURE_NO_WARNINGS

struct studentas {
	string vardas, pavarde;
	int egz = 0;
	vector<int> paz;
	double vid, med;
};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, vector<studentas>& mas);
void pild(studentas& tempas);
double vidurkis(const vector<int>& paz, studentas& tempas);
double mediana(vector<int>& paz, studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, vector<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas);
bool egzistuojantis(const string& filename);