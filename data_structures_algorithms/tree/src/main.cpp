#include "main.hpp"

int main() {
   Tree my_tree {0};
   my_tree.create_tree(Full_BT);
   my_tree.delete_tree(my_tree.get_root());

   return 0;
}
