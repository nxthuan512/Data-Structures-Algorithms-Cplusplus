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
   // create node
   Tree *create_node(int value);
   // create tree
   void create_tree(Tree_Type type);
   // delete tree
   void delete_tree(Tree *tree);
};


#endif /* TREE_HPP */
