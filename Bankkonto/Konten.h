#pragma once
#include <vector>
using namespace std;
class Konten
{
public:
	Konten();
	~Konten();
	Konten(int id);	//Konstruktor 

	void deposit(int value);		//einzahlen
	int getBalance();				// kontostand

	vector<int> getHistory();
	int getId();
	void withdraw(int amount);		//abheben	
protected:
	//void withdraw(int amount);		//abheben		
private:
	int id;
	int balance;
	vector <int> history;

};

