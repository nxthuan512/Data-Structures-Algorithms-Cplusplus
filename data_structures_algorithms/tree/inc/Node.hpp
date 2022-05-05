#ifndef NODE_HPP
#define NODE_HPP

class Node {
   friend class Tree;
private: 
   int m_value;
   int m_height;
   Node *m_left;
   Node *m_right;
public:
   Node(int value = 0, int height = 0);
   ~Node();
};

#endif /* NODE_HPP */
