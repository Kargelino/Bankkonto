#pragma once
#include "DataService.h"
class DBDataService :
	public DataService
{
public:
	DBDataService();
	~DBDataService();
	void save(vector <Konto*>acconts);
	vector<Konto*> load();
private:
	
};

