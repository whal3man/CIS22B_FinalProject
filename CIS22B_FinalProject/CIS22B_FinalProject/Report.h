#ifndef _REPORT_H
#define _REPORT_H

#include "BookDatabase.h"

class Report : public Book, BookDatabase
{
private:
	BookDatabase* database;
public:
	Report();
	Report(BookDatabase* dtbs);
	//list attribues of the inventory
	void listInventory();
	//list all books retail values sorted and have sum at the end
	void listRetailValue();
	//list all books retail values sorted and have sum at the end
	void listWholesaleValue();
	//list all books sorted by date added to inventory - added first comes first
	void listAge();
	//list the inventory sorted by wholesale price - basically is the same as listWholesaleValue
	void listCost();
	//list the inventory sorted by quantity - most quantity first
	void listQuantity();
	//main menu for the module
	void mainMenu();
};


#endif
