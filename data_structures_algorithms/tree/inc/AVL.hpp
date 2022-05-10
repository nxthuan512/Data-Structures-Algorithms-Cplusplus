#ifndef AVL_HPP
#define AVL_HPP

#include "Tree.hpp"

class AVL: public Tree {
public:
   // Constructor
   AVL();
   ~AVL();

   // create tree
   void create_tree(AVL *tree);
   // calculate balanced factor
   int calc_balance_factor(Node *node);
   // get height of subtrees
   int get_height(Node *node) const;
   // get max height between 2 subtrees
   int get_max_height(Node *node) const;
   // left rotation
   Node *left_rotation(Node *node);
   // right rotation
   Node *right_rotation(Node *node);
   // insert node to AVL
   Node *insert_node(Node *node, int value);
   // delete node in AVL
   Node *delete_node(Node *node, int value);

   // check if tree is AVL
   bool is_avl_tree(Node *node);
};

AVL *create_avl();
void check_avl(AVL &avl);

#endif /* AVL_HPP */
