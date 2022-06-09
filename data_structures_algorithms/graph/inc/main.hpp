#ifndef MAIN_HPP
#define MAIN_HPP

#include "Graph.hpp"

enum TestCase {DFS, BFS, SCC, STR};

Graph *initialize_graph(int n_vertices, TestCase test_case);
void test_DFS();
void test_BFS();
void test_Strongly_Connected_Components();
void test_Spanning_Tree();


#endif /* MAIN_HPP */
