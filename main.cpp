#include "Mylib.h"

struct studentas {
    string vardas, pavarde;
    int egz;
    int* paz;
    double vid, med;
    bool random = false;
};
struct studentai {
    studentas* studentas;
    int dydis;
};

void mediana(studentas* tempas, int dydis) {
    {
        sort(tempas->paz, tempas->paz + dydis, greater<int>());
    }
    int vidurys = dydis / 2;
    float mediana = dydis % 2 == 0 ? (tempas->paz[vidurys - 1] + tempas->paz[vidurys]) / 2.0 : tempas->paz[vidurys];
    tempas->med = 0.4 * mediana + 0.6 * tempas->egz;
}

void keistiint(int*& array, int dydis) {
    int* newArray = new int[dydis];
    for (int i = 0;i < dydis - 1;i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}
//liepia ivesti varda, pavarde, egzamino ir namu darbu rezultatus
void pild(studentas* tempas) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 10);
    char uzkl;
    cout << "Iveskite varda ir pavarde: ";
    cin >> tempas->vardas >> tempas->pavarde;
    double x, suma = 0;
    int n = 0;
    tempas->paz = NULL;
    cout << "Ar norite suzinoti,kokie galutinis pazymys butu generuojant atsitiktinius sk.? Jei taip, irasykite 'y'" << endl;
    cin >> uzkl;
    if (uzkl == 'y' || uzkl=='Y') {
        cout << "Iveskite kiek pazymiu norite sugeneruoti: " << endl;
        cin >> n;
        while (cin.fail() || n <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Skaicius privalo buti nuo 1-10" << endl;
            cin >> n;
        }
        tempas->paz = new int[n];
        for (int i = 0; i < n; i++)
        {
            tempas->paz[i] = dist(gen);
            suma += tempas->paz[i];
        }
        tempas->egz = dist(gen);
        tempas->vid = suma / n;
        mediana(tempas, n);
    }
    else
    {
        cout << "Iveskite pazymius, kai noresite baigti, parasykite raide arba skaiciu didesni uz 10: " << endl;
        cin >> x;
        while (cin.fail() || x <= 0 || x > 10)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Skaicius privalo buti nuo 1-10" << endl;
            cin >> x;
        }
        tempas->paz = new int[1];
        tempas->paz[0] = x;
        suma += x;
        n++;
        while (cin >> x && x > 0 && x <= 10) {
            suma += x;
            n++;
            keistiint(tempas->paz, n);
            tempas->paz[n - 1] = x;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Iveskite egzamino paz: " << endl;
        cin >> tempas->egz;

        while (tempas->egz < 1 || tempas->egz > 10 || cin.fail())
        {
            cout << "Iveskite skaiciu nuo 1-10" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> tempas->egz;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        tempas->vid = 0.4*(suma / n)+0.6*tempas->egz;
        mediana(tempas, n);
    }

}
void keististruk(studentas*& array, int size) {
    studentas* newArray = new studentas[size];
    for (int i = 0;i < size - 1;i++) {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

// atspausdinimas duomenu
void spausd(studentas* tempas) {
    cout << setw(10) << left << tempas->vardas << setw(15) << left << tempas->pavarde;
    cout << setw(17) << left << setprecision(2) << fixed << tempas->vid << setw(3) << setprecision(2) << fixed << tempas->med;
    cout << endl;
}

int main() {
    int n = 0;
    char uzkl = ' ';
    studentai Kursas;

    while (uzkl != 'n' && uzkl != 'N') {
        if (n == 0) { //pati pirma karta bus inicijuojamas masyvas
            Kursas.studentas = new studentas[1]; //duodame tik viena vieta
            ++n; //max tampa 1, kad loopas vel nesoktu i if{}
            Kursas.dydis = n;
            pild(&Kursas.studentas[0]); //uzpildome ta viena vieta
        }
        else { //visais kitais kartais
            ++n; //padidiname skaitliuka, (antra karta bus 2)
            keististruk(Kursas.studentas, n); //padidiname masyva
            pild(&Kursas.studentas[n - 1]); //uzpildome ta suteikta vieta
        }
        if (Kursas.studentas[n - 1].paz == NULL) { //leidzia viena karta pabandyti is naujo
            cout << "Neivedete jokiu studentu duomenu, iveskite is nujo." << endl;
            pild(&Kursas.studentas[n - 1]);
        }
        Kursas.dydis = n;
        cout << "Baigti darba? Spausk n, testi - bet koks kitas klavisas" << endl;
        cin >> uzkl;
    }

    cout << endl << endl << setw(10) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(17) << "Galutinis (Vid.) " << setw(18) << "/ Galutinis (Med.)";
    cout << endl << "------------------------------------------------------------" << endl;
    for (int i = 0;i < Kursas.dydis;i++) {
        spausd(&Kursas.studentas[i]);
        delete[] Kursas.studentas[i].paz;
    }
    cout << endl;
    delete[] Kursas.studentas;
}
