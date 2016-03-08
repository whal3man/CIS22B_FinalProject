#ifndef _MAIN_H
#define _MAIN_H

#include "BookDatabase.h"
#include "Cashier.h"
#include "Report.h"
using namespace std;

class MainMenu
{
private:
	BookDatabase* database;
	Cashier cashier;
	Report report;
public:
	// creates database object to be used in other modules
	MainMenu();
	// deletes database object
	~MainMenu();
	// displays a menu asking the user if they wish to load database from file
	void fileLoadMenu();
	// displays a menu asking the user which module they wish to use
	void mainMenu();
};

#endif