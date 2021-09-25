#include <iostream>
#include "decaf.h"

Decaf::Decaf(const int cost) : Coffee(cost) { }

bool Decaf::AddCoffee()
{
	std::cout << "Adding 1/3 Decaf Coffee\n";
	return true;
}

bool Decaf::AddMilk()
{
	std::cout << "Adding 2/3 Milk\n";
	return true;
}