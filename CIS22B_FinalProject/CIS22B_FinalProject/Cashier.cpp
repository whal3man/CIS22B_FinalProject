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
			cout << books[i] << endl;
		}
	}
}


void Cashier::addBookMenu()
{
	int identifier = -1;
	cout << "Enter the identifier of the book you wish to add to cart: ";
	cin >> identifier;
	Book* tempBook = database->searchIdentifier(identifier);
	if (tempBook->getIdentifier() == -1)
	{
		cout << "A book with the identifier " << identifier << " was not found.\n";
		cout << "Press return to continue.";
		cin.ignore();
		cin.get();
	}
	else
	{
		cout << "Does this look correct?\n\n" << *tempBook << endl;
		cout << "Response (Y/N)> ";
		string response;
		cin >> response;
		if (response == "y" || response == "Y")
		{
			bool bookAlreadyInCart = false;
			for (int i = 0; i < cartSize; i++)
			{
				if (cart[i] == identifier)
				{
					bookAlreadyInCart = true;
				}
			}

			if (bookAlreadyInCart)
			{
				cout << "That book is already in the cart.\n";
				cout << "Press return to continue.";
				cin.ignore();
				cin.get();
			}
			else
			{
				cart[cartSize] = identifier;
				cartSize++;
				cout << "The book " << tempBook->getTitle() << " was added to the cart.\n";
				cout << "Press return to continue.";
				cin.ignore();
				cin.get();
			}
		}
		else if (response == "n" || response == "N")
		{
			cout << "Exiting...\n";
			cout << "Press return to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "Invalid response...\n";
			cout << "Press return to continue.";
			cin.ignore();
			cin.get();
		}
	}
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
	if (cartSize > 0)
	{
		cout << "  ID   Price\t   Title\n" << endl;
		for (int i = 0; i < cartSize; i++)
		{
			Book* book = database->searchIdentifier(cart[i]);

			cout << setw(4) << right << i + 1 << ". " << "$"
				<< setprecision(2) << fixed
				<< setw(12) << left << book->getRetailPrice()
				<< setw(20) << left << book->getTitle()
				<< endl;

			cout << "\nWhat book would you like to remove? ";
			int identifier = 0;
			cin >> identifier;


			if (identifier == cart[i])
			{
				char choice;
				cout << "\nYou have chosen to remove " << book->getTitle() << " from your list. \n\nIs this acceptable? (y/n)" << endl;
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
	else
	{
		cout << "\n\n\t    The cart is empty!\n\n";
	}
	system("PAUSE");
}
void Cashier::checkout()
{
	double subtotal = 0;
	for (int i = 0; i < cartSize; i++)
	{
		subtotal += database->getPrice(cart[i]);
	}
	cout << "Serendipity Book Sellers" << endl << endl;
	cout << "Date: " << endl << endl;
	cout << "ISBN\t\tTitle\t\t\t\tPrice" << endl;
	cout << "____________________________________________________________" << endl << endl;
	for (int i = 0; i < cartSize; i++)
	{
		Book* book = database->searchIdentifier(cart[i]);
		cout << book->getIsbn() << "\t\t" << book->getTitle() << "\t\t\t\t" << book->getRetailPrice() << endl;
	}
	cout << "\t\t\t\t\t____________________" << endl << endl;
	cout << "\t\tSubtotal:\t\t\t" << subtotal << endl << "\t\tTax: " << "Sales Tax @ 6.25%:\t\t" << (subtotal * 0.0625) << endl << "\t\tTotal:\t\t\t\t" << subtotal + subtotal*0.0625 << endl << endl;
	cout << "Does this look correct? (Y/N)> ";
	string response;
	cin >> response;
	if (response == "y" || response == "Y")
	{
		for (int i = 0; i < cartSize; i++)
		{
			database->removeBook(cart[i]);
		}
		cartSize = 0;
		cout << "Transaction successful.\n";
		cout << "Press return to continue.";
		cin.ignore();
		cin.get();
	}
	else if (response == "n" || response == "N")
	{
		cout << "Exiting...\n";
		cout << "Press return to continue.";
		cin.ignore();
		cin.get();
	}
	else
	{
		cout << "Invalid response...\n";
		cout << "Press return to continue.";
		cin.ignore();
		cin.get();
	}
}
void Cashier::mainMenu()
{
	bool done = false;
	while (!done)
	{
		system("CLS");
		cout << "\t\tSerendipity Booksellers\n\t\t\tCashier\n\n";
		cout << "\t    1. Add a Book to the Cart\n";
		cout << "\t    2. Proceed to Checkout\n";
		cout << "\t    3. Remove a Book from the Cart\n";
		cout << "\t    4. Exit\n";
		cout << "\n\t     Enter your choice: ";
		int choice = 0;
		cin >> choice;

		if (cin.fail())
		{
			system("CLS");
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "That is an invalid response. Press return to continue.";
			cin.get();
			done = false;
		}
		else if (choice == 1)
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
		else if (choice == 4)
		{
			done = true;
		}
		else
		{
			cout << "Invalid choice! ";
		}
	}
}

