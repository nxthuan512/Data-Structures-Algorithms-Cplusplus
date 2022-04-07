#ifndef SAVINGS_ACCOUNT_HPP
#define SAVINGS_ACCOUNT_HPP

#include "Account.hpp"
#include <iostream>
#include <string>

class Savings_Account: public Account {
private:
   static constexpr const char *def_name {"Unnamed Savings_Account"};
   static constexpr const double def_balance {0.0};
   static constexpr const double def_interest_rate {2};

protected:
   std::string m_name;
   double m_balance;
   double m_interest_rate;

public:
   Savings_Account(std::string t_name = def_name, double t_balance = def_balance, double t_interest_rate = def_interest_rate);
   virtual bool deposit(double t_amount) override;
   virtual bool withdraw(double t_amount) override;
   virtual void print(std::ostream &t_string) const override;
   virtual ~Savings_Account() = default;
};


#endif /* SAVINGS_ACCOUNT_HPP */
