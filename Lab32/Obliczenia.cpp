#include "Obliczenia.h"
#include <iostream>
#include <vector>
using namespace std;




Obliczenia::Obliczenia()
{
}


Obliczenia::~Obliczenia()
{
}


double Obliczenia::oblicz_delte(std::vector<int> tab)
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];
	double delta = 0;
	if (a != 0) {
		delta = 1.0 * b * b - 4.0 * a * c;
	}
	else if (b != 0) {
		delta = -4.0 * b * c;
	}
	return delta;
}

void Obliczenia::oblicz_pierwiastki(std::vector<int> tab)
{
	vector<complex<double>> wyniki;
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	x1.real(0);
	x1.imag(0);
	x2.real(0);
	x2.imag(0);
	x3.real(0);
	x3.imag(0);
	x4.real(0);
	x4.imag(0);

	if (a != 0) { //a nierowne 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);

			double t1 = (-1.0 * b - pdelta) / (2.0 * a);
			double t2 = (-1.0 * b + pdelta) / (2.0 * a);

			if (t1 < 0) {//t1 ujemne 
				x1.real(0.0);
				x1.imag(sqrt(-1.0 * t1));
				x2.real(x1.real());
				x2.imag(-1.0 * x1.imag());
				wyniki.push_back(x1);
				wyniki.push_back(x2);
			}
			else { //t1 dodatnie lub rowne 0
				x1.real(sqrt(t1));
				x2.real(-1.0 * sqrt(t1));
				wyniki.push_back(x1);
				wyniki.push_back(x2);
			}

			if (t2 < 0) { //t2 ujemne
				x3.real(0.0);
				x3.imag(sqrt(-1.0 * t2));
				x4.real(x3.real());
				x4.imag(-1.0 * x3.imag());
				wyniki.push_back(x3);
				wyniki.push_back(x4);
			}
			else { //t2 wieksze lub rowne 0
				x3.real(sqrt(t2));
				x4.real(-1.0 * sqrt(t2));
			}
		}
		else if (delta == 0) {//delta rowna 0
			double t = (-1.0 * b) / (2.0 * a);

			if (t >= 0) { // t wieksze lub rowne 0
				x1.real(sqrt(t));
				x2.real(-1.0 * sqrt(t));
			}
			else { // t ujemne
				x1.real(0.0);
				x1.imag(sqrt(-1.0 * t));
				x2.real(x1.real());
				x2.imag(-1.0 * x1.imag());
			}
		}
		else { //delta ujemna
			double pdelta = sqrt(-1.0 * delta);

			double t1r = (-1.0 * b) / (2.0 * a);
			double t1u = (-1.0 * pdelta) / (2.0 * a);
			double t2r = t1r;
			double t2u = (1.0 * pdelta) / (2.0 * a);

			x1.real(sqrt((sqrt(t1r * t1r + t1u * t1u) + t1r) / 2.0));
			x1.imag(sqrt((sqrt(t1r * t1r + t1u * t1u) - t1r) / 2.0));

			x2.real(x1.real());
			x2.imag(-1.0 * x1.imag());

			x3.real(-1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) + t2r) / 2.0));
			x3.imag(-1.0 * sqrt((sqrt(t2r * t2r + t2u * t2u) - t2r) / 2.0));

			x4.real(x3.real());
			x4.imag(-1.0 * x3.imag());
		}
	}
	else if (b != 0) {//a rowne 0, b rozne od 0
		double delta = oblicz_delte(tab);

		if (delta > 0) { //delta dodatnia
			double pdelta = sqrt(delta);
			x1.real((-1.0 * pdelta) / (2.0 * b));
			x2.real((1.0 * pdelta) / (2.0 * b));
		}
		else if (delta == 0) {//delta rowna 0
			x1.real(0.0);
			x2.real(x1.real());
		}
		else { //delta ujemna
			double delta_2 = -1.0 * delta;
			double pdelta = sqrt(delta_2);

			x1.real(0.0);
			x1.imag((-1.0 * pdelta) / (2.0 * b));
			x2.real(0.0);
			x2.imag((1.0 * pdelta) / (2.0 * b));
		}
	}
}

void Obliczenia::dodaj_l_zesp()
{
	addResult.real(0);
	addResult.imag(0);
	addResult.real(x1.real() + x2.real() + x3.real() + x4.real());
}

void Obliczenia::odejm_l_zesp()
{
	subResult.real(0);
	subResult.imag(0);
	subResult.real(x1.real() - x2.real() - x3.real() - x4.real());
	subResult.imag(x1.imag() - x2.imag() - x3.imag() - x4.imag());
	if (subResult.imag() < 0) {
		subResult.imag(subResult.imag() * -1);
	}
}

void Obliczenia::wyswietl_wyniki(std::vector<int> tab)
{
	int a = tab[0];
	int b = tab[1];
	int c = tab[2];

	if (a != 0) {
		double delta = oblicz_delte(tab);
		cout << "delta: " << delta << endl;
		if (delta != 0) //delta rozna od zera
		{
			//wypisz x1
			cout << "x1: ";
			//cout << x1.real() << "+" << x1.getImaginaryNumber() << endl;
			printString(x1);
			//wypisz x2
			cout << "x2: ";
			printString(x2);
			//wypisz x3
			cout << "x3: ";
			printString(x3);
			//wypisz x4
			cout << "x3: ";
			printString(x4);
		}
		else // delta rowna 0
		{
			printString(x1);
			printString(x2);
		}
	}
	else //a rowne zero
	{
		double delta = oblicz_delte(tab);
		cout << "delta: " << delta << "\n";
		if (delta < 0) //delta ujemna
		{
			//cout << x1.real() << "+" << x1.getImaginaryNumber() << endl;
			printString(x1);
			printString(x2);
		}
		else //delta wieksza lub rowna zero
		{
			cout << "x1: " << x1.real() << "\n";
			cout << "x2: " << x2.real() << "\n";
		}
	}
	odejm_l_zesp();
	dodaj_l_zesp();
	
	cout << "sr: " << addResult.real() << endl;
	cout << "su: " << addResult.imag() << endl;
	cout << "rr: " << subResult.real() << endl;
	cout << "ru: " << subResult.imag() << endl;
	cout << "suma: ";
	if (addResult.real() == 0 && addResult.imag() == 0) {
		cout << endl;
	}
	else {
		printString(addResult);
	}
	cout << "roznica: ";
	if (subResult.real() == 0 && subResult.imag() == 0) {
		cout << endl;
	}
	else {
		printString(subResult);
	}
}

void Obliczenia::printString(std::complex<double> complexValue)
{
	if (complexValue.imag() < 0) {
		cout << complexValue.real() << complexValue.imag() << "i" << endl;
	}
	else {
		cout << complexValue.real() << "+" << complexValue.imag() << "i" << endl;
	}
}
