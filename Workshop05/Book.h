/* 
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/


#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>
#include <iostream>
namespace sdds {
	class Book
	{
	private:
		std::string m_author;
		std::string m_title;
		std::string m_pub_country;
		size_t m_pub_year;
		double m_price;
		std::string m_description;
	public:
		Book();
		Book(const std::string& strBook); // AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION

		~Book();

		// accessors
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;

		std::ostream& display(std::ostream& os) const;

		// members
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& book);
		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_description);
		}
	};
	std::string& trimb(std::string& input);
}

#endif