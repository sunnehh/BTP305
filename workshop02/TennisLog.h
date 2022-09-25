// Workshop 2
// Sunny Qi - 2022/09/25


#ifndef SDDS_TENNIS_LOG_H
#define SDDS_TENNIS_LOG_H
#include <string>
#include <iostream>

namespace sdds {

	struct TennisMatch
	{
		std::string tournament_id{};
		std::string tournament_name{};
		unsigned int match_id{};
		std::string winner{};
		std::string loser{};
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

		void addMatch(const TennisMatch match);
		TennisLog findMatches(std::string name) const;

		TennisMatch operator[](size_t index) const;

		operator size_t() const;

		TennisLog(const TennisLog& other); // copy constructor
		TennisLog(TennisLog&& other) noexcept; // move constructor

		TennisLog& operator= (const TennisLog& other); // copy assignment
		TennisLog& operator= (TennisLog&& other) noexcept; // move assignment
	};
}
#endif