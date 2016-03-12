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
	// sets databse file to file
	void setDatabaseFile(string file);
	// returns databaseFile
	string getDatabaseFile();

	// adds book to the database, assigns it an identifier
	// incraments identiferCount, incraments size
	// and runs writeFile()
	void addBook(Book book);
	// returns the price 
	double getPrice(int identifier);
	// prints all of the books with the given ISBN
	void printISBN(string isbn);
	// returns a pointer to books
	Book* getBooks();
	// get identifier count
	int getIdentifierCount();
	// returns size
	int getSize();
	// removes book with identifier from books,
	// decrements size, and runs writeFile()
	void removeBook(int identifier);
	// returns the Book with identifier, or book[1023] if not found
	Book* searchIdentifier(int identifier);
	// same as searchIdentifier but allows for easier [] notation
	Book* operator[](int i);
	// swaps books with index1 and index2
	void swapBooks(int index1, int index2);


	// displays a menu asking the user which menu they wish to enter
	void mainMenu();
	// displays a menu to add a book to the database
	void addBookMenu();
	// displays a menu to remove a book from the database
	void removeBookMenu();
	// allows the user to find books by entering information about them
	void lookupBookMenu();
	// menu that allows the user to change any of the books variables except identifier
	void changeBook();
};

#endif