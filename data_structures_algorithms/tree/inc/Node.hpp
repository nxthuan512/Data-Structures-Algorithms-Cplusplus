#ifndef NODE_HPP
#define NODE_HPP

class Node {
   friend class Tree;
private: 
   int m_value;
   Node *m_left;
   Node *m_right;
public:
   Node(int value = 0);
   ~Node();
};

#endif /* NODE_HPP */
