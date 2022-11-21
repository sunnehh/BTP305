#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include <iostream>
#include "Vehicle.h"


namespace sdds {

   class Car :public Vehicle
   {
   private:
      std::string m_maker;
      char m_condition;
      double m_top_speed;

   public:
      Car();
      Car(std::istream& is);

      bool validCondition(const char condition);
      bool isNumber(std::string& input);

      // virtual functions
      double topSpeed() const;
      void display(std::ostream& os) const;
      std::string condition() const;

      ~Car() {};

   };
   std::string& trimm(std::string& input);

}


#endif // !SDDS_CAR_H

