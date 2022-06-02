#include "main.hpp"

int main() {
   Graph simple_graph = initialize_graph(5);
   simple_graph.print_all();
   return 0;
}

// =========================================
Graph initialize_graph(int n_vertices) {
   std::cout << "Initialize graph" << std::endl;
   Graph simple_graph(n_vertices, 0);
   simple_graph.add_edge(0, 1);
   simple_graph.add_edge(0, 2);
   simple_graph.add_edge(0, 3);
   simple_graph.add_edge(1, 2);

   return simple_graph;
}
