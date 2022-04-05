#include "savings_account.h"

savings_account::savings_account(std::string new_name, double new_balance, double new_rate)
   : account {new_name, new_balance}, rate (new_rate) {
      printf ("XT_DEBUG: Created a savings account name=%s, balance=%.1f, rate=%.1f\n", \
               new_name.c_str(), new_balance, new_rate);
   }

savings_account::~savings_account() {
   printf ("XT_DEBUG: Removed savings account name=%s\n", name.c_str());
};

bool savings_account::deposit (double amount) {
   if (amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amout=%.1f\n", amount);
      return false;
   } else {
      amount += (amount * (rate/100));
      return account::deposit(amount);
   }
}


