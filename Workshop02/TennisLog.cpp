// Workshop 2
// Sunny Qi - 2022/09/25

#include <iomanip>
#include <fstream>
#include <iostream>
#include "TennisLog.h"

namespace sdds {
	using namespace std;
	ostream& operator<<(std::ostream& os, const TennisMatch& match) {
		if (match.match_id == 0 || match.tournament_name == "")
		{
			os << "Empty Match";
		}
		else
		{
			os << right << setw(20) << setfill('.');
			os << "Tourney ID" << " : ";
			os << left << setw(30) << setfill('.');
			os << match.tournament_id << endl;

			os << right << setw(20) << setfill('.');
			os << "Match ID" << " : ";
			os << left << setw(30) << setfill('.');
			os << match.match_id << endl;

			os << right << setw(20) << setfill('.');
			os << "Tourney" << " : ";
			os << left << setw(30) << setfill('.');
			os << match.tournament_name << endl;

			os << right << setw(20) << setfill('.');
			os << "Winner" << " : ";
			os << left << setw(30) << setfill('.');
			os << match.winner << endl;

			os << right << setw(20) << setfill('.');
			os << "Loser" << " : ";
			os << left << setw(30) << setfill('.');
			os << match.loser << endl;
		};
		return os;
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

	TennisLog::TennisLog(string filename) {
		// get the num of elements in the file
		// create new matches for each entry
		// assign the values to the matches
		size_t lines = 0;
		string currentline = "";
		ifstream in;
		in.open(filename);
		if (in.is_open() == false)
		{
			this->m_matches = nullptr;
			this->m_num_matches = 0;
			cout << "cannot open file " << filename << endl;
			return;
		}
		// count number of lines
		while (getline(in, currentline))
		{
			lines++;
		}
		// disregard first line since it isn't data
		--lines;
		m_matches = new TennisMatch[lines];
		m_num_matches = lines;
		// set reader back to beginning of the file
		in.clear();
		in.seekg(0, std::ios::beg);
		// read the file
			// skip the first line
		getline(in, currentline, '\n');
		for (size_t i = 0; i < m_num_matches; i++)
		{
			string matchid = "";
			getline(in, m_matches[i].tournament_id, ',');
			getline(in, m_matches[i].tournament_name, ',');
			getline(in, matchid, ',');
			m_matches[i].match_id = stoi(matchid);
			getline(in, m_matches[i].winner, ',');
			getline(in, m_matches[i].loser, '\n');
		}
	}

	TennisLog::TennisLog(const TennisLog& other) {
		this->m_num_matches = other.m_num_matches;
		this->m_matches = new TennisMatch[m_num_matches];
		for (size_t i = 0; i < m_num_matches; i++)
		{
			m_matches[i].tournament_id = other.m_matches[i].tournament_id;
			m_matches[i].tournament_name = other.m_matches[i].tournament_name;
			m_matches[i].match_id = other.m_matches[i].match_id;
			m_matches[i].winner = other.m_matches[i].winner;
			m_matches[i].loser = other.m_matches[i].loser;
		}
	}

	TennisLog& TennisLog::operator=(const TennisLog& other) {
		if (this != &other)
		{
			if (this->m_num_matches > 0 && this->m_matches != nullptr)
			{
				delete[] m_matches;
				m_num_matches = 0;
			}
			this->m_num_matches = other.m_num_matches;
			this->m_matches = new TennisMatch[m_num_matches];
			for (size_t i = 0; i < m_num_matches; i++)
			{
				m_matches[i].tournament_id = other.m_matches[i].tournament_id;
				m_matches[i].tournament_name = other.m_matches[i].tournament_name;
				m_matches[i].match_id = other.m_matches[i].match_id;
				m_matches[i].winner = other.m_matches[i].winner;
				m_matches[i].loser = other.m_matches[i].loser;
			}
		}
		return *this;
	}

	TennisLog::TennisLog(TennisLog&& other) noexcept {
		if (this != &other)
		{
			this->m_num_matches = other.m_num_matches;
			this->m_matches = other.m_matches;
			other.m_matches = nullptr;
			other.m_num_matches = 0;
		}
		else
		{
			this->m_num_matches = 0;
			this->m_matches = nullptr;
		}
	}

	TennisLog& TennisLog::operator=(TennisLog&& other) noexcept {
		if (this != &other)
		{
			if (this->m_num_matches > 0 && this->m_matches != nullptr)
			{
				delete[] m_matches;
				m_num_matches = 0;
			}
			this->m_num_matches = other.m_num_matches;
			this->m_matches = other.m_matches;
			other.m_matches = nullptr;
			other.m_num_matches = 0;
		}
		return *this;
	}

	void TennisLog::addMatch(const TennisMatch match) {
		TennisLog temp(*this);
		if (this->m_matches != nullptr)
		{
			delete[] this->m_matches;
		}
		m_num_matches++;
		this->m_matches = new TennisMatch[m_num_matches];
		for (size_t i = 0; i < m_num_matches - 1; i++)
		{
			m_matches[i].tournament_id = temp[i].tournament_id;
			m_matches[i].tournament_name = temp[i].tournament_name;
			m_matches[i].match_id = temp[i].match_id;
			m_matches[i].winner = temp[i].winner;
			m_matches[i].loser = temp[i].loser;
		}
		m_matches[m_num_matches-1].tournament_id = match.tournament_id;
		m_matches[m_num_matches-1].tournament_name = match.tournament_name;
		m_matches[m_num_matches-1].match_id = match.match_id;
		m_matches[m_num_matches-1].winner = match.winner;
		m_matches[m_num_matches-1].loser = match.loser;
	}

	TennisLog TennisLog::findMatches(string name) const{
		TennisLog temp;
		for (size_t i = 0; i < m_num_matches; i++)
		{
			if ((m_matches[i].loser == name) || (m_matches[i].winner == name)) {
				temp.addMatch(m_matches[i]);
			}
		}
		return temp;
	}

	TennisMatch TennisLog::operator[](size_t index) const{
		if (index >= m_num_matches)
		{
			TennisMatch empty;
			return empty;
		}
		return this->m_matches[index];
	}

	TennisLog::operator size_t() const{
		return m_num_matches;
	}

}
