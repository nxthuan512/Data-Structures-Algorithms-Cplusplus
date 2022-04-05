#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include "account.h"

class savings_account: public account {
   private:
      static constexpr const char *def_name = "Unnamed savings account";
      static constexpr double def_balance = 0.0;
      static constexpr double def_rate = 0.0;

   protected: 
      double rate;

   public:
      savings_account(std::string name = def_name, double balance = def_balance, double rate = def_rate);
      ~savings_account();
      bool deposit(double amount);
};


#endif /* SAVINGS_ACCOUNT_H */
