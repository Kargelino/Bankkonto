#pragma once
#include <vector>
#include "pch.h"
#include <iostream>
#include "Konto.h"
#include <fstream>

using namespace std;


class DataService {
public:
	virtual vector<Konto*> load() ;
	virtual void save(vector <Konto*> acconts) ;

protected:
	
};