#include <iostream>
#include "AVL.hpp"

// Constructor
AVL::AVL() = default;
// Destructor
AVL::~AVL() = default;

// =======================================================
// Create Tree
// =======================================================
void AVL::create_tree(AVL *tree) {
   std::cout << "Create a AVL TREE" << std::endl;
   tree->m_node = insert_node(tree->m_node, 33);
   tree->m_node = insert_node(tree->m_node, 13);
   tree->m_node = insert_node(tree->m_node, 53);
   tree->m_node = insert_node(tree->m_node, 9);
   tree->m_node = insert_node(tree->m_node, 21);
   tree->m_node = insert_node(tree->m_node, 61);
   tree->m_node = insert_node(tree->m_node, 8);
   tree->m_node = insert_node(tree->m_node, 11);
   tree->m_node = insert_node(tree->m_node, 7);
}

// Get height of substree
int AVL::get_height(Node *node) const {
   if (node == nullptr)
      return 0;
   else 
      return node->m_height;
}

// Get max height between 2 subtrees
int AVL::get_max_height(Node *node) const {
   return std::max(get_height(node->m_left), get_height(node->m_right));
}

// Calculate the balanced factor
int AVL::calc_balance_factor(Node *node) {
   if (node == nullptr) {
      return 0;
   } else {
      return (get_height(node->m_left) - get_height(node->m_right));
   }
}

// Left rotation
Node *AVL::left_rotation(Node *x) {
   Node *y = x->m_right;
   Node *z = y->m_left;

   // Rotate
   y->m_left = x;
   x->m_right = z;

   // Update the height
   x->m_height = 1 + get_max_height(x);
   y->m_height = 1 + get_max_height(y);

   return y;
}

// Right rotation
Node *AVL::right_rotation(Node *x) {
   Node *y = x->m_left;
   Node *z = y->m_right;

   // Rotate
   y->m_right = x;
   x->m_left = z;

   // Update the height
   x->m_height = 1 + get_max_height(x);
   y->m_height = 1 + get_max_height(y);

   return y;
}

// Insert node
Node *AVL::insert_node(Node *node, int value) {
   // Insert new node in leaf node
   if (node == nullptr) {
      return create_node(value, 1);
   }

   if (value < node->m_value) {
      node->m_left = insert_node(node->m_left, value);
   }
   else if (value > node->m_value) {
      node->m_right = insert_node(node->m_right, value);
   }
   else {
      return node;
   }

   // Update height of node
   node->m_height = 1 + get_max_height(node);
   int balanced_factor = calc_balance_factor(node);

   // If tree is unbalanced and height_left > height_right
   if (balanced_factor > 1) {
      if (value < node->m_value) {
         return right_rotation(node);
      } else {
         node->m_left = left_rotation(node);
         return right_rotation(node);
      }
   }

   // If tree is unbalanced and height_right > height_left
   else if (balanced_factor < -1) {
      if (value < node->m_value) {
         return left_rotation(node);
      } else {
         node->m_right = right_rotation(node);
         return left_rotation(node);
      }
   }

   return node;
}

// ==============================================================
AVL *create_avl() {
   AVL *my_tree = new AVL;
   my_tree->create_tree(my_tree);
   return my_tree;
}

void check_avl (AVL &my_tree) {
   std::cout << "XT_INFO: Not supported Tree root = " << my_tree.get_root() << std::endl;
   // Node *my_root = my_tree.get_root();
   // bool my_check = my_tree.is_avl_tree(my_root);
   // if (my_check == true) {
   //    std::cout << "This is a binary search tree" << std::endl;
   // } else {
   //    std::cout << "This is NOT a binary search tree" << std::endl;
   // }
}
