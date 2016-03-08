#define _CRT_SECURE_NO_WARNINGS
#include "MainMenu.h"

MainMenu::MainMenu()
{
	database = new BookDatabase();
	cashier = Cashier(database);
	report = Report(database);
}

MainMenu::~MainMenu()
{
	delete database;
}

/*  this will be the main()
int main()
{
	MainMenu();
}
*/