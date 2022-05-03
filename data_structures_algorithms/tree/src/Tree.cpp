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

   if (node == nullptr) {
      return 0;
   }
   left_height = get_height(node->m_left);   
   right_height = get_height(node->m_right);
   return (1 + std::max(left_height, right_height));
}

// Find the height of left most branch
int Tree::get_height_left_only(Tree *node) {
   int height_left = 0;
   while (node->m_left != nullptr) {
      ++height_left;
      node = node->m_left;
   }
   return (height_left+1);
}

// Get number of nodes in tree
int Tree::get_num_nodes(Tree *node) {
   if (node == nullptr) {
      return 0;
   }
   return (1 + get_num_nodes(node->m_left) + get_num_nodes(node->m_right));
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
      case Full_BT: {
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
      }

      case Perfect_BT: {
         std::cout << "Create a PERFECT BINARY TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_right->m_left = create_node(6);          
         m_right->m_right = create_node(7);          
         m_left->m_left->m_left = create_node(8);          
         m_left->m_left->m_right = create_node(9);          
         m_left->m_right->m_left = create_node(10);          
         m_left->m_right->m_right = create_node(11);          
         m_right->m_left->m_left = create_node(12);          
         m_right->m_left->m_right = create_node(13);          
         m_right->m_right->m_left = create_node(14);          
         m_right->m_right->m_right = create_node(15);          
         break;
      }

      case Complete_BT: {
         std::cout << "Create a COMPLETE BINARY TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_right->m_left = create_node(6);          
         // m_right->m_right = create_node(7);          
         break;
      }

      case Balanced_BT: {
         std::cout << "Create a BALANCED BINARY TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_right->m_left = create_node(6);          
         m_right->m_right = create_node(7);          
         m_left->m_left->m_left = create_node(8);          
         m_left->m_left->m_right = create_node(9);          
         m_left->m_left->m_left->m_left = create_node(16);          
         break;
      }

      case Binary_Search_Tree: {
         std::cout << "Create a BINARY SEARCH TREE" << std::endl;
         m_left = create_node(2);          
         m_right = create_node(3);          
         m_left->m_left = create_node(4);          
         m_left->m_right = create_node(5);          
         m_right->m_left = create_node(6);          
         m_right->m_right = create_node(7);          
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
}

void Tree::delete_tree(Tree *node, Tree *root) {
   // std::cout << "XT_DEBUG: At node: value=" << node->m_value << std::endl;
   if (node == nullptr) {
      return;
   }
   delete_tree(node->m_left, root);
   delete_tree(node->m_right, root);

   if (node != root) {
      std::cout << "Delete node: value=" << node->m_value << std::endl;
      delete node;
   }
}

// =======================================================
// Check Tree type
// =======================================================
bool Tree::is_full_binary(Tree *node) {
   if (node == nullptr) {
      return true;
   }
   if (node->m_left == nullptr && node->m_right == nullptr) {
      // std::cout << "XT_DEBUG: At node [2]: value=" << node->m_value << std::endl;
      return true;
   } 
   if (node->m_left != nullptr && node->m_right != nullptr) {
      // std::cout << "XT_DEBUG: At node [1]: value=" << node->m_value << std::endl;
      return (is_full_binary(node->m_left)) && (is_full_binary(node->m_right));
   }
   return false;
}

bool Tree::is_perfect_binary(Tree *node, int my_height_left, int my_level) {
   // std::cout << "XT_DEBUG: node.value=" << node->m_value << " my_height_left=" << my_height_left << " my_level=" << my_level << std::endl;
   if (node == nullptr) {
      return true;
   }
   // At leaf node
   if (node->m_left == nullptr && node->m_right == nullptr) {
      return (my_height_left == my_level + 1);
   }
   if (node->m_left == nullptr || node->m_right == nullptr) {
      return false;
   }
   return (is_perfect_binary(node->m_left, my_height_left, my_level + 1)) && (is_perfect_binary(node->m_right, my_height_left, my_level + 1));
}

bool Tree::is_complete_binary(Tree *node, int my_num_nodes, int my_index) {
   if (node == nullptr) {
      return true;
   }
   // std::cout << "XT_DEBUG: node.value=" << node->m_value << " my_num_nodes=" << my_num_nodes << " my_index=" << my_index << std::endl;
   if (my_index >= my_num_nodes) {
      return false;
   }
   return (is_complete_binary(node->m_left, my_num_nodes, 2*my_index+1)) && (is_complete_binary(node->m_right, my_num_nodes, 2*my_index+2));
}

bool Tree::is_balanced_binary(Tree *node) {
   int my_level_left;
   int my_level_right;

   if (node == nullptr) {
      return true;
   }
   // std::cout << "XT_DEBUG: At node: value=" << node->m_value << std::endl;
   my_level_left = get_height(node->m_left);
   my_level_right = get_height(node->m_right);
   // std::cout << "XT_DEBUG: At node: value=" << node->m_value << " my_level_left=" << my_level_left << " my_level_right=" << my_level_right << std::endl;

   if ((std::abs(my_level_left - my_level_right) < 2) && is_balanced_binary(node->m_left) && is_balanced_binary(node->m_right)) {
      return true;
   }
   return false;
}
