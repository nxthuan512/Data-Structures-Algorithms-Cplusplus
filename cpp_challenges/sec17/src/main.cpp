#include "main.hpp"
#include <memory>

// std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
auto make() {
   std::cout << "\tXT_DEBUG: Call make()" << std::endl;
   return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec_ptr, int num) {
   std::cout << "\tXT_DEBUG: Call fill()" << std::endl;
   for (int i = 0; i < num; ++i) {
      vec_ptr.push_back(std::make_shared<Test>(std::to_string(i+10), 100+i*10));
   }
}

void display(std::vector<std::shared_ptr<Test>> &vec_ptr) {
   std::cout << "\tXT_DEBUG: Call display()" << std::endl;
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
   
   int num = 5;
   fill(*vec_ptr, num);
   display(*vec_ptr);


   std::cout << "========================" << std::endl;
   return 0;
}
