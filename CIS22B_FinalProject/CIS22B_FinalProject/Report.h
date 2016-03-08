#ifndef _REPORT_H
#define _REPORT_H

#include <string>
using namespace std;

class Report
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
