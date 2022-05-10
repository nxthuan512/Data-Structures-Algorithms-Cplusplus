#ifndef BST_HPP
#define BST_HPP

#include "Tree.hpp"

class BST: public Tree {
public:
   // Constructor
   BST();
   ~BST();

   // create tree
   void create_tree(BST *tree);
   // get left most node
   Node *get_left_most_node_in_right(Node *node);
   // insert node to BST
   Node *insert_node(Node *node, int value);
   // delete node in BST
   Node *delete_node(Node *node, int value);

   // check if tree is BST
   bool is_binary_search_tree(Node *node);
};

BST *create_bst();
void check_bst(BST &bst);

#endif /* BST_HPP */
