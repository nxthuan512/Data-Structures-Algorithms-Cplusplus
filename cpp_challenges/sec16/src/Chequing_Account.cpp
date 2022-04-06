#include "Chequing_Account.hpp"

Chequing_Account::Chequing_Account(std::string t_name, double t_balance)
   : m_name(t_name), m_balance(t_balance) {
      printf ("XT_DEBUG: Created Chequing_Account: name=%s, balance=%.1f\n", m_name.c_str(), m_balance);
}

bool Chequing_Account::deposit(double t_amount) {
   if (t_amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", t_amount);
      return false;
   } else {
      m_balance += t_amount;
      return true;
   }
}

bool Chequing_Account::withdraw(double t_amount) {
   if (t_amount < 0) {
      printf ("XT_DEBUG: Amount must be positive: amount=%.1f\n", t_amount);
      return false;
   } else if (t_amount > m_balance) {
      printf ("XT_DEBUG: Amount must be smaller than balance: amount=%.1f, balance=%.1f\n", t_amount, m_balance);
      return false;
   } else {
      m_balance += t_amount;
      return true;
   }
}
