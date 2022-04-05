#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class account {
   private:
      // Define the default values within class account
      static constexpr const char *def_name = "Unnamed account";
      static constexpr double def_balance = 0.0;

   protected:
      std::string name;
      double balance;

   public:
      account(std::string name = def_name, double balance = def_balance);
      ~account();
      bool deposit(double amount);
      bool withdraw(double amount);
      double get_balance() const;
};


#endif /* ACCOUNT_H */
