#include <iostream>
#include "AVL.hpp"

// =======================================================
// Create Tree
// =======================================================
void AVL::create_tree(AVL *tree) {
   std::cout << "Create a AVL TREE" << std::endl;
   tree->m_node = create_node(8);
   // insert_node(tree->m_node, 33);
   // insert_node(tree->m_node, 13);
   // insert_node(tree->m_node, 53);
   // insert_node(tree->m_node, 9);
   // insert_node(tree->m_node, 21);
   // insert_node(tree->m_node, 61);
   // insert_node(tree->m_node, 8);
   // insert_node(tree->m_node, 11);
}

// Get max height between 2 subtrees
int AVL::calc_balance_factor(Node *node) {
   if (node == nullptr) {
      return 0;
   } else {
      return (node->m_left->m_height - node->m_right->m_height);
   }
}

// Node *AVL::insert_node(Node *node, int value) {
//    // Insert new node in leaf node
//    if (node == nullptr) {
//       return create_node(value);
//    }
//    if (value > node->m_value) {
//       node->m_left = avl_insert_node(node->m_left, value);
//    }
//    else if (value < node->m_value) {
//       node->m_right = avl_insert_node(node->m_right, value);
//    }
//    else {
//       return node;
//    }

//    // Update heigth of node
//    node->m_height = 1 + std::max(node->m_left->m_height, node->m_right->m_height);
//    int balanced_factor = calc_balance_factor(node);

//    // If tree is unbalanced, height_left > height_right
//    // if (balanced_factor > 1) {
//    //    if (value < node->m_value) {
//    //       return avl_right_rotation(node);
//    //    } else {
//    //       return avl_left_rotation(node)
//    //    }
//    // }
// }

