#include "pch.h"
#include "FileDataService.h"


FileDataService::FileDataService()
{
}


FileDataService::~FileDataService()
{
}

void FileDataService::save(vector<Konto*> acconts)
{
	fstream file("Kontodaten.csv", ios::out); //File über den Konstuktor gleich mit open instantiert 	
	for (Konto* temp : acconts) {
		file << temp->getId() << ";" << temp->getPin()<<";" <<temp->getAccountType()<< ";";
		for (int historyAccount : temp->getHistory()) {
			file << historyAccount << ",";
		}
		file <<":"<< temp->getBalance() << endl;
	}
	file.close();

}

vector<Konto*> FileDataService::load()
{
	vector<Konto*> acconts;
	Bank Konten;
	fstream file;
	string temp = "", temp2 = "";		//Pointer auf char array der leer ist mit " " 

	file.open("Kontodaten.csv", ios::in);			// File wird gelesen, in ist read modus
	if(!file.is_open()){
		throw "Noch keine Kontodaten.csv vorhanden!";
	}
	while (!file.eof())					//Solang File nicht zu ende ist 
	{
		getline(file, temp, ';');		// liest bis zum ersten ;
		int Id = atoi(temp.c_str());	//typumwandlung wegen string 
		getline(file, temp, ';');
		int Pin = atoi(temp.c_str());	//temp.c_str() ist methode String in const char* umwandeln
		getline(file, temp, ';');
		int AccountType = atoi(temp.c_str());
		getline(file, temp, ':');
		stringstream t(temp);			//Temp in den t Stream reinkopieren damit getline String zerlegen kann
		vector<int> historyAccount;
		while (!t.eof()){
			getline(t, temp2, ',');
			int i;
			if (temp2 != "") {			//Wenn der String Temp2 != leer,sonst ist hab ich eine 0 in der History;	
				i = atoi(temp2.c_str());
				historyAccount.push_back(i);
			}
		}
		getline(file, temp, '\n');
		int Balance = atoi(temp.c_str());
			
		if (AccountType == 1) {
			// Erbt von Konto ...
			Konto* k = new Jugendkonto(Id);
			k->setPin(Pin);
			k->deposit(Balance);
			k->setHistory(historyAccount);
			acconts.push_back(k);
		}
		if (AccountType == 2) {
			// Erbt von Konto ...
			Konto* k = new Kreditkonto(Id);
			k->setPin(Pin);
			k->deposit(Balance);
			k->setHistory(historyAccount);
			acconts.push_back(k);
		}

	}
	return acconts;
}
