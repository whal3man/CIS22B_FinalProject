#ifndef _CASHIER_H
#define _CASHIER_H

#include <string>
#include "BookDatabase.h"
using namespace std;

class Cashier
{
private:
	int cart[128];
	int cartSize = 0;
	BookDatabase* database;
public:
	Cashier();
	Cashier(BookDatabase* dtbs);
	//displays a menu that
	//asks the user for the identifier of the book they wish to add to cart
	//adds the book they select to the cart
	void addBookMenu();
	// displays a menu to remove a book from the cart
	void removeBookMenu();
	// displays checkout menu for all items in cart
	// if they are satisfied with their cart, remove the books from database
	void checkout();
	// main menu that asks the user what they want to do
	void mainMenu();
	// to remove book from removeBookMenu function
	void removeBookFromCart(int identifier);
	
};

#endif