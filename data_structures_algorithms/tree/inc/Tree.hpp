#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include "Node.hpp"

enum Tree_Type {Full_BT, 
                Complete_BT, 
                Perfect_BT, 
                Balanced_BT,
                Binary_Search_Tree, 
                AVL_Tree,
                B_Tree,
                Bplus_Tree,
                Black_Red_Tree};

class Tree {
private:
   Node *m_node;
public:
   Tree();
   ~Tree();

   // get root
   Node *get_root();
   // get root value
   int get_root_value();
   // get height
   int get_height(Node *node);
   // get height from left side
   int get_height_left_only(Node *node);
   // get number of nodes
   int get_num_nodes(Node *node);

   // create node
   Node *create_node(int value);
   // insert node to BTS
   Node *bts_insert_node(Node *node, int value);
   // create tree
   void create_tree(Tree *tree, Tree_Type type);
   // delete tree
   void delete_tree(Node *node, int root_value);

   // check if tree is full binary tree
   bool is_full_binary(Node *root);
   // check if tree is perfect binary tree
   bool is_perfect_binary(Node *node, int my_height_left, int my_level = 0);
   // check if tree is complete binary tree
   bool is_complete_binary(Node *node, int my_num_nodes, int my_index = 0);
   // check if tree is balanced binary tree
   bool is_balanced_binary(Node *node);
   // check if tree is BTS
   bool is_binary_search_tree(Node *node);
};


#endif /* TREE_HPP */
