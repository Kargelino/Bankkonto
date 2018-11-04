#pragma once
#include <vector>
#include "pch.h"
#include <iostream>

using namespace std;

class Konto
{
public:
	~Konto();
	
	void deposit(int value);		//einzahlen
	int getBalance();// kontostand
	void setBalance(int amount);
	void setPin(int pin);
	int getPin();
	int getId();
	void getHistory();
	virtual void withdrawAccount(int amount)=0;		//abheben	
protected:
	void withdraw(int amount);		//abheben
	Konto();					//Konstruktor 
	int id;

private:
	int pin;
	int balance = 0;
	vector <int> history;

};

