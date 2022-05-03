#include "Node.hpp"

// =======================================================
// Constructor/Destructor
// =======================================================
Node::Node(int value)
: m_value(value), m_left(nullptr), m_right(nullptr) {
   // std::cout << "XT_DEBUG: Call a constructor: value=" << m_value << std::endl;
}

Node::~Node() {
   // std::cout << "XT_DEBUG: Call a destruction: value=" << m_value << std::endl;
} 

