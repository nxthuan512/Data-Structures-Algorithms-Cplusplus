#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "I_Printable.hpp"
#include <ostream>
#include <string>

class Account {
// class Account: public I_Printable {
private:
   static constexpr const char *def_name {"Unnamed Account"};
   static constexpr const double def_balance {0.0};

protected:
   std::string m_name;
   double m_balance;

public:
   Account(std::string t_name = def_name, double t_balance = def_balance);
   virtual bool deposit(double t_amount) = 0;
   virtual bool withdraw(double t_amount) = 0;
   // virtual void print(std::ostream &) const override;
   virtual ~Account() = default;
};

#endif /* ACCOUNT_HPP */
