#pragma once
#include <vector>
#include "pch.h"
#include <iostream>
#include "Konten.h"
using namespace std;

class Bank
{
public:
	Bank();
	~Bank();
	void showMenu();

private:
	
	vector <Konten*> acconts;
	Konten* getAccont(int id);	//Konto finden
	void addAccount();
	void deleteAccount(Konten* id);
	void manipulate(Konten* ID, int choiseManipulation, int value);
};


