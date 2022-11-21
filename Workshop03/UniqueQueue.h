// Workshop03
// Sunny Qi - 2022/09/27
#ifndef SDDS_UNIQUE_QUEUE_H
#define SDDS_UNIQUE_QUEUE_H

#include <cmath>
#include "Queue.h"
#include "Dictionary.h"

namespace sdds {
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:
		bool push(T item) override {
			bool success = false;
			bool dupe = false;
			if (Queue<T, 100>::m_num_elements < 100)
			{
				for (int i = 0; (i < 100) && !dupe; ++i)
				{
					if (Queue<T, 100>::m_queue[i] == item)
					{
						dupe = true;
					}
				}
				if (!dupe)
				{
					Queue<T, 100>::push(item);
					success = true;
				}
			}
			return success;
		};
	};

	template<>
	bool UniqueQueue<double>::push(double item) {
		bool success = false;
		bool dupe = false;
		if (Queue<double, 100>::m_num_elements < 100)
		{
			for (int i = 0; (i < 100) && !dupe; ++i)
			{
				if (!(Queue<double, 100>::m_queue[i] == dummy))
				{
					double compare = fabs((Queue<double, 100>::m_queue[i] - item));
					if (compare < 0.005)
					{
						dupe = true;
					}
				}
			}
			if (!dupe)
			{
				Queue<double, 100>::push(item);
			}
		}
		return success;
	};

	template<>
	Dictionary Queue<Dictionary, 100>::dummy = Dictionary("Empty Term", "Empty Substitute");
}
#endif