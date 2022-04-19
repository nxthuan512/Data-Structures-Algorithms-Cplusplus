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
};


#endif /* SORT_HPP */
