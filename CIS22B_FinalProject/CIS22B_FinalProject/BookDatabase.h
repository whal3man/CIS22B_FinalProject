#ifndef _BOOK_DATABASE_H
#define _BOOK_DATABASE_H

#include "Book.h"
#include <iostream>
#include <fstream>

class BookDatabase
{
private:
	Book* books;			// array of 1024 books
	int identifierCount;
	int size;
	string databaseFile;
public:
	// initializes the books array, sets identifier count to 1, and sets size to 0
	BookDatabase();
	// deletes the books array
	~BookDatabase();
	// clear BookDatabase, then read database from file
	void readFile();
	// write all info in database to file
	void writeFile();
	const void setDatabaseFile(string file);
	string getDatabaseFile();
	void addBook(Book book);
	int getPrice(int identifier);
	void printBook(int identifier);
	void printISBN(string isbn);
	const Book* getBooks();
	int getSize();
	void removeBook(int identifier);
	// returns the index of book with identifier, or -1 if no book with identifier is found
	int searchIdentifier(int identifier);
	// same as searchIdentifier but allows for easier [] notation
	int operator[](int i);
	int sellBook(int identifier);
	//need a mainmenu for the inventory database module
	void mainMenu();
};

#endif