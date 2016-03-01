#include "Book.h"

string Book::getAuthor()
{
	return author;
}

string Book::getDateAdded()
{
	return dateAdded;
}

int Book::getIdentifier()
{
	return bookIdentifier;
}

string Book::getIsbn()
{
	return isbn;
}

string Book::getPublisher()
{
	return publisher;
}

double Book::getRetailPrice()
{
	return retailPrice;
}

string Book::getTitle()
{
	return title;
}

double Book::getWholesaleCost()
{
	return wholesaleCost;
}

void Book::setAuthor(string auth)
{
	author = auth;
}

void Book::setDateAdded(string dateAdd)
{
	dateAdded = dateAdd;
}

void Book::setIdentifier(int identifier)
{
	bookIdentifier = identifier;
}

void Book::setIsbn(string Isbn)
{
	isbn = Isbn;
}

void Book::setPublisher(string publish)
{
	publisher = publish;
}

void Book::setRetailPrice(double retailPric)
{
	retailPrice = retailPric;
}

void Book::setTitle(string titl)
{
	title = titl;
}

void Book::setWholesaleCost(double wholesaleCos)
{
	wholesaleCost = wholesaleCos;
}
