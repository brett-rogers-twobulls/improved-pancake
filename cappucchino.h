#ifndef CAPPUCCHINO_H
#define CAPPUCCHINO_H

#include "coffee.h"

class Cappucchino : public Coffee
{
public:
	Cappucchino(const int);
	virtual bool AddCoffee() override;
	virtual bool AddMilk() override;
	virtual bool AddFoam() override;
	virtual bool AddExtras() override;
};

#endif