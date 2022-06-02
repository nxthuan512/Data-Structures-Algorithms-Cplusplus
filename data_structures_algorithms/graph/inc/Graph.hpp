#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list>

class Graph {
private: 
   int m_nv;
   int m_ne;
   std::vector<std::list<int>> m_graph;
public:
   Graph(int n_vertices = 0, int n_edges = 0);
   ~Graph();
   void add_edge(int src_v, int dest_v, bool bidir = true);
   void print_all();
};



#endif /* GRAPH_HPP */
