#define _CRT_SECURE_NO_WARNINGS
#include "Report.h"

/*
	This module generates reports based on the users choice
	listInventory() lists all books in the inventory
	listRetailValue() lists retail value of all books in the inventory
	listWholesaleValue() lists wholesale value of all books in the inventory
	listAge() lists books sorted by date added to the inventory via the inventory database module
	listCost() lists books sorted by wholesale cost, greatest first to least last
	listQuantity() lists books sorted by quantity on hand. The book with the most copies is listed first
*/

Report::Report()
{

}
Report::Report(BookDatabase* dtbs)
{
	database = dtbs;
}

//A list of information on all books in the inventory
//List books by title
void Report::listInventory()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing current inventory...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();
	bool swap;

	do
	{
		swap = false;
		for (int i = 0; i < size; i++)
		{

			if ((i + 1) < size) //if next book index < size
			{
				if (books[i].getTitle() > books[i + 1].getTitle())
				{
					Book temp = books[i];
					books[i] = books[i + 1];
					books[i + 1] = temp;
					swap = true;
				}
			}
		}
	} while (swap);

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". " << books[i].getTitle()  << books[i].getAuthor() << books[i].getPublisher() << books[i].getIsbn() << endl;
	}
}

//A list of the retail value of all books in the inventory
//and the total retail value of the inventory.
void Report::listRetailValue()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory sorted by retail value...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();
	bool swap;
	double sum = 0;

	//new
	do
	{
		swap = false;
		for (int i = 0; i < size; i++)
		{

			if ((i + 1) < size) //if next book index < size
			{
				if (books[i].getRetailPrice() > books[i + 1].getRetailPrice())
				{
					Book temp = books[i];
					books[i] = books[i + 1];
					books[i + 1] = temp;
					swap = true;
				}
			}
		}
	} while (swap);

	cout << "Retail Price\tTitle\n";
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) << i + 1 << ". $" << books[i].getRetailPrice() << "\t" << books[i].getTitle() << endl;
		sum += books[i].getRetailPrice();
	}

	//print the total retail value
	cout << fixed << setprecision(2) << "Total Retail Value: $" << sum << endl << endl;
}

//A list of the wholesale value of all books in the
//inventory and the total wholesale value of the inventory
void Report::listWholesaleValue()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing wholesale value of the inventory...\n\n";

	//all books + total
}

//A list of all books in the inventory, sorted by purchase date. The
//books that have been in the inventory longest will be listed first.
void Report::listAge()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory by date added...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();

	for (int i = 0; i < size; i++)
	{
		string bookDateAdded1; //get title of the current index
		string bookDateAdded2; //get title of the next index
		bookDateAdded1 = books[i].getDateAdded();
		for (int j = 0; j < size; j++)
		{
			if ((j + 1) != size) //if next book index == size
			{
				bookDateAdded2 = books[j + 1].getDateAdded();
				if (bookDateAdded1 > bookDateAdded2)
				{
					Book temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
				}
			}
		}
		cout << i + 1 << ". " << books[i].getDateAdded() << endl;
	}
}

//A list of all books in the inventory, sorted by wholesale cost. The
//books with the greatest wholesale cost will be listed first.
void Report::listCost()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory sorted by wholesale cost...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();


}

//A list of all books in the inventory sorted by quantity on hand.
//The books with the greatest quantity on hand will be listed first.
void Report::listQuantity()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory sorted by quantity on hand...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();

	//count multiples of each book
	for(int i = 0; i < size; i++)
	{
		for(int j = i; j < size; j++)
		{
			if (books[i].getIsbn() == books[j].getIsbn())
			{
				//increase quantity of the book
				books[i].setQuantity(1);
			}	
		}
	}

	cout << "\nQuantity\tTitle\n";
	for (int i = 0; i < size; i++)
	{
		cout << books[i].getQuantity() << books[i].getTitle() << endl;
	}
}

void Report::mainMenu()
{
	system("CLS"); //clear screen of other modules and text
	int selection = 0; //to hold the user selection

	//ask user what they want to have shown
		do
		{
			cout << "\t\tReport Module\n\n";
			cout << "\t    1. Inventory Listing\n";
			cout << "\t    2. Inventory Retail Value\n";
			cout << "\t    3. Inventory Wholesale Value\n";
			cout << "\t    4. List by Age\n";
			cout << "\t    5. List by Quantity\n";
			cout << "\t    6. List by Cost\n";
			cout << "\t    7. Return to Main Menu\n";
			cout << "\n\n\tPlease enter a number corresponding to a selection: ";
			if (cin >> selection)
			{
				//run the choice selected 1-6
				//break if == 7
				if (selection == 1)
				{
					listInventory();
				}
				else if (selection == 2)
				{
					listRetailValue();
				}
				else if (selection == 3)
				{
					listWholesaleValue();
				}
				else if (selection == 4)
				{
					listAge();
				}
				else if (selection == 5)
				{
					listQuantity();
				}
				else if (selection == 6)
				{
					listCost();
				}
				else if (selection == 7)
				{
					break;
				}
				else
				{
					cout << "\n\t    Please enter a valid selection.\n\n";
				}
			}
			else
			{
				cout << "\n\t    Please enter a valid selection.\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				selection = 0;
			}
		} while (selection != 7); //7 here is return to front main menu
	return;
}