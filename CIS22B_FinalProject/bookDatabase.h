


#ifndef _bookDatabase_H
#define _bookDatabase_H
#include <iostream>
using namespace std;
class bookDatabase
{
private:
	Book books[/*some artbirtary number*/ ];
	int identifiercount;
	int size;
public:
	void addBook(Book);
	int getPrice(int identifier);
	void printBook(int identifier);
	void printISBN(int isbn);
	void removeBook(int isbn);
	int searchIndentifier(int identifier);
	int sellBook(int identifier);
	void sortBook();
	void swapBook(int location1, int location2);


};



#endif