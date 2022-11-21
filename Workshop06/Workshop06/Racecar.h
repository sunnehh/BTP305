#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include <iostream>
#include "Car.h"

namespace sdds {
   class Racecar :
      public Car
   {
   private:
      double m_booster;
   public:
      Racecar(std::istream& in);
      void display(std::ostream& os) const;
      double topSpeed() const;
   };
}


#endif // !SDDS_RACECAR_H

