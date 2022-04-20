#ifndef MAIN_HPP
#define MAIN_HPP

#include <vector>
#include <chrono>
#include "Sort.hpp"

enum Sort_algo   {Bubble_Sort, \
                  Quick_Sort, \
                  Merge_Sort, \
                  Heap_Sort, \
                  STL};

void init_vector(int length, std::vector<int> &vec);
void display_vector(const std::vector<int> &vec);
void test_sort(Sort_algo sort_algo, const std::vector<int> &vec, Sort &sort);

#endif /* MAIN_HPP */
