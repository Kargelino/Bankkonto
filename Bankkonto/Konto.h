#pragma once
#include <vector>
#include "Bank.h"


class Konto
{
public:
	Konto();
	~Konto();
	Konto(int id);
	void deposit(int value);		//einzahlen
	int getBalance();				// kontostand

	std::vector<int> getHistory();
	int getId();
protected:
	void withdraw(int amount);		//abheben		
private:
	int id;
	int balance;
	//Konto(int id);	//Constructor 

	std::vector <int> history;

};
