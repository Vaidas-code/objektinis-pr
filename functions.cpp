// ----------------------------------------------------------------------------------------------------------------------
//---------------------------------VECTOR--------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------- 
/*
#include "Mylib.h"
#define _CRT_SECURE_NO_WARNINGS

struct studentas {
	string vardas, pavarde;
	int egz = 0;
	vector<int> paz;
	double vid, med;
};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, vector<studentas>& mas, string pav);
void pild(studentas& tempas);
double vidurkis(const vector<int>& paz, studentas& tempas);
double mediana(vector<int>& paz, studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, vector<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl);
bool egzistuojantis(const string& filename);
*/
// ----------------------------------------------------------------------------------------------------------------------
//---------------------------------DEQUE---------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------- 
/*
#include "Mylib.h"
#define _CRT_SECURE_NO_WARNINGS

struct studentas {
	string vardas, pavarde;
	int egz = 0;
	deque<int> paz;
	double vid, med;
};
//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b);
void skait(studentas& tempas, int kiekis, deque<studentas>& mas, string pav);
void pild(studentas& tempas);
double vidurkis(const deque<int>& paz, studentas& tempas);
double mediana(deque<int>& paz, studentas& tempas);
void spausd(studentas& tempas);
void sukurti1(studentas& tempas, deque<studentas>& mas);
bool palyginti_galutinius(const studentas& a, const studentas& b);
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl);
bool egzistuojantis(const string& filename);
*/
// ----------------------------------------------------------------------------------------------------------------------
//---------------------------------LIST----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------- 
/*
#include "Mylib.h"
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
*/