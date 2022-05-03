#ifndef NODE_HPP
#define NODE_HPP

class Node {
private: 
   int m_value;
   Node *m_left;
   Node *m_right;
public:
   Node(int value = 0);
   ~Node();

   friend class Tree;
};

#endif /* NODE_HPP */
