/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/
#include <vector>
#include <sstream>
#include <iomanip>
#include "Book.h"

namespace sdds {
   using namespace std;
	Book::Book() : m_author{}, m_title{}, m_pub_country{}, m_pub_year{}, m_price{}, m_description{} {
	}

   Book::Book(const string& strBook){
      // split input into tokens
      vector<string> tokens = {"", "", "", "", "", ""};
      stringstream mystream(strBook);
      getline(mystream, tokens[0], ',');
      getline(mystream, tokens[1], ',');
      getline(mystream, tokens[2], ',');
      getline(mystream, tokens[3], ',');
      getline(mystream, tokens[4], ',');
      getline(mystream, tokens[5]);
      // AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
      m_author = trimb(tokens[0]);
      m_title = trimb(tokens[1]);
      m_pub_country = trimb(tokens[2]);
      m_price = stod(trimb(tokens[3]));
      m_pub_year = stoi(trimb(tokens[4]));
      m_description = trimb(tokens[5]);
   }

   Book::~Book() {
   }



   const string& Book::title() const {
      return m_title;
   }
   const string& Book::country() const {
      return m_pub_country;
   }
   const size_t& Book::year() const {
      return m_pub_year;
   }
   double& Book::price() {
      return m_price;
   }

   ostream& Book::display(ostream& os) const {
      os << setw(20) << right << m_author;
      os << " | " << setw(22) << right << m_title
         << " | " << setw(5) << right << m_pub_country
         << " | " << setw(4) << m_pub_year
         << " | " << setw(6) << fixed << setprecision(2) << m_price
         << " | " << m_description << endl;
      return os;
   }
   
   ostream& operator<<(ostream& os, const Book& book) {
      return book.display(os);
   }

   string& trimb(std::string& input) {
      string WHITESPACE = " \n\r\t\f\v";
      size_t start = input.find_first_not_of(WHITESPACE);
      size_t end = input.find_last_not_of(WHITESPACE);
      input = input.substr(start, end - start + 1);
      return input;
   }
}