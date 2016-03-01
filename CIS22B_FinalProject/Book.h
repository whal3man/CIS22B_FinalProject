#ifndef _BOOK_H
#define _BOOK_H

#include <string>
using namespace std;

class Book
{
private:
	string author;			// full name of the author
	int bookIdentifier;		// unique identifier for this specific book
	string dateAdded;		// date added in format MM/DD/YYYY
	string isbn;			// isbn of book
	string publisher;		// publisher of the book
	double retailPrice;		// retail price of book
	string title;			// full title of the book
	double wholesaleCost;	// wholesale cost of the book
public:
	// default constructor
	Book();
	// constructor with all attributes
	Book(string title, string author, string isbn, string publisher, 
		double wholesaleCost, double retailPrice, string dateAdded, int bookIdentifier);
	// retuns the author attribute
	string getAuthor();
	// returns the date that the book was added
	string getDateAdded();
	// returns the unique identifier
	int getIdentifier();
	// returns the isbn
	string getIsbn();
	// returns the publisher
	string getPublisher();
	// returns the retail price
	double getRetailPrice();
	// returns the title 
	string getTitle();
	// returns the wholesale cost
	double getWholesaleCost();
	// sets the author attribute to author
	void setAuthor(string author);
	// sets the dateAdded attribute to dateAdded
	void setDateAdded(string dateAdd);
	// sets the bookIdentifier attribute to identifier
	void setIdentifier(int identifier);
	// sets the isbn attribute to isbn
	void setIsbn(string Isbn);
	// sets the publisher attribute to publisher
	void setPublisher(string publish);
	// sets the retailPrice attribute to retailPrice
	void setRetailPrice(double retailPric);
	// sets the title attribute to title
	void setTitle(string titl);
	// sets the wholesaleCost attribute to wholesaleCost
	void setWholesaleCost(double wholesaleCost);
};

#endif
