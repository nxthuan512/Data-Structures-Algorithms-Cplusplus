#include "Graph.hpp"
#include <iostream>

// Constructor
Graph::Graph(int n_vertices, int n_edges) 
: m_nv {n_vertices}, m_ne {n_edges}{
   // Initialize graph based on the number of virtices
   std::cout << "XT_DEBUG: #vertices=" << m_nv << " #edges=" << m_ne << std::endl;
   std::list<int> empty_list;
   for (int v = 0; v < m_nv; ++v) {
      m_graph.push_back(empty_list);
   }
}

// Deconstructor
Graph::~Graph() = default;

// Add edge to graph
void Graph::add_edge(int src_v, int dest_v, bool bidir) {
   std::cout << "XT_DEBUG: Add edge: src=" << src_v << " dest=" << dest_v << std::endl;
   m_graph[src_v].push_back(dest_v);
   if (bidir) {
      m_graph[dest_v].push_back(src_v);
   }
}

// Print graph
void Graph::print_all() {
   for (int v = 0; v < m_nv; ++v) {
      std::cout << "Number of edges at vertex " << v << ": " << m_graph[v].size() << std::endl;
      std::cout << v << " -> ";
      for (const auto e : m_graph[v]) {
         std::cout << e << " "; 
      }
      std::cout << std::endl;
   }
}
