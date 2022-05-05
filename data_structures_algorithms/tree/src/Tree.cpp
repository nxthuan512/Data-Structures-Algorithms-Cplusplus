#include "Tree.hpp"
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

// Get max height between 2 subtrees
int Tree::calc_balance_factor(Node *node) {
   if (node == nullptr) {
      return 0;
   } else {
      return (node->m_left->m_height - node->m_right->m_height);
   }
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

// Get the left most node
Node *Tree::get_left_most_node_in_right(Node *node) {
   node = node->m_right;
   while (node->m_left != nullptr) {
      node = node->m_left;
   }
   return node;
}

// =======================================================
// Create/Delete/Insert Node
// =======================================================
Node *Tree::create_node(int value, int heigth) {
   std::cout << "Create a node: value=" << value << std::endl;
   Node *new_node = new Node {value, heigth};
   return new_node; 
}

Node *Tree::bts_insert_node(Node *node, int value) {
   if (node == nullptr) {
      // std::cout << "Insert a node to BTS: value=" << value << std::endl;
      node = create_node(value);
      return node;
   }
   if (value < node->m_value) {
      node->m_left = bts_insert_node(node->m_left, value);
   }
   if (value > node->m_value) {
      node->m_right = bts_insert_node(node->m_right, value);
   }
   return node;
}

Node *Tree::bts_delete_node(Node *node, int value) {
   // If not found 
   if (node == nullptr) {
      return nullptr;
   }
   if (value < node->m_value) {
      node->m_left = bts_delete_node(node->m_left, value);
   }
   if (value > node->m_value) {
      node->m_right = bts_delete_node(node->m_right, value);
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
         node->m_right = bts_delete_node(node->m_right, new_node->m_value);
      }
   }
   return node;
}

Node *Tree::avl_insert_node(Node *node, int value) {
   // Insert new node in leaf node
   if (node == nullptr) {
      return create_node(value);
   }
   if (value > node->m_value) {
      node->m_left = avl_insert_node(node->m_left, value);
   }
   else if (value < node->m_value) {
      node->m_right = avl_insert_node(node->m_right, value);
   }
   else {
      return node;
   }

   // Update heigth of node
   node->m_height = 1 + std::max(node->m_left->m_height, node->m_right->m_height);
   int balanced_factor = calc_balance_factor(node);

   // If tree is unbalanced, height_left > height_right
   // if (balanced_factor > 1) {
   //    if (value < node->m_value) {
   //       return avl_right_rotation(node);
   //    } else {
   //       return avl_left_rotation(node)
   //    }
   // }
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

      case Binary_Search_Tree: {
         std::cout << "Create a BINARY SEARCH TREE" << std::endl;
         tree->m_node = create_node(8);
         bts_insert_node(tree->m_node, 3);
         bts_insert_node(tree->m_node, 1);
         bts_insert_node(tree->m_node, 6);
         bts_insert_node(tree->m_node, 7);
         bts_insert_node(tree->m_node, 10);
         bts_insert_node(tree->m_node, 14);
         bts_insert_node(tree->m_node, 4);
         break;
      }

      case AVL_Tree: {
         std::cout << "Create a AVL TREE" << std::endl;
         tree->m_node = create_node(8);
         avl_insert_node(tree->m_node, 33);
         avl_insert_node(tree->m_node, 13);
         avl_insert_node(tree->m_node, 53);
         avl_insert_node(tree->m_node, 9);
         avl_insert_node(tree->m_node, 21);
         avl_insert_node(tree->m_node, 61);
         avl_insert_node(tree->m_node, 8);
         avl_insert_node(tree->m_node, 11);
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

bool Tree::is_binary_search_tree(Node *node) {
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
