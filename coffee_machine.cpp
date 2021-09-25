#include <sstream>
#include <memory>
#include <iomanip>

#include "coffee_machine.h"

CoffeeMachine::CoffeeMachine() : _message("Coffee Machine booting up...\n"),  
	_coins{ ONE_CENT, TWO_CENT, FIVE_CENT, TEN_CENT, TWENTY_CENT, FIFTY_CENT, ONE_DOLLAR, TWO_DOLLAR } { }

CoffeeMachine& CoffeeMachine::Instance()
{
	static CoffeeMachine instance;
	return instance;
}

void CoffeeMachine::DispenseCoffee(char code)
{
	std::unique_ptr<Coffee> coffee;
	
	if (code == 'l')
		coffee = std::make_unique<Latte>(LATTE_COST);
	else if (code == 'c')
		coffee = std::make_unique<Cappucchino>(CAPPUCCHINO_COST);
	else if (code == 'd')
		coffee = std::make_unique<Decaf>(DECAF_COST);
	
	if (_insertedAmount >= coffee->GetCost())
	{	
		bool success = coffee->MakeCoffee();
		if (!success)
		{
			_message = "Error making coffee! Maybe check water level?\n";
			return;
		}
		_insertedAmount -= coffee->GetCost();
		Refund();
	}
	else
		_message = "Insert more coins\n";
}

void CoffeeMachine::InsertCoin(const double value)
{
	double d = value * 100;
	int cents = d;
	if (cents > TWO_CENT)
	{
		_insertedAmount += cents;

		std::stringstream ss;
		
		d = (double)_insertedAmount / 100;
		ss << std::fixed << std::setprecision(2) << d;
		_message = "$" + ss.str() + '\n';
	}
	else if (cents == TWO_CENT)
	{
		_change[TWO_CENT]++;
		Refund();
	}
	else if (cents == ONE_CENT)
	{
		_change[ONE_CENT]++;
		Refund();
	}
}

void CoffeeMachine::Refund()
{
	if (_change[TWO_CENT] == 0 && _change[ONE_CENT] == 0)
	{	
		if (_insertedAmount == 0)
		{
			_message = "$0\n";
			return;
		}
		
		int remainder;
		
		for (auto it = _coins.rbegin(); it != _coins.rend(); it++)
		{
			remainder = _insertedAmount % *it;
			_change[*it] = _insertedAmount / *it;
			if (remainder == 0)
				break;
			else
				_insertedAmount = remainder;
		}
		
		_insertedAmount = 0;
	}
		
	_message = "You have these coins in the refund slot\n";	
	_message += "\n1c pieces: " + std::to_string(_change[ONE_CENT]);
	_message += "\n2c pieces: " + std::to_string(_change[TWO_CENT]);
	_message += "\n5c pieces: " + std::to_string(_change[FIVE_CENT]);
	_message += "\n10c pieces: "+ std::to_string(_change[TEN_CENT]);
	_message += "\n20c pieces: "+ std::to_string(_change[TWENTY_CENT]);
	_message += "\n50c pieces: "+ std::to_string(_change[FIFTY_CENT]);
	_message += "\n$1 pieces: " + std::to_string(_change[ONE_DOLLAR]);
	_message += "\n$2 pieces: " + std::to_string(_change[TWO_DOLLAR]);
	_message += '\n';
	
	_change.clear();
}

std::string CoffeeMachine::MessageDisplay() const
{
	return _message;
}