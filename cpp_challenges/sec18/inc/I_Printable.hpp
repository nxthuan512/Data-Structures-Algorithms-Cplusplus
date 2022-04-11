#ifndef I_PRINTABLE_HPP
#define I_PRINTABLE_HPP

#include <iostream>

class I_Printable {
   friend std::ostream &operator<<(std::ostream &t_string, const I_Printable &t_obj);
public:
   virtual void print(std::ostream &t_string) const = 0;
   virtual ~I_Printable() = default;
};

#endif /* I_PRINTABLE_HPP */
