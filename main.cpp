#include <iostream>

#include "coffee_machine.h"

void PrintHelp()
{
	std::cout << ">> To insert coins: enter 1, 2, 5, 10, 20, or 50 cent coins as decimal number\n"
		 << ">> E.g. 2c = 0.02, 50c = 0.5 or 0.50\n"
		 << ">> Enter 1 or 2 dollar coins as integers\n"
		 << ">> E.g. $1 = 1\n"
		 << ">> To refund entered coins: enter 'r'\n"
		 << ">>\n"
		 << ">> Available coffee: Cappuccino - $3.50. Enter 'c' to select\n"
		 << ">>                   Latte      - $3.00. Enter 'l' to select\n"
		 << ">>                   Decaf      - $4.00. Enter 'd' to select\n"
		 << ">>\n" 
		 << ">> Enter 'q' to quit\n"
		 << ">>\n";
}
	
int main(void)
{
	using namespace std;
	
	CoffeeMachine& machine = CoffeeMachine::Instance();
	cout << machine.MessageDisplay();
	
	bool quit = false;
	string input;
	
	cout << ">> Type h for help\n>> ";

	while(!quit)
	{	
		if (cin.get() == '\n') 
		{	
			cout << ">> ";
			continue;
		}
		
		cin.unget();
		cin >> input;
		
		char *p;
		double d = strtod(input.c_str(), &p);

		// If selection is non-numeric its ASCII value is used for the case
		switch (d != 0 ? (int)(d * 100) : (int)*p * 10) {
			case 1:
			case 2:
			case 5:
			case 10:
			case 20:
			case 50: 
			case 100:
			case 200: machine.InsertCoin(d);
					  cout << machine.MessageDisplay();
					  break;
			case 760:  // 'l'
			case 1080:
			case 670:  // 'c'
			case 990:
			case 680:  // 'd'
			case 1000: machine.DispenseCoffee(*p);
					   cout << machine.MessageDisplay();
					   break;
			case 820:  // 'r'
			case 1140: machine.Refund();
			           cout << machine.MessageDisplay();
					   break;
			case 810:  // 'q'
			case 1130: quit = true;
					   break;
			case 720: // 'h'
			case 1040:
			default: PrintHelp();
		}	
	}
	
	return 0;
}