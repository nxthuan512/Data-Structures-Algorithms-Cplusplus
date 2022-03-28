#include <iostream>
#include <cstring>
#include <string>
#include <ctype.h>
#include "my_string.h"

// Constructor
my_string::my_string(const std::string new_string) {
   str = new char [new_string.size()+1];
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

// Copy assignment 
my_string &my_string::operator=(const my_string &that_string) {
   printf ("XT_DEBUG: Calling a COPY assignment string1=%s string2=%s\n", str, that_string.str);
   delete [] str;
   str = new char [that_string.size()+1];
   strcpy(str, that_string.str);
   printf ("XT_DEBUG: DONE\n");
   return *this;
}

// Move assignment
my_string &my_string::operator=(my_string &&that_string) noexcept {
   printf ("XT_DEBUG: Calling a MOVE assignment string1=%s string2=%s\n", str, that_string.str);
   str = that_string.str;
   that_string.str = nullptr;
   printf ("XT_DEBUG: DONE\n");
   return *this;
}


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

// Operator ==, !=, <, >
bool my_string::operator==(const my_string &that_string) const {
   printf ("XT_DEBUG: Calling operator ==\n");
   int n1 = strlen(str)+1;
   int n2 = strlen(that_string.str)+1;
   if (n1 != n2) {
      return false;
   } else {
      if (strcmp(str, that_string.str) == 0)
         return true;
      else
         return false;
   }
}

bool my_string::operator!=(const my_string &that_string) const {
   printf ("XT_DEBUG: Calling operator !=\n");
   int n1 = strlen(str)+1;
   int n2 = strlen(that_string.str)+1;
   if (n1 != n2) {
      return true;
   } else {
      if (strcmp(str, that_string.str) != 0)
         return true;
      else
         return false;
   }
}

bool my_string::operator>(const my_string &that_string) const {
   printf ("XT_DEBUG: Calling operator >\n");
   int n1 = strlen(str)+1;
   int n2 = strlen(that_string.str)+1;
   if (n1 > n2) {
      return true;
   } else if (n1 < n2) {
      return false;
   } else {
      if (strcmp(str, that_string.str) > 0)
         return true;
      else
         return false;
   }
}

bool my_string::operator<(const my_string &that_string) const {
   printf ("XT_DEBUG: Calling operator <\n");
   int n1 = strlen(str)+1;
   int n2 = strlen(that_string.str)+1;
   if (n1 < n2) {
      return true;
   } else if (n1 > n2) {
      return false;
   } else {
      if (strcmp(str, that_string.str) < 0)
         return true;
      else
         return false;
   }
}

// Operator +, *
my_string my_string::operator+(const my_string &that_string) const {
   printf ("XT_DEBUG: Calling operator +\n");
   int n1 = strlen(str) + 1;
   int n2 = strlen(that_string.str) + 1;
   int n = n1 + n2 - 1;

   char *sum_str = new char [n];
   strcpy(sum_str, str);
   strcat(sum_str, that_string.str);

   my_string sum_string {sum_str};
   delete [] sum_str;
   return sum_string;
}

my_string my_string::operator+(const char *that_string) const {
   printf ("XT_DEBUG: Calling operator +\n");
   int n1 = strlen(str) + 1;
   int n2 = strlen(that_string) + 1;
   int n = n1 + n2 - 1;

   char *sum_str = new char [n];
   strcpy(sum_str, str);
   strcat(sum_str, that_string);

   my_string sum_string {sum_str};
   delete [] sum_str;
   return sum_string;
}
