// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel
/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// ws books.txt
using namespace std;
using namespace sdds;
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	int lines = 0;
	if (argc == 2) {
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
		//       - if the file cannot be open, print a message to standard error console and
		//                exit from application with error code "AppErrors::CannotOpenFile"
		fstream in;
		in.open(argv[1]);
		if (!in.is_open())
		{
			cerr << "cannot open file " << argv[1] << endl;
			exit(AppErrors::BadArgumentCount);
		}
		string currentline = "";
		while (getline(in, currentline))
		{
			// count number of lines
			lines++;
		}
		lines-=2; // disregard last line since it is a blank line and first 2 lines since it's a header
		// allocate memory for an array to store books
		in.clear();
		in.seekg(0, ios::beg);
		getline(in, currentline);
		getline(in, currentline);
		for (size_t i = 0; i < lines; i++)
		{
			getline(in, currentline);
			Book newbook(currentline);
			library[i] = newbook;
		}
	}
	else
	{
		std::cerr << "ERROR: Incorrect number of arguments.\n";
		exit(AppErrors::BadArgumentCount);
	}

	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
	auto setprice = [usdToCadRate, gbpToCadRate](Book& mybook) {
		if (mybook.country() == "US")
		{
			mybook.price() *= usdToCadRate;
		}
		if (mybook.country() == "UK" && (mybook.year() >= 1990 && mybook.year() <= 1999))
		{
			mybook.price() *= gbpToCadRate;
		}
	};


	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (int i = 0; i < lines; i++)
	{
		cout<<(library[i]);
	}





	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
	for (int i = 0; i < lines; i++)
	{
		setprice(library[i]);
	}



	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	// TODO: iterate over the library and print each book to the screen
	for (int i = 0; i < lines; i++)
	{
		cout << (library[i]);
	}




	std::cout << "-----------------------------------------\n";


	SpellChecker test1("words.txt");
	string badwords = "teh teh teh teh";
	test1(badwords);
	cout << badwords << endl;
	test1.showStatistics(cout);

	return 0;
}
