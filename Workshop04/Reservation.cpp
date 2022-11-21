#define _CRT_SECURE_NO_WARNINGS
#include <sstream>
#include <iomanip>
#include "Reservation.h"

namespace sdds {
	using namespace std;
	Reservation::Reservation() :
		m_reservation_id{nullptr}, 
		m_name{},
		m_email{},
		m_num_people{},
		m_day{},
		m_hour{}
	{}

	Reservation::Reservation(const std::string& res) {
		// ID:NAME,EMAIL,PARTY_SIZE,DAY,HOUR
		std::string tokens[6]{};
		// split input into tokens
		std::stringstream mystream(res);
		std::getline(mystream, tokens[0], ':');
		std::getline(mystream, tokens[1], ',');
		std::getline(mystream, tokens[2], ',');
		std::getline(mystream, tokens[3], ',');
		std::getline(mystream, tokens[4], ',');
		std::getline(mystream, tokens[5], ',');
		// res id
		m_reservation_id = new char[tokens[0].length() + 1];
		std::strcpy(m_reservation_id, trim(tokens[0]).c_str());
		// name, email, people, day, hour
		m_name = trim(tokens[1]);
		m_email = trim(tokens[2]);
		m_num_people = stoi(trim(tokens[3]));
		m_day = stoi(trim(tokens[4]));
		m_hour = stoi(trim(tokens[5]));

	}

	Reservation::~Reservation() {
		if (m_reservation_id != nullptr)
		{
			delete[] m_reservation_id;
		}
	}

	void Reservation::update(int day, int time) {
		m_day = day;
		m_hour = time;
	}

	std::string& trim(std::string& input) {
		std::string WHITESPACE = " \n\r\t\f\v";
		size_t start = input.find_first_not_of(WHITESPACE);
		size_t end = input.find_last_not_of(WHITESPACE);
		input = input.substr(start, end - start + 1);
		return input;
	}

	std::ostream& Reservation::Display(std::ostream& os) const{
		os << "Reservation" << setw(11) << right << m_reservation_id;
		os << ": " << setw(20) << right << m_name
			<< "  <" << setw(23) << left << m_email + ">";
		if (m_hour >= 6 && m_hour <= 9 )
		{ //bfast
			os << "Breakfast ";
		}
		else if (m_hour >= 11 && m_hour <= 15) 
		{// lunch
			os << "Lunch ";
		}
		else if (m_hour >= 17 && m_hour <= 21)
		{//dinner
			os << "Dinner ";
		}
		else
		{
			// drinks
			os << "Drinks ";
		}
		os << "on day " << m_day << " @ " << m_hour << ":00 for "
			<< m_num_people;
		if (m_num_people > 1)
		{
			os << " people";
		}
		else {
			os << " person";
		}

		return os;
	}
}

using namespace sdds;
using namespace std;
int main() {
	Reservation myres("RES-001:sun,sun@email,6,23,15");
	myres.Display(cout);
	
}