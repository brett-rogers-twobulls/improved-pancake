#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include <map>
#include <vector>

#include "latte.h"
#include "cappucchino.h"
#include "decaf.h"

#define LATTE_COST 300
#define CAPPUCCHINO_COST 350
#define DECAF_COST 400

class CoffeeMachine
{
public:
	// Singleton
	static CoffeeMachine& Instance();
	
	void DispenseCoffee(char);
	void InsertCoin(const double);
	void Refund();
	std::string MessageDisplay() const;

private:
	CoffeeMachine();
	CoffeeMachine(const CoffeeMachine&) =default;
	CoffeeMachine& operator=(const CoffeeMachine&) =default;

	int _insertedAmount;
	std::string _message;
	enum Coin { ONE_CENT = 1,
				TWO_CENT = 2,
				FIVE_CENT = 5,
				TEN_CENT = 10,
				TWENTY_CENT = 20,
				FIFTY_CENT = 50,
				ONE_DOLLAR = 100,
				TWO_DOLLAR = 200,
			  };
	const std::vector<Coin> _coins;
	std::map<Coin, int> _change;
};

#endif