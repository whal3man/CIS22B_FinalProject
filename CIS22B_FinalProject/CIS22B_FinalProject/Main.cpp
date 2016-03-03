#include "Main.h"

Main::Main()
{
	database = new BookDatabase();
	cashier = Cashier(database);
	report = Report(database);
}

Main::~Main()
{
	delete database;
}
