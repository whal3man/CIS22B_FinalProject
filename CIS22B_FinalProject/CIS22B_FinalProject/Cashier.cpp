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
		if (books[i].getIsbn() == isbn)
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

void Cashier::removeBookFromCart(int identifier)
{
	int count = 0;
	bool condition = false;
	while (count < cartSize - 1)
	{
		if (condition)
		{
			cart[count] = cart[count++];
		}
		else if (cart[count] == identifier)
		{
			cart[count] = cart[count++];
			condition = true;
		}
		count++;
	}
	cartSize--;
		
}
void Cashier::removeBookMenu()
{
	for (int i = 0; i < cartSize; i++)
	{
		cout << &database[cart[i]];
	}
	cout << "What book would you like to remove?" << endl;
	int identifier = 0;
	cin >> identifier;
	for (int i = 0; i < cartSize; i++)
	{
		if (identifier == cart[i])
		{
			char choice;
			cout << "You have chosen to remove " << &database[cart[i]] << " from you list. Is this acceptable? (y/n)" << endl;
			cin >> choice;
			if (choice == 'y')
			{
				cout << "This book will be removed from your cart. " << endl;
				removeBookFromCart(identifier);
			}
			if (choice == 'n')
			{
				cout << "You will move back to the main menu." << endl;
			}
		}
	}
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
}

