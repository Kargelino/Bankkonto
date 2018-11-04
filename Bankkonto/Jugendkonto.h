#pragma once
#include "Konto.h"
#include <exception>

class Jugendkonto :
	public Konto
{
public:
	Jugendkonto(int id);
	~Jugendkonto();
	void withdrawAccount(int amount) override;
};

