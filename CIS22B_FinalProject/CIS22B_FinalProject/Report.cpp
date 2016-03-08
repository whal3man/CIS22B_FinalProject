#define _CRT_SECURE_NO_WARNINGS
#include "Report.h"

Report::Report()
{

}
Report::Report(BookDatabase* dtbs)
{

}
//A list of information on all books in the inventory
void Report::listInventory()
{

}
//A list of the retail value of all books in the inventory
//and the total retail value of the inventory.
void Report::listRetailValue()
{

}
//A list of the wholesale value of all books in the
//inventory and the total wholesale value of the inventory
void Report::listWholesaleValue()
{

}
//A list of all books in the inventory, sorted by purchase date. The
//books that have been in the inventory longest will be listed first.
void Report::listAge()
{

}
//A list of all books in the inventory, sorted by wholesale cost. The
//books with the greatest wholesale cost will be listed first.
void Report::listCost()
{

}
//A list of all books in the inventory sorted by quantity on hand.
//The books with the greatest quantity on hand will be listed first.
void Report::listQuantity()
{

}
void Report::mainMenu()
{
	int selection = 0; //to hold the user selection

	//ask user what they want to have shown
	try
	{
		do
		{
			cout << "1. List Inventory";
			cout << "2. List by Retail Value";
			cout << "3. List by Wholesale Value";
			cout << "4. List by Age";
			cout << "5. List by Quantity";
			cout << "6. Return to Main Menu";
			cout << "Please enter a number corresponding to a selection: ";

			if (cin >> selection)
			{
				//run the choice selected 1-5
				//break if == 6
			}
			else
			{
				throw "Please enter a valid selection.\n";
			}
		} while (selection != 6);
	}
	catch (string error)
	{
		cout << error;
	}

	return;
}