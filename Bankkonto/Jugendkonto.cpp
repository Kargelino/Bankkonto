#include "pch.h"
#include "Jugendkonto.h"



Jugendkonto::Jugendkonto(int id)
{
	this->id = id;
	this->accountType = 1;		//Initialisierung mit 1 für Jugendkonto  im Konstruktor schon
}

Jugendkonto::~Jugendkonto()
{
}

void Jugendkonto::withdrawAccount(int amount)
{

	int i = this->getBalance();
	if ((i -= amount) < 0) {
		throw "Jugendkonto ueberziehen nicht moeglich!";
	}
	else {
		this->withdraw(amount);

	}
}
