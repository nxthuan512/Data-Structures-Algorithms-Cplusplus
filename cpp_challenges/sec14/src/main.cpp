#include <iostream>
#include <vector>
#include "main.h"
#include "my_string.h"

//
void add_string(std::vector <my_string> &list_str, const std::string new_string) {
   printf ("XT_DEBUG: Add new string=%s\n", new_string.c_str());
   list_str.push_back(my_string {new_string}); 
   std::cout << std::endl;
}

//
void display_string(const std::vector<my_string> &list_str) {
   std::cout << "=== Print all strings ===" << std::endl;
   for (const auto &str:list_str) {
      std::cout << str.content() << std::endl;
   }
   std::cout << std::endl;
}

int main() {
   std::vector <my_string> list_str;

   add_string(list_str, "Starwars Collections");
   add_string(list_str, "Episode VI: ");
   add_string(list_str, "Return of the Jedi");
   add_string(list_str, "A New Hope");
   
   // Test 1
   my_string tmp_str = -list_str.at(0);
   add_string(list_str, tmp_str.content());

   // Test 2
   for (const auto &istr:list_str) {
      if (list_str.at(0) == istr) {
         std::cout << list_str.at(0).content() << " is equal to " << istr.content() << std::endl;
      } else if (list_str.at(0) != istr) {
         std::cout << list_str.at(0).content() << " is not equal to " << istr.content() << std::endl;
         if (list_str.at(0) > istr) {
            std::cout << list_str.at(0).content() << " is greater than " << istr.content() << std::endl;
         } else if (list_str.at(0) < istr) {
            std::cout << list_str.at(0).content() << " is smaller than " << istr.content() << std::endl;
         }     
      }
   }
   std::cout << std::endl;

   // Test 3
   my_string tmp_str_1 = list_str.at(1) + list_str.at(2);
   add_string(list_str, tmp_str_1.content());

   tmp_str_1 = list_str.at(1) + "Darth Vader died";
   add_string(list_str, tmp_str_1.content());

   display_string(list_str);

   return 0;
}
