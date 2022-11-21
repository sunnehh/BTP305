// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 12, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <fstream>
#include <iomanip>
#include <stdexcept>
#include <sstream>
#include "CrimeStatistics.h"

using namespace std;
namespace sdds {

	CrimeStatistics::CrimeStatistics(string filename) {
		std::ifstream fs(filename);
		if (!fs)
		{
			throw invalid_argument("ERROR: Cannot open file[" + filename + "].\n");
		}
		else
		{
			while (fs) {
				string currentline = "";
				getline(fs, currentline, '\n');

				// parse the line
				if (currentline != "")
				{
					stringstream ss(currentline);
					char province[26] = "";
					char district[26] = "";
					char crime[26] = "";
					char numcases[6] = "";
					char year[6] = "";
					char m_resolved[6] = "";
					ss.read(province, 25);
					ss.read(district, 25);
					ss.read(crime, 25);
					ss.read(numcases, 5);
					ss.read(year, 5);
					ss.read(m_resolved, 5);
					string p(province);
					string d(district);
					string c(crime);
					string n(numcases);
					string y(year);
					string nr(m_resolved);
					p = trim(p);
					d = trim(d);
					c = trim(c);
					n = trim(n);
					y = trim(y);
					nr = trim(nr);
					Crime newcrime({ p, d, c, stoi(n), stoi(y), stoi(nr) });
					crimes.push_back(newcrime);
				}
			}
		}
	}

	void CrimeStatistics::display(ostream& os) const {
		int totalcrimes = 0;
		int totalresolvedcrimes = 0;
		std::for_each(crimes.begin(), crimes.end(), [&](Crime thecrime) {
			os << thecrime << endl;
			totalcrimes += thecrime.num_cases;
			totalresolvedcrimes += thecrime.m_resolved;
			});
		os << "----------------------------------------------------------------------------------------" << endl;
		os << "|" << setw(78) << right << "Total Crimes:" << setw(7) <<totalcrimes << " |" <<endl;
		os << "|" << setw(78) << right << "Total Resolved Cases:" << setw(7) << totalresolvedcrimes << " |" << endl;
	}

	void CrimeStatistics::cleanList() {
		std::for_each(crimes.begin(), crimes.end(),
			[&](Crime& thecrime) {
				if (thecrime.crime == "[None]") {
					thecrime.crime = "";
				}
			}
		);
	}
	
	bool CrimeStatistics::inCollection(string crime) const {
		bool found = false;
		std::for_each(crimes.begin(), crimes.end(),
			[&found, crime](Crime thecrime) {
				if (thecrime.crime == crime)
				{
					found = true;
				}
			}
		);
		return found;
	}

	vector<Crime>CrimeStatistics::getListForProvince(const std::string province) const {
		vector<Crime> mylist;

		std::for_each(crimes.begin(), crimes.end(), [&](Crime thecrime) {
			if (thecrime.province == province)
			{
				mylist.push_back(thecrime);
			}
			});
		return mylist;
	}

	void sdds::CrimeStatistics::sort(string filter) {
		if (filter == "Province")
		{
			std::sort(crimes.begin(), crimes.end(), [](Crime crime1, Crime crime2){
				return crime1.province < crime2.province;
				});
		}

		if (filter == "Crime")
		{
			std::sort(crimes.begin(), crimes.end(), [](Crime crime1, Crime crime2) {
				return crime1.crime < crime2.crime;
				});
		}

		if (filter == "Cases")
		{
			std::sort(crimes.begin(), crimes.end(), [](Crime crime1, Crime crime2) {
				return crime1.num_cases < crime2.num_cases;
				});
		}

		if (filter == "Resolved")
		{
			std::sort(crimes.begin(), crimes.end(), [](Crime crime1, Crime crime2) {
				return crime1.m_resolved < crime2.m_resolved;
				});
		}
	}

	std::string& CrimeStatistics::trim(std::string& input) {
		if (input != "")
		{
			std::string WHITESPACE = " \n\r\t\f\v";
			size_t start = input.find_first_not_of(WHITESPACE);
			size_t end = input.find_last_not_of(WHITESPACE);
			input = input.substr(start, end - start + 1);
		}
		return input;
	}

	std::ostream& operator<<(std::ostream& os, const Crime& theCrime) {
		os << "| " << setw(21) << left << theCrime.province
			<< " | " << setw(15) << left << theCrime.district
			<< " | " << setw(20) << left << theCrime.crime
			<< " | " << right <<setw(6)<< theCrime.year
			<< " | " << setw(4) << theCrime.num_cases
			<< " | " << setw(3) << theCrime.m_resolved
			<< " |";
		return os;
	}
}

