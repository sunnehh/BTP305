// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion:11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>

namespace sdds {
	class Utilities
	{
	private:
		size_t m_widthField;
		static char m_delimiter;

	public:
		Utilities();

		// getters and setters
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;

		// uses m_delimiter to extract the next token starting at next_pos.
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	};

	std::string& trim(std::string& input);
	bool isNumber(std::string& input);
}
#endif
