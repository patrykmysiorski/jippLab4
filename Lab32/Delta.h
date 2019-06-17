#pragma once
#include <vector>
class Delta
{
public:
	Delta();
	~Delta();
protected:
	virtual double oblicz_delte(std::vector<int> tab) = 0;
};

