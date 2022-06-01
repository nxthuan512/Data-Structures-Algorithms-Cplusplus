#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph {
private: 
   int m_nv;
   int m_ne;
   std::vector<int> m_graph;
public:
   Graph(int n_edges = 0, int n_vertices = 0);
   ~Graph();
   void add_edge(int src_v, int dest_v);
};



#endif /* GRAPH_HPP */
