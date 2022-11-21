// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion:11/20/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_CUSTOM_ORDER_H
#define SDDS_CUSTOM_ORDER_H

#include <string>
#include "Station.h"

namespace sdds {

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder
	{
	private:
		std::string m_name; // customer name
		std::string m_product; // product name
		size_t m_cntItem; // current size of array
		Item** m_lstItem; // array of dynamically allocated items
		size_t m_maxsize; // max size of array

		static size_t m_widthField;

	public:
		CustomerOrder();
		CustomerOrder(const std::string& order);
		CustomerOrder(CustomerOrder& other);
		CustomerOrder& operator= (CustomerOrder& other) = delete;

		CustomerOrder(CustomerOrder&& other) noexcept;
		CustomerOrder& operator= (CustomerOrder&& other) noexcept;
		~CustomerOrder();

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;

		void resize();
	};
}
#endif