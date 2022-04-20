#include "Sort.hpp"
#include <iostream>

Sort::Sort() = default;
Sort::~Sort() = default;

// Overloading the cout
std::ostream &operator<<(std::ostream &os, const std::vector<int> &vec) {
   std::cout << "XT_DEBUG: Vector content: ";
   for (const auto &v : vec) {
      std::cout << v << " ";
   }
   std::cout << std::endl;
   return os;
}

// Bubble sort
void Sort::bubble_sort(std::vector<int> &vec, bool ascending) {
   if (ascending == true) {
      int updated_length = vec.size();
      bool is_sorted = true;
      do {
         for (int i = 0; i < updated_length - 1; ++i) {
            if (vec.at(i) > vec.at(i+1)) {
               auto tmp = vec.at(i);
               vec.at(i) = vec.at(i+1);
               vec.at(i+1) = tmp;
               is_sorted = false;
            }
         }
         --updated_length;
      } while (is_sorted == false && updated_length > 0);
   } else {
      std::cerr << "XT_ERROR: Descending sort is not supported" << std::endl;
   }
}

// Quick sort
auto Sort::quick_sort_rearrange(std::vector<int> &vec, int start_idx, int end_idx) {
   // Pivot is the last vector element
   int pivot = vec.at(end_idx-1);
   auto tmp = vec.at(start_idx);
   // std::cout << "XT_DEBUG: Pivot=" << pivot << " start_idx=" << start_idx << " end_idx=" << end_idx << std::endl;
   for (int idx = start_idx; idx < end_idx; ++idx) {
      if (vec.at(idx) < pivot) {
         // std::cout << "XT_DEBUG: Pivot=" << pivot << ": swap vec[" << start_idx << "]=" << vec.at(start_idx) << " with vec[" << idx << "]=" << vec.at(idx) << std::endl;
         tmp = vec.at(start_idx);
         vec.at(start_idx) = vec.at(idx);
         vec.at(idx) = tmp;
         ++start_idx;
      }
   }
   // Swap pivot with the start_index
   vec.at(end_idx-1) = vec.at(start_idx);
   vec.at(start_idx) = pivot;
   return start_idx;
}

void Sort::quick_sort(std::vector<int> &vec, int start_idx, int end_idx, bool ascending) {
   if (ascending == true) {
      if (start_idx < end_idx) {
         int idx = quick_sort_rearrange(vec, start_idx, end_idx);
         // std::cout << vec;
         quick_sort(vec, start_idx, idx);
         quick_sort(vec, idx+1, end_idx);
      }
   } else {
      std::cerr << "XT_ERROR: Descending sort is not supported" << std::endl;
   }
}


