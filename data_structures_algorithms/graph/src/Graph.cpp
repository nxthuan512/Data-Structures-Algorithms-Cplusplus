#include "Graph.hpp"
#include <iostream>

// Constructor
Graph::Graph(int n_vertices, int n_edges) 
: m_nv {n_vertices}, m_ne {n_edges}{
   // Initialize graph based on the number of vertices
   // std::cout << "XT_DEBUG: #vertices=" << m_nv << " #edges=" << m_ne << std::endl;
   std::list<int> empty_list;
   for (int v = 0; v < m_nv; ++v) {
      m_graph.push_back(empty_list);
      m_visited.push_back(0);
   }
}

// Deconstructor
Graph::~Graph() = default;

// Add edge to graph
void Graph::add_edge(int src_v, int dest_v, int direction) {
   // std::cout << "XT_DEBUG: Add edge: src=" << src_v << " dest=" << dest_v << std::endl;
   m_graph[src_v].push_back(dest_v);
   if (direction == 0) {
      m_graph[dest_v].push_back(src_v);
   }
}

// Print graph
void Graph::print_all() {
   std::cout << "=============================================" << std::endl;
   std::cout << "Calling print_all()" << std::endl;
   std::cout << "=============================================" << std::endl;
   for (int v = 0; v < m_nv; ++v) {
      std::cout << "Number of edges at vertex " << v << ": " << m_graph[v].size() << std::endl;
      std::cout << v << " -> ";
      for (const auto &e : m_graph[v]) {
         std::cout << e << " "; 
      }
      std::cout << std::endl;
   }
}

// ======================================================
void Graph::reset_visited() {
   for (auto &v : m_visited) {
      v = 0;
   }
}

void Graph::deep_first_search(int current_vertex) {
   // Base case
   m_visited[current_vertex] = 1;
   std::cout << "Visited vertex: " << current_vertex << std::endl;
   //
   for (const auto &v : m_graph[current_vertex]) {
      if (m_visited[v] == 0) {
         Graph::deep_first_search(v);
      }
   } 
}

void Graph::breadth_first_search(int current_vertex) {
   std::queue<int> my_queue;
   my_queue.push(current_vertex);
   m_visited[current_vertex] = 1;

   while (!my_queue.empty()) {
      int queue_vertex = my_queue.front();
      my_queue.pop();
      std::cout << "Visited vertex: " << queue_vertex << std::endl;

      for (const auto &v : m_graph[queue_vertex]) {
         if (m_visited[v] == 0) {
            my_queue.push(v);
            m_visited[v] = 1;
         }
      }
   }
}
