#pragma once
#include "DataService.h"
#include <string>
#include <sstream>
#include "Bank.h"


class FileDataService :
	public DataService
{
public:
	FileDataService();
	~FileDataService();
	void save(vector <Konto*> acconts)override;
	vector<Konto*> load()override;

private:
	

};

