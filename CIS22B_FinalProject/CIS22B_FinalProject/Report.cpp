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

//we need default constructor
Report::Report()
{

}
Report::Report(BookDatabase* dtbs)
{
	database = dtbs;
}

//used for sorting by quantity
struct BooksWithIsbn
{
	string Isbn;
	int bookIdentifiers[1024];
	int numBookIdentifiers = 0;
};

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

	cout << "\n\tTitle\t\t   Author\t      Publisher\t\t    ISBN\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << right << i + 1 << ". "
			 << setw(20) << left << books[i].getTitle()
			 << setw(20) << left << books[i].getAuthor()
			 << setw(20) << left << books[i].getPublisher()
			 << setw(12) << left << books[i].getIsbn() << endl;
	}
	cout << endl;
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

	cout << "    Retail Price\tTitle\t\tISBN\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) 
			 << setw(5) << right << i + 1 << ". $"
			 << setw(10) << left << books[i].getRetailPrice()
			 << setw(20) << books[i].getTitle() 
			 << setw(12) << books[i].getIsbn()
			 << endl;
		sum += books[i].getRetailPrice();
	}

	//print the total retail value
	cout << fixed << setprecision(2) << "\nTotal Retail Value: $" << sum << endl << endl;
}

//A list of the wholesale value of all books in the
//inventory and the total wholesale value of the inventory
void Report::listWholesaleValue()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing wholesale value of the inventory...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();
	bool swap;
	double sum = 0;

	do
	{
		swap = false;
		for (int i = 0; i < size; i++)
		{

			if ((i + 1) < size) //if next book index < size
			{
				if (books[i].getWholesaleCost() > books[i + 1].getWholesaleCost())
				{
					Book temp = books[i];
					books[i] = books[i + 1];
					books[i + 1] = temp;
					swap = true;
				}
			}
		}
	} while (swap);

	cout << " Wholesale Price\tTitle\t\tISBN\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2)
			<< setw(5) << right << i + 1 << ". $"
			<< setw(10) << left << books[i].getWholesaleCost()
			<< setw(20) << books[i].getTitle()
			<< setw(12) << books[i].getIsbn()
			<< endl;
		sum += books[i].getWholesaleCost();
	}

	//print the total retail value
	cout << fixed << setprecision(2) << "\nTotal Wholesale Value: $" << sum << endl << endl;
}

//A list of all books in the inventory, sorted by purchase date. The
//books that have been in the inventory longest will be listed first.
void Report::listAge()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory by date added...\n\n";

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
				if (books[i].getDateAdded() < books[i + 1].getDateAdded())
				{
					Book temp = books[i + 1];
					books[i + 1] = books[i];
					books[i] = temp;
					swap = true;
				}
			}
		}
	} while (swap);
	cout << "\tDate added\t\tTitle\t\tISBN\n";
	for (int i = 0; i < size; i++)
	{
		cout << setw(5) << right
			 << i + 1 << ". "
			 << setw(20) << left << books[i].getDateAdded()
			 << setw(20) << left << books[i].getTitle()
			 << setw(12) << left << books[i].getIsbn()
			 << endl;
	}
	cout << endl;
}

//A list of all books in the inventory, sorted by wholesale cost. The
//books with the greatest wholesale cost will be listed first.
void Report::listCost()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory sorted by wholesale cost...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();

	bool swap;
	double sum = 0;

	do
	{
		swap = false;
		for (int i = 0; i < size; i++)
		{

			if ((i + 1) < size) //if next book index < size
			{
				if (books[i].getWholesaleCost() < books[i + 1].getWholesaleCost())
				{
					Book temp = books[i];
					books[i] = books[i + 1];
					books[i + 1] = temp;
					swap = true;
				}
			}
		}
	} while (swap);

	cout << " Wholesale Price\tTitle\t\tISBN\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2)
			<< setw(5) << right << i + 1 << ". $"
			<< setw(10) << left << books[i].getWholesaleCost()
			<< setw(20) << books[i].getTitle()
			<< setw(12) << books[i].getIsbn()
			<< endl;
		sum += books[i].getWholesaleCost();
	}

	//print the total retail value
	cout << fixed << setprecision(2) << "\nTotal Wholesale Value: $" << sum << endl << endl;

	
}

//A list of all books in the inventory sorted by quantity on hand.
//The books with the greatest quantity on hand will be listed first.
void Report::listQuantity()
{
	system("CLS"); //clear screen of other modules and text
	cout << "Listing inventory sorted by quantity on hand...\n\n";

	Book* books = database->getBooks();
	int size = database->getSize();
	BooksWithIsbn* isbnDatabase = new BooksWithIsbn[1024];
	int numIsbns = 0;

	// goes through the entire database finding books with the same isbn
	// and putting their identifiers in bookIdentifiers of the element
	// in isbnDatabase that has the same isbn as them
	for (int i = 0; i < size; i++)
	{
		bool foundIsbn = false;
		for (int j = 0; j < numIsbns; j++)
		{
			if (isbnDatabase[j].Isbn == books[i].getIsbn())
			{
				foundIsbn = true;
				isbnDatabase[j].bookIdentifiers[isbnDatabase[j].numBookIdentifiers] = books[i].getIdentifier();
				isbnDatabase[j].numBookIdentifiers++;
			}
		}
		if (!foundIsbn)
		{
			isbnDatabase[numIsbns].Isbn = books[i].getIsbn();
			isbnDatabase[numIsbns].bookIdentifiers[isbnDatabase[numIsbns].numBookIdentifiers] = books[i].getIdentifier();
			isbnDatabase[numIsbns].numBookIdentifiers++;
			numIsbns++;
		}
	}

	//sort the titles corresponding to the quantity
	//to keep the book attributes matched with the quantity
	int sorted = 0;
	while (sorted < numIsbns - 1)
	{
		int maxLocation = sorted;
		int maxValue = isbnDatabase[sorted].numBookIdentifiers;
		for (int i = sorted; i < numIsbns; i++)
		{
			if (isbnDatabase[i].numBookIdentifiers > maxValue)
			{
				maxLocation = i;
				maxValue = isbnDatabase[i].numBookIdentifiers;
			}
		}
		BooksWithIsbn temp = isbnDatabase[maxLocation];
		isbnDatabase[maxLocation] = isbnDatabase[sorted];
		isbnDatabase[sorted] = temp;
		sorted++;
	}

	cout << "Quantity\t\tTitle\t\t\tISBN\n";
	for (int i = 0; i < numIsbns; i++)
	{
		cout <<
			setw(20) << left << isbnDatabase[i].numBookIdentifiers
			<< setw(25) << left << database->searchIdentifier(isbnDatabase[i].bookIdentifiers[0])->getTitle()
			<< setw(20) << left << isbnDatabase[i].Isbn << endl;
	}

	cout << endl;
	
	delete[] isbnDatabase;
}

//main menu for the module
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