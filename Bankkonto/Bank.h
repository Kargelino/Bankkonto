#pragma once
#include <vector>
#include "Konto.h"

class Bank
{
public:
	Bank();
	~Bank();
	void showMenu();

private:
	std::vector <Konto*> acconts();
	Konto* getAccont(int identnr);	//Konto finden
	void addAccount();
	void deleteAccount();
	void manipulate(int id, int choiseManipulation, int value);
};



Bank::Bank()
{
}

