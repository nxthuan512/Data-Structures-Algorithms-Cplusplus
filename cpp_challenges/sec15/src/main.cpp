#include "main.h"

void get_all_balances(const std::vector<account> &accounts) {
   for (auto const &account:accounts) {
      account.get_balance();
   }
}

void get_all_balances(const std::vector<savings_account> &accounts) {
   for (auto const &account:accounts) {
      account.get_balance();
   }
}

void get_all_balances(const std::vector<chequing_account> &accounts) {
   for (auto const &account:accounts) {
      account.get_balance();
   }
}

void get_all_balances(const std::vector<trust_account> &accounts) {
   for (auto const &account:accounts) {
      account.get_balance();
   }
}


int main()
{
   std::vector<account> jedi_acc;
   jedi_acc.push_back({"Obiwan Kenobi", 0.0});
   jedi_acc.push_back({"Anakin Skywalker", 0.0});

   jedi_acc.at(0).deposit(778.5);
   jedi_acc.at(1).deposit(123.9);
   get_all_balances(jedi_acc);
   std::cout << "=================" << std::endl;

   std::vector<savings_account> jedi_sav_acc;
   jedi_sav_acc.push_back({"Obiwan Kenobi", 0.0, 4.3});
   jedi_sav_acc.push_back({"Anakin Skywalker", 0.0, 9.8});

   jedi_sav_acc.at(0).deposit(3265.4);
   jedi_sav_acc.at(1).deposit(9533.6);
   get_all_balances(jedi_sav_acc);
   std::cout << "=================" << std::endl;

   std::vector<chequing_account> jedi_chq_acc;
   jedi_chq_acc.push_back({"Obiwan Kenobi", 0.0});
   jedi_chq_acc.push_back({"Anakin Skywalker", 0.0});

   jedi_chq_acc.at(0).deposit(145.4);
   jedi_chq_acc.at(1).deposit(92.9);
   get_all_balances(jedi_chq_acc);

   jedi_chq_acc.at(0).withdraw(15.4);
   jedi_chq_acc.at(1).withdraw(12.9);
   get_all_balances(jedi_chq_acc);
   std::cout << "=================" << std::endl;

   std::vector<trust_account> jedi_trust_acc;
   jedi_trust_acc.push_back({"Obiwan Kenobi", 0.0, 6.7});
   jedi_trust_acc.push_back({"Anakin Skywalker", 0.0, 2.9});

   jedi_trust_acc.at(0).deposit(9533.6);
   jedi_trust_acc.at(1).deposit(3265.4);

   get_all_balances(jedi_trust_acc);
   std::cout << "=================" << std::endl;




   return 0;
}
