#include "Tree.hpp"
#include "BST.hpp"
#include <string>
#include <iostream>

// =======================================================
// Constructor/Destructor
// =======================================================
Tree::Tree() {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
}

Tree::~Tree() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

// =======================================================
// Getter
// =======================================================
// Get the root of tree
Node *Tree::get_root() {
   return m_node;
}

// Get the root value of tree
int Tree::get_root_value() {
   Node *my_root = get_root();
   return my_root->m_value;
}

// Find the height of tree from node
int Tree::get_height(Node *node) {
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
int Tree::get_height_left_most_node(Node *node) {
   int height_left = 0;
   while (node->m_left != nullptr) {
      ++height_left;
      node = node->m_left;
   }
   return (height_left+1);
}

// Get number of nodes in tree
int Tree::get_num_nodes(Node *node) {
   if (node == nullptr) {
      return 0;
   }
   return (1 + get_num_nodes(node->m_left) + get_num_nodes(node->m_right));
}

// =======================================================
// Create/Delete/Insert Node
// =======================================================
Node *Tree::create_node(int value, int height) {
   std::cout << "Create a node: value=" << value << std::endl;
   Node *new_node = new Node {value, height};
   return new_node; 
}

// =======================================================
// Create/Delete Tree
// =======================================================
void Tree::create_tree(Tree *tree, Tree_Type type) {
   switch (type) {
      case Full_BT: {
         std::cout << "Create a FULL BINARY TREE" << std::endl;
         tree->m_node = create_node(0);
         tree->m_node->m_left = create_node(2);          
         tree->m_node->m_right = create_node(3);          
         tree->m_node->m_left->m_left = create_node(4);          
         tree->m_node->m_left->m_right = create_node(5);          
         tree->m_node->m_left->m_right->m_left = create_node(6);          
         tree->m_node->m_left->m_right->m_right = create_node(7);          
         tree->m_node->m_left->m_right->m_left->m_left = create_node(8);          
         tree->m_node->m_left->m_right->m_left->m_right = create_node(9);          
         break;
      }

      case Perfect_BT: {
         std::cout << "Create a PERFECT BINARY TREE" << std::endl;
         tree->m_node = create_node(0);
         tree->m_node->m_left = create_node(2);          
         tree->m_node->m_right = create_node(3);          
         tree->m_node->m_left->m_left = create_node(4);          
         tree->m_node->m_left->m_right = create_node(5);          
         tree->m_node->m_right->m_left = create_node(6);          
         tree->m_node->m_right->m_right = create_node(7);          
         tree->m_node->m_left->m_left->m_left = create_node(8);          
         tree->m_node->m_left->m_left->m_right = create_node(9);          
         tree->m_node->m_left->m_right->m_left = create_node(10);          
         tree->m_node->m_left->m_right->m_right = create_node(11);          
         tree->m_node->m_right->m_left->m_left = create_node(12);          
         tree->m_node->m_right->m_left->m_right = create_node(13);          
         tree->m_node->m_right->m_right->m_left = create_node(14);          
         tree->m_node->m_right->m_right->m_right = create_node(15);          
         break;
      }

      case Complete_BT: {
         std::cout << "Create a COMPLETE BINARY TREE" << std::endl;
         tree->m_node = create_node(0);
         tree->m_node->m_left = create_node(2);          
         tree->m_node->m_right = create_node(3);          
         tree->m_node->m_left->m_left = create_node(4);          
         tree->m_node->m_left->m_right = create_node(5);          
         tree->m_node->m_right->m_left = create_node(6);          
         // m_right->m_right = create_node(7);          
         break;
      }

      case Balanced_BT: {
         std::cout << "Create a BALANCED BINARY TREE" << std::endl;
         tree->m_node = create_node(0);
         tree->m_node->m_left = create_node(2);          
         tree->m_node->m_right = create_node(3);          
         tree->m_node->m_left->m_left = create_node(4);          
         tree->m_node->m_left->m_right = create_node(5);          
         tree->m_node->m_right->m_left = create_node(6);          
         tree->m_node->m_right->m_right = create_node(7);          
         tree->m_node->m_left->m_left->m_left = create_node(8);          
         tree->m_node->m_left->m_left->m_right = create_node(9);          
         tree->m_node->m_left->m_left->m_left->m_left = create_node(16);          
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

void Tree::delete_tree(Node *node, int root_value) {
   if (node == nullptr) {
      return;
   }
   // std::cout << "XT_DEBUG: At node: value=" << node->m_value << " root_value=" << root_value << std::endl;
   delete_tree(node->m_left, root_value);
   delete_tree(node->m_right, root_value);

   std::cout << "Delete node: value=" << node->m_value << std::endl;
   delete node;
}

// =======================================================
// Check Tree type
// =======================================================
bool Tree::is_full_binary(Node *node) {
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

bool Tree::is_perfect_binary(Node *node, int my_height_left, int my_level) {
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

bool Tree::is_complete_binary(Node *node, int my_num_nodes, int my_index) {
   if (node == nullptr) {
      return true;
   }
   // std::cout << "XT_DEBUG: node.value=" << node->m_value << " my_num_nodes=" << my_num_nodes << " my_index=" << my_index << std::endl;
   if (my_index >= my_num_nodes) {
      return false;
   }
   return (is_complete_binary(node->m_left, my_num_nodes, 2*my_index+1)) && (is_complete_binary(node->m_right, my_num_nodes, 2*my_index+2));
}

bool Tree::is_balanced_binary(Node *node) {
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

// ======================================================================
Tree *create_tree(Tree_Type my_type) {
   Tree *my_tree = new Tree;
   my_tree->create_tree(my_tree, my_type);
   return my_tree;
}

void delete_tree(Tree my_tree) {
   Node *my_root = my_tree.get_root();
   int my_root_value = my_tree.get_root_value();
   my_tree.delete_tree(my_root, my_root_value);
}

void check_tree_type(Tree_Type my_type, Tree &my_tree) {
   Node *my_root = my_tree.get_root();
   bool my_check;
   int my_height;

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
         int my_height_left = my_tree.get_height_left_most_node(my_root);
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

      case Balanced_BT: {
         my_check = my_tree.is_balanced_binary(my_root);
         if (my_check == true) {
            std::cout << "This is a balanced binary tree" << std::endl;
         } else {
            std::cout << "This is NOT a balanced binary tree" << std::endl;
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
}
