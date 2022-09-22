#include <iomanip>
#include <fstream>
#include <iostream>
#include "TennisLog.h"

namespace sdds {
	using namespace std;
	TennisMatch::TennisMatch() {
		this->match_id = -1;
		this->tournament_id = {};
		this->tournament_name = {};
		this->winner = {};
		this->loser = {};
	};

	ostream& operator<<(std::ostream& os, const TennisMatch& match) {
		if (match.match_id == -1)
		{
			os << "Empty Match" << endl;
		}
		else
		{
			os << right << setw(20) << setfill('.');
			os << "Tourney ID : ";
			os << left << setw(30) << setfill('.');
			os << match.tournament_id << endl;

			os << right << setw(20) << setfill('.');
			os << "Match ID : ";
			os << left << setw(30) << setfill('.');
			os << match.match_id << endl;

			os << right << setw(20) << setfill('.');
			os << "Tourney : ";
			os << left << setw(30) << setfill('.');
			os << match.tournament_name << endl;

			os << right << setw(20) << setfill('.');
			os << "Winner : ";
			os << left << setw(30) << setfill('.');
			os << match.winner << endl;

			os << right << setw(20) << setfill('.');
			os << "Loser : ";
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
		ifstream in(filename);
		if (in.is_open() == false)
		{
			TennisLog();
			cout << "cannot open file " << filename << endl;
			return;
		}
		while (!in.eof())
		{
			lines++;

		}
	}
}

int main() {
}