// Workshop 2
// Sunny Qi - 2022/09/25

#include "Timer.h"

namespace sdds {
	using namespace std;
	Timer::Timer() : m_start{}, m_finish{}, m_duration{} {
	}

	void Timer::start() {
		m_start = chrono::high_resolution_clock::now();
	}

	long long Timer::stop() {
		m_finish = chrono::high_resolution_clock::now();
		m_duration = m_finish - m_start;
		return chrono::duration_cast<chrono::nanoseconds>(m_duration).count();
	}
}