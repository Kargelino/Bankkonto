// Bankkonto.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.


#include "pch.h"
#include <iostream>
#include <vector>
#include "Bank.h"
#include "Konten.h"
using namespace std;
//vector<Konten*>konoliste;
//void addVector() {
//	
//	Konten k(konoliste.size() + 1);
//	konoliste.push_back(&k);
//}

int main()
{
	Bank raika;
	raika.showMenu();

 	system("Pause");
	return 0;
}

