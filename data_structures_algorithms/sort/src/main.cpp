#include "main.hpp"

// Initialize the vector with random values
void init_vector(int length, std::vector<int> &vec) {
   std::cout << "XT_INFO: Create a vector containing length=" << length << " random values" << std::endl;
   std::srand(unsigned(std::time(nullptr)));
   vec.resize(length);
   std::generate(vec.begin(), vec.end(), []() {return std::rand() % 100;});
   // vec = {63, 40, 52, 61, 1, 4, 61, 61, 85, 14};
}

void display_vector(const std::vector<int> &vec) {
   std::cout << "XT_INFO: Vector content: ";
   for (const auto &v : vec) {
      std::cout << v << " ";
   }
   std::cout << std::endl;
}

int main() {
   Sort sort;
   std::vector<int> vec;

   init_vector(10, vec);
   display_vector(vec);

   std::cout << "XT_INFO: Sorting vector using Bubble Sort (ascending, length=" << vec.size() << ")" << std::endl;
   std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
   sort.bubble_sort(vec);
   display_vector(vec);
   std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
   std::cout << "Sort time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

   std::cout << "XT_INFO: Sorting vector using Quick Sort (ascending, length=" << vec.size() << ")" << std::endl;
   begin = std::chrono::steady_clock::now();
   sort.quick_sort(vec, 0, vec.size());
   display_vector(vec);
   end = std::chrono::steady_clock::now();
   std::cout << "Sort time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

   return 0;
}
