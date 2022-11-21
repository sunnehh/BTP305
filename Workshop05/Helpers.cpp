#include "Helpers.h"

using namespace std;


string& trim(std::string& input) {
   string WHITESPACE = " \n\r\t\f\v";
   size_t start = input.find_first_not_of(WHITESPACE);
   size_t end = input.find_last_not_of(WHITESPACE);
   input = input.substr(start, end - start + 1);
   return input;
}

