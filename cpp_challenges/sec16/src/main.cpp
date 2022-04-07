#include "main.hpp"

int main() {
   Account *acc_1 = new Chequing_Account {"Asoka Tano", 0.0};
   acc_1->deposit(1000.0);
   acc_1->withdraw(500.0);
   std::cout << *acc_1 << std::endl;

   Account *acc_2 = new Savings_Account {"Mace Windu", 0.0};
   acc_2->deposit(9000.0);
   acc_2->withdraw(750.0);
   std::cout << *acc_2 << std::endl;
   return 0;
}
