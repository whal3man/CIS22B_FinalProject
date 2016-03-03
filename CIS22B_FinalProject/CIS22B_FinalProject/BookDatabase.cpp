#define _CRT_SECURE_NO_WARNINGS
#include "BookDatabase.h"

BookDatabase::BookDatabase()
{
	books = new Book[1024];
	identifierCount = 1;
	size = 0;
}

BookDatabase::~BookDatabase()
{
	delete[] books;
}

void BookDatabase::clearDatabase()
{
	identifierCount = 1;
	size = 0;
}

void BookDatabase::addBook(Book book)
{
	books[size].changeAll(book.getTitle(), book.getAuthor(), book.getIsbn(), book.getPublisher(),
		book.getWholesaleCost(), book.getRetailPrice(), book.getDateAdded(), identifierCount);
	identifierCount++;
	size++;
}
int BookDatabase::getPrice(int identifier)
{
	return 0;
}
void BookDatabase::printBook(int identifier)
{

}
void BookDatabase::printISBN(int isbn)
{

}
void BookDatabase::removeBook(int isbn)
{

}
int BookDatabase::searchIdentifier(int identifier)
{
	int count = 0;
	while (count < size)
	{
		if (books[count].getIdentifier() == identifier)
		{
			return count;
		}
		count++;
	}
	return -1;
}

int BookDatabase::operator[](int i)
{
	return searchIdentifier(i);
}
