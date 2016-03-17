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

void MainMenu::fileLoadMenu()
{
	// asks the user if they want to use a specific database file, then sets the database file to what they chose
	bool databaseFileDone = false;
	string response;
	while (!databaseFileDone)
	{
		cout << "Do you want to specify where the database will be saved/loaded? (Y/N) ";
		cin >> response;
		if (response == "y" || response == "Y")
		{
			cout << "Where do you want to save/load the database from? ";
			cin >> response;
			database->setDatabaseFile(response);
			cout << "The database will be saved/loaded to " << response << endl << endl;
			databaseFileDone = true;
		}
		else if (response == "n" || response == "N")
		{
			cout << "Default location will be used. (./database.txt)\n";
			databaseFileDone = true;
		}
		else
		{
			cout << "That is not a valid response.\n";
		}
	}

	// if the database file already exists, read from existing file
	ifstream ifile(database->getDatabaseFile().c_str());
	if (ifile)
	{
		database->readFile();
		cout << "Existing database was read from " << database->getDatabaseFile() << ".";
		
	}
	cout << " (Press return to continue)";
	cin.ignore();
	cin.get();
	ifile.close();
}

int MainMenu::showMainMenu()
{
	bool done = false;
	int choice = 0;
	do
	{
		system("CLS");
		//show the mainMenu and get the choice
		cout << "\t\tSerendipity Booksellers\n\t\t\tMain Menu\n\n";
		cout << "\t    1. Cashier Module\n";
		cout << "\t    2. Inventory Database Module\n";
		cout << "\t    3. Report Module\n";
		cout << "\t    4. Exit\n";
		cout << "\n\t     Enter your choice: ";

		cin >> choice;

		if (choice == 1)
		{
			cashier.mainMenu();
		}
		else if (choice == 2)
		{
			database->mainMenu();
		}
		else if (choice == 3)
		{
			report.mainMenu();
		}
		else if (choice == 4)
		{
			system("CLS");
			cout << "\n\n\t   Thank you for using Serendipity Booksellers Database!\n\n";
			cout << "\t\t\t(Press return to continue)";
			cin.ignore();
			cin.get();
			return 0;
		}
		else
		{
			system("CLS");
			cout << "\n\t    Please enter a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n\t    Press return to continue.";
			cin.get();
			choice = 0;
		}
	} while (choice != 4);
	return -1;
}

int main()
{
	MainMenu menu; //we need a main menu object
	menu.fileLoadMenu();
	menu.showMainMenu();
}
