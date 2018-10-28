#include <vector>
using namespace std;

#pragma once
class Konto
{
public:
	Konto();
	~Konto();

private:
	int id;
	int balance;
	std::vector<int> history;
};

