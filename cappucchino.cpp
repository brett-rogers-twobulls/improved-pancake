#include <iostream>
#include "cappucchino.h"

Cappucchino::Cappucchino(const int cost) : Coffee(cost) { }

bool Cappucchino::AddCoffee()
{
	std::cout << "Adding 1/3 Coffee\n";
	return true;
}

bool Cappucchino::AddMilk()
{
	std::cout << "Adding 1/3 Milk\n";
	return true;
}

bool Cappucchino::AddFoam()
{
	std::cout << "Adding 1/3 Foam\n";
	return true;
}

bool Cappucchino::AddExtras()
{
	std::cout << "Adding Chocolate Powder\n";
	return false; // Out of powder perhaps?
}
