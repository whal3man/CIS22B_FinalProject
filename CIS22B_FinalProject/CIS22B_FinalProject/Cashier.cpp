#define _CRT_SECURE_NO_WARNINGS
#include "Cashier.h"




Cashier::Cashier()
{
}
Cashier::Cashier(BookDatabase* dtbs)
{
	database = dtbs;
}

void Cashier::listIsbn(string isbn)
{
	Book * books = database->getBooks();
	for (int i = 0; i < database->getSize(); i++)
	{
		if (books[i].getIsbn == isbn)
		{
			cout << books[i];
		}
	}
}


void Cashier::addBookMenu()
{
	cout << "Enter in the ISBN of the book you want to purchase: " << endl;
	string isbn;
	cin >> isbn;
	listIsbn(isbn);
}
void Cashier::removeBookMenu()
{
	cout << cartSize;
}
void Cashier::checkout()
{
	cout << "";
	for (int i = 0; i < cartSize; i++)
	{
		database->getPrice(cart[i]);
	}
}
void Cashier::mainMenu()
{
	cout << "What would you like to do?" << endl << endl << "Press '1' to add a book. " << endl << "Press '2' to go to checkout." << endl << "Press '3' to remove a book." << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		addBookMenu();
	}
	else if (choice == 2)
	{
		checkout();
	}
	else if (choice == 3)
	{
		removeBookMenu();
	}
	else
	{
		cout << "Invalid choice! ";
	}
	system("PAUSE");
}