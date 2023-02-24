#include "Mylib.h"

struct studentas {
	string vardas, pavarde;
	int egz=0;
	vector<int> paz;
};

// liepia ivesti varda, pavarde, egzamino ir namu darbu rezultatus
void pild(studentas& tempas) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> tempas.vardas >> tempas.pavarde;
	int x;
	cout << "Iveskite pazymius, kai noresite baigti, parasykite raide arba skaiciu didesni uz 10: ";
	cin >> x;
	while (cin.fail() || x <= 0 || x > 10)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Skaicius privalo buti nuo 1-10" << endl;
		cin >> x;
		tempas.paz.push_back(x);
	}
	cin >> x;
	while (cin.fail() || x < 0 || x > 10)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Skaicius privalo buti nuo 1-10" << endl;
		cin >> x;
		tempas.paz.push_back(x);
	}
	while (cin >> x )
	{
		if (x <= 0 || x>10 )
		{
			break;
		}
		tempas.paz.push_back(x);
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Iveskite egzamino paz: ";
	cin >> tempas.egz;
	while (cin.fail() || tempas.egz < 0 || tempas.egz > 10) {
		cout << "Iveskite skaiciu nuo 1-10" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> tempas.egz;
	}
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	cout << "Ar norite kad skaiciai butu generuojami? Jei taip, irasykite '1'," << endl;
	cout << "jei ne, bet koki kita simboli ar skaiciu" << endl;
	int uzklausa;
	cin >> uzklausa;
	if (uzklausa == 1)
	{
		for (int i = 0; i < tempas.paz.size(); i++)
			tempas.paz[i] = dist(gen);
		tempas.egz = dist(gen);
	}
}
// apskaiciuoja vidurki
double vidurkis(const vector<int>& paz, studentas& tempas) {
	double sum = accumulate(paz.begin(), paz.end(), 0);
	if (paz.size() > 0)
		return 0.4 * (sum / paz.size()) + 0.6 * tempas.egz;
	else
		return 0;
}

// apskaiciuoja mediana
double mediana(vector<int>& paz, studentas& tempas) {
	if (paz.size() != 0)
	{
		int n = paz.size();
		sort(paz.begin(), paz.end());
		if (n % 2 == 0) {
			return (double)0.4 * ((paz[n / 2 - 1] + paz[n / 2]) / 2) + 0.6 * tempas.egz;
		}
		else {
			return (double)0.4 * (paz[n / 2]) + 0.6 * tempas.egz;
		}
	}
	else
		return 0;
}
// ispausdina visus reikalingus duomenis
void spausd(studentas& tempas) {
	cout << left << setw(10) << tempas.vardas << setw(15) << tempas.pavarde;
	cout << setw(12) << fixed << setprecision(2) << vidurkis(tempas.paz, tempas);
	cout  << setw(10) << fixed << setprecision(2) << mediana(tempas.paz, tempas) << endl;
}
int main() {
	vector <studentas> mas;
	studentas tempasas;
	char uzkl = 'n';
		do {
			pild(tempasas);
			mas.push_back(tempasas);
			tempasas.paz.clear();
			cout << "Baigti darba spausk n, testi - bet koks klavisas: ";
			cin >> uzkl;
			if (uzkl == 'n' || uzkl == 'N')
			{
				cout << left << setw(10) << "Vardas" << setw(10) << "Pavarde" << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
				cout << "-----------------------------------------------------------" << endl;
			}

		} while (uzkl != 'n' && uzkl != 'N');
		{
			for (auto& i : mas) spausd(i);
			for (auto& i : mas) i.paz.clear();
		}

	}

	