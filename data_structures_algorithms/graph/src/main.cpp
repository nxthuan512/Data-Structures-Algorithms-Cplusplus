#include "main.hpp"

int main() {
   Graph *simple_graph = initialize_graph(5);
   simple_graph->print_all();

   std::cout << "=============================================" << std::endl;
   std::cout << "Calling DFS" << std::endl;
   std::cout << "=============================================" << std::endl;
   simple_graph->deep_first_search(0);
   simple_graph->reset_visited();
   std::cout << "=============================================" << std::endl;
   simple_graph->deep_first_search(2);
   simple_graph->reset_visited();

   delete simple_graph;
   return 0;
}

// =========================================
Graph *initialize_graph(int n_vertices) {
   std::cout << "Initialize graph" << std::endl;
   Graph *simple_graph = new Graph(n_vertices, 0);
   simple_graph->add_edge(0, 1);
   simple_graph->add_edge(0, 2);
   simple_graph->add_edge(0, 3);
   simple_graph->add_edge(1, 2);
   simple_graph->add_edge(2, 4);

   return simple_graph;
}
