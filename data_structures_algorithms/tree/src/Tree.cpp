#include "Tree.hpp"
#include <string>
#include <iostream>

// =======================================================
// Constructor/Destructor
// =======================================================
Tree::Tree(int value)
: m_value(value), m_left(nullptr), m_right(nullptr) {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
}

Tree::~Tree() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

// =======================================================
// Getter
// =======================================================
// Get the root of tree
Tree *Tree::get_root() {
   return this;
}

// Find the height of tree from node
int Tree::get_height(Tree *node) {
   int left_height = 0;
   int right_height = 0;

   if (node->m_left == nullptr && node->m_right == nullptr) {
      return 0;
   }
   if (node->m_left != nullptr) {
      left_height = get_height(node->m_left);   
   }
   if (node->m_right != nullptr) {
      right_height = get_height(node->m_right);
   }
   return (1 + std::max(left_height, right_height));
}

// =======================================================
// Create/Delete Tree/Node
// =======================================================
Tree *Tree::create_node(int value) {
   std::cout << "Create a node: value=" << value << std::endl;
   Tree *new_node = new Tree {value};
   return new_node; 
}

void Tree::create_tree(Tree_Type type) {
   switch (type) {
      case Full_BT: 
         std::cout << "Create a FULL BINARY TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_left->m_right->m_left = create_node(6);          
         m_left->m_right->m_right = create_node(7);          
         m_left->m_right->m_left->m_left = create_node(8);          
         m_left->m_right->m_left->m_right = create_node(9);          
         break;

      default: break;
   }
}

void Tree::delete_tree(Tree *node) {
   // std::cout << "XT_DEBUG: At node: value=" << node->m_value << std::endl;
   if (node->m_left != nullptr) {
      delete_tree(node->m_left);
      node->m_left = nullptr;
   }
   if (node->m_right != nullptr) {
      delete_tree(node->m_right);
      node->m_right = nullptr;
   }
   if (node->m_left == nullptr && node->m_right == nullptr && node->m_value > 0) {
      std::cout << "Delete node: value=" << node->m_value << std::endl;
      delete node;
      return;
   }
}

// =======================================================
// Check Tree type
// =======================================================
bool Tree::is_full_binary(Tree *node) {
   if (node->m_left != nullptr && node->m_right != nullptr) {
      // std::cout << "XT_DEBUG: At node [1]: value=" << node->m_value << std::endl;
      return (is_full_binary(node->m_left)) && (is_full_binary(node->m_right));
   }
   if (node->m_left == nullptr && node->m_right == nullptr) {
      // std::cout << "XT_DEBUG: At node [2]: value=" << node->m_value << std::endl;
      return true;
   } 
   return false;
}
