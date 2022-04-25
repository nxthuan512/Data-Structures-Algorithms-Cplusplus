#include "Tree.hpp"
#include <string>
#include <iostream>

Tree::Tree(int value)
: m_value(value), m_left(nullptr), m_right(nullptr) {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
}

Tree::~Tree() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

Tree *Tree::get_root() {
   return this;
}

Tree *Tree::create_node(int value) {
   std::cout << "Create a node: value=" << value << std::endl;
   Tree *new_node = new Tree {value};
   return new_node; 
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

void Tree::create_tree(Tree_Type type) {
   switch (type) {
      case Full_BT: 
         std::cout << "Create a FULL BINARY TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_right->m_left = create_node(6);          
         m_right->m_right = create_node(7);          
         break;

      default: break;
   }
}
