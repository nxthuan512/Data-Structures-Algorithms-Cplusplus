#include "main.hpp"

int main() {
   // test_DFS();
   // test_BFS();
   test_Spanning_Tree();

   return 0;
}

// =========================================
Graph *initialize_graph(int n_vertices, int directed) {
   std::cout << "Initialize directed graph" << std::endl;
   Graph *simple_graph = new Graph(n_vertices, 0);

   // Test cases for DFS, BFS
   switch (directed) {
      case 0: 
         simple_graph->add_edge(0, 1);
         simple_graph->add_edge(0, 2);
         simple_graph->add_edge(0, 3);
         simple_graph->add_edge(1, 2);
         simple_graph->add_edge(2, 4);
         break;
      case 1:
         simple_graph->add_edge(0, 1, 1);
         simple_graph->add_edge(1, 2, 1);
         simple_graph->add_edge(2, 3, 1);
         simple_graph->add_edge(3, 0, 1);
         simple_graph->add_edge(2, 4, 1);
         simple_graph->add_edge(4, 5, 1);
         simple_graph->add_edge(5, 6, 1);
         simple_graph->add_edge(6, 4, 1);
         simple_graph->add_edge(6, 7, 1);
         break;
      default:;
   }

   return simple_graph;
}

void test_DFS() {
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
}

void test_BFS() {
   Graph *simple_graph = initialize_graph(5);
   simple_graph->print_all();

   std::cout << "=============================================" << std::endl;
   std::cout << "Calling BFS" << std::endl;
   std::cout << "=============================================" << std::endl;
   simple_graph->breadth_first_search(0);
   simple_graph->reset_visited();
   std::cout << "=============================================" << std::endl;
   simple_graph->breadth_first_search(2);
   simple_graph->reset_visited();

   delete simple_graph;
}


void test_Spanning_Tree() {
   Graph *simple_graph = initialize_graph(8, 1);
   simple_graph->print_all();

   std::cout << "Calling DFS" << std::endl;
   simple_graph->deep_first_search(0);
   simple_graph->reset_visited();

   delete simple_graph;
}
