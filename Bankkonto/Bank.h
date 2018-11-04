#pragma once
#include <vector>
#include "pch.h"
#include <iostream>
#include "Konto.h"
#include "Jugendkonto.h"
#include "Kreditkonto.h"
#include <string>
#include <exception>



using namespace std;

class Bank
{
public:
	Bank();
	~Bank();
	void showMenu();

private:
	vector <Konto*> acconts;
	Konto* getAccont(int id, int pin);	//Konto finden
	Konto* getAccont(int id);	//Fuer Uberweisungen soll ich keine Pin brauchen
	void addAccount(int id, int pin,Konto* k);
	void deleteAccount(Konto* id);
	void manipulate(Konto* ID, int choiseManipulation, int value);
	int einlesen();
	int einlesen(int k,int g);	//Fuer Fehler eingabe
	void copyRight();
	void strichLinie();
};


