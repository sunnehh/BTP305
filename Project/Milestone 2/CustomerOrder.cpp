// Name: Sunny Qi
// Seneca Student ID: 136570207
// Seneca email: sqi9@myseneca.ca
// Date of completion:11/20/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;
namespace sdds {

	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder() {
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
		m_maxsize = 0;
	}

	CustomerOrder::CustomerOrder(const string& order) {
		string name;
		string product;
		Utilities a;
		size_t pos = 0;
		m_maxsize = 1;
		m_cntItem = 0;
		bool more = true;
		name = a.extractToken(order, pos, more);
		product = a.extractToken(order, pos, more);
		while (more)
		{
			string itemname;
			itemname = a.extractToken(order, pos, more);
			if (m_cntItem >= m_maxsize)
			{
				resize();
			}
			else if (m_cntItem == 0)
			{
				m_lstItem = new Item*[m_maxsize];
			}
			m_lstItem[m_cntItem] = new Item(itemname);
			m_cntItem++;
		}
		m_name = name;
		m_product = product;
		if (a.getFieldWidth() > m_widthField)
		{
			m_widthField = a.getFieldWidth();
		}
	}

	CustomerOrder::CustomerOrder(CustomerOrder& other) {
		throw invalid_argument("Copy is not allowed");
	}

	CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
		// steal other's data
		this->m_cntItem = move(other.m_cntItem);
		this->m_maxsize = move(other.m_maxsize);
		this->m_name = move(other.m_name);
		this->m_product = move(other.m_product);
		this->m_lstItem = new Item * [m_maxsize];
		for (size_t i = 0; i < m_cntItem; i++)
		{
			this->m_lstItem[i] = other.m_lstItem[i];
			other.m_lstItem[i] = nullptr;
		}
		// set other to safe state


	}

	CustomerOrder& CustomerOrder::operator= (CustomerOrder&& other) noexcept {
		// self assignment check
		if (this != &other)
		{
			// delete my current data;
			delete[] m_lstItem;
			// steal other's data;
			this->m_cntItem = move(other.m_cntItem);
			this->m_maxsize = move(other.m_maxsize);
			this->m_name = move(other.m_name);
			this->m_product = move(other.m_product);
			this->m_lstItem = new Item * [m_maxsize];
			for (size_t i = 0; i < m_cntItem; i++)
			{
				this->m_lstItem[i] = other.m_lstItem[i];
				other.m_lstItem[i] = nullptr;
			}
		}
		return *this;
	}

	void CustomerOrder::resize() {
		size_t newmaxsize = (m_maxsize * 2) + 1;
		Item** lstItem = new Item* [newmaxsize];
		for (size_t i = 0; i < m_maxsize; i++)
		{
			lstItem[i] = m_lstItem[i];
		}
		delete[] m_lstItem;
		m_maxsize = newmaxsize;
		m_lstItem = lstItem;
	}

	void CustomerOrder::display(ostream& os) const {
		os << m_name << " - " << m_product << endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "]";
			os << " " << setw(m_widthField) << setfill(' ') << left << m_lstItem[i]->m_itemName << "   - ";
			if (m_lstItem[i]->m_isFilled)
			{
				os << "FULFILLED";
			}
			else
			{
				os << "TO BE FILLED";
			}
			os << endl;
		}
	}


	bool CustomerOrder::isOrderFilled() const {
		size_t cnt_filled = 0;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled)
			{
				cnt_filled++;
			}
		}
		return cnt_filled == m_cntItem;
	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const {
		int found = 0;
		int foundfilled = 0;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (itemName == m_lstItem[i]->m_itemName)
			{
				found++;
			}
			if (m_lstItem[i]->m_isFilled)
			{
				foundfilled++;
			}
		}
		return foundfilled == found;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os) {
		bool isfilled = false;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (station.getItemName() == m_lstItem[i]->m_itemName)
			{
				if (station.getQuantity() > 0)
				{
					if (!m_lstItem[i]->m_isFilled && !isfilled)
					{
						m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
						m_lstItem[i]->m_isFilled = true;
						isfilled = true;
						station.updateQuantity();
						os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
					}

				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
				}
			}
		}

	}

	CustomerOrder::~CustomerOrder() {
		if (m_lstItem != nullptr)
		{
			delete[] m_lstItem;
		}
	}
}

