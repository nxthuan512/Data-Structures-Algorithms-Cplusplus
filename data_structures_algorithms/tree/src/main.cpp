#include "main.hpp"
#include <iostream>

void check_tree_type(Tree_Type my_type) {
   Tree my_tree {0};
   Tree *my_root = my_tree.get_root();
   bool my_check;
   int my_height;

   my_tree.create_tree(my_type);
   my_height = my_tree.get_height(my_root);
   std::cout << "Tree height is " << my_height << std::endl;

   switch (my_type) {
      case Full_BT: {
         my_check = my_tree.is_full_binary(my_root);
         if (my_check == true) {
            std::cout << "This is a full binary tree" << std::endl;
         } else {
            std::cout << "This is NOT a full binary tree" << std::endl;
         }
         break;
      }

      case Perfect_BT: {
         int my_height_left = my_tree.get_height_left_only(my_root);
         my_check = my_tree.is_perfect_binary(my_root, my_height_left);
         if (my_check == true) {
            std::cout << "This is a perfect binary tree" << std::endl;
         } else {
            std::cout << "This is NOT a perfect binary tree" << std::endl;
         }
         break;
      }

      case Complete_BT: {
         int my_num_nodes = my_tree.get_num_nodes(my_root);
         my_check = my_tree.is_complete_binary(my_root, my_num_nodes);
         if (my_check == true) {
            std::cout << "This is a complete binary tree" << std::endl;
         } else {
            std::cout << "This is NOT a complete binary tree" << std::endl;
         }
         break;
      }

      default: {
         try {
            throw "Unknow tree type";
         }
         catch (std::string e) {
            std::cout << "An exception occurred. Exception: " << e << std::endl;
         }
      }
   }
   
   my_tree.delete_tree(my_root);
   std::cout << " ========================================= " << std::endl;
}

int main() {
   check_tree_type(Full_BT);
   check_tree_type(Perfect_BT);
   check_tree_type(Complete_BT);
   return 0;
}
