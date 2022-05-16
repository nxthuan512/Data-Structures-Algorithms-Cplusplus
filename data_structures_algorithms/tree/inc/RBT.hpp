#ifndef RBT_HPP
#define RBT_HPP

#include "Node_RBT.hpp"
#include "AVL.hpp"

class RBT: public AVL {
public:
   RBT();
   ~RBT();

   // create tree
   void create_tree(RBT *tree);
   // insert node to RBT
   Node_RBT *insert_node(Node_RBT *node, int value);
   // delete node in RBT
   Node_RBT *delete_node(Node_RBT *node, int value);

   // check if tree is RBT
   bool is_rbt_tree(Node_RBT *node);
};

RBT *create_rbt();
void check_rbt(RBT &rbt);


#endif /* RBT_HPP */
