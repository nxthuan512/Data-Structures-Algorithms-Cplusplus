#ifndef NODE_RBT_HPP
#define NODE_RBT_HPP

#include "Node.hpp"

class Node_RBT: public Node {
   friend class RBT;
private: 
   int m_color;
   Node_RBT *m_parent;
public:
   Node_RBT(int value = 0, int color = 0);
   ~Node_RBT();
};


#endif /* NODE_RBT_HPP */
