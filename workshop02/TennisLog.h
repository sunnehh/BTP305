#ifndef SDDS_TENNIS_LOG_H
#define SDDS_TENNIS_LOG_H
#include <string>

struct TennisMatch
{
	std::string tournament_id;
	std::string tournament_name;
	unsigned int match_id;
	std::string winner;
	std::string loser;
};


class TennisLog
{
private:
	int m_num_matches;
	int m_matches;

public:
	TennisLog();
	~TennisLog();
};

#endif