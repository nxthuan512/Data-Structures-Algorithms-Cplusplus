#ifndef CHEQUING_ACCOUNT_HPP
#define CHEQUING_ACCOUNT_HPP

#include "Account.hpp"
#include <iostream>
#include <string>

class Chequing_Account: public Account {
private:
   static constexpr const char *def_name {"Unnamed Chequing_Account"};
   static constexpr const double def_balance {0.0};
   static constexpr const double def_withdraw_fee {1.5};

protected:
   std::string m_name;
   double m_balance;
   double m_withdraw_fee;

public:
   Chequing_Account(std::string t_name = def_name, double t_balance = def_balance, double t_withdraw_fee = def_withdraw_fee);
   virtual bool deposit(double t_amount) override;
   virtual bool withdraw(double t_amount) override;
   // virtual void print(std::ostream &t_string) const override;
   virtual ~Chequing_Account() = default;

};



#endif /* CHEQUING_ACCOUNT_HPP */
