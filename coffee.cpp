#include <iostream>

#include "coffee.h"

Coffee::Coffee(const int cost)
{
	_cost = cost;
}

int Coffee::GetCost() const { return _cost; }

bool Coffee::MakeCoffee()
{
	bool success =
	AddCoffee() &&
	AddMilk() &&
	AddFoam() &&
	AddExtras();
	
	if (success) std::cout << "Enjoy!\n";
	return success;
}

bool Coffee::AddExtras() { return true; }

bool Coffee::AddFoam() { return true; }
