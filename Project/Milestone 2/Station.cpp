// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion:11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds{
	size_t Station::m_widthField = 1;
	int Station::id_generator = 1;

	Station::Station(const string& record) {
		string itemname;
		string serialno;
		string qoh;
		string descript;
		Utilities a;
		size_t pos = 0;
		bool more = true;
		itemname = a.extractToken(record, pos, more);
		serialno = a.extractToken(record, pos, more);
		qoh = a.extractToken(record, pos, more);
		Station::m_widthField = max(Station::m_widthField, a.getFieldWidth());
		descript = a.extractToken(record, pos, more);
		if (isNumber(qoh) && isNumber(serialno))
		{
			m_station_id = id_generator++;
			m_station_item = itemname;
			m_serial_no = stoi(serialno);
			m_current_stock = stoi(qoh);
			m_station_descript = descript;
		}
		else
		{
			throw "Invalid input file. QOH or Serial Number aren't numbers";
		}
	}

	const string& Station::getItemName()const {
		return m_station_item;
	}
	size_t Station::getNextSerialNumber() {
		return m_serial_no++;
	}
	size_t Station::getQuantity() const{
		return m_current_stock;
	}
	void Station::updateQuantity() {
		if (m_current_stock > 0)
		{
			m_current_stock -= 1;
		}
	}
	
	void Station::display(ostream& os, bool full) const {

		os << setfill('0') << setw(3) << right << m_station_id << " | "
			<< setfill(' ') << setw(m_widthField) << left << m_station_item << "  | "
			<< setw(6) << setfill('0') << right << m_serial_no << " | "
			<< setfill(' ');

		if (full)
		{
			// ID | NAME | SERIAL | QUANTITY | DESCRIPTION
			os << setw(4) << right << m_current_stock << " | "
				<< m_station_descript;
		}
		os << endl;
	}
}

