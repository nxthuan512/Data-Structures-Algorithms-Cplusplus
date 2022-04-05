#ifndef CHEQUING_ACCOUNT_H
#define CHEQUING_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"

class chequing_account: public account {
   private:
      static constexpr const char *def_name = "Unamed chequing account";
      static constexpr const double def_balance = 0.0;
      static constexpr const double def_withdraw_fee = 1.5;

   protected: 
      double withdraw_fee;

   public:
      chequing_account(std::string name = def_name, double balance = def_balance, double withdraw_fee = def_withdraw_fee);
      ~chequing_account();
      bool withdraw(double);
};


#endif /* CHEQUING_ACCOUNT_H */
