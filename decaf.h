#ifndef DECAF_H
#define DECAF_H

#include "coffee.h"

class Decaf : public Coffee
{
public:
	Decaf(const int);
	virtual bool AddCoffee() override;
	virtual bool AddMilk() override;
};

#endif