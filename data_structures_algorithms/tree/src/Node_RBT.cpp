#include "Node_RBT.hpp"
#include <iostream>

// =======================================================
// Constructor/Destructor
// =======================================================
Node_RBT::Node_RBT(int value, Color_RBT color, Node_RBT *parent)
: m_color(color), m_parent(parent) {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
   Node {value};
}

Node_RBT::~Node_RBT() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

Node_RBT *Node_RBT::create_node(int value, Color_RBT color, Node_RBT *parent) {
   std::cout << "Create a RBT node: value=" << value << " color=" << color << " parent=" << parent->m_value << std::endl;
   Node_RBT *new_node = new Node_RBT {value, color, parent};
   return new_node; 
}


