#include "main.hpp"
#include "Graph.hpp"

int main() {
   Graph simple_graph(5, 0);
   simple_graph.add_edge(0, 1);
   simple_graph.add_edge(0, 2);
   simple_graph.add_edge(0, 3);
   simple_graph.add_edge(1, 2);
   simple_graph.print_all();
   return 0;
}
