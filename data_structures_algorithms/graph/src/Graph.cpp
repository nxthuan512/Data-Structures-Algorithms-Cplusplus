#include "Graph.hpp"

// Constructor
Graph::Graph(int n_edges, int n_vertices) 
: m_nv {n_vertices}, m_ne {n_edges}{
   // Initialize graph based on the number of edges
   for (int i = 0; i < n_vertices; ++i) {
      m_graph.push_back(0);
   }
};

// Deconstructor
Graph::~Graph() = default;

// Add edge to graph
void Graph::add_edge(int src_v, int dest_v) {
   m_graph[src_v].push_back(0);
}
