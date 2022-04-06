#ifndef CHEQUING_ACCOUNT_HPP
#define CHEQUING_ACCOUNT_HPP

#include <iostream>
#include <string>
#include "Account.hpp"

class Chequing_Account: public Account {
   private:
      static constexpr const double def_balance {0.0};

   public:
      Chequing_Account(std::string t_name, double t_balance);
      virtual bool deposit(double t_amount) override;
      virtual bool withdraw(double t_amount) override;
      virtual ~Chequing_Account() {};

   protected:
      std::string m_name;
      double m_balance;
};



#endif /* CHEQUING_ACCOUNT_HPP */
