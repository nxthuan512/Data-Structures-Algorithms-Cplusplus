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

// ========= Bubble sort =========
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

// ========= Quick sort =========
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

// ========= Merge sort =========
void Sort::merge_sort_merge_sorted_arrays(std::vector<int> &vec, int start_idx_1, int start_idx_2, int end_idx) {
   // Create 2 copied vectors
   int end_idx_1 = start_idx_2;
   int end_idx_2 = end_idx;

   std::vector<int> vec_1 {vec.begin()+start_idx_1, vec.begin()+end_idx_1};
   std::vector<int> vec_2 {vec.begin()+start_idx_2, vec.begin()+end_idx_2};
   // std::cout << "XT_DEBUG: start_idx_1=" << start_idx_1 << " end_idx_1=" << end_idx_1 << " vec_1: " << vec_1;
   // std::cout << "XT_DEBUG: start_idx_2=" << start_idx_2 << " end_idx_2=" << end_idx_2 << " vec_2: " << vec_2;

   unsigned long idx_1 = 0;
   unsigned long idx_2 = 0;

   // Merge from start_idx_1 to min(length_1, length_2)
   int idx = start_idx_1;
   while (idx_1 < vec_1.size() && idx_2 < vec_2.size()) {
      // std::cout << "XT_DEBUG: Before: idx=" << idx << " idx_1=" << idx_1 << " idx_2=" << idx_2 << " vec_1[idx_1]=" << vec_1.at(idx_1) << " vec_2[idx_2]=" << vec_2.at(idx_2) << std::endl;
      if (vec_1.at(idx_1) > vec_2.at(idx_2)) {
         vec.at(idx) = vec_2.at(idx_2);
         ++idx_2;
      } else if (vec_1.at(idx_1) <= vec_2.at(idx_2)) {
         vec.at(idx) = vec_1.at(idx_1);
         ++idx_1;
      }
      ++idx;
      // std::cout << "XT_DEBUG: After: idx=" << idx << " idx_1=" << idx_1 << " idx_2=" << idx_2 << std::endl;
      // std::cout << "XT_DEBUG: vec: " << vec;
   }

   // Copy the remaining to vec
   // std::cout << "XT_DEBUG: Before: idx=" << idx << " idx_1=" << idx_1 << " idx_2=" << idx_2 << std::endl;
   while (idx_1 < vec_1.size()) {
      vec.at(idx) = vec_1.at(idx_1);
      ++idx_1;
      ++idx;
   }
   while (idx_2 < vec_2.size()) {
      vec.at(idx) = vec_2.at(idx_2);
      ++idx_2;
      ++idx;
   }
   // std::cout << "XT_DEBUG: After: idx=" << idx << " idx_1=" << idx_1 << " idx_2=" << idx_2 << std::endl;
   // std::cout << "XT_DEBUG: vec: " << vec << std::endl;
}

void Sort::merge_sort(std::vector<int> &vec, int start_idx, int end_idx, bool ascending) {
   if (ascending == true) {
      if (start_idx < end_idx) {
         int mid_idx = start_idx + (end_idx - start_idx)/2;
         merge_sort(vec, start_idx, mid_idx);
         merge_sort(vec, mid_idx+1, end_idx);
         merge_sort_merge_sorted_arrays(vec, start_idx, mid_idx+1, end_idx+1);
      }
   } else {
      std::cerr << "XT_ERROR: Descending sort is not supported" << std::endl;
   }
}

// ========= Heap sort =========
void Sort::heap_sort_heapify(std::vector<int> &vec, int index, bool ascending) {
   int vec_size = vec.size();
   int select_index = index;
   int l = 2 * index + 1;
   int r = 2 * index + 2;

   if (ascending == true) {
      if (l < vec_size && vec[l] < vec[select_index])
         select_index = l;
      if (r < vec_size && vec[r] < vec[select_index])
         select_index = r;
   } else {
      if (l < vec_size && vec[l] > vec[select_index])
         select_index = l;
      if (r < vec_size && vec[r] > vec[select_index])
         select_index = r;
   }

   if (select_index != index)
   {
      int tmp = vec[index];
      vec[index] = vec[select_index];
      vec[select_index] = tmp;
      heap_sort_heapify(vec, select_index, ascending);
   }
}

void Sort::heap_sort_insert(std::vector<int> &vec, int new_value, bool ascending) {
   int vec_size = vec.size();

   vec.push_back(new_value);
   if (vec_size > 0) {
      vec_size = vec.size();
      // Ignore the leaf nodes (only run from all levels that are above leaf nodes)
      for (int i = vec_size/2-1; i >= 0; --i) {
         heap_sort_heapify(vec, i, ascending);
      }
   }
}

void Sort::heap_sort_delete(std::vector<int> &vec, int delete_value, bool ascending)
{
   int vec_size = vec.size();

   for (int i = 0; i < vec_size; i++)
   {
      if (delete_value == vec[i]) {
         // Swap the delete_value with the last value in the vector
         int tmp = vec[i];
         vec[i] = vec[vec_size-1];
         vec[vec_size-1] = tmp;
         break;
      }
   }

   vec.pop_back();
   for (int i = vec_size/2-1; i >= 0; --i)
   {
      heap_sort_heapify(vec, i, ascending);
   }
}

void Sort::heap_sort(std::vector<int> &vec, bool ascending) {
   std::vector<int> sorted_vec;

   // Insert
   for (const auto &v : vec) {
      heap_sort_insert(sorted_vec, v, ascending);
   }

   // std::cout << "XT_DEBUG: Max-Heap" << std::endl;
   // for (const auto &v: sorted_vec) {
   //    std::cout << v << " ";
   // }
   // std::cout << std::endl;

   // Delete for heap sort
   vec.clear();
   int vec_size = sorted_vec.size();
   for (int i = 0; i < vec_size; ++i) {
      vec.push_back(sorted_vec[0]);
      heap_sort_delete(sorted_vec, sorted_vec[0], ascending);
   }
}
