/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#define SIZE 6

#include <iostream>



namespace sdds {
	class SpellChecker
	{
	private:
		char* m_badWords[SIZE];
		char* m_goodWords[SIZE];
		int stats[SIZE];

	public:
		SpellChecker();
		SpellChecker(const char* filename);

		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;


		~SpellChecker();

	private:

	};

}
#endif // !SDDS_SPELLCHECKER_H
