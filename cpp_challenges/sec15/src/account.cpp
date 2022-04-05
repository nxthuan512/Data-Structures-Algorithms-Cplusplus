#include <iostream>
#include <string>
#include "account.h"


account::account(std::string new_name, double new_balance) 
   : name (new_name), balance (new_balance) {
   printf ("XT_DEBUG: Created an account name=%s, balance=%.1f\n", name.c_str(), balance);
}

account::~account() {
   printf ("XT_DEBUG: Removed account name=%s\n", name.c_str());
};


bool account::deposit(double amount) {
   if (amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", amount);
      return false;
   } else {
      printf ("XT_DEBUG: Deposit an amount=%.1f\n", amount);
      balance += amount;
      return true;
   }
}

bool account::withdraw(double amount) {
   if (amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: deposit=%.1f\n", amount);
      return false;
   } else if (amount > balance) {
      printf ("XT_DEBUG: Insufficient balance: balance=%.1f, amount=%.1f\n", balance, amount);
      return false;
   } else {
      balance -= amount;
      return true;
   }
}

double account::get_balance() const {
   printf ("XT_DEBUG: Balance of %s is %.1f\n", name.c_str(), balance);
   return balance;
}

