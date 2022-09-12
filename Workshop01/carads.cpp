#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include "carads.h"

 double g_taxrate = 0;
 double g_discount = 0;
using namespace std;
namespace sdds {
	// global function that lists out arguments
	void listArgs(int argc, char* argv[]) {
		cout << "Command Line:" << endl;
		cout << "--------------------------" << endl;
		for (int i = 0; i < argc; ++i) {
			cout << i << ": " << argv[i] << endl;
		}
		cout << "--------------------------" << endl;
	}

	int counter = 0;

	Cars::Cars() {
		m_make = nullptr;
		m_makelen = 0;
		m_model = nullptr;
		m_modellen = 0;
		m_year = 0;
		m_price = -1;
		m_condition = 'z';
		m_discount = false;
	};

	Cars::Cars(std::string make, std::string model, int year, double price, char condition, bool discount) {
		this->m_makelen = make.length();
		this->m_make = new char[make.length()];
		strcpy(this->m_make, make.c_str());
		this->m_modellen = model.length();
		this->m_model = new char[model.length()];
		strcpy(this->m_model, model.c_str());
		this->m_year = year;
		this->m_price = price;
		this->m_condition = condition;
		this->m_discount = discount;
	}

	Cars::~Cars() {
		delete[] m_make;
		delete[] m_model;
	}

	Cars::Cars(const Cars& src) {
		if (&src != this)
		{
			if (this->m_make != nullptr)
			{
				delete[] this->m_make;
				this->m_make = nullptr;
			}
			if (this->m_model != nullptr)
			{
				delete[] this->m_model;
				this->m_model = nullptr;
			}
			this->m_makelen = src.m_makelen;
			this->m_make = new char[m_makelen];
			strcpy(this->m_make, src.m_make);
			this->m_modellen = src.m_modellen;
			this->m_model = new char[m_modellen];
			strcpy(this->m_model, src.m_model);
			this->m_year = src.m_year;
			this->m_price = src.m_price;
			this->m_condition = src.m_condition;
			this->m_discount = src.m_discount;
		}
	}

	Cars& Cars::operator=(const Cars& rhs) {
		if (&rhs != this)
		{
			if (this->m_make != nullptr)
			{
				delete[] this->m_make;
				this->m_make = nullptr;
			}
			if (this->m_model != nullptr)
			{
				delete[] this->m_model;
				this->m_model = nullptr;
			}
			this->m_makelen = rhs.m_makelen;
			this->m_make = new char[m_makelen];
			strcpy(this->m_make, rhs.m_make);
			this->m_modellen = rhs.m_modellen;
			this->m_model = new char[m_modellen];
			strcpy(this->m_model, rhs.m_model);
			this->m_year = rhs.m_year;
			this->m_price = rhs.m_price;
			this->m_condition = rhs.m_condition;
			this->m_discount = rhs.m_discount;
		}
		return *this;
	}

	int Cars::read(istream& is) {
		// std::string make, std::string model, int year, double price, char condition, bool discount)
		char condition;
		string make;
		string model;
		string year;
		string price;
		string discount;

		if (is.good()) {
			// read the line
			string line = "";
			getline(is, line, ',');
			condition = line.c_str()[0];
			getline(is, make, ',');
			getline(is, model, ',');
			getline(is, year, ',');
			getline(is, price, ',');
			getline(is, discount, '\n');

			if (this->m_make != nullptr)
			{
				delete[] this->m_make;
			}
			if (this->m_model != nullptr)
			{
				delete[] this->m_model;
			}
			this->m_condition = condition;
			this->m_makelen = make.length();
			this->m_make = new char[m_makelen];
			strcpy(this->m_make, make.c_str());
			this->m_modellen = model.length();
			this->m_model = new char[m_modellen];
			strcpy(this->m_model, model.c_str());
			this->m_year = atoi(year.c_str());
			this->m_price = atof(price.c_str());
			this->m_discount = discount.c_str()[0];
			return 1;
		}
	};



	int Cars::display(bool reset) {
		if (m_price != -1)
		{
			if (reset)
			{
				counter = 0;
			}
			counter++;
			cout << setw(2) << left << counter << '. ';
			cout << setw(10) << left << m_make << '| '
				<< setw(15) << left << m_model << '| '
				<< m_year << '| '
				<< setw(12) << fixed << setprecision(2) << right << (m_price * g_taxrate) + m_price;
			if (m_discount)
			{
				double off_ticket = (m_price * g_discount);
				cout << setw(12) << right << ((m_price - off_ticket) * g_taxrate) + (m_price - off_ticket) << endl;
			}
			else
			{
				cout << endl;
			}
			return 1;
		}
		else
		{
			cout << setw(2) << left << counter << '.' << "No Car" << endl;
			return 0;
		}
	}

	char Cars::getStatus() {
		return m_condition;
	}
}