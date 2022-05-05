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
   // get max height between 2 subtrees
   int calc_balance_factor(Node *node);
   // insert node to AVL
   Node *insert_node(Node *node, int value);
   // delete node in AVL
   Node *delete_node(Node *node, int value);

   // check if tree is AVL
   bool is_avl_tree(Node *node);
};


#endif /* AVL_HPP */
