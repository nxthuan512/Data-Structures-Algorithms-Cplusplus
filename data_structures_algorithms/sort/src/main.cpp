#include "main.hpp"

// Initialize the vector with random values
void init_vector(int length, std::vector<int> &vec) {
   std::cout << "XT_INFO: Create a vector containing length=" << length << " random values" << std::endl;
   std::srand(unsigned(std::time(nullptr)));
   vec.resize(length);
   std::generate(vec.begin(), vec.end(), []() {return std::rand() % 100;});
   // vec = {63, 40, 52, 61, 1, 4, 61, 61, 85, 14};
}

// Display vector content
void display_vector(const std::vector<int> &vec) {
   std::cout << "XT_INFO: Vector content: ";
   for (const auto &v : vec) {
      std::cout << v << " ";
   }
   std::cout << std::endl;
}

// Test cases
void test_sort(Sort_algo sort_algo, const std::vector<int> &vec_org, Sort &sort) {
   std::vector<int> vec {vec_org};
   std::string sort_algo_str = (sort_algo == Bubble_Sort) ? "Bubble Sort" : 
                               (sort_algo == Quick_Sort)  ? "Quick Sort" : 
                               (sort_algo == Merge_Sort)  ? "Merge Sort" : "STL";

   std::cout << "XT_INFO: Sorting vector using " << sort_algo_str << " (ascending, length=" << vec.size() << ")" << std::endl;
   std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

   if (sort_algo == Bubble_Sort) {
      sort.bubble_sort(vec);
   } else if (sort_algo == Quick_Sort) {
      sort.quick_sort(vec, 0, vec.size());
   } else if (sort_algo == Merge_Sort) {
      sort.merge_sort(vec, 0, vec.size()-1);
   } else if (sort_algo == STL) {
      std::sort(vec.begin(), vec.end());
   }
   display_vector(vec);
   std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
   std::cout << "Sort time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

}

int main() {
   Sort sort;
   std::vector<int> vec;
   std::vector<int> vec_org;

   init_vector(10, vec_org);
   // display_vector(vec_org);

   test_sort(Bubble_Sort, vec_org, sort);
   test_sort(Quick_Sort, vec_org, sort);
   test_sort(Merge_Sort, vec_org, sort);
   test_sort(STL, vec_org, sort);
   return 0;
}
