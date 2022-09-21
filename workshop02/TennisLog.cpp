#include "TennisLog.h"

namespace sdds {

	TennisMatch::TennisMatch() {
		this->match_id = {};
		this->tournament_id = {};
		this->tournament_name = {};
		this->winner = {};
		this->loser = {};
	};

	TennisLog::TennisLog() {
		this->m_matches = nullptr;
		this->m_num_matches = 0;
	}

	TennisLog::~TennisLog() {
		if (m_matches != nullptr)
		{
			delete[] m_matches;
			m_num_matches = 0;
		}
	}
}