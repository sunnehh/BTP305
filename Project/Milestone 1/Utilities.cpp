// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion: 11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "Utilities.h"

namespace sdds {
	using namespace std;
	char Utilities::m_delimiter = '\0';

	/*
	*	Default Constructor. Initializes all values to a safe state
	*/
	Utilities::Utilities() {
		m_widthField = 1;
	}

	/*
	*	Set field width to the new width inputted
	*/
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}

	/*
	*	Get current field width
	*/
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	/*
	*	Set delimiter to the new delimiter inputted
	*/
	void Utilities::setDelimiter(char newDelimiter) {
		Utilities::m_delimiter = newDelimiter;
	}
	
	/*
	*	Get current delimiter
	*/
	char Utilities::getDelimiter() {
		return m_delimiter;
	}

	/*
	*	Using the delimiter, extract the next token 
	*	if successfully extracted, set more to true;
	*/
	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
		stringstream input(str);
		input.seekg(next_pos);
		string my_token;
		string next;
		char nextchar;
		input.get(nextchar);
		if (nextchar == m_delimiter) {
			more = false;
			throw std::invalid_argument("ERROR: No token.");
		}
		else
		{
			input.seekg(next_pos);
			getline(input, my_token, m_delimiter);
			next_pos = input.tellg();
			if (my_token != "" && (input.get() != EOF))
			{
				more = true;
			}
			else
			{
				more = false;
			}
			my_token = trim(my_token);
			if (my_token == "")
			{
				more = false;
			}
			else
			{
				m_widthField = max(m_widthField, my_token.length());
			}
			return my_token;
		}
	}

	/* Helper Function:
	*	Removes starting and trailing whitespace
	*/
	string& trim(string& input) {
		if (input != "")
		{
			std::string WHITESPACE = " \n\r\t\f\v";
			size_t start = input.find_first_not_of(WHITESPACE);
			size_t end = input.find_last_not_of(WHITESPACE);
			input = input.substr(start, end - start + 1);
		}
		return input;
	}

	/* Helper Function:
	*	Check whether input string is a number
	*/
	bool isNumber(string& input) {
		// iterate over the string
		std::string::const_iterator it = input.begin();
		// check char by char whether the value is a digit
		while (it != input.end() && (std::isdigit(*it) || ((*it == '.') && (*(it - 1) != '.'))))
		{
			it++;
		}
		// if the iterator makes it to the end of the string, it's a number
		return (!input.empty() && it == input.end());
	}
}
