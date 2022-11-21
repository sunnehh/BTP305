#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include <iostream>
#include "Vehicle.h"



namespace sdds {
   class Van : public Vehicle
   {
   private:
      std::string m_maker;
      char m_type; // p pickup, m minibus, c camper
      char m_condition;
      char m_purpose; // d delivery, p passenger, c camping
      double m_top_speed;

   public:
      Van();
      Van(std::istream& is);

      bool validPurpose(const char purpose);
      bool validType(const char type);
      bool validCondition(const char condition);
      bool isNumber(std::string& input);

      double topSpeed() const;
      void display(std::ostream& os) const;
      std::string condition() const;
      std::string type() const;
      std::string usage() const;
   };
   std::string& trim(std::string& input);
}

#endif // !SDDS_VAN_H


