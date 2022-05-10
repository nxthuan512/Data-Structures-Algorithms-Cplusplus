#include "BST.hpp"
#include <iostream>

// Constructor
BST::BST() = default;
// Destructor
BST::~BST() = default;

// =======================================================
// Create Tree
// =======================================================
void BST::create_tree(BST *tree) {
   std::cout << "Create a BINARY SEARCH TREE" << std::endl;
   tree->m_node = create_node(8);
   insert_node(tree->m_node, 3);
   insert_node(tree->m_node, 1);
   insert_node(tree->m_node, 6);
   insert_node(tree->m_node, 7);
   insert_node(tree->m_node, 10);
   insert_node(tree->m_node, 14);
   insert_node(tree->m_node, 4);
}

// Get the left most node
Node *BST::get_left_most_node_in_right(Node *node) {
   node = node->m_right;
   while (node->m_left != nullptr) {
      node = node->m_left;
   }
   return node;
}

// Insert node
Node *BST::insert_node(Node *node, int value) {
   if (node == nullptr) {
      // std::cout << "Insert a node to BST: value=" << value << std::endl;
      node = create_node(value);
      return node;
   }
   if (value < node->m_value) {
      node->m_left = insert_node(node->m_left, value);
   }
   if (value > node->m_value) {
      node->m_right = insert_node(node->m_right, value);
   }
   return node;
}

// Delete node
Node *BST::delete_node(Node *node, int value) {
   // If not found 
   if (node == nullptr) {
      return nullptr;
   }
   if (value < node->m_value) {
      node->m_left = delete_node(node->m_left, value);
   }
   if (value > node->m_value) {
      node->m_right = delete_node(node->m_right, value);
   }
   if (node->m_value == value) {
      // If the node is leaf node
      if (node->m_left == nullptr && node->m_right == nullptr) {
         // std::cout << "XT_DEBUG: The delete_node " << node->m_value << " is a leaf node" << std::endl;
         delete node;
         return nullptr;
      } 
      // If the node contains a single child
      else if (node->m_right != nullptr && node->m_left == nullptr) {
         // std::cout << "XT_DEBUG: The delete_node " << node->m_value << " has only right child" << std::endl;
         Node *new_node = node->m_right;
         delete node;
         return new_node;
      } 
      else if (node->m_left != nullptr && node->m_right == nullptr) {
         // std::cout << "XT_DEBUG: The delete_node " << node->m_value << " has only left child" << std::endl;
         Node *new_node = node->m_left;
         delete node;
         return new_node;
      }
      // If the node contains 2 childs
      else {
         // std::cout << "XT_DEBUG: The delete_node " << node->m_value << " has both left and right children" << std::endl;
         Node *new_node = get_left_most_node_in_right(node);
         node->m_value = new_node->m_value;
         node->m_right = delete_node(node->m_right, new_node->m_value);
      }
   }
   return node;
}

// Check
bool BST::is_binary_search_tree(Node *node) {
   if (node == nullptr) {
      return true;
   }
   if (node->m_left != nullptr && node->m_value <= node->m_left->m_value) {
      return false;
   }
   if (node->m_right != nullptr && node->m_value > node->m_right->m_value) {
      return false;
   }
   return (is_balanced_binary(node->m_left) && is_balanced_binary(node->m_right));
}

// ==============================================================
BST *create_bst() {
   BST *my_tree = new BST;
   my_tree->create_tree(my_tree);
   return my_tree;
}

void check_bst (BST &my_tree) {
   Node *my_root = my_tree.get_root();
   bool my_check = my_tree.is_binary_search_tree(my_root);
   if (my_check == true) {
      std::cout << "This is a binary search tree" << std::endl;
   } else {
      std::cout << "This is NOT a binary search tree" << std::endl;
   }
}
