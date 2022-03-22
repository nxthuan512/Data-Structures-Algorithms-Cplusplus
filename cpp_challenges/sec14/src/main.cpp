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

   add_string(list_str, "Starwars");
   add_string(list_str, "Return of the Jedi");
   add_string(list_str, "The clone wars");
   
   my_string tmp_str = -list_str.at(0);
   add_string(list_str, tmp_str.content());

   display_string(list_str);

   return 0;
}
