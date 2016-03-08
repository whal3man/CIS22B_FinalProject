#define _CRT_SECURE_NO_WARNINGS
#include "MainMenu.h"

MainMenu::MainMenu()
{
	database = new BookDatabase();
	cashier = Cashier(database);
	report = Report(database);


	// asks the user if they want to use a specific database file, then sets the database file to what they chose
	bool databaseFileDone = false;
	string response;
	while (!databaseFileDone)
	{
		cout << "Do you want to specify where the database will be saved? (Y/N) ";
		cin >> response;
		if (response == "y" || response == "Y")
		{
			cout << "Where do you want to save the database? ";
			cin >> response;
			database->setDatabaseFile(response);
			cout << "The database will be saved to " << response << endl;
			databaseFileDone = true;
		}
		else if (response == "n" || response == "N")
		{
			cout << "Default location will be used.\n";
			databaseFileDone = true;
		}
		else
		{
			cout << "That is not a valid response.\n";
		}
	}

	// if the database file already exists, read from existing file
	ifstream ifile(database->getDatabaseFile.c_str());
	if (ifile)
	{
		database->readFile();
		cout << "Read database from " << database->getDatabaseFile() << ".\n";
	}


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