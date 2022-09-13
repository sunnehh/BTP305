#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>
#include <string>

extern double g_taxrate;
extern double g_discount;


namespace sdds {

	void listArgs(int argc, char* argv[]);

	class Cars {

	public:
		Cars();
		Cars(std::string make, std::string model, int year, double price, char condition, bool discount);
		~Cars();
		// copy and assignment
		Cars(const Cars& src);
		Cars& operator=(const Cars& src);

		int read(std::istream& is);
		int display(bool reset);
		char getStatus();
	private:
		char* m_make;
		int m_makelen;
		char* m_model;
		int m_modellen;
		int m_year;
		double m_price;
		char m_condition;
		bool m_discount;
	};
	//ostream& operator<<(ostream& os, const Cars& src);
}


#endif // !SDDS_CARADS_H
