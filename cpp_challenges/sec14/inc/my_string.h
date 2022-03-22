#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <string>

class my_string {
   private:
      char *str;
   public: 
      // Constructor
      my_string(const std::string);
      // Deep copy constructor
      my_string(const my_string &);
      // Move constructor
      my_string(my_string &&) noexcept;
      // Destructor
      ~my_string();

      // Get size
      int size() const;
      // Get content
      char *content() const;

      // -, ==, !=, <, >, +, +=, *, *=, A++, ++A, A--, --A
      // Unary minus
      my_string operator-() const;
};


#endif /* MY_STRING_H */
