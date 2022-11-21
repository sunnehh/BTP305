// Workshop03
// Sunny Qi - 2022/09/27

#include <iomanip>
#include "Dictionary.h"
#include "Queue.h"

namespace sdds {
	using namespace std;


	ostream& Dictionary::display(ostream& os) const{
		os << setw(20) << right << m_term << ": ";
		os << m_definition;
		return os;
	}


	ostream& operator<<(ostream& os, const Dictionary& dictionary) {
		dictionary.display(os);
		return os;
	}

	Dictionary::Dictionary() {
		m_term = "";
		m_definition = "";
	}

	Dictionary::~Dictionary() {
	}

	bool operator==(const Dictionary& lhs, const Dictionary& rhs) {
		bool issame = false;
		if (
			((lhs.getTerm() == rhs.getTerm()) && (lhs.getDefinition() == rhs.getDefinition())) 
			|| (((rhs.getTerm() == "Empty Term") && (lhs.getTerm() == "")))
			)
		{
			issame = true;
		}
		return issame;
	}

	Dictionary::Dictionary(const Dictionary& other) : m_term{ other.m_term }, m_definition{ other.m_definition } {
	}

	Dictionary& Dictionary::operator=(const Dictionary& other) {
		m_term = other.m_term;
		m_definition = other.m_definition;
		return *this;
	}
}