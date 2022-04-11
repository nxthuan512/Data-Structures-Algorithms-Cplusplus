#include "Account.hpp"

Account::Account(std::string t_name, double t_balance)
: m_name {t_name}, m_balance {t_balance} {
   if (m_balance < 0) {
      throw IllegalBalanceException();
   } else {
      printf ("XT_DEBUG: Created Account: name=%s, balance=%.1f\n", m_name.c_str(), m_balance);
   }
}

bool Account::deposit(double t_amount) {
   if (t_amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", t_amount);
      return false;
   } else {
      m_balance += t_amount;
      printf ("XT_DEBUG: Deposit: amount=%.1f new balance=%.1f\n", t_amount, m_balance);
      return true;
   }
}

bool Account::withdraw(double t_amount) {
   if (t_amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", t_amount);
      return false;
   } else {
      m_balance -= t_amount;
      if (m_balance < 0) {
         throw InsufficentFundsException();
      } else {
         printf ("XT_DEBUG: Withdraw: amount=%.1f new balance=%.1f\n", t_amount, m_balance);
         return true;
      }
   }
}

void Account::print(std::ostream &t_string) const {
   t_string.precision(2);
   t_string << "XT_DEBUG: Print Account: name=" << m_name << ", balance=" << m_balance;
}
