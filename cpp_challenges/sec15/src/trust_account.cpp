#include "trust_account.h"


trust_account::trust_account(std::string new_name, double new_balance, double new_rate)
   : savings_account {new_name, new_balance, new_rate} {
      printf ("XT_DEBUG: Created a trust account name=%s, balance=%.1f, rate=%.1f\n", \
               new_name.c_str(), new_balance, new_rate);
   }

trust_account::~trust_account() {
   printf ("XT_DEBUG: Removed trust account name=%s\n", name.c_str());
};

bool trust_account::deposit (double amount) {
   if (amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", amount);
      return false;
   } else {
      printf ("XT_DEBUG: Deposit a trust amount=%.1f\n", amount);
      if (amount >= 5000) {
         amount += 50;
         printf ("XT_DEBUG: Receive a bonus=%.1f. Total trust amount=%.1f\n", bonus, amount);
      }
      return savings_account::deposit(amount);
   }
}

bool trust_account::withdraw(double amount) {
   static int n_withdraw = 1;
   if (n_withdraw < 4) {
      return savings_account::withdraw(amount);
   } else {
      printf ("XT_DEBUG: Cannot withdraw because you withdrawed more than 3 times per year\n");
      return false;
   }
}

