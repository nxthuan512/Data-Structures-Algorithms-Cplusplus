#include "main.hpp"
#include <iostream>

int main() {
   Tree my_tree {0};
   Tree *my_root = my_tree.get_root();
   bool my_check;
   int my_height;

   my_tree.create_tree(Full_BT);
   my_height = my_tree.get_height(my_root);
   std::cout << "Tree height is " << my_height << std::endl;

   my_check = my_tree.is_full_binary(my_root);
   if (my_check == true) {
      std::cout << "This is a full binary tree" << std::endl;
   } else {
      std::cout << "This is NOT a full binary tree" << std::endl;
   }
   
   my_tree.delete_tree(my_root);

   return 0;
}
