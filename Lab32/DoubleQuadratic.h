#pragma once
#include "Rownanie.h"
class DoubleQuadratic : public Rownanie
{
public:
	DoubleQuadratic();
	~DoubleQuadratic();
	virtual void formatuj_rnie(std::vector<int> tab);
};

