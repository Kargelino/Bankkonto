#include "pch.h"
#include "Konto.h"


Konto::Konto()
{
}


Konto::~Konto()
{
}

void Konto::deposit(int value)
{
	balance += value;
}

int Konto::getBalance()
{
	return balance;
}

std::vector<int> Konto::getHistory()
{
	return std::vector<int>();
}

int Konto::getId()
{
	return 0;
}

void Konto::withdraw(int amount)
{
	balance -= amount;

}

Konto::Konto(int id)
{	// Uebergabe gleich wie Elementvariable
	//->fuer zuweisung  'this-> (Pointer)'
	this->id = id;
}