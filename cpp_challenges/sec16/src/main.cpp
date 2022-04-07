#include "main.hpp"

int main() {
   Account *acc_1 = new Chequing_Account {"Asoka", 0.0};
   acc_1->deposit(1000.0);
   acc_1->withdraw(500.0);
   // std::cout << *acc_1 << std::endl;
   return 0;
}
