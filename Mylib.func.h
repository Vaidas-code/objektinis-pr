#pragma once
#ifndef HEADER_FILE_1_H
#define HEADER_FILE_1_H
#include "functions.cpp"


bool egzistuojantis(const std::string& Filename)
{
	return access(Filename.c_str(), 0) == 0;
}
void fgeneravimas(int kiekis, string failovardas, double& laikas, bool genl)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(1, 10);
	if (genl)
	{
		ofstream file1(failovardas);
		//auto startS = std::chrono::high_resolution_clock::now();
		file1 << left << setw(20) << "Vardas" << setw(21) << "Pavarde" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(5) << "EGZ." << endl;
		for (int i = 1; i < kiekis + 1; i++)
		{
			file1 << left << "Vardas" << setw(14) << i << "Pavarde" << setw(14) << i << " ";
			for (int j = 0; j < 5; j++)
			{
				file1 << left << setw(4) << dist(gen) << " ";
			}
			file1 << left << setw(4) << dist(gen) << endl;
		}
		file1.close();
		//auto endS = std::chrono::high_resolution_clock::now();
	//	auto durationS = std::chrono::duration_cast<std::chrono::microseconds>(endS - startS);
	//	laikas=durationS.count() / 1000000.0;
	}
	else
	{
		ofstream file1(failovardas);
		file1 << left << setw(20) << "Vardas" << setw(21) << "Pavarde" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(5) << "EGZ." << endl;
		for (int i = 1; i < kiekis + 1; i++)
		{
			file1 << left << "Vardas" << setw(14) << i << "Pavarde" << setw(14) << i << " ";
			for (int j = 0; j < 5; j++)
			{
				file1 << left << setw(4) << dist(gen) << " ";
			}
			file1 << left << setw(4) << dist(gen) << endl;
		}
		file1.close();
	}
}

bool palyginti_vardus(const studentas& a, const studentas& b) {
	return a.vardas < b.vardas;
}
bool palyginti_galutinius(const studentas& a, const studentas& b) {
	return a.vid > b.vid;
}
//skaitymas is failo
void skait(studentas& tempas, int kiekis, vector<studentas>& mas, string pav) {
	string vardas, pavarde, tmp;
	int temp;
	ifstream inputFile(pav);
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
				tempas.paz.push_back(temp);
			}
			inputFile >> tempas.egz;
			if (tempas.paz.size() != kiekis) {
				throw runtime_error("Klaidingas duomenu formatas: neteisingas elementu skaicius");
			}
			mas.push_back(tempas);
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
			tempas.paz.push_back(p);
		}
		for (int i = 0; i < p; i++) {
			tempas.paz.push_back(dist(gen));
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
			tempas.paz.push_back(x);
		}
		cin >> x;
		while (cin.fail() || x < 0 || x > 10)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Skaicius privalo buti nuo 1-10" << endl;
			cin >> x;
			tempas.paz.push_back(x);
		}
		while (cin >> x)
		{
			if (x <= 0 || x > 10)
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
	int tikrinimas, tikrinimas2;
	string tikrinimas1, fvardas, tikrinimas3;
	bool baigimas = false;
	double laikas = 0;
	auto durationN = std::chrono::microseconds();
	auto durationR = std::chrono::microseconds();
	auto durationS = std::chrono::microseconds();
	vector<studentas> pirmunai;
	vector<studentas> abejingi;
	if (!egzistuojantis("sukurtas1000.txt") && !egzistuojantis("sukurtas10000.txt") && !egzistuojantis("sukurtas100000.txt") && !egzistuojantis("sukurtas1000000.txt") && !egzistuojantis("sukurtas1000000.txt"))
	{
		cout << "Failu nera, ar norite generuoti faila? Jei taip iveskite 1" << endl;
		cin >> tikrinimas3;
		if (tikrinimas3 == "1")
		{
			cout << "Iveskite kiek irasu norite sugeneruoti? Galima rinktis nuo 1-10000000, \n jei norite baigti iveskite 0" << endl;
			cin >> tikrinimas;
			ofstream file2("sukurtas2.txt");
			ofstream file3("sukurtas3.txt");
			file2 << "Pirmunai: " << endl;
			file3 << "Abejingi: " << endl;
			while (baigimas == false)
			{
				while (cin.fail() || tikrinimas <= 0 || tikrinimas > 10000000)
				{
					if (tikrinimas == 0)
						return;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Netinkamas skaicius, iveskite skaiciu nuo 1 iki  10000000" << endl;
					cin >> tikrinimas;
				}
				if (tikrinimas > 0 && tikrinimas <= 1000)
					fvardas = "sukurtas1000.txt";
				if (tikrinimas > 1000 && tikrinimas <= 10000)
					fvardas = "sukurtas10000.txt";
				if (tikrinimas > 10000 && tikrinimas <= 100000)
					fvardas = "sukurtas100000.txt";
				if (tikrinimas > 100000 && tikrinimas <= 1000000)
					fvardas = "sukurtas1000000.txt";
				if (tikrinimas > 1000000 && tikrinimas <= 10000000)
					fvardas = "sukurtas10000000.txt";
				fgeneravimas(tikrinimas, fvardas, laikas, true);
				ifstream rfile1(fvardas);
				string linija;
				getline(rfile1, linija);
				auto startN = std::chrono::high_resolution_clock::now();
				for (int i = 1; i < tikrinimas + 1; i++)
				{
					rfile1 >> tempas.vardas >> tempas.pavarde;
					for (int j = 0; j < 5; j++)
					{
						int pazymys;
						rfile1 >> pazymys;
						tempas.paz.push_back(pazymys);
					}
					rfile1 >> tempas.egz;
					tempas.med = mediana(tempas.paz, tempas);
					tempas.vid = vidurkis(tempas.paz, tempas);
					mas.push_back(tempas);
					tempas.paz.clear();
				}
				rfile1.close();
				auto endN = std::chrono::high_resolution_clock::now();
				durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
				auto startW = std::chrono::high_resolution_clock::now();
				sort(mas.begin(), mas.end(), palyginti_galutinius);
				auto endW = std::chrono::high_resolution_clock::now();
				durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
				auto startR = std::chrono::high_resolution_clock::now();
				for (auto& student : mas)
				{
					if (student.vid >= 5)
					{
						//	pirmunai.push_back(move(student));
						pirmunai.push_back(student);
					}
					else
					{
						//abejingi.push_back(move(student));
						abejingi.push_back(student);
					}

				}
				mas.clear();
				auto endR = std::chrono::high_resolution_clock::now();
				durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
				char eil[100];
				for (auto pirm : pirmunai)
				{
					sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", pirm.vardas.c_str(), pirm.pavarde.c_str(), pirm.vid, pirm.med);
					file2 << eil;
				}
				//		file2 << left << setw(20) << pirm.vardas << setw(20) << pirm.pavarde << fixed << setprecision(2) << setw(6) << pirm.vid << pirm.med << endl;
				for (auto abej : abejingi)
				{
					sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", abej.vardas.c_str(), abej.pavarde.c_str(), abej.vid, abej.med);
					file3 << eil;
				}
				cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 != "0")
				{
					cout << "Kiek dabar norite sugeneruoti irasu? ";
					cin >> tikrinimas;
				}
				else
				{
					baigimas = true;
				}
			}
			file2.close();
			file3.close();
			cout << endl;
			cout << left << "Tiek trunka failo nuskaitymas:                   " << durationN.count() / 1000000.0 << " seconds. " << endl;
			cout << left << "Tiek trunka studentu rusiavimas pagal vidurkius  " << durationS.count() / 1000000.0 << " seconds  " << endl;
			cout << left << "Tiek trunka pirmunu ir abejingu rusiavimas:      " << durationR.count() / 1000000.0 << " seconds. " << endl;
			cout << left << "Tiek trunka visa programa:                       " << durationN.count() / 1000000.0 + durationR.count() / 1000000.0 + durationS.count() / 1000000.0 << "seconds. " << endl;
		}

	}
	else
	{
		while (baigimas == false)
		{
			cout << "Iveskite kiek irasu norite sugeneruoti? Galima rinktis nuo 1-10000000, \n jei norite baigti iveskite 0" << endl;
			cin >> tikrinimas;
			ofstream file2("sukurtas2.txt");
			ofstream file3("sukurtas3.txt");
			file2 << "Pirmunai: " << endl;
			file3 << "Abejingi: " << endl;
			while (cin.fail() || tikrinimas <= 0 || tikrinimas > 10000000)
			{
				if (tikrinimas == 0)
					return;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Netinkamas skaicius, iveskite skaiciu nuo 1 iki  10000000" << endl;
				cin >> tikrinimas;
			}
			if (tikrinimas > 0 && tikrinimas <= 1000)
				fvardas = "sukurtas1000.txt";
			if (tikrinimas > 1000 && tikrinimas <= 10000)
				fvardas = "sukurtas10000.txt";
			if (tikrinimas > 10000 && tikrinimas <= 100000)
				fvardas = "sukurtas100000.txt";
			if (tikrinimas > 100000 && tikrinimas <= 1000000)
				fvardas = "sukurtas1000000.txt";
			if (tikrinimas > 1000000 && tikrinimas <= 10000000)
				fvardas = "sukurtas10000000.txt";
			if (!egzistuojantis(fvardas))
			{
				cout << "Tokio dydzio failo nera, jei norite ji sugeneruoti iveskite - 1 jei uzbaigti programa - bet koks simbolis" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 == "1")
				{
					fgeneravimas(tikrinimas, fvardas, laikas, true);
					ifstream rfile1(fvardas);
					string linija;
					getline(rfile1, linija);
					auto startN = std::chrono::high_resolution_clock::now();
					for (int i = 1; i < tikrinimas + 1; i++)
					{
						rfile1 >> tempas.vardas >> tempas.pavarde;
						for (int j = 0; j < 5; j++)
						{
							int pazymys;
							rfile1 >> pazymys;
							tempas.paz.push_back(pazymys);
						}
						rfile1 >> tempas.egz;
						tempas.med = mediana(tempas.paz, tempas);
						tempas.vid = vidurkis(tempas.paz, tempas);
						mas.push_back(tempas);
						tempas.paz.clear();
					}
					rfile1.close();
					auto endN = std::chrono::high_resolution_clock::now();
					durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
					auto startW = std::chrono::high_resolution_clock::now();
					sort(mas.begin(), mas.end(), palyginti_galutinius);
					auto endW = std::chrono::high_resolution_clock::now();
					durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
					auto startR = std::chrono::high_resolution_clock::now();
					for (auto& student : mas)
					{
						if (student.vid >= 5)
						{
							//	pirmunai.push_back(move(student));
							pirmunai.push_back(student);
						}
						else
						{
							//abejingi.push_back(move(student));
							abejingi.push_back(student);
						}

					}
					mas.clear();
					auto endR = std::chrono::high_resolution_clock::now();
					durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
					char eil[100];
					for (auto pirm : pirmunai)
					{
						sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", pirm.vardas.c_str(), pirm.pavarde.c_str(), pirm.vid, pirm.med);
						file2 << eil;
					}
					//		file2 << left << setw(20) << pirm.vardas << setw(20) << pirm.pavarde << fixed << setprecision(2) << setw(6) << pirm.vid << pirm.med << endl;


					for (auto abej : abejingi)
					{
						sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", abej.vardas.c_str(), abej.pavarde.c_str(), abej.vid, abej.med);
						file3 << eil;
					}
					cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
					cin >> tikrinimas1;
					cout << endl;
					if (tikrinimas1 != "0")
					{
						cout << "Kiek dabar norite sugeneruoti irasu? ";
						cin >> tikrinimas;
					}
					else
					{
						baigimas = true;
					}
				}
				else
					return;
				file2.close();
				file3.close();
				cout << endl;
			}
			else
			{
				cout << "Tokio dydzio failas jau egzistuoja, jei norite ji perskaityti iveskite - 1, \n jei sugeneruoti is naujo - 2, jei uzbaigti programa - bet koks simbolis" << endl;
				cin >> tikrinimas1;
				if (tikrinimas1 == "1")
				{
					ifstream rfile1(fvardas);
					string linija;
					auto startN = std::chrono::high_resolution_clock::now();
					getline(rfile1, linija);
					while (rfile1 >> tempas.vardas >> tempas.pavarde)
					{
						for (int j = 0; j < 5; j++)
						{
							int pazymys;
							rfile1 >> pazymys;
							tempas.paz.push_back(pazymys);
						}
						rfile1 >> tempas.egz;
						tempas.med = mediana(tempas.paz, tempas);
						tempas.vid = vidurkis(tempas.paz, tempas);
						mas.push_back(tempas);
						tempas.paz.clear();
					}
					rfile1.close();
					auto endN = std::chrono::high_resolution_clock::now();
					durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
					auto startW = std::chrono::high_resolution_clock::now();
					sort(mas.begin(), mas.end(), palyginti_galutinius);
					auto endW = std::chrono::high_resolution_clock::now();
					durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
					auto startR = std::chrono::high_resolution_clock::now();
					for (auto& student : mas)
					{
						if (student.vid >= 5)
						{
							//	pirmunai.push_back(move(student));
							pirmunai.push_back(student);
						}
						else
						{
							//abejingi.push_back(move(student));
							abejingi.push_back(student);
						}

					}
					mas.clear();
					auto endR = std::chrono::high_resolution_clock::now();
					durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
					char eil[100];
					for (auto pirm : pirmunai)
					{
						sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", pirm.vardas.c_str(), pirm.pavarde.c_str(), pirm.vid, pirm.med);
						file2 << eil;
					}
					//		file2 << left << setw(20) << pirm.vardas << setw(20) << pirm.pavarde << fixed << setprecision(2) << setw(6) << pirm.vid << pirm.med << endl;
					for (auto abej : abejingi)
					{
						sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", abej.vardas.c_str(), abej.pavarde.c_str(), abej.vid, abej.med);
						file3 << eil;
					}
				}
				else
					if (tikrinimas1 == "2")
					{
						fgeneravimas(tikrinimas, fvardas, laikas, true);
						ifstream rfile1(fvardas);
						string linija;
						getline(rfile1, linija);
						auto startN = std::chrono::high_resolution_clock::now();
						for (int i = 1; i < tikrinimas + 1; i++)
						{
							rfile1 >> tempas.vardas >> tempas.pavarde;
							for (int j = 0; j < 5; j++)
							{
								int pazymys;
								rfile1 >> pazymys;
								tempas.paz.push_back(pazymys);
							}
							rfile1 >> tempas.egz;
							tempas.med = mediana(tempas.paz, tempas);
							tempas.vid = vidurkis(tempas.paz, tempas);
							mas.push_back(tempas);
							tempas.paz.clear();
						}
						rfile1.close();
						auto endN = std::chrono::high_resolution_clock::now();
						durationN = std::chrono::duration_cast<std::chrono::microseconds>(endN - startN);
						auto startW = std::chrono::high_resolution_clock::now();
						sort(mas.begin(), mas.end(), palyginti_galutinius);
						auto endW = std::chrono::high_resolution_clock::now();
						durationS = std::chrono::duration_cast<std::chrono::microseconds>(endW - startW);
						auto startR = std::chrono::high_resolution_clock::now();
						for (auto& student : mas)
						{
							if (student.vid >= 5)
							{
								//	pirmunai.push_back(move(student));
								pirmunai.push_back(student);
							}
							else
							{
								//abejingi.push_back(move(student));
								abejingi.push_back(student);
							}

						}
						mas.clear();
						auto endR = std::chrono::high_resolution_clock::now();
						durationR = std::chrono::duration_cast<std::chrono::microseconds>(endR - startR);
						char eil[100];
						for (auto pirm : pirmunai)
						{
							sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", pirm.vardas.c_str(), pirm.pavarde.c_str(), pirm.vid, pirm.med);
							file2 << eil;
						}
						//		file2 << left << setw(20) << pirm.vardas << setw(20) << pirm.pavarde << fixed << setprecision(2) << setw(6) << pirm.vid << pirm.med << endl;

						for (auto abej : abejingi)
						{
							sprintf_s(eil, sizeof(eil), "%-20s%-20s%-6.2f%-6.2f\n", abej.vardas.c_str(), abej.pavarde.c_str(), abej.vid, abej.med);
							file3 << eil;
						}
					}
					else
					{
						return;
					}
				cout << left << "Tiek trunka failo nuskaitymas:                   " << durationN.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka studentu rusiavimas pagal vidurkius  " << durationS.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka pirmunu ir abejingu rusiavimas:      " << durationR.count() / 1000000.0 << " seconds. " << endl;
				cout << left << "Tiek trunka visa programa:                       " << durationN.count() / 1000000.0 + durationR.count() / 1000000.0 + durationS.count() / 1000000.0 << "seconds. " << endl;
				cout << endl;
				cout << "Jei norite baigti iveskite 0, jei ne bet koki kita skaiciu ar simboli" << endl;
				cin >> tikrinimas1;
				cout << endl;
				if (tikrinimas1 == "0")
				{
					baigimas = true;
				}
				file2.close();
				file3.close();
				//-------------------------------------------
			}
		}
	}
}
#endif