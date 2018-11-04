#pragma once
#include "Konto.h"
class Kreditkonto :
	public Konto
{
public:
	Kreditkonto(int id);
	~Kreditkonto();
	void withdrawAccount(int amount) override;
};

