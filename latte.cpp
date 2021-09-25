#include <iostream>
#include "latte.h"

Latte::Latte(const int cost) : Coffee(cost) { }

bool Latte::AddCoffee()
{
	std::cout << "Adding 1/3 Coffee\n"; 
	return true;
}

bool Latte::AddMilk()
{
	std::cout << "Adding 1/2 Milk\n";
	return true;
}

bool Latte::AddFoam()
{
	std::cout << "Adding 1/6 Foam\n";
	return true;
}
