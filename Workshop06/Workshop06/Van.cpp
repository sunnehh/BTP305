// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 8, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <iomanip>
#include <stdexcept>
#include "Van.h"

namespace sdds {
	using namespace std;

	static char VALID_PURPOSE[]{ 'd', 'p', 'c' };
	static char VALID_TYPE[]{ 'p', 'm', 'c' };
	static char VALID_CONDITION[]{ 'n', 'u', 'b' };

	Van::Van() {
		this->m_maker = "";
		this->m_condition = 0;
		this->m_purpose = 0;
		this->m_top_speed = 0;
		this->m_type = 0;
	}



	Van::Van(istream& is) {
		string tag{};
		string maker{};
		string type{};
		string purpose{};
		string condition{};
		string top_speed{};

		getline(is, tag, ',');
		getline(is, maker, ',');
		getline(is, type, ',');
		getline(is, purpose, ',');
		getline(is, condition, ',');
		getline(is, top_speed, ',');

		if ( 
			isNumber(trim(top_speed)) &&
			validPurpose(trim(purpose).c_str()[0]) && 
			validType(trim(type).c_str()[0]) &&
			validCondition((trim(condition)).c_str()[0])
			)
		{
			this->m_maker = trim(maker);
			this->m_type = trim(type).c_str()[0];
			this->m_purpose = trim(purpose).c_str()[0];
			if (condition == "" || condition == " ")
			{
				this->m_condition = 'n';
			}
			else
			{
				this->m_condition = trim(condition).c_str()[0];
			}
			this->m_top_speed = stof(trim(top_speed));
		}
		else
		{
			throw invalid_argument("Invalid record!");
			this->m_maker = "";
			this->m_condition = 0;
			this->m_purpose = 0;
			this->m_top_speed = 0;
			this->m_type = 0;
		}
	}

	bool Van::validPurpose(const char purpose) {
		bool found = false;
		for (size_t i = 0; i < sizeof(VALID_PURPOSE)/sizeof(*VALID_PURPOSE); i++)
		{
			if (purpose == VALID_PURPOSE[i])
				found = true;
		}
		return found;
	}

	bool Van::validType(const char type) {
		bool found = false;
		for (size_t i = 0; i < sizeof(VALID_TYPE) / sizeof(*VALID_TYPE); i++)
		{
			if (type == VALID_TYPE[i])
				found = true;
		}
		return found;
	}

	bool Van::validCondition(const char condition) {
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

	double Van::topSpeed() const {
		return m_top_speed;
	};

	void Van::display(std::ostream& os) const {
		os << "| "
			<< setw(8) << right << m_maker
			<< " | "
			<< setw(12) << left << this->type()
			<< " | "
			<< setw(12) << left << this->usage()
			<< " | "
			<< setw(6) << left << this->condition()
			<< " | "
			<< setw(6) << setprecision(2) << fixed << m_top_speed << " |";

	};

	std::string Van::condition() const {
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

	string Van::type()const {
		string type = "";
		if (m_type == 'p')
		{
			type = "pickup";
		}
		else if (m_type == 'm') {
			type = "mini-bus";
		}
		else if (m_type == 'c')
		{
			type = "camper";
		}
		return type;
	}

	string Van::usage()const {
		string usage = "";
		if (m_purpose == 'd')
		{
			usage = "delivery";
		}
		else if (m_purpose == 'p') {
			usage = "passenger";
		}
		else if (m_purpose == 'c')
		{
			usage = "camping";
		}
		return usage;
	}

	std::string& trim(std::string& input) {
		if (input != "")
		{
			std::string WHITESPACE = " \n\r\t\f\v";
			size_t start = input.find_first_not_of(WHITESPACE);
			size_t end = input.find_last_not_of(WHITESPACE);
			input = input.substr(start, end - start + 1);
		}
		return input;
	}

	bool Van::isNumber(std::string& input) {
		// iterate over the string
		std::string::const_iterator it = input.begin();
		// check char by char whether the value is a digit
		while (it != input.end() && (std::isdigit(*it) || ((*it == '.') && (*(it-1) != '.') )))
		{
			it++;
		}
		// if the iterator makes it to the end of the string, it's a number
		return (!input.empty() && it == input.end());
	}
}
