#pragma once
#ifndef HEADER_FILE_1_H
#define HEADER_FILE_1_H
#include "functions.cpp"
#include <chrono> 

//palyginam vardus
bool palyginti_vardus(const studentas& a, const studentas& b) {
	return a.vardas < b.vardas;
}
bool palyginti_galutinius(const studentas& a, const studentas& b) {
	return a.vid > b.vid;
}
//skaitymas is failo
void skait(studentas& tempas, int kiekis, vector<studentas>& mas) {
	string vardas, pavarde, tmp;
	int temp;
	ifstream inputFile(FILENAME);
	try {
		if (!inputFile.is_open()) {
			throw runtime_error("Nepavyko atidaryti failo");
		}
		// read the first student's data
		inputFile >> vardas >> pavarde;
		string line;
		getline(inputFile, line);
		stringstream ss(line);
		string zodis;
		while (ss >> zodis) {
			kiekis++;
		}
		kiekis--;
		while (!inputFile.eof()) {
			inputFile >> tempas.vardas >> tempas.pavarde;
			for (int i = 0; i < kiekis; i++) {
				inputFile >> temp;
				tempas.paz.emplace_back(temp);
			}
			inputFile >> tempas.egz;
			if (tempas.paz.size() != kiekis) {
				throw runtime_error("Klaidingas duomenu formatas: neteisingas elementu skaicius");
			}
			mas.emplace_back(tempas);
			tempas.paz.clear();
		}
	}
	catch (exception& e) {
		cout << "Klaida: " << e.what() << endl;
	}
	inputFile.close();
}


// liepia ivesti varda, pavarde, egzamino ir namu darbu rezultatus
void pild(studentas& tempas) {
	cout << "Iveskite varda ir pavarde: ";
	cin >> tempas.vardas >> tempas.pavarde;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	cout << "Ar norite kad skaiciai butu generuojami? Jei taip, irasykite 'y'," << endl;
	cout << "jei ne, bet koki kita simboli ar skaiciu" << endl;
	char uzklausa;
	cin >> uzklausa;
	if (uzklausa == 'y' || uzklausa == 'Y')
	{
		cout << "Iveskite kiek pazymiu norite sugeneruoti: " << endl;
		int p;
		cin >> p;
		while (cin.fail() || p < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti didesnis uz 0" << endl;
			cin >> p;
			tempas.paz.emplace_back(p);
		}
		for (int i = 0; i < p; i++) {
			tempas.paz.emplace_back(dist(gen));
		}
		tempas.egz = dist(gen);
	}
	else
	{
		int x;
		cout << "Iveskite pazymius, kai noresite baigti, parasykite raide arba skaiciu didesni uz 10: ";
		cin >> x;
		while (cin.fail() || x <= 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.paz.emplace_back(x);
		}
		cin >> x;
		while (cin.fail() || x < 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.paz.emplace_back(x);
		}
		while (cin >> x)
		{
			if (x <= 0 || x > 10)
			{
				break;
			}
			tempas.paz.emplace_back(x);
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
	cout << left << setw(20) << tempas.vardas << setw(20) << tempas.pavarde;
	cout << setw(12) << fixed << setprecision(2) << vidurkis(tempas.paz, tempas);
	cout << setw(10) << fixed << setprecision(2) << mediana(tempas.paz, tempas) << endl;
}

void sukurti1(studentas& tempas, vector<studentas>& mas) {
	const char* trinti1 = "sukurtas1.txt";
	int r1 = remove(trinti1);
	const char* trinti2 = "sukurtas2.txt";
	int r2 = remove(trinti2);
	const char* trinti3 = "sukurtas3.txt";
	int r3 = remove(trinti3);
	string tikrinimas;
	int irasai;
	auto durationN = std::chrono::microseconds();
	auto durationR = std::chrono::microseconds(); 
	auto durationP = std::chrono::microseconds(); 
	auto durationA = std::chrono::microseconds();
	vector<studentas> pirmunai;
	vector<studentas> abejingi;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	cout << "Iveskite kiek irasu norite sugeneruoti? Galima rinktis 1000, 10000, 100000, 1000000, 10000000, \n jei norite baigti iveskite 0" << endl;
	cin >> tikrinimas;
	auto startS = std::chrono::high_resolution_clock::now();
	ofstream file1("sukurtas1.txt");
	auto endS = std::chrono::high_resolution_clock::now();
	auto durationS = std::chrono::duration_cast<std::chrono::microseconds>(endS - startS);
	ofstream file2("sukurtas2.txt");
	ofstream file3("sukurtas3.txt");
	file1 << left << setw(20) << "Vardas" << setw(21) << "Pavarde" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(5) << "EGZ."<< endl;
	file2 << "Pirmunai: " << endl;
	file3 << "Abejingi: " << endl;
	while (tikrinimas != "0") {
		while (tikrinimas != "1000" && tikrinimas != "10000" && tikrinimas != "100000" && tikrinimas != "1000000" && tikrinimas != "10000000")
		{
			cout << "Netinkamas skaicius, iveskite viena is siu skaiciu: 1000, 10000, 100000, 1000000, 10000000" << endl;
			cin >> tikrinimas;
		}
		if (file1.is_open()) {
			irasai = stoi(tikrinimas);
			cout << "Failas sukurtas. " << irasai << endl;
			//mas.reserve(irasai);
			for (int i = 1; i < irasai + 1; i++)
			{
				file1 << left  << "Vardas" << setw(14) << i <<  "Pavarde" << setw(14) << i << " ";
				for (int j = 0; j < 5; j++)
				{
					file1 << left << setw(4) << dist(gen) << " ";
				}
				file1 << left << setw(4) << dist(gen) << endl;
			}
			file1.close();
			ifstream rfile1("sukurtas1.txt");
			string linija;
			getline(rfile1, linija);
			auto startN = std::chrono::high_resolution_clock::now();
			for (int i = 1; i < irasai + 1; i++)
			{
				rfile1 >> tempas.vardas >> tempas.pavarde;
				for (int j = 0; j < 5; j++)
				{
					int pazymys;
					rfile1 >> pazymys;
					tempas.paz.emplace_back(pazymys);
				}
				rfile1 >> tempas.egz;
				tempas.med = mediana(tempas.paz, tempas);
				tempas.vid = vidurkis(tempas.paz, tempas);
				mas.emplace_back(move(tempas));
				tempas.paz.clear();
			}
			rfile1.close();
			auto endN = std::chrono::high_resolution_clock::now();
			durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
			auto startR = std::chrono::high_resolution_clock::now();
			sort(mas.begin(), mas.end(), palyginti_galutinius);
			for (auto& student: mas )
			{
				if (student.vid >= 5)
				{
					pirmunai.emplace_back(move(student));
				}
				else
				{
					abejingi.emplace_back(move(student));
				}

			}
			auto endR = std::chrono::high_resolution_clock::now();
			durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
			auto startP = std::chrono::high_resolution_clock::now();
			char eil[100];
			for (auto pirm : pirmunai)
			{
				sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", pirm.vardas.c_str(), pirm.pavarde.c_str(), pirm.vid, pirm.med);
				file2 << eil;
			}
			//		file2 << left << setw(20) << pirm.vardas << setw(20) << pirm.pavarde << fixed << setprecision(2) << setw(6) << pirm.vid << pirm.med << endl;

			auto endP = std::chrono::high_resolution_clock::now();
			durationP = std::chrono::duration_cast<std::chrono::microseconds>(endP - startP);
			auto startA = std::chrono::high_resolution_clock::now();
			for (auto abej : abejingi)
			{
				sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", abej.vardas.c_str(), abej.pavarde.c_str(), abej.vid, abej.med);
				file3 << eil;
			}
			auto endA = std::chrono::high_resolution_clock::now();
			durationA = std::chrono::duration_cast<std::chrono::microseconds>(endA - startA);
		}
		else {
			cout << "Nepavyko sukurti failo." << endl;
			break;
		}
		cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
		cin >> tikrinimas;
		if (tikrinimas != "0")
		{
			cout << "Kiek dabar norite sugeneruoti irasu? ";
			cin >> tikrinimas;
		}
		else
		{
			break;
		}
	}
	file2.close();
	file3.close();
	cout << endl;
	cout << left << "Tiek trunka failo sukurimas:             " << durationS.count() / 1000000.0 << " seconds. " << endl;
	cout << left << "Tiek trunka failo nuskaitymas:           " << durationN.count() / 1000000.0 << " seconds. " << endl; 
	cout << left << "Tiek trunka studentu rusiavimas:         " << durationR.count() / 1000000.0 << " seconds. " << endl; 
	cout << left << "Tiek trunka pirmunu irasymas:            " << durationP.count() / 1000000.0 << " seconds. " << endl;
	cout << left << "Tiek trunka abejingu irasymas:           " << durationA.count() / 1000000.0 << " seconds. " << endl;
}
#endif