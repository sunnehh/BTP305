// Workshop03
// Sunny Qi - 2022/09/27
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include <iostream>

namespace sdds {
	template <typename T, int capacity>
	class Queue
	{
	protected:
		static T dummy;
		T m_queue[capacity];
		int m_num_elements;
	public:
		Queue<T, capacity>() : m_queue {}, m_num_elements{ 0 } {
		};
		virtual ~Queue() {};

		// functions for ws
		virtual bool push(T item) {
			bool success = false;
			if (m_num_elements < capacity)
			{
				for (int i = 0; (i < capacity) && !success; ++i)
				{
					if (m_queue[i] == dummy) // note
					{
						m_queue[i] = item;
						success = true;
						m_num_elements++;
					}
				}
			}
			return success;
		};


		T pop() {
			T temp = this->m_queue[0];
			if (!(&m_queue[0] == nullptr))
			{
				for (int i = 1; i < m_num_elements; i++)
				{
					m_queue[i - 1] = m_queue[i];
				}
				m_queue[m_num_elements - 1] = dummy;
				m_num_elements--;
			}
			else
			{
				temp = dummy;
			}
			return temp;
		};
		int size() const {
			return this->m_num_elements;
		}

		std::ostream& display(std::ostream& os = std::cout) {
			os << "----------------------\n";
			os << "| Dictionary Content |\n";
			os << "----------------------\n";

			for (int i = 0; i < m_num_elements; i++)
			{
				os << m_queue[i] << "\n";
			}
			os << "----------------------\n";
			return os;
		}

		T operator[](int index) {
			T returnval;
			if (index > m_num_elements)
			{
				 returnval = dummy;
			}
			else {
				returnval = m_queue[index];
			}
			return returnval;
		}

	};

	template<typename T, int capacity>
	T Queue<T, capacity>::dummy = {};
}


#endif // !SDDS_QUEUE_H


