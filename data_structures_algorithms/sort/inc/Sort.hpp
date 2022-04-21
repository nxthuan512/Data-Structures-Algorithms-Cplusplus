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
};


#endif /* SORT_HPP */
