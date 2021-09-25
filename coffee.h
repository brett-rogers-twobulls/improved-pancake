#ifndef COFFEE_H
#define COFFEE_H

class Coffee
{
public:
	// Return cost in cents
	virtual int GetCost() const;
	
	virtual bool AddCoffee() = 0;
	virtual bool AddMilk() = 0;
	virtual bool AddFoam();
	virtual bool AddExtras();
	
	// Template method
	bool MakeCoffee();
	
protected:
	Coffee(const int);

private:
	int _cost;
};

#endif