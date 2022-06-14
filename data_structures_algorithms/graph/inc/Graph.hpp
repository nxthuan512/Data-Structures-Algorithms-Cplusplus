#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <tuple>

class Graph {
private: 
   int m_nv;
   int m_ne;
   std::vector<std::list<std::tuple<int, int>>> m_graph;
   std::vector<std::list<std::tuple<int, int>>> m_trans_graph;
   std::vector<int> m_visited;
   std::vector<int> m_saved_order;
public:
   Graph(int n_vertices = 0, int n_edges = 0);
   ~Graph();
   // 0: undirected; 1: directed and/or weighted, 2: bidrected and/or weighted
   void add_edge(int src_v, int dest_v, int direction = 0, int weight = 0);
   void print_all();

   // Functions supports Graph algorithms
   // Insert the start vertex to vector saved_order
   void fill_dfs_stack(int start_vertex);
   // Transpose the graph
   void transpose_graph();

   // Graph algorithms
   void reset_visited();
   void deep_first_search(int current_vertex);
   void deep_first_search_directed_graph();
   void breadth_first_search(int current_vertex);
   void min_spanning_tree(int start_vertex);
   void strongly_connected_components();
};



#endif /* GRAPH_HPP */
