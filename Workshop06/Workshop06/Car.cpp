// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 8, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iomanip>
#include <stdexcept>
#include "Car.h"

namespace sdds {
	using namespace std;

	static char VALID_CONDITION[]{ 'n', 'u', 'b' };

	Car::Car() {
		this->m_maker = "";
		this->m_condition = 0;
		this->m_top_speed = 0;

	}

	Car::Car(istream& is) {
		string tag{};
		string maker{};
		string condition{};
		string top_speed{};

		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, condition, ',');
		tag = trimm(tag);
		getline(is, top_speed, ',');


		if ((tag.c_str()[0] == 'c' || tag.c_str()[0] == 'C' || tag.c_str()[0] == 'r' || tag.c_str()[0] == 'R') &&
			isNumber(trimm(top_speed)) &&
			validCondition((trimm(condition)).c_str()[0])
			)
		{
			this->m_maker = trimm(maker);
			if (condition == "" || condition == " ")
			{
				this->m_condition = 'n';
			}
			else
			{
				this->m_condition = trimm(condition).c_str()[0];
			}
			this->m_top_speed = stof(trimm(top_speed));
		}
		else
		{
			throw invalid_argument("Invalid record!");
			this->m_maker = "";
			this->m_condition = 0;
			this->m_top_speed = 0;
		}
	}
	

	double Car::topSpeed() const {
		return m_top_speed;
	};

	void Car::display(std::ostream& os) const {
		os << "| "
			<< setw(10) << right << m_maker
			<< " | "
			<< setw(6) << left << this->condition()
			<< " | "
			<< setw(6) << setprecision(2) << fixed << this->topSpeed() << " |";
	};

	std::string Car::condition() const {
		string condition = "";
		if (m_condition == 'n')
		{
			condition = "new";
		}
		else if (m_condition == 'u')
		{
			condition = "used";
		}
		else if (m_condition == 'b')
		{
			condition = "broken";
		}
		return condition;
	};

	bool Car::validCondition(const char condition) {
		bool found = false;
		if (condition == 0 || condition == ' ')
		{
			found = true;
		}
		for (size_t i = 0; (i < sizeof(VALID_CONDITION) / sizeof(*VALID_CONDITION) && !found); i++)
		{
			if (condition == VALID_CONDITION[i])
				found = true;
		}
		return found;
	}

	bool Car::isNumber(std::string& input) {
		bool valid = false;
		// iterate over the string
		std::string::const_iterator it = input.begin();
		// check char by char whether the value is a digit
		while (it != input.end() && (std::isdigit(*it) || ((*it == '.') && (*(it - 1) != '.'))))
		{
			it++;
		}
		// if the iterator makes it to the end of the string, it's a number
		valid = (!input.empty() && it == input.end());
		return valid;
	}

	std::string& trimm(std::string& input) {
		if (input != "" && input != " ")
		{
			std::string WHITESPACE = " \n\r\t\f\v";
			size_t start = input.find_first_not_of(WHITESPACE);
			size_t end = input.find_last_not_of(WHITESPACE);
			input = input.substr(start, end - start + 1);
		}
		return input;
	}
}
