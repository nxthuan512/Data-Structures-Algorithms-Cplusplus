#include "main.hpp"

int main() {
   // test_DFS();
   // test_BFS();
   // test_Strongly_Connected_Components();
   test_Spanning_Tree();

   return 0;
}

// =========================================
Graph *initialize_graph(int n_vertices, TestCase test_case) {
   std::cout << "Initialize directed graph" << std::endl;
   Graph *simple_graph = new Graph(n_vertices, 0);

   // Test cases for DFS, BFS
   switch (test_case) {
      case DFS: 
      case BFS: 
         simple_graph->add_edge(0, 1);
         simple_graph->add_edge(0, 2);
         simple_graph->add_edge(0, 3);
         simple_graph->add_edge(1, 2);
         simple_graph->add_edge(2, 4);
         break;
      case SCC:
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
      case STR:
         simple_graph->add_edge(0, 1, 0, 4);
         simple_graph->add_edge(0, 2, 0, 4);
         simple_graph->add_edge(1, 2, 0, 2);
         simple_graph->add_edge(2, 3, 0, 3);
         simple_graph->add_edge(2, 4, 0, 2);
         simple_graph->add_edge(2, 5, 0, 4);
         simple_graph->add_edge(3, 5, 0, 3);
         simple_graph->add_edge(4, 5, 0, 3);
         break;
      default:;
   }

   return simple_graph;
}

void test_DFS() {
   Graph *simple_graph = initialize_graph(5, DFS);
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
   Graph *simple_graph = initialize_graph(5, BFS);
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


void test_Strongly_Connected_Components() {
   Graph *simple_graph = initialize_graph(8, SCC);
   simple_graph->print_all();

   std::cout << "=============================================" << std::endl;
   std::cout << "Find Strongly Connected Components" << std::endl;
   std::cout << "=============================================" << std::endl;

   std::cout << "=== Calling DFS ===" << std::endl;
   simple_graph->deep_first_search_directed_graph();
   simple_graph->reset_visited();

   std::cout << "=== Transpose graph ===" << std::endl;
   simple_graph->transpose_graph();
   // simple_graph->print_all();

   std::cout << "=== Calling DFS on transposed graph ===" << std::endl;
   simple_graph->deep_first_search_directed_graph();
   simple_graph->reset_visited();

   delete simple_graph;
}


void test_Spanning_Tree() {
   Graph *simple_graph = initialize_graph(6, STR);
   simple_graph->print_all();

   std::cout << "=============================================" << std::endl;
   std::cout << "Find Minimum Spanning Tree" << std::endl;
   std::cout << "=============================================" << std::endl;
   simple_graph->min_spanning_tree(2);
}
