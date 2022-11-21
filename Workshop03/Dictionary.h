// Workshop03
// Sunny Qi - 2022/09/27
#ifndef SDDS_DICTIONARY_H
#define SDDS_DICTIONARY_H
#include <iostream>
#include <string>

namespace sdds {
	class Dictionary
	{
		std::string m_term{};
		std::string m_definition{};
	public:
		const std::string& getTerm() const { return m_term; }
		const std::string& getDefinition() const { return m_definition; }
		Dictionary(const std::string& term, const std::string& definition) : m_term{ term }, m_definition{ definition } {}
		std::ostream& display(std::ostream& os) const;
		
		// TODO: Code the missing prototype functions and operators
		//       that the class needs in order to work with the Queue class.
		//       Implement them in the Dictionary.cpp file.
		Dictionary();
		~Dictionary();
		// need copy and assignment operators
		Dictionary& operator=(const Dictionary& other);
		Dictionary(const Dictionary& other);
		friend std::ostream& operator<<(std::ostream& os, const Dictionary& dictionary);
		friend bool operator==(const Dictionary& lhs, const Dictionary& rhs);
	};
	

}

#endif // !SDDS_DICTIONARY_H



