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
	void setDatabaseFile(string file);
	string getDatabaseFile();

	// adds book to the database, assigns it an identifier
	// incraments identiferCount, incraments size
	// and runs writeFile()
	void addBook(Book book);
	// returns the price 
	double getPrice(int identifier);
	// prints the book with the given identifier
	void printBook(int identifier);
	// prints all of the books with the given ISBN
	void printISBN(string isbn);
	// returns a pointer to books
	Book* getBooks();
	// returns size
	int getSize();
	// removes book with identifier from books,
	// decrements size, and runs writeFile()
	void removeBook(int identifier);
	// returns the index of book with identifier, or -1 if no book with identifier is found
	int searchIdentifier(int identifier);
	// same as searchIdentifier but allows for easier [] notation
	int operator[](int i);
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
	// allows the user to change any of the books variables except identifier
	void changeBook();
};

#endif