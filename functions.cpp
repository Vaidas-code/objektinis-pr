#include "Mylib.h"
const char FILENAME[] = "kursiokai.txt";

struct studentas {
	string vardas, pavarde;
	int egz = 0;
	vector<int> paz;

};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, vector<studentas>& mas);
void pild(studentas& tempas);
double vidurkis(const vector<int>& paz, studentas& tempas);
double mediana(vector<int>& paz, studentas& tempas);
void spausd(studentas& tempas);