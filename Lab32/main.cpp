#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Complex.h"
#include "Obliczenia.h"
#include <iostream>
#include "Rownanie.h"
#include "Quadratic.h"
#include "DoubleQuadratic.h"
#include <vector>
#include <complex>

using namespace std;

int main()
{
	//int* tab = new int[3];
	Rownanie *wskaznik;
	int tmp;
	vector <int> tab;
	std::complex<double> x1;
	x1.real(2);
	x1.imag(3.26262);
	cout << x1.real();
	cout << x1;

	cout << "a: ";
	cin >> tmp;
	tab.push_back(tmp);
	cout << "b: ";
	cin >> tmp;
	tab.push_back(tmp);
	cout << "c: ";
	cin >> tmp;
	tab.push_back(tmp);
	/*tab[0] = 0;
	tab[1] = 2;
	tab[2] = 1;*/
	/*for (size_t i = 0; i < dane.size(); i++)
		printf("%d, ", dane[i]);

	printf("\n\nKoniec\n");*/
	cout << endl;
	Obliczenia* obliczenie = new Obliczenia();
	if (tab[0] == 0) {
		wskaznik = new Quadratic();
	}
	else {
		wskaznik = new DoubleQuadratic();
	}
	wskaznik->formatuj_rnie(tab);
	cout << endl;
	obliczenie->oblicz_pierwiastki(tab);
	obliczenie->wyswietl_wyniki(tab);

	system("pause");
	return 0;
}
