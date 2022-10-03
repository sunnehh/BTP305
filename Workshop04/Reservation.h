// Workshop 04
// sqi9@myseneca.ca 136570207
// Sunny Qi - 


#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {
	class Reservation
	{
	private:
		char* m_reservation_id;
		std::string m_name;
		std::string m_email;
		int m_num_people;
		int m_day;
		int m_hour;

	public:
		Reservation();
		Reservation(const std::string& res);
		~Reservation();
		void update(int day, int time);
		std::ostream& Display(std::ostream& os) const;
		friend std::ostream& operator<<(std::ostream&, const Reservation& res);

	};

	std::string& trim(std::string& input);
}
#endif // !SDDS_RESERVATION_H