#include "main.hpp"
#include <iostream>


// ======================================================================

// ======================================================================
int main() {
   Tree *my_tree = nullptr;

   my_tree = create_tree(Full_BT);
   check_tree_type(Full_BT, *my_tree);
   delete_tree(*my_tree);
   std::cout << " ========================================= " << std::endl;

   my_tree = create_tree(Perfect_BT);
   check_tree_type(Perfect_BT, *my_tree);
   delete_tree(*my_tree);
   std::cout << " ========================================= " << std::endl;

   my_tree = create_tree(Complete_BT);
   check_tree_type(Complete_BT, *my_tree);
   delete_tree(*my_tree);
   std::cout << " ========================================= " << std::endl;

   my_tree = create_tree(Complete_BT);
   check_tree_type(Balanced_BT, *my_tree);
   delete_tree(*my_tree);
   std::cout << " ========================================= " << std::endl;

   BST *my_bst = create_bst();
   check_bst(*my_bst);
   my_bst->delete_node(my_bst->get_root(), 4);
   my_bst->delete_node(my_bst->get_root(), 10);
   my_bst->delete_node(my_bst->get_root(), 3);
   delete_tree(*my_bst);
   std::cout << " ========================================= " << std::endl;

   AVL *my_avl = create_avl();
   delete_tree(*my_avl);
   std::cout << " ========================================= " << std::endl;

   // RBT *my_rbt = create_rbt();
   // delete_tree(*my_rbt);
   // std::cout << " ========================================= " << std::endl;
   
   return 0;
}
