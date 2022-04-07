#include "Chequing_Account.hpp"
#include <ostream>

Chequing_Account::Chequing_Account(std::string t_name, double t_balance, double t_withdraw_fee)
   : Account {t_name, t_balance}, m_withdraw_fee {t_withdraw_fee} {
      printf ("XT_DEBUG: Created Chequing_Account: name=%s, balance=%.1f, withdraw fee=%.1f\n", Account::m_name.c_str(), Account::m_balance, m_withdraw_fee);
}

bool Chequing_Account::deposit(double t_amount) {
   return Account::deposit(t_amount);
}

bool Chequing_Account::withdraw(double t_amount) {
   t_amount += m_withdraw_fee;
   return Account::withdraw(t_amount);
}

void Chequing_Account::print(std::ostream &t_string) const {
   // t_string.precision(2);
   t_string << "XT_DEBUG: Print Chequing_Account: name=" << Account::m_name << ", balance=" << Account::m_balance;
}
