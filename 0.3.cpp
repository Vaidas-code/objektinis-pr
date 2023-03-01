#include "Mylib.func.h"


int main() {
	char tikr;
	cout << "Ar norite kad duomenys butu skaitomi is failo? Jei taip iveskite 'y':" << endl;
	cin >> tikr;
	if (tikr == 'y' || tikr == 'Y')
	{
		int kiekis = 0;
		vector <studentas> mas;
		studentas tempas;
		skait(tempas, kiekis, mas);
		sort(mas.begin(), mas.end(), palyginti_vardus);
		cout << "Vardas" << setw(20) << "Pavarde " << setw(20) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
		cout << "-----------------------------------------------------------" << endl;
		for (auto& i : mas) spausd(i);
		for (auto& i : mas) i.paz.clear();
	}
	else
	{
		vector <studentas> mas;
		studentas tempas;
		char uzkl = 'n';
		do {
			pild(tempas);
			mas.push_back(tempas);
			tempas.paz.clear();
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

}




