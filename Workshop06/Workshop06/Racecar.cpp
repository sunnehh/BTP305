// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 8, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <sstream>
#include "Racecar.h"

namespace sdds {
	using namespace std;

	Racecar::Racecar(istream& is) : Car(is){
		is.clear();
		is.seekg(0);
		if (Car::topSpeed() != 0)
		{
			string booster{};
			for (size_t i = 0; i < 4; i++)
			{
				getline(is, booster, ',');
			}
			getline(is, booster);
			this->m_booster = atof(trimm(booster).c_str());
		}
		else
		{
			this->m_booster = 0;
		}
	}

	void Racecar::display(ostream& os) const {
		Car::display(os);
		os << '*';
	}

	double Racecar::topSpeed() const {
		return (Car::topSpeed() * m_booster) + Car::topSpeed();
	}
}


