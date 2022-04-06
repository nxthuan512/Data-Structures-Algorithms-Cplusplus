#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "savings_account.h"

class trust_account: public savings_account {
   private:
      static constexpr const char *def_name = "Unnamed trust account";
      static constexpr double def_balance = 0.0;
      static constexpr double def_rate = 0.0;
      static constexpr double def_bonus = 50.0;

   protected: 
      double bonus = def_bonus;
      int n_withdraw = 0;

   public:
      trust_account(std::string name = def_name, double balance = def_balance, double rate = def_rate);
      ~trust_account();
      bool deposit(double amount);
      bool withdraw(double amount);
      void increase_n_withdraw();
      int get_n_withdraw();
};


#endif /* TRUST_ACCOUNT_H */
