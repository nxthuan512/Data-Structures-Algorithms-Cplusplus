#include "chequing_account.h"

chequing_account::chequing_account(std::string new_name, double new_balance, double new_withdraw_fee)
   : account {new_name, new_balance}, withdraw_fee (new_withdraw_fee) {
      printf ("XT_DEBUG: Created a chequing account name=%s, balance=%.1f, withdraw fee=%.1f\n", new_name.c_str(), new_balance, new_withdraw_fee);
}

chequing_account::~chequing_account() {
   printf ("XT_DEBUG: Removed the chequing account name=%s\n", name.c_str());
}

bool chequing_account::withdraw(double amount) {
   if (amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: deposit=%.1f\n", amount);
      return false;
   } else if (amount + withdraw_fee > balance) {
      printf ("XT_DEBUG: Insufficient balance: balance=%.1f, amount=%.1f, withdraw fee=%.1f\n", balance, amount, withdraw_fee);
      return false;
   } else {
      balance -= (amount + withdraw_fee);
      return true;
   }
}
