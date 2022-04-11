#include "I_Printable.hpp"

std::ostream &operator<<(std::ostream &t_string, const I_Printable &t_obj) {
   t_obj.print(t_string);
   return t_string;
}

