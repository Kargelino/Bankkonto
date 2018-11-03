#include "pch.h"
#include<iostream>
#include "Bank.h"
#include "Konten.h"
#include <vector>
using namespace std;

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::showMenu()
{
	#pragma region Variable erstellen
	int start, id, choiseAccountmanipulation = 0, value = 0, choiseAccount = 0, choiseAccountYoungorCredit = 0;
	Konten* first;
	#pragma endregion
	/*this->addAccount();
	this->addAccount();
	this->addAccount();*/
	/*for (Konten* temp : this->acconts)
		cout << temp << endl;*/
	
	//deleteAccount(getAccont(2));
	#pragma region String Für Wilkommenstext wird ausgegeben
	while (true) {
		std::cout << "\n\n\nWillkommen bei der Raika-Bank\nBitte geben Sie die 1 fuer ihre Kontonummereingabe, die 2 fuer andere Auftraege  oder 3 fuer Beenden ein:" << std::endl;
		std::cin >> start;
	#pragma endregion
		if (start == 1) {
			std::cout << "Bitte geben Sie ihre Bankkontonummer ein :" << std::endl;
			std::cin >> id;
			first = getAccont(id);

			if (first != NULL) {
				std::cout << "Sie haben " << first->getBalance() << "Euro auf ihrem Konto." << std::endl;
				std::cout << "Fuer Geld abheben druecken Sie die Taste 1.\nFuer Geld einzahlen die Taste 2.\nFuer Konto loeschen die Taste 3!" << std::endl;
				std::cin >> choiseAccountmanipulation;
				if (choiseAccountmanipulation == 1) {
					std::cout << "Bitte geben Sie einen Betrag den Sie abheben wollen ein:" << std::endl;
					std::cin >> value;
					this->manipulate(first, choiseAccountmanipulation, value);
					std::cout << "Auftrag ausgefuehrt! neuer Kontostand:" << first->getBalance() << std::endl;
				}
				if (choiseAccountmanipulation == 2) {
					std::cout << "Bitte geben Sie einen Betrag den Sie einzahlen wollen ein:" << std::endl;
					std::cin >> value;
					this->manipulate(first, choiseAccountmanipulation, value);
					std::cout << "Auftrag ausgefuert! neuer Kontostand:" << first->getBalance() << std::endl;
				}
				if (choiseAccountmanipulation == 3) {
					this->deleteAccount(first);
				}
			}
		}
		if (start == 2) {
			std::cout << "Menueauswahl:\nZum erstellen eines Bankkontos: 1" << std::endl;
			std::cout << "Zum loeschen eines Bankkontos: 2\n Bitte druecken Sie Ihre Auswahltaste!" << std::endl;
			std::cin >> choiseAccount;
			if (choiseAccount == 1) {
				std::cout << "Fuer Jugendkonto druecken Sie die 1, fuer Kreditkonto die 2" << std::endl;
				std::cin >> choiseAccountYoungorCredit;
				if (choiseAccountYoungorCredit == 1) {
					// Erbt von Konto ...
				}
				if (choiseAccountYoungorCredit == 2) {
					// Erbt von Konto ...
					//für Testzwecke ein normales Konto erstellen 
					this->addAccount();
				}
			}
			
		}
		if (start == 3) break;
	}
}

Konten* Bank::getAccont(int id)
{
		for (Konten* temp : this->acconts) {
			if (temp->getId() == id) {
				return temp;
			}		
		}
		cout << "Kein Konto erkannt" << endl;
		return NULL;
}

void Bank::addAccount()
{
	Konten* k = new Konten (this->acconts.size()+1);		//immer new Konstruktor u(id) erzeugen 				
	this->acconts.push_back(k);
	cout << "\nSie haben die Konto-ID:" << k->getId() << endl;
 }

void Bank::deleteAccount(Konten* id)
{
	try
	{
		//acconts.erase(remove_if(acconts.begin(), acconts.end(), id), acconts.end());
		//Iteratoreigenschaft ist die inkremetierung
		vector<Konten*>::iterator pos = find(acconts.begin(), acconts.end(), id);
		acconts.erase(pos);
		//cout << acconts.size() << endl;
		cout << "Sie haben erfolgreich das Konto geloescht!" << endl;
	}
	catch (...)   //soll alle Fehler melden
	{
		cout << "Fehler bei Kontoloeschen!" << endl;
	}
}

void Bank::manipulate(Konten* ID, int choiseManipulation, int value)
{
	if (choiseManipulation == 1) {
		ID->withdraw(value);
	}
	else if (choiseManipulation == 2) {
		ID->deposit(value);
	}

}
