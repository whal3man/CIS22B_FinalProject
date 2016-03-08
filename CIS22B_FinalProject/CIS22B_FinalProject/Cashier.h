#ifndef _CASHIER_H
#define _CASHIER_H

#include <string>
using namespace std;

class Cashier
{
private:
	int cart[128];
	int cartSize;
	BookDatabase* databse;
public:
	Cashier();
	Cashier(BookDatabase* dtbs);
	// displays a menu to add a book to the cart
	void addBookMenu();
	// displays a menu to remove a book from the cart
	void removeBookMenu();
	// displays checkout menu for all items in cart
	// if they are satisfied with their cart, remove the books from database
	void checkout();
	// main menu that asks the user what they want to do
	void mainMenu();
};

#endif