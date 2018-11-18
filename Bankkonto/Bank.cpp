#include "pch.h"
#include "Bank.h"

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
	int start,wunschID, id, wunschPin,pin,  uebID,choiseAccountmanipulation = 0, value = 0, choiseAccountYoungorCredit = 0;
	Konto* first;
	DataService* storeData = new FileDataService;
	#pragma endregion
	
#pragma region Fix implementierte Konten
	strichLinie();
	
	try {
		//Hier werden die Vektoren aktuallisiert
		this->acconts = storeData->load();
		Konto* J = new Jugendkonto(123); //Fix implementierte Konten
		Konto* K = new Kreditkonto(456);
		this->addAccount(123, 123, J);
		this->addAccount(456, 456, K);
		cout << "Das sind fix implementierte Konten bei dieser Bank" << endl;
	}
	catch (const char* Failure) {
		cout << Failure << endl;
	}
#pragma endregion
	strichLinie();
	#pragma region String Für Wilkommenstext wird ausgegeben
	while (true) {
		strichLinie();
		std::cout << "\n\nWillkommen bei der Raikaka-Bank" << endl;
		copyRight();
		strichLinie();
		std::cout<<"Bitte geben Sie die 1 fuer ihre Kontonummereingabe, die 2 fuer andere Auftraege  oder 3 fuer Beenden ein:" << std::endl;
		start = einlesen(1,3);
	#pragma endregion
		switch (start)
		{
			case 1: {
				std::cout << "Bitte geben Sie ihre Bankkontonummer ein :" << std::endl;
				id = einlesen();
				std::cout << "Bitte geben Sie ihre PIN-Nummer ein :" << std::endl;
				pin = einlesen();
				first = getAccont(id, pin);

				if (first != NULL) {
					std::cout << "Sie haben " << first->getBalance() << "Euro auf ihrem Konto." << std::endl;
					std::cout << "Fuer Geld abheben druecken Sie die Taste 1.\nFuer Geld einzahlen die Taste 2.\nFuer Kontoauszug die Taste 3\nFuer Ueberweisungen die Taste 4\nFuer Konto loeschen die Taste 5!" << std::endl;
					choiseAccountmanipulation = einlesen(1,5);
					switch (choiseAccountmanipulation)
					{
					#pragma region Case 1
						case 1: {
							std::cout << "Bitte geben Sie einen Betrag den Sie abheben wollen ein:" << std::endl;
							value = einlesen();
							try {
								this->manipulate(first, choiseAccountmanipulation, value);
								std::cout << "Auftrag ausgefuehrt! neuer Kontostand Euro:" << first->getBalance() << std::endl;
							}
							catch (const char* msg) {
								cerr << "FEHLER:" << msg << endl;
							}
							break;
						}
					#pragma endregion
					#pragma region Case 2
						case 2: {
							std::cout << "Bitte geben Sie einen Betrag den Sie einzahlen wollen ein:" << std::endl;
							value = einlesen();
							this->manipulate(first, choiseAccountmanipulation, value);
							std::cout << "Auftrag ausgefuert! Neuer Kontostand Euro:" << first->getBalance() << std::endl;
							break;
						}
					#pragma endregion
					#pragma region Case 3
						case 3: {
							getHistory = first->getHistory();
							for (int temp : getHistory) {
								cout << temp << endl;
							}
							break;
						}
					#pragma endregion
					#pragma region Case 4
						case 4: {
							cout << "Bitte die Kontonr eingeben wo ueberwiesen werden soll:" << endl;
							uebID = einlesen();
							cout << "Bitte den zu ueberweisenden Betrag eingeben:" << endl;
							value = einlesen();
							Konto* Second = getAccont(uebID);	//
							try {
								if (Second == NULL) {
									throw "Kein Konto Vorhanden";
								}
								this->manipulate(first, 1, value);		//Eigenes Konto belasten
								this->manipulate(Second, 2, value);		//Gewaehltes Konto hinzufuegen
							}
							catch (const char* msg) {
								cerr << "Ueberweisung Fehler: " << msg << endl;
							}
							break;
						}
					#pragma endregion
					#pragma region Case 5
						case 5: {
							this->deleteAccount(first);
							break;
						}
					#pragma endregion
					default:
						break;
					}
				}
				break;
			}
			case 2: {
				std::cout << "Menueauswahl:\nZum erstellen eines Bankkontos: " << std::endl;
				cout << "Bitte geben Sie eine gewuenschte ID-Nummer ein:" << endl;
				wunschID = einlesen();
				cout << "Bitte geben Sie eine gewuenschte PIN-Nummer ein:" << endl;
				wunschPin = einlesen();
				std::cout << "Fuer Jugendkonto druecken Sie die 1, fuer Kreditkonto die 2" << std::endl;
				choiseAccountYoungorCredit=einlesen(1,2);
				
				try {
					if (choiseAccountYoungorCredit == 1) {
						// Erbt von Konto ...
						Konto* k = new Jugendkonto(wunschID);
						this->addAccount(wunschID, wunschPin, k);

					}
					if (choiseAccountYoungorCredit == 2) {
						// Erbt von Konto ...
						Konto* k = new Kreditkonto(wunschID);
						this->addAccount(wunschID, wunschPin, k);
					}
				}
				catch (const char* msg) {
					cout << msg << endl;
				}
				
				break;
			}
			case 3: {

				return;
			}
			default:
				break;
		}
		//Hier erfolgt ein Backup
		storeData->save(this->acconts);

	}
}

Konto* Bank::getAccont(int id, int pin)
{
	for (Konto* temp : this->acconts) {
		if (temp->getId() == id && temp->getPin() == pin) { //Id u Pin Pruefung
			return temp;
		}		
	}
	cout << "Kein Konto erkannt  oder falsche PIN-Eingabe!" << endl;
	return NULL;
}

Konto * Bank::getAccont(int id)
{
	for (Konto* temp : this->acconts) {
		if (temp->getId() == id ) { //Id  Pruefung
			return temp;
		}
	}
	cout << "Kein Konto erkannt  oder falsche PIN-Eingabe!" << endl;
	return NULL;
}

void Bank::addAccount(int id, int pin,Konto* k)
{
	k->setPin(pin);								//seta Methode fuer Pin setzen
	if (this->acconts.size() == 0) {			//Nur wenn Vektor accounts leer ist Konto hinzufuegen
		this->acconts.push_back(k);
		cout << "\nSie haben die Konto-ID: " << k->getId() << ", mit der PIN-Nummer: " << k->getPin() << endl;
	}
	else {
		for (Konto* temp : this->acconts) {
			if (temp->getId() == id) {
				throw "Dieses Konto existiert bereits und kann nicht doppelt existieren!";
			}
		}
		this->acconts.push_back(k);
		cout << "\nSie haben die Konto-ID: " << k->getId() << ", mit der PIN-Nummer: " << k->getPin() << endl;	
	}
		//bool flag = true;		//in C Style
		//for (Konto* temp : this->acconts) {
		//	if (temp->getId() == id) {	//Nur wenn dieses Konto nicht bereits existiret, Konto erzeugen
		//		cout << "Dieses Konto existiert bereits und kann nicht doppelt existieren!" << endl;
		//		cout << "Bitte geben Sie beim naechsten Versuch eine andere WunschId ein!" << endl;
		//		flag = false;
		//		break;
		//	}
		//}
		//if (flag == true) {
		//	this->acconts.push_back(k);
		//	cout << "\nSie haben die Konto-ID: " << k->getId() << ", mit der PIN-Nummer: " << k->getPin() << endl;
		//}	
 }

void Bank::deleteAccount(Konto* id)
{
	try
	{
		//acconts.erase(remove_if(acconts.begin(), acconts.end(), id), acconts.end());
		//Iteratoreigenschaft ist die inkremetierung
		vector<Konto*>::iterator pos = find(acconts.begin(), acconts.end(), id);
		acconts.erase(pos);
		//cout << acconts.size() << endl;
		cout << "Sie haben erfolgreich das Konto geloescht!" << endl;
	}
	catch (...)   //soll alle Fehler melden
	{
		cout << "Fehler bei Kontoloeschen!" << endl;
	}
}

void Bank::manipulate(Konto* ID, int choiseManipulation, int value)
{
	if (ID == NULL) { 
		throw "Kein Account gefunden"; }
	if (choiseManipulation == 1) {
		ID->withdrawAccount(value);
	}
	else if (choiseManipulation == 2) {
		ID->deposit(value);
	}

}

int Bank::einlesen()
{
	int i;
	while (true) {
		cin >> i;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Fehlerhafte Eingabe";
		}
		else break;
	}
	return i;
}

int Bank::einlesen(int k, int g)
{
	int i;
	while (true) {
		cin >> i;
		if (cin.fail() || i<k || i>g) {
			cin.clear();
			cin.ignore();
			cout << "\nFehlerhafte Eingabe, Bitte wiederholen sie ihre Eingabe:\n";
		}
		else break;
	}
	return i;
}

void Bank::copyRight()
{	//Ausgabe AUTOR mit (c) in "old C-Style"
	int i;
	printf(" ");
	printf("\t\t\t\t\t\t\t\t\t\t\t%c", 0xDA);
	for (i = 1; i <= 24; i++)
		printf("%c", 0xC4);
	printf("%c\n", 0xBF);
	printf("\t\t\t\t\t\t\t\t\t\t\t%c \xB8  B Maxim u. M Kargl  %c\n", 0xB3, 0xB3);
	printf("\t\t\t\t\t\t\t\t\t\t\t%c", 0xC0);
	for (i = 1; i <= 24; i++)
		printf("%c", 0xC4);
	printf("%c\n", 0xD9);
	printf("\n");
}

void Bank::strichLinie()
{
	//Schleife fuer die Ausgabe einer kpl Strichlinie
	for (int i = 0; i < 120; i++) {
		cout << "_";
	}
}
