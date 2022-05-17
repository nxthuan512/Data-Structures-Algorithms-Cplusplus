#ifndef NODE_RBT_HPP
#define NODE_RBT_HPP

#include "Node.hpp"

enum Color_RBT {Red, Black};

class Node_RBT{
   friend class RBT;
private: 
   int m_value;
   Color_RBT m_color;
   Node_RBT *m_left;
   Node_RBT *m_right;
   Node_RBT *m_parent;
public:
   Node_RBT(int value = 0, Color_RBT color = Red, Node_RBT *parent = nullptr);
   ~Node_RBT();
   Node_RBT *create_node(int value, Color_RBT color, Node_RBT *parent);
};


#endif /* NODE_RBT_HPP */
