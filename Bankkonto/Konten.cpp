#include "pch.h"
#include "Konten.h"

Konten::Konten()
{
}

Konten::~Konten()
{
}

void Konten::deposit(int value)
{
	balance += value;
	history.push_back(balance);
}

int Konten::getBalance()
{
	return balance;
}


vector<int> Konten::getHistory()
{
	return vector<int> (history);
}

int Konten::getId()
{
	return id;
}

void Konten::withdraw(int amount)
{
	balance -= amount;
	history.push_back(balance);
}

Konten::Konten(int id)
{	// Uebergabe gleich wie Elementvariable
	//->fuer zuweisung  'this-> (Pointer)'
	this->id = id;
	this->balance = 0;
}