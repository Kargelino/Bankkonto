// Bankkonto.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.


#include "pch.h"
#include <iostream>
#include "Bank.h"
using namespace std;

int main()
{
	Bank raika;
	raika.showMenu();
	//Schleife fuer die Ausgabe einer kpl Strichlinie
	for (int i = 0; i < 120; i++)
		//printf("%c", 0xC4);
		cout << "_";
 	system("Pause");
	return 0;
}

