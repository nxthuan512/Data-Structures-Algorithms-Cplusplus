#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include "my_string.h"

// Constructor
my_string::my_string(const std::string new_string) {
   str = new char [new_string.size()];
   strcpy(str, new_string.c_str());
   printf ("XT_DEBUG: Called a constructor string=%s\n", &str[0]);
}

// DEEP copy constructor
my_string::my_string(const my_string &new_string) {
   str = new char [new_string.size()+1]; 
   strcpy(str, new_string.str);
   printf ("XT_DEBUG: Called a DEEP copy constructor string=%s\n", &str[0]);
} 

// Move constructor
my_string::my_string(my_string &&new_string) noexcept {
   str = new_string.str;
   new_string.str = nullptr; 
   printf ("XT_DEBUG: Called a move constructor string=%s\n", &str[0]);
}

// Destructor
my_string::~my_string() {
   delete [] str;
   printf ("XT_DEBUG: Called a destructor\n");
}

// Get length
int my_string::size() const {
   return strlen(str);
}

// Get string
char *my_string::content() const {
   return str;
}

// ==============================
// -, ==, !=, <, >, +, +=, *, *=, A++, ++A, A--, --A

// Operator unary minus
my_string my_string::operator-() const {
   printf ("XT_DEBUG: Calling operator -\n");
   int n = strlen(str)+1;
   char *new_str = new char [n];
   for (int i = 0; i < n; ++i) {
      new_str[i] = tolower(str[i]);
   }
   my_string new_string {new_str};
   delete [] new_str;
   return new_string;
}


//
