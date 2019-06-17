#pragma once
#include "Rownanie.h"
class Quadratic : public Rownanie
{
public:
	Quadratic();
	~Quadratic();
	virtual void formatuj_rnie(std::vector<int> tab);
};

