/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/

#include <sstream>
#include <vector>
#include <iomanip>
#include "Movie.h"

namespace sdds {
	using namespace std;

	const string& Movie::title()const {
		return m_title;
	}

   Movie::Movie() :m_title{}, m_year{}, m_description{} {
   };

	Movie::Movie(const string& strMovie) {
      // split input into tokens
      vector<string> tokens = { "", "", "" };
      stringstream mystream(strMovie);
      getline(mystream, tokens[0], ',');
      getline(mystream, tokens[1], ',');
      getline(mystream, tokens[2]);
      // TITLE,YEAR,DESCRIPTION
      m_title = trimm(tokens[0]);
      m_year = stoi(trimm(tokens[1]));
      m_description = trimm(tokens[2]);
	};

   ostream& Movie::display(ostream& os) const {
      os << setw(40) << right << m_title
         << " | " << setw(4) << m_year
         << " | " << m_description << endl;
      return os;
   }


   ostream& operator<< (ostream& os, const Movie& movie) {
      movie.display(os);
      return os;
   }
   string& trimm(std::string& input) {
      string WHITESPACE = " \n\r\t\f\v";
      size_t start = input.find_first_not_of(WHITESPACE);
      size_t end = input.find_last_not_of(WHITESPACE);
      input = input.substr(start, end - start + 1);
      return input;
   }
}