#include "pch.h"
#include "Kreditkonto.h"


Kreditkonto::Kreditkonto(int id)
{
	this->id = id;
	this->accountType = 2;		//Initialisierung mit 2 f�r Jugendkonto  im Konstruktor schon
}


Kreditkonto::~Kreditkonto()
{
}

void Kreditkonto::withdrawAccount(int amount)
{
	int i = this->getBalance();
	if ((i -= amount) < -400) {
		throw "Kreditkonto ueberziehen um 400 Euro nicht moeglich!";
	}
	else {
		this->withdraw(amount);
	}
}
