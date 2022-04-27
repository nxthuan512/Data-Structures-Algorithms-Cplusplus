#ifndef TREE_HPP
#define TREE_HPP

#include <string>

enum Tree_Type {Full_BT, Complete_BT, Perfect_BT, Balanced_BT};

class Tree {
private:
   int m_value;
   Tree *m_left;
   Tree *m_right;
public:
   Tree(int value = 0);
   ~Tree();

   // get root
   Tree *get_root();
   // get height
   int get_height(Tree *node);
   // get height from left side
   int get_height_left_only(Tree *node);
   // get number of nodes
   int get_num_nodes(Tree *node);

   // create node
   Tree *create_node(int value);
   // create tree
   void create_tree(Tree_Type type);
   // delete tree
   void delete_tree(Tree *tree);

   // check if tree is full binary tree
   bool is_full_binary(Tree *root);
   // check if tree is perfect binary tree
   bool is_perfect_binary(Tree *node, int my_height_left, int my_level = 0);
   // check if tree is complete binary tree
   bool is_complete_binary(Tree *node, int my_num_nodes, int my_index = 0);
};


#endif /* TREE_HPP */
