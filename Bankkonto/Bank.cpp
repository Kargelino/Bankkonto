#include "pch.h"
#include<iostream>
#include "Bank.h"


Bank::Bank()
{
}


Bank::~Bank()
{
}

void Bank::showMenu()
{
	int id, choiseAccountmanipulation = 0, value = 0, choiseAccount = 0, choiseAccount1 = 0;
	std::cout << "Willkommen bei Ihrer Bank\nBitte geben Sie ihren Bankkontonummer ein oder x fuer andere Auftraege:" << std::endl;
	std::cin >> id;

	if (NULL != getAccont(id)) {
		std::cout << "Sie haben " << getBalance() << "Euro auf ihrem Konto." << std::endl;
		std::cout << "Fuer Geld abheben druecken Sie die Taste1.\nFuer Geld einzahlen die Taste 2!" << std::endl;
		std::cin >> choiseAccountmanipulation;
		if (choiseAccountmanipulation == 1) {
			std::cout << "Bitte geben Sie einen Betrag den Sie abheben wollen ein:" << std::endl;
			std::cin >> value;
			manipulate(id, choiseAccountmanipulation, value);
			std::cout << "Auftrag ausgefuehrt! neuer Kontostand:" << getBalance() << std::endl;
		}
		if (choiseAccountmanipulation == 2) {
			std::cout << "Bitte geben Sie einen Betrag den Sie einzahlen wollen ein:" << std::endl;
			std::cin >> value;
			manipulate(id, choiseAccountmanipulation, value);
			std::cout << "Auftrag ausgefuert! neuer Kontostand:" << getBalance() << std::endl;
		}
		if (id == 'x' || id == 'X') {
			std::cout << "Menueauswahl:\nZum erstellen eines Bankkontos: 1" << std::endl;
			std::cout << "Zum loeschen eines Bankkontos: 2\n Bitte druecken Sie Ihre Auswahltaste!" << std::endl;
			std::cin >> choiseAccount;
			if (choiseAccount == 1) {
				std::cout << "Fuer Jugendkonto druecken Sie die 1, fuer Kreditkonto die 2" << std::endl;
				std::cin >> choiseAccount1;
			}
			if (choiseAccount == 2) {
				deleteAccount();
				//std::cout << "Ihr Konto ist geloescht!" << std::endl;
			}
		}

	}

}