#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <list>

class Graph {
private: 
   int m_nv;
   int m_ne;
   std::vector<std::list<int>> m_graph;
   std::vector<int> m_visited;
public:
   Graph(int n_vertices = 0, int n_edges = 0);
   ~Graph();
   // 0: undirected; 1: directed and/or weighted, 2: bidrected and/or weighted
   void add_edge(int src_v, int dest_v, int direction = 0);
   void print_all();

   // Graph algorithms
   void reset_visited();
   void deep_first_search(int current_vertex);
   void breadth_first_search(int current_vertex);
   void min_spanning_tree();
   void strongly_connected_components();
};



#endif /* GRAPH_HPP */
