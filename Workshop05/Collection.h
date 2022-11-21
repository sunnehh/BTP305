/*
Workshop 05 - Sunny Qi
sqi9@myseneca.ca

Completed: 22-10-19
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>
#include <stdexcept>

namespace sdds {

	template <typename T>
	class Collection
	{
	private:
		std::string m_name;
		T* m_collection;
		size_t m_size;
		size_t m_last_index;
		void (*callback)(const Collection<T>& col, const T& type);
	public:
		Collection();
		Collection(const std::string& name);
		Collection(const Collection& other) = delete;
		Collection(const Collection&& other) = delete;
		Collection& operator=(const Collection& other) = delete;
		Collection& operator=(Collection&& other) = delete;

		const std::string& name() const;

		size_t size() const;

		void setObserver(void (*observer)(const Collection<T>&, const T&));
		Collection<T>& operator+=(const T& item);
		T& operator[](size_t idx) const;
		T* operator[](const std::string& title) const;


		~Collection();
	};

	template <typename T>
	Collection<T>::Collection() : m_name{}, m_collection{}, m_size{}, callback{} {}

	template <typename T>
	Collection<T>::Collection(const std::string& name) : m_collection{}, m_size{}, callback{} {
		m_name = name;
	}

	template <typename T>
	Collection<T>::~Collection() {
		if (m_collection != nullptr)
		{
			delete[] m_collection;
		}
	}

	template <typename T>
	size_t Collection<T>::size() const{
		return m_size;
	}

	template <typename T>
	const std::string& Collection<T>::name() const{
		return m_name;
	}

	template <typename T>
	void Collection<T>::setObserver(void (*observer)(const Collection<T>&, const T&)) {
		callback = observer;
	}

	template<typename T>
	T& Collection<T>::operator[](size_t idx) const {
		if (idx >= m_last_index)
		{
			std::string message = "Bad index [";
			message += std::to_string(idx);
			message += "]. Collection has [";
			message += std::to_string(m_last_index);
			message += "] items.";
			throw std::out_of_range(message);
		}
		else
		{
			return m_collection[idx];
		}
	}

	template<typename T>
	T* Collection<T>::operator[](const std::string& title)const {
		for (size_t i = 0; i < m_size; i++)
		{
			if (m_collection[i].title() == title) {
				return &m_collection[i];
			}
		}
		return nullptr;
	}

	template<typename T>
	Collection<T>& Collection<T>::operator+=(const T& item) {
		bool dupe = false;
		bool found_empty = false;
		size_t empty_index = -1;
		T* resizedCollection = nullptr;
		for (size_t i = 0; i < m_size && !dupe; i++)
		{
			if (item.title().compare(m_collection[i].title()) == 0)
				dupe = true;
			if (m_collection[i].title().compare("") == 0 && !found_empty)
			{
				empty_index = i;
				found_empty = true;
				m_last_index = empty_index;
			}
		}
		if (!dupe)
		{
			if (found_empty)
			{
				if (empty_index < m_size) {
					m_collection[empty_index] = item;
				}
			}
			else // resize
			{
				resizedCollection = new T[m_size + 1];
				for (size_t i = 0; i < m_size; i++)
				{
					resizedCollection[i] = m_collection[i];
				}
				delete[] m_collection;
				m_collection = resizedCollection;
				m_collection[m_size] = item;
				m_size += 1;
				m_last_index = m_size;
			}
			if (this->callback != nullptr)
			{
				callback(*this, item);
			}
		}
		return *this;
	}

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		for (size_t i = 0; i < col.size(); i++)
		{
			if (col[i].title().compare("") != 0)
			{
				os << col[i];
			}
			
		}
		return os;
	}

}
#endif // !SDDS_COLLECTION_H
