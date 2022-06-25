#ifndef SORT_HPP
#define SORT_HPP

#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

class Sort {
   friend std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec);
private:
public:
   Sort();
   ~Sort();
   void bubble_sort(std::vector<int> &vec, bool ascending=true);

   void quick_sort(std::vector<int> &vec, int start_idx, int end_idx, bool ascending=true);
   auto quick_sort_rearrange(std::vector<int> &vec, int start_idx, int end_idx);
   
   void merge_sort(std::vector<int> &vec, int start_idx, int end_idx, bool ascending=true);
   void merge_sort_merge_sorted_arrays(std::vector<int> &vec, int start_idx_1, int start_idx_2, int end_idx);

   void heap_sort(std::vector<int> &vec, bool ascending=true);
   void heap_sort_heapify(std::vector<int> &vec, int index, bool ascending=true);
   void heap_sort_insert(std::vector<int> &vec, int new_value, bool ascending=true);
   void heap_sort_delete(std::vector<int> &vec, int new_value, bool ascending=true);
};


#endif /* SORT_HPP */
