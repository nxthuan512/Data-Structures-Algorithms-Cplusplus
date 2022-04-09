#include "main.hpp"
#include <memory>

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
   std::shared_ptr<Test> test = std::make_shared<Test>();
   std::vector<std::shared_ptr<Test>> vec_test;
   std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_test_ptr = std::make_unique<std::vector<std::shared_ptr<Test>>>();
   return vec_test_ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec_ptr, int num) {
   for (int i = 0; i < num; ++i) {
      vec_ptr.push_back(std::make_shared<Test>(std::to_string(i+10), 100+i*10));
   }
}

void display(std::vector<std::shared_ptr<Test>> &vec_ptr) {
   for (const auto &vec : vec_ptr) {
      vec->get_info();
   }
}

// ================================================
int main() {
   // Raw pointers
   std::cout << "========================" << std::endl;
   Test t0 {"0", 10};
   t0.get_info();

   std::cout << "========================" << std::endl;
   Test *t1 = new Test {"1", 20};
   t1->get_info();
   delete t1;

   // Smart pointer
   std::cout << "========================" << std::endl;
   std::unique_ptr<Test> t2 = std::make_unique<Test>("2", 30);
   t2->get_info();
   
   // Main challenge
   std::cout << "========================" << std::endl;
   std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
   vec_ptr = make();
   // std::cout << "How many data points do you want to enter: ";
   int num = 5;
   // std::cin >> num;
   fill(*vec_ptr, num);
   display(*vec_ptr);


   std::cout << "========================" << std::endl;
   return 0;
}
