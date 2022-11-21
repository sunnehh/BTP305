/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19

Notes:
Learned about 
	- search/replace
	- Functor (a class with an overloaded () operator, so the class can be called like a function)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include "SpellChecker.h"

namespace sdds {
	using namespace std;
	SpellChecker::SpellChecker() : m_badWords{}, m_goodWords{}, stats{} {};

	SpellChecker::SpellChecker(const char* filename) {
		for (int i = 0; i < SIZE; i++)
		{
			m_badWords[i] = nullptr;
			m_goodWords[i] = nullptr;
			stats[i] = 0;
		}
		fstream in;
		in.open(filename);
		if (!in.is_open())
		{
			string error = "Bad file name!";
			throw error;
		}
		else
		{
			string currentline = "";
			int totalWords = 0;
			while (getline(in, currentline))
			{
				stringstream ss(currentline);
				string goodword;
				string badword;
				getline(ss, badword, ' ');
				while (ss.peek() == ' ')
				{
					ss.get();
				}
				getline(ss, goodword);
				m_badWords[totalWords] = new char[badword.length() + 1];
				m_goodWords[totalWords] = new char[goodword.length() + 1];
				strcpy(m_badWords[totalWords], badword.c_str());
				strcpy(m_goodWords[totalWords], goodword.c_str());
				totalWords++;
			}
		}
	}
	void SpellChecker::showStatistics(ostream& out) const {
		out << "Spellchecker Statistics" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			out << setw(15) << right << m_badWords[i];
			out << ": ";
			out << stats[i] << " replacements" << endl;
		}
	}

	void SpellChecker::operator()(string& text) {
		for (int i = 0; i < SIZE; i++)
		{
			string badword = m_badWords[i];
			string goodword = m_goodWords[i];
			size_t length = strlen(m_badWords[i]);
			while (text.find(badword) != string::npos) {
				text.replace(text.find(badword), length, goodword);
				stats[i]++;
			}
		}
		
	}

	SpellChecker::~SpellChecker() {
		for (auto i = 0; i < SIZE; i++)
		{
			if (m_badWords[i] != nullptr)
				delete[] m_badWords[i];
			if (m_goodWords[i] != nullptr)
				delete[] m_goodWords[i];
		}
	}
}