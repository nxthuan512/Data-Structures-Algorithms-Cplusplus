#include "main.hpp"
#include "Savings_Account.hpp"
#include <memory>

void display_accounts(const std::vector<Account *> &accounts) {
   std::cout << "Print all accounts" << std::endl;
   for (const auto acc : accounts) {
      std::cout << *acc << std::endl;
   }
}

int main() {
   std::vector<double> balances {-10.0, 10.0};
   for (auto balance : balances) {
      try {
         std::unique_ptr<Account> acc_1 = std::make_unique<Chequing_Account>("Asoka Tano", balance);
         std::cout << *acc_1 << std::endl;
         acc_1->deposit(1000.0);
         acc_1->withdraw(500.0);
         acc_1->withdraw(1500.0);
      }
      catch (const IllegalBalanceException &ex) {
         std::cerr << ex.what() << std::endl;
      }
      catch (const InsufficentFundsException &ex) {
         std::cerr << ex.what() << std::endl;
      }
   }

   std::unique_ptr<Account> acc_2 = std::make_unique<Savings_Account>("Mace Windu", 0.0);
   acc_2->deposit(9000.0);
   acc_2->withdraw(750.0);
   std::cout << *acc_2 << std::endl;

   return 0;
}
