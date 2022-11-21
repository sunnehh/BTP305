#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool sinChecker(const std::string& SIN) {
			int total = 0;
			size_t sin_length = SIN.length();
			for (size_t i = 0; i < sin_length; i++)
			{
				int curr_digit = SIN[i] - '0'; // get each digit
				int factor = (i % 2 + 1);
				int product = factor * curr_digit; // multiply by 1 2 1 2 1 2 etc;
				if (product >= 10)
				{
					total += (product % 10 + product / 10 % 10);
				}
				else{
					total += product;
				}
			}
			return (total%10 == 0);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator +=(T* item) {
			list.push_back(*item);
			delete item;
		}

		void operator +=(std::unique_ptr<T>& item) {
			list.push_back(std::move(*item));
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
