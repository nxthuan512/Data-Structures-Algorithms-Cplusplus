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

      // Copy assignment
      my_string &operator=(const my_string &);

      // Move assignment
      my_string &operator=(my_string &&) noexcept;

      // -, ==, !=, <, >, +, +=, *, *=, A++, ++A, A--, --A
      my_string operator-() const;
      bool operator==(const my_string &) const;
      bool operator!=(const my_string &) const;
      bool operator>(const my_string &) const;
      bool operator<(const my_string &) const;
      my_string operator+(const my_string &) const;
      my_string operator+(const char *) const;
      my_string operator*(const my_string &) const;
};


#endif /* MY_STRING_H */
