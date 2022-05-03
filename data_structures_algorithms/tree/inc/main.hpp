#ifndef MAIN_HPP
#define MAIN_HPP

#include "Tree.hpp"

Tree *create_tree(Tree_Type my_type);
void delete_tree(Tree my_tree);
void check_tree_type(Tree_Type my_type, Tree &my_tree);


#endif /* MAIN_HPP */
