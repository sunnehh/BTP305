// Sunny Qi, 136570207, sqi9@myseneca.ca
// Nov 8, 2022
// I have done all the coding by myself and only copied the code that my 
// professor provided to complete my workshops and assignments.

#include <string>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds {
	using namespace std;

	Vehicle* createInstance(istream& in) {
		Vehicle* newVehicle = nullptr;

		string firstchar = "";
		string line = "";
		getline(in, line);

		stringstream mystream(line);
		getline(mystream, firstchar, ',');
		mystream.seekg(0);
		firstchar = trim(firstchar);
		if (firstchar.c_str()[0] == 'c' || firstchar.c_str()[0] == 'C')
		{
			newVehicle = new Car(mystream);
		}
		else if (firstchar.c_str()[0] == 'v' || firstchar.c_str()[0] == 'V')
		{
			newVehicle = new Van(mystream);
		}
		else if (firstchar.c_str()[0] == 'r' || firstchar.c_str()[0] == 'R')
		{
			newVehicle = new Racecar(mystream);
		}
		else if (firstchar.c_str()[0] == 'l' || firstchar.c_str()[0] == 'L')
		{
			newVehicle = new Luxuryvan(mystream);
		}
		else
		{
			if (firstchar != "")
			{
				throw invalid_argument("Unrecognized record type: [" + firstchar + "]");
			}
		}
		return newVehicle;
	}
}