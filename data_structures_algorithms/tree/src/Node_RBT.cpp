#include "Node_RBT.hpp"

// =======================================================
// Constructor/Destructor
// =======================================================
Node_RBT::Node_RBT(int value, int color)
: m_color(color), m_parent(nullptr) {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
   Node {value};
}

Node_RBT::~Node_RBT() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

