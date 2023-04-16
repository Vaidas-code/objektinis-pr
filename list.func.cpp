#include "List.h"
#define _CRT_SECURE_NO_WARNINGS
struct studentas {
	string vardas, pavarde;
	int egz = 0;
	list<int> paz;
	double vid, med;
};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, list<studentas>& mas, string pav);
void pild(studentas& tempas);
double vidurkis(const list<int>& paz, studentas& tempas);
double mediana(list<int>& paz, studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, list<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl);
bool egzistuojantis(const string& filename);