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
		cout << i + 1 << ". " << books[i].getTitle() << endl;
	}
}

//A list of the retail value of all books in the inventory
//and the total retail value of the inventory.
void Report::listRetailValue()
{
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

	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) << i + 1 << ". $" << books[i].getRetailPrice() << " " << books[i].getTitle() << endl;
		sum += books[i].getRetailPrice();
	}

	//print the total retail value
	cout << fixed << setprecision(2) << "Total Retail Value: $" << sum << endl << endl;
}

//A list of the wholesale value of all books in the
//inventory and the total wholesale value of the inventory
void Report::listWholesaleValue()
{
	cout << "Listing wholesale value of the inventory...\n\n";

	//all books + total
}

//A list of all books in the inventory, sorted by purchase date. The
//books that have been in the inventory longest will be listed first.
void Report::listAge()
{
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
	cout << "Listing inventory sorted by wholesale cost...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();

	for (int i = 0; i < size; i++)
	{
		double bookWholesaleValue1; //get retail value of the current index
		double bookWholesaleValue2; //get retail value of the next index
		bookWholesaleValue1 = books[i].getWholesaleCost();
		for (int j = 0; j <= size; j++)
		{
			if ((j + 1) != size) //if next book index == size
			{
				bookWholesaleValue2 = books[j + 1].getRetailPrice();
				if (bookWholesaleValue1 > bookWholesaleValue2)
				{
					Book temp = books[j];
					books[j] = books[j + 1];
					books[j + 1] = temp;
				}
			}
		}
		cout << fixed << setprecision(2) << i + 1 << ". " << books[i].getWholesaleCost() << endl;
	}
}

//A list of all books in the inventory sorted by quantity on hand.
//The books with the greatest quantity on hand will be listed first.
void Report::listQuantity()
{
	cout << "Listing inventory sorted by quantity on hand...\n\n";
	//write newly sorted book database to file
}

void Report::mainMenu()
{
	int selection = 0; //to hold the user selection

	//ask user what they want to have shown
		do
		{
			//system("CLS"); //clear screen of other modules and text
			cout << "\t\tReport Module\n\n";
			cout << "\t    1. List Inventory\n";
			cout << "\t    2. List by Retail Value\n";
			cout << "\t    3. List by Wholesale Value\n";
			cout << "\t    4. List by Age\n";
			cout << "\t    5. List by Quantity\n";
			cout << "\t    6. Return to Main Menu\n";
			cout << "\n\n\tPlease enter a number corresponding to a selection: ";
			if (cin >> selection)
			{
				//run the choice selected 1-5
				//break if == 6
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
		} while (selection != 6); //6 here is return to front main menu
	return;
}