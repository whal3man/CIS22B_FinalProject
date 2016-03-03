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

void BookDatabase::writeFile(string file)
{
	try
	{
		// if file already exists, renames it to file.bak
		// if file.bak already exists, delete it
		ifstream ifile(file.c_str());
		if (ifile)
		{
			string newName = file + ".bak";
			ifstream bakIsFile(newName.c_str());
			if (bakIsFile)
			{
				remove(newName.c_str());
			}
			rename(file.c_str(), newName.c_str());
		}

		ofstream fout;
		fout.open(file);
		if (fout.fail())
		{
			throw "Failed to open " + file + " for writing.\n";
		}

		fout << identifierCount << endl;
		fout << size << endl;
		for (int i = 0; i < size; i++)
		{
			cout << books[i].getAuthor() << endl;
			cout << books[i].getDateAdded() << endl;
			cout << books[i].getIdentifier() << endl;
			cout << books[i].getIsbn() << endl;
			cout << books[i].getPublisher() << endl;
			cout << books[i].getRetailPrice() << endl;
			cout << books[i].getTitle() << endl;
			cout << books[i].getWholesaleCost() << endl;
		}
	}
	catch (string e)
	{
		cout << e;
	}
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
