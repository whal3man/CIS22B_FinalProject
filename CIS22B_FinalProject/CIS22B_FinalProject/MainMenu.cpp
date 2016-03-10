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
	ifstream ifile(database->getDatabaseFile().c_str());
	if (ifile)
	{
	database->readFile();
	cout << "Read database from " << database->getDatabaseFile() << ".\n";
	}
}

int MainMenu::showMainMenu()
{
	fileLoadMenu();

	bool done = false;

	int choice = 0;

	
		cout << "\t\tSerendipity Booksellers\n\t\t\tMain Menu\n\n";
		cout << "\t    1. Cashier Module\n";
		cout << "\t    2. Inventory Database Module\n";
		cout << "\t    3. Report Module\n";
		cout << "\t    4. Exit\n";

		do
		{
			cout << "\n\t     Enter your choice: ";

			cin >> choice;

			if (choice == 1)
			{
				cashier.mainMenu();
			}
			else if (choice == 2)
			{
				return 2;
			}
			else if (choice == 3)
			{
				return 3;
			}
			else if (choice == 4)
			{
				return 4;
			}
			else
			{
				{
					cout << "\n\t    Please enter a valid selection.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					choice = 0;
				}
			}
	} while (choice != 4);
}

Report MainMenu::getReport() const
{
	return report;
}

int main()
{
	int choice = 0; // to hold the user's module choice
	MainMenu menu; //we need a main menu object

				   //traverse the modules based on users choice
	do
	{
		//show the mainMenu and get the choice
		choice = menu.showMainMenu();

		if (choice == 1)
		{
			//run cashier mainMenu();
			cout << "Cashier module loading...\n\n";
		}
		else if (choice == 2)
		{
			cout << "Inventory Database module loading...\n\n";
			//get the database object
			//run database mainMenu;
		}
		else if (choice == 3)
		{
			cout << "Report module loading...\n\n";
			Report* report = &menu.getReport();
			report->mainMenu();
		}
		else if (choice == 4)
		{
			cout << "\n\n\t\t\tThank you!\n\n";
			system("pause");
			return 0;
		}
	} while (choice != 4);

	system("pause");
}
