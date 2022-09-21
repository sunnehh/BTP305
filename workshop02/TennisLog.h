#ifndef SDDS_TENNIS_LOG_H
#define SDDS_TENNIS_LOG_H
#include <string>

namespace sdds {

	struct TennisMatch
	{
		std::string tournament_id;
		std::string tournament_name;
		unsigned int match_id;
		std::string winner;
		std::string loser;

		TennisMatch();
	};


	class TennisLog
	{
	private:
		int m_num_matches;
		TennisMatch* m_matches;

	public:
		TennisLog();
		~TennisLog();
	};
}
#endif