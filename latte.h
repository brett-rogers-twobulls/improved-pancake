#ifndef LATTE_H
#define LATTE_H

#include "coffee.h"

class Latte : public Coffee
{
public:
	Latte(const int);
	virtual bool AddCoffee() override;
	virtual bool AddMilk() override;
	virtual bool AddFoam() override;

};

#endif