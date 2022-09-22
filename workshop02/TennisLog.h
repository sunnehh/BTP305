#ifndef SDDS_TENNIS_LOG_H
#define SDDS_TENNIS_LOG_H
#include <string>
#include <iostream>

namespace sdds {

	struct TennisMatch
	{
		std::string tournament_id;
		std::string tournament_name;
		int match_id;
		std::string winner;
		std::string loser;

		TennisMatch();
	};
	std::ostream& operator<<(std::ostream& os, const TennisMatch& match);

	class TennisLog
	{
	private:
		size_t m_num_matches;
		TennisMatch* m_matches;

	public:
		TennisLog();
		TennisLog(std::string filename);
		~TennisLog();

		void addMatch(TennisMatch match);
		TennisLog findMatches();

		TennisMatch operator[](size_t size);

		operator size_t();

		TennisLog(const TennisLog& other); // copy constructor
		TennisLog(TennisLog&& other); // move constructor

		TennisLog& operator= (const TennisLog& other); // copy assignment
		TennisLog& operator= (TennisLog&& other) noexcept; // move assignment
	};
}
#endif