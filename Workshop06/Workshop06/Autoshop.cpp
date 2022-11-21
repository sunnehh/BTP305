#include "Autoshop.h"

namespace sdds {
	using namespace std;

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {

		for (vector<Vehicle*>::const_iterator it = m_vehicles.begin();it != m_vehicles.end() ; it++)
		{
			(*it)->display(out);
			out << endl;
		}

	}

	Autoshop::~Autoshop() {
		for (vector<Vehicle*>::const_iterator it = m_vehicles.begin();it != m_vehicles.end(); it++)
		{
			delete *it;
		}
	}
}

