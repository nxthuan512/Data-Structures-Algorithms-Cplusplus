#include "RBT.hpp"
#include <iostream>

// Constructor
RBT::RBT() = default;
// Destructor
RBT::~RBT() = default;


// =======================================================
// Create Tree
// =======================================================
void RBT::create_tree(RBT *tree) {
   std::cout << "Create a RED BLACK TREE" << std::endl;
   // tree->m_node = create_node(8);
   // insert_node(tree->m_node, 3);
   // insert_node(tree->m_node, 1);
   // insert_node(tree->m_node, 6);
   // insert_node(tree->m_node, 7);
   // insert_node(tree->m_node, 10);
   // insert_node(tree->m_node, 14);
   // insert_node(tree->m_node, 4);
}

// Node_RBT *insert_node(Node_RBT *node, int value) {
//    if (node == nullptr) {
//       return 
//    }
// }

// ==============================================================
RBT *create_rbt() {
   RBT *my_tree = new RBT;
   my_tree->create_tree(my_tree);
   return my_tree;
}

void check_rbt (RBT &my_tree) {
   std::cout << "XT_INFO: Not supported Tree root = " << my_tree.get_root() << std::endl;
   // Node *my_root = my_tree.get_root();
   // bool my_check = my_tree.is_rbt_tree(my_root);
   // if (my_check == true) {
   //    std::cout << "This is a binary search tree" << std::endl;
   // } else {
   //    std::cout << "This is NOT a binary search tree" << std::endl;
   // }
}
