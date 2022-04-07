#include "main.hpp"

void display_accounts(const std::vector<Account *> &accounts) {
   std::cout << "Print all accounts" << std::endl;
   for (auto acc : accounts) {
      std::cout << *acc << std::endl;
   }
}

int main() {
   Account *acc_1 = new Chequing_Account {"Asoka Tano", 0.0};
   acc_1->deposit(1000.0);
   acc_1->withdraw(500.0);
   std::cout << *acc_1 << std::endl;

   Account *acc_2 = new Savings_Account {"Mace Windu", 0.0};
   acc_2->deposit(9000.0);
   acc_2->withdraw(750.0);
   std::cout << *acc_2 << std::endl;

   std::vector<Account *> jedi_acc {acc_1, acc_2};
   display_accounts(jedi_acc);
   return 0;
}
