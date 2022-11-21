// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 8, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include "Luxuryvan.h"

namespace sdds {
	using namespace std;

	Luxuryvan::Luxuryvan(istream& is) : Van(is) {
		is.clear();
		is.seekg(0);
		if (Van::topSpeed() != 0)
		{
			string electric{};
			for (size_t i = 0; i < 6; i++)
			{
				getline(is, electric, ',');
			}
			getline(is, electric);
			if (trim(electric) == "e" || trim(electric) == "E")
			{
				this->m_consumption = "electric";
			}
			else if(trim(electric) == "g" || trim(electric) == "G")
			{
				throw invalid_argument("Invalid record!");
				this->m_consumption = "";
			}
		}
		else
		{
			this->m_consumption = "";
		}
	}

	void Luxuryvan::display(ostream& os) const {
		if (this->consumption() == "electric")
		{
			Van::display(os);
			os << " electric van  *";
		}
	}

	string Luxuryvan::consumption() const {
		return this->m_consumption;
	}
}
