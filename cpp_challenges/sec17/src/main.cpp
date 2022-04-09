#include "main.hpp"
#include "test.hpp"

int main() {
   // Raw pointers
   std::cout << "========================" << std::endl;
   Test t0 {"0", 10};
   std::cout << "XT_INFO: t0.data=" << t0.get_data() << std::endl;

   std::cout << "========================" << std::endl;
   Test *t1 = new Test {"1", 20};
   std::cout << "XT_INFO: t1.data=" << t1->get_data() << std::endl;
   delete t1;

   // Smart pointer

   return 0;
}
