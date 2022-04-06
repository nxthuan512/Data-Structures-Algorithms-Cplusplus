#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>

class Account {
   public:
      virtual bool deposit(double t_amount) = 0;
      virtual bool withdraw(double t_amount) = 0;
      virtual ~Account() {};
};

#endif /* ACCOUNT_HPP */
