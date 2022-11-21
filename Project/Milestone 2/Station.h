// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion:11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>
#include <iostream>

namespace sdds {

	class Station
	{
	private:
		int m_station_id;
		std::string m_station_item;
		std::string m_station_descript;
		unsigned int m_serial_no;
		unsigned int m_current_stock;

		static size_t m_widthField;
		static int id_generator;

	public:
		Station(const std::string& record);

		// getters & setters
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;

	};

}

#endif