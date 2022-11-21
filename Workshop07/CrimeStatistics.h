// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 12, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#ifndef SDDS_CRIME_STATISTICS_H
#define SDDS_CRIME_STATISTICS_H

#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <iostream>

namespace sdds {
	struct Crime
	{
		std::string province;
		std::string district;
		std::string crime;
		int year;
		int num_cases;
		int m_resolved;
	};

	class CrimeStatistics
	{
	private:
		std::vector<Crime> crimes;

	public:
		CrimeStatistics(std::string filename);
		void display(std::ostream& out) const;

		void sort(const std::string filter);
		bool inCollection(const std::string crime) const;
		std::vector<Crime>getListForProvince(const std::string province)const;
		void cleanList();

		std::string& trim(std::string& input);
	};

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}

#endif




