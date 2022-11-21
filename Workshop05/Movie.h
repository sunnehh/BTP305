/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H

#include <string>
#include <iostream>
namespace sdds {
	class Movie
	{

	private:
		std::string m_title;
		int m_year;
		std::string m_description;

	public:
		Movie();
		Movie(const std::string& strMovie); // TITLE,YEAR,DESCRIPTION
		~Movie()=default;

		const std::string& title() const;

		std::ostream& display(std::ostream& os) const;

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& os, const Movie& movie);
	};
	
	std::string& trimm(std::string& input);
}
#endif // !SDDS_MOVIE_H
