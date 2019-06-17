#pragma once
#include "Delta.h"
#include "Complex.h"
#include <complex>

class Obliczenia : protected Delta
{
private:
	double oblicz_delte(std::vector<int> tab) override;
public:
	Obliczenia();
	~Obliczenia();
	void oblicz_pierwiastki(std::vector<int> tab);
	void dodaj_l_zesp();
	void odejm_l_zesp();
	
	void wyswietl_wyniki(std::vector<int> tab);

private:
	std::complex<double> x1;
	std::complex<double> x2;
	std::complex<double> x3;
	std::complex<double> x4;
	std::complex<double> addResult;
	std::complex<double> subResult;
	void printString(std::complex<double> complexValue);
	//Complex x1;
	//Complex x2;
	//Complex x3;
	//Complex x4;
	//Complex addResult;
	//Complex subResult;
};

