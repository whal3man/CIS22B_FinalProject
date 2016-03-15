#define _CRT_SECURE_NO_WARNINGS
#include "BookDatabase.h"


BookDatabase::BookDatabase()
{
	//creates a book array of size 1024
	//initiializes indentifiercount, size and databaseFile
	books = new Book[1024];
	invalidBook = new Book();
	identifierCount = 1;
	size = 0;
	databaseFile = "database.txt";
}

void BookDatabase::readFile()
{
	try
	{
		ifstream fin;
		fin.open(databaseFile);
		if (fin.fail())
		{
			throw "Failed to open " + databaseFile + " for reading.\n";
		}

		fin >> identifierCount;
		fin >> size;

		string tempAuthor, tempDateAdded, tempIsbn, tempPublisher, tempTitle;
		int tempIdentifier;
		double tempRetailPrice, tempWholesaleCost;

		for (int i = 0; i < size; i++)
		{
			fin.ignore(1000, '\n');
			getline(fin, tempAuthor);
			getline(fin, tempDateAdded);
			fin >> tempIdentifier;
			fin.ignore(1000, '\n');
			getline(fin, tempIsbn);
			getline(fin, tempPublisher);
			fin >> tempRetailPrice;
			fin.ignore(1000, '\n');
			getline(fin, tempTitle);
			fin >> tempWholesaleCost;
			books[i].setAll(tempTitle, tempAuthor, tempIsbn, tempPublisher, tempWholesaleCost, tempRetailPrice, tempDateAdded, tempIdentifier);
		}
		fin.close(); //close the input file 
	}
	catch (string e)
	{
		cout << e;
	}
}

void BookDatabase::writeFile()
{
	try
	{
		// if file already exists, renames it to file.bak
		// if file.bak already exists, delete it
		ifstream ifile(databaseFile.c_str());
		if (ifile)
		{
			ifile.close();
			string newName = databaseFile + ".bak";
			ifstream bakIsFile(newName.c_str());
			if (bakIsFile)
			{
				bakIsFile.close();
				remove(newName.c_str());
			}
			else
			{
				bakIsFile.close();
			}
			rename(databaseFile.c_str(), newName.c_str());
		}

		ofstream fout;
		fout.open(databaseFile);
		if (fout.fail())
		{
			throw "Failed to open " + databaseFile + " for writing.\n";
		}

		fout << identifierCount << endl;
		fout << size << endl;
		for (int i = 0; i < size; i++)
		{
			fout << books[i].getAuthor() << endl;
			fout << books[i].getDateAdded() << endl;
			fout << books[i].getIdentifier() << endl;
			fout << books[i].getIsbn() << endl;
			fout << books[i].getPublisher() << endl;
			fout << books[i].getRetailPrice() << endl;
			fout << books[i].getTitle() << endl;
			fout << books[i].getWholesaleCost() << endl;
		}
		fout.close(); //close the output file
	}
	catch (string e)
	{
		cout << e;
	}
}

void BookDatabase::setDatabaseFile(string file)
{
	//creates a way to set the name of database file
	databaseFile = file;
}

string BookDatabase::getDatabaseFile()
{
	//creates a way to get the name of the database file
	return databaseFile;
}

void BookDatabase::addBook(Book book)
{
	//adds a book with the specifications that the user inputs
	try
	{
		books[size].setAll(book.getTitle(), book.getAuthor(), book.getIsbn(), book.getPublisher(),
			book.getWholesaleCost(), book.getRetailPrice(), book.getDateAdded(), identifierCount);
		identifierCount++;
		size++;
		writeFile();
	}
	catch (char e[])
	{
		throw e;
	}
	catch (...)
	{
		throw;
	}
}
double BookDatabase::getPrice(int identifier)
{
	int count = 0;
	//runs through all books in the "books" array
	//then if the book matches the identifier given, it returns the price of that book
	while (count < size)
	{
		if (books[count].getIdentifier() == identifier)
		{
			return books[count].getRetailPrice();
		}
		count++;
	}
	return -1;
}
Book * BookDatabase::getBooks()
{
	//creates a way to return the books array
	return books;
}
int BookDatabase::getSize()
{
	//creates a way to return the size integer
	return size;
}
void BookDatabase::removeBook(int identifier)
{
	//sets integer size to zero
	//then if the books array if equal to the identifier provided to the function
	//it shifts the array then sets the bool variable to true
	//which makes the loop enter the if statement that shifts the array to remove replace the book
	//then reduces the size by one and updates the file
	int count = 0;
	bool foundBook = false;
	while (count < size - 1)
	{
		if (foundBook)
		{
			 books[count] = books[count + 1];
		}
		else if (books[count].getIdentifier() == identifier)
		{
			books[count] = books[count + 1];
			foundBook = true;
		}
		count++;
	}
	
	size--;
	writeFile();
}
Book* BookDatabase::searchIdentifier(int identifier)
{
	//runs through all the books and checks if ay of them matches the identifier the returns
	//the book with that count.
	//if the book with that "count" was not found, it returns an invalidbook(a default book that is returned when none is found)
	int count = 0;
	while (count < size)
	{
		if (books[count].getIdentifier() == identifier)
		{
			return &books[count];
		}
		count++;
	}
	return invalidBook;
}

Book* BookDatabase::operator[](int i)
{
	//example of an operator
	return searchIdentifier(i);
}

void BookDatabase::mainMenu()
{
	//sets a bool variable to false
	//then while the bool is false, prints the main menu
	//prompts user to respond and then calls the approriate function depending on their answer
	//if the user inputs a char instead of an int, t tells them its invalid
	//clears the screen and returns to the main menu again
	bool done = false;
	while (!done)
	{
		system("CLS");
		cout << "\n\t\t\tSerendipity Booksellers\n\t\t\tInventory Main Menu\n\n";
		cout << "\t    1. Look Up a Book\n";
		cout << "\t    2. Add a Book\n";
		cout << "\t    3. Edit a Books Record\n";
		cout << "\t    4. Delete a Book\n";
		cout << "\t    5. Exit\n";
		cout << "\n\t     Enter your choice: ";
		int response;
		//changed from switch so we can catch if user inputs a char instead of int
		if (cin >> response)
		{
			if (response == 1)
			{
				lookupBookMenu();
			}
			if (response == 2)
			{
				addBookMenu();
			}
			if (response == 3)
			{
				changeBook();
			}
			if (response == 4)
			{
				removeBookMenu();
			}
			if (response == 5)
			{
				done = true;
			}
		}
		else
		{
			system("CLS");
			cout << "\n\t\t\tInvalid response.\n\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}

void BookDatabase::swapBooks(int index1, int index2)
{
	//makes book1 equal to a temporary variable then switches book2 with book1 then sets book2 equal to temporary variable
	Book temp = books[index1];
	books[index1] = books[index2];
	books[index2] = temp;
}
void BookDatabase::addBookMenu()
{
	//asks the user to to enter the followinng inforation for the book: title, author, isbn, publisher, dateadded, wholesalecost and retailcost.
	//then get the line that the user entered.
	system("CLS");
	string title, author, isbn, publisher, dateadded;
	double wholesalecost, retailcost;
	cout << "What is the title of the book you want to add? ";
	cin.ignore(1000, '\n');
	getline(cin, title);
	cout << "What is the name of the author? ";
	getline(cin, author);
	cout << "What is the isbn of the book? ";
	getline(cin, isbn);
	cout << "What is the publisher of the book? ";
	getline(cin, publisher);
	cout << "On what day was this book added? (MM/DD/YYYY) ";
	getline(cin, dateadded);
	//makes a bool false and while it is false
	//asks the user what the retailcost is, and if it is not valid clears the screen
	//otherwise it sets bool variable true and continues out of the loop
	bool retailEntered = false;
	while (!retailEntered)
	{
		cout << "What is the retail cost? ";
		cin >> retailcost;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n";
		}
		else
		{
			retailEntered = true;
		}
	}
	// does the same thing as the retailcost, but with the varaible wholesalecost
	bool wholesaleEntered = false;
	while (!wholesaleEntered)
	{
		cout << "What is the wholesalecost? ";
		cin >> wholesalecost;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid response.\n";
		}
		else
		{
			wholesaleEntered = true;
		}
	}
	cin.ignore(1000, '\n');
	system("CLS");
	cout << "\n\n\t\t\tBook successfully added!" << endl;
	//creates a new book with everything that the user entered
	Book a;
	a.setAll(title, author, isbn, publisher, wholesalecost, retailcost, dateadded, identifierCount);
	//asks the user if their informatiion is correct, and outputs their book that they just created
	cout << "\n\nDoes this look right?\n\n";
	cout << a;

	string response;
	bool done = false;
	while (!done)
	{
		//tells the user to enter yes or no
		cout << "(Y/N)> ";
		cin >> response;
		if (response == "y" || response == "Y")
		{
			while (!done)
			{
				//takes answer and asks how many copies tha tthe user wants to add
				cout << "How many copies of " << a.getTitle() << " would you like to add? ";
				int numBooksToAdd;
				cin >> numBooksToAdd;
				//created if the user enters anything that is not an int variable
				if (cin.fail())
				{
					cout << "That is an invalid response.\n";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				//used if the user adds a number less than zero and tells them it is invalid
				else if (numBooksToAdd < 0)
				{
					cout << "That is an invalid number of books.\n";
				}
				//used if the number of books added exceed the limit of the number of books that are able to be stored in the database
				else if (numBooksToAdd > 1024 - (identifierCount - 1))
				{
					done = true;
					cout << "\nDatabase will be full! Database can have a maximum of 1024 books.\n";
					cout << "\nPress return to continue.";
					cin.ignore(1000, '\n');
					cin.get();
				}
				else
				{
					for (int i = 0; i < numBooksToAdd; i++)
					{
						try
						{
							addBook(a);
						}
						catch (char e[])
						{
							cout << e;
							cout << "Press return to continue.";
							cin.ignore(1000, '\n');
							cin.get();
						}
						catch (...)
						{
							cout << "There was an error.\n";
							cout << "Press return to continue.";
							cin.ignore(1000, '\n');
							cin.get();
						}
					}
					done = true;
				}
			}
		}
		else if (response == "n" || response == "N")
		{
			cout << "Exiting...\n";
			done = true;
			cout << "Press return to continue.";
			cin.ignore();
			cin.get();
		}
		else
		{
			cout << "Invalid response.\n";
			cout << "Press return to continue.";
			cin.ignore();
			cin.get();
		}
	}
}
void BookDatabase::removeBookMenu()
{
	system("CLS");
	int identifier;
	cout << "Enter the identifier of the book that you want to remove: ";
	if (cin >> identifier)
		removeBook(identifier);
	else
	{
		cout << "That is an invalid identifier. Press return to continue.";
		cin.clear();
		cin.ignore(1000, '\n');
		cin.get();
	}
}

void BookDatabase::lookupBookMenu()
{
	bool done = false;
	while (!done)
	{
		system("CLS");
		cout << "\n\t\tSerendipity Booksellers\n\t\t\tBook Lookup\n\n";
		cout << "\t    1. Look Up by Identifier\n";
		cout << "\t    2. Look Up by Title\n";
		cout << "\t    3. Look Up by Author\n";
		cout << "\t    4. Look Up by ISBN\n";
		cout << "\t    5. Look Up by Publisher\n";
		cout << "\t    6. Look Up by Date Added\n";
		cout << "\t    7. Look Up by Retail Cost\n";
		cout << "\t    8. Look Up by Wholesale Cost\n";
		cout << "\t    9. Exit\n";
		cout << "\n\t     Enter your choice: ";
		int response;

		if (cin >> response)
		{
			bool pubFound = false;
			string publisher;
			string title;
			bool titleFound = false;
			string author;
			bool authorFound = false;
			bool idenFound = false;
			int identifier;
			bool isbnFound = false;
			string isbn;
			bool dateFound = false;
			string dateadded;
			bool retailFound = false;
			double retailPrice;
			double wholsaleCost;
			bool wholeFound = false;
			bool correctResponse = false;

			while (correctResponse == false)
			{
				switch (response)
				{
				case 1:
					cout << "Enter the identifier you are looking for: ";
					if (cin >> identifier)
					{
						correctResponse = true;
						cout << endl;
						for (int i = 0; i < size; i++)
						{
							if (books[i].getIdentifier() == identifier)
							{
								cout << books[i] << endl;
								idenFound = true;
							}
						}
						cout << endl;
						if (!idenFound)
						{
							cout << "No book with that identifier was found.\n";
						}
						else idenFound = false;
						cout << "Press return to continue.\n\n";
						cin.ignore();
						cin.get();
					}
					else
					{
						cout << "Invalid response. Please try again.\n\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}
	
					break;
				case 2:
					correctResponse = true;
					cout << "Enter the title you want to search for: ";
					cin >> title;
					cout << endl;
					for (int i = 0; i < size; i++)
					{
						if (books[i].getTitle().find(title) != std::string::npos)
						{
							cout << books[i] << endl;
							titleFound = true;
						}
					}
					cout << endl;
					if (!titleFound)
					{
						cout << "No book with that title was found.\n";
					}
					else titleFound = false;
					cout << "Press return to continue.\n\n";
					cin.ignore();
					cin.get();
					break;
				case 3:
					correctResponse = true;
					cout << "Enter the author you want to search for: ";
					cin >> author;
					cout << endl;
					for (int i = 0; i < size; i++)
					{
						if (books[i].getAuthor().find(author) != std::string::npos)
						{
							cout << books[i] << endl;
							authorFound = true;
						}
					}
					cout << endl;
					if (!authorFound)
					{
						cout << "No book with that author was found.\n";
					}
					else authorFound = false;
					cout << "Press return to continue.";
					cin.ignore();
					cin.get();
					break;
				case 4:
					correctResponse = true;
					cout << "Enter the ISBN you are looking for: ";
					cin >> isbn;
					cout << endl;
					for (int i = 0; i < size; i++)
					{
						if (books[i].getIsbn() == isbn)
						{
							cout << books[i] << endl;
							isbnFound = true;
						}
					}
					cout << endl;
					if (!isbnFound)
					{
						cout << "No book with that ISBN was found.\n";
					}
					else isbnFound = false;
					cout << "Press return to continue.";
					cin.ignore();
					cin.get();
					break;
				case 5:
					correctResponse = true;
					cout << "Enter the publisher you want to search for: ";
					cin >> publisher;
					cout << endl;
					for (int i = 0; i < size; i++)
					{
						if (books[i].getPublisher().find(publisher) != std::string::npos)
						{
							cout << books[i] << endl;
							pubFound = true;
						}
					}
					cout << endl;
					if (!pubFound)
					{
						cout << "No book with that publisher was found.\n";
					}
					else pubFound = false;
					cout << "Press return to continue.";
					cin.ignore();
					cin.get();
					break;
				case 6:
					correctResponse = true;
					cout << "Enter the date added you are looking for: ";
					cin >> dateadded;
					cout << endl;
					for (int i = 0; i < size; i++)
					{
						if (books[i].getDateAdded() == dateadded)
						{
							cout << books[i] << endl;
							dateFound = true;
						}
					}
					cout << endl;
					if (!dateFound)
					{
						cout << "No book with that publisher was found.\n";
					}
					else dateFound = false;
					cout << "Press return to continue.";
					cin.ignore();
					cin.get();
					break;
				case 7:
					cout << "Enter the retail price you are looking for: ";
					if (cin >> retailPrice)
					{
						correctResponse = true;
						cout << endl;
						for (int i = 0; i < size; i++)
						{
							if (books[i].getRetailPrice() == retailPrice)
							{
								cout << books[i] << endl;
								retailFound = true;
							}
						}
						cout << endl;
						if (!retailFound)
						{
							cout << "No book with that retail price was found.\n";
						}
						else retailFound = false;
						cout << "Press return to continue.\n\n";
						cin.ignore();
						cin.get();
					}
					else
					{
						cout << "Invalid response. Please try again.\n\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}
					break;
				case 8:
					cout << "Enter the wholesale cost you are looking for: ";
					if (cin >> wholsaleCost)
					{
						correctResponse = true;
						cout << endl;
						for (int i = 0; i < size; i++)
						{
							if (books[i].getWholesaleCost() == wholsaleCost)
							{
								cout << books[i] << endl;
								wholeFound = true;
							}
						}
						cout << endl;
						if (!wholeFound)
						{
							cout << "No book with that wholesale cost was found.\n";
						}
						else wholeFound = false;
						cout << "Press return to continue.\n\n";
						cin.ignore();
						cin.get();
					}
					else
					{
						cout << "Invalid response. Please try again.\n\n";
						cin.clear();
						cin.ignore(1000, '\n');
					}
					break;
				case 9:
					correctResponse = true;
					done = true;
					break;
				default:
					cout << "Invalid response. ";
					cout << "Press return to continue.";
					cin.ignore();
					cin.get();
					break;
				}
			}
		}
		else
		{
			cout << "Invalid response. ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
}
void BookDatabase::changeBook()
{
	string title, author, ISBN, publisher, dateadded;
	double retailcost, wholesalecost;
	int choice, identifier;
	bool done = false;
	while (done != false);
	{
		system("CLS");
		cout << "Enter the identifier of the book you would like to change: ";
		if (cin >> identifier)
		{
			Book* book = searchIdentifier(identifier); //we only need to get the identifier once per user input
			if (book->getIdentifier() == -1)
			{
				cout << "A book with that identifier does not exist.\n";
				cout << "Press return to continue.";
				cin.ignore();
				cin.get();
			}
			else
			{
				cout << endl << *book << endl;
				cout << "What would you like to change?" << endl; // change from "that book" to the actual title for clarity
				cout << "1. Title" << endl;
				cout << "2. Author" << endl;
				cout << "3. ISBN" << endl;
				cout << "4. Publisher" << endl;
				cout << "5. Date Added" << endl;
				cout << "6. Retail Cost" << endl;
				cout << "7. Wholesale Cost" << endl;
				cout << "8. Exit" << endl;
				cout << "Enter your choice: ";
				cin >> choice;
				if (!(cin.fail()))
				{
					switch (choice)
					{
					case 1:
						cout << "What is the new title: ";
						cin.ignore(1000, '\n');
						getline(cin, title);
						book->setTitle(title);
						cout << "The title is now " << book->getTitle() << endl;
						cout << "Press return to continue.";
						cin.get();
						writeFile();
						break;
					case 2:
						cout << "What is the new Author name: ";
						cin.ignore(1000, '\n');
						getline(cin, author);
						book->setAuthor(author);
						cout << "The author of " << book->getTitle() << " is now " << book->getAuthor() << endl;
						cout << "Press return to continue.";
						cin.get();
						writeFile();
						break;
					case 3:
						cout << "What is the new ISBN: ";
						cin >> ISBN;
						book->setIsbn(ISBN);
						cout << "The ISBN of " << book->getTitle() << " is now " << book->getIsbn() << endl;
						cout << "Press return to continue.";
						cin.ignore();
						cin.get();
						writeFile();
						break;
					case 4:
						cout << "Who is the new publisher: ";
						cin.ignore(1000, '\n');
						getline(cin, publisher);
						book->setPublisher(publisher);
						cout << "The publisher of " << book->getTitle() << " is now " << book->getPublisher() << endl;
						cout << "Press return to continue.";
						cin.get();
						writeFile();
						break;
					case 5:
						cout << "What is the new date added (MM/DD/YYYY): ";
						cin >> dateadded;
						book->setDateAdded(dateadded);
						cout << "The date added of " << book->getTitle() << " is now " << book->getDateAdded() << endl;
						cout << "Press return to continue.";
						cin.ignore();
						cin.get();
						writeFile();
						break;
					case 6:
						cout << "What is the new retail cost: ";
						cin >> retailcost;
						book->setRetailPrice(retailcost);
						cout << "The retail cost of " << book->getTitle() << " is now " << book->getRetailPrice() << endl;
						cout << "Press return to continue.";
						cin.ignore();
						cin.get();
						writeFile();
						break;
					case 7:
						cout << "What is the new wholesale cost: ";
						cin >> wholesalecost;
						book->setWholesaleCost(wholesalecost);
						cout << "The wholesale cost of " << book->getTitle() << " is now " << book->getWholesaleCost() << endl;
						cout << "Press return to continue.";
						cin.ignore();
						cin.get();
						writeFile();
						break;
					case 8:
						done = true;
						cout << "Exiting. Press return to continue.";
						cin.ignore();
						cin.get();
						break;
					default:
						cout << "Invalid response. ";
						cout << "Press return to continue.";
						cin.ignore();
						cin.get();
						break;
					}
				}
				else
				{
					cout << "Invalid response. Press return to continue.";
					cin.ignore();
					cin.get();
					cin.ignore(1000, '\n');
					cin.clear();
					done = false;
				}
			}
		}
		else
		{
			cout << "That is an invalid identifier. Press return to continue.";
			cin.clear();
			cin.ignore(1000, '\n');
			cin.get();	
		}
	}
}