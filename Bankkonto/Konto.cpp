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
	this->balance += value;
	this->history.push_back(this->balance);
}

int Konto::getBalance()
{
	return this->balance;
}

void Konto::setBalance(int amount)
{
	this->balance += amount;
}

void Konto::setPin(int pin)
{
	this->pin = pin;
}

int Konto::getPin()
{
	
	return pin;
}

vector<int> Konto::getHistory()
{
	return this->history;
}

int Konto::getAccountType()
{
	return this->accountType;
}

void Konto::withdraw(int amount)
{
	this->balance -= amount;
	this->history.push_back(this->balance);
}

int Konto::getId()
{
	return this->id;
}

void Konto::setHistory(vector<int> temphistory)
{
	this->history = temphistory;
}

