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
	void listInventory();
	void listRetailValue();
	void listWholesaleValue();
	void listAge();
	void listCost();
	void listQuantity();
	void mainMenu();
};


#endif
