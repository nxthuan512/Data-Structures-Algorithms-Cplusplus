#include "Savings_Account.hpp"
#include <ostream>

Savings_Account::Savings_Account(std::string t_name, double t_balance, double t_interest_rate)
: Account {t_name, t_balance}, m_interest_rate {t_interest_rate} {
   printf ("XT_DEBUG: Created Savings_Account: name=%s, balance=%.1f, interest rate=%.1f%%\n", Account::m_name.c_str(), Account::m_balance, m_interest_rate);
}

bool Savings_Account::deposit(double t_amount) {
   t_amount += (m_interest_rate/100);
   return Account::deposit(t_amount);
}

bool Savings_Account::withdraw(double t_amount) {
   return Account::withdraw(t_amount);
}

void Savings_Account::print(std::ostream &t_string) const {
   t_string.precision(6);
   t_string << "XT_DEBUG: Print Savings_Account: name=" << Account::m_name << ", balance=" << Account::m_balance << ", interest rate=" << m_interest_rate << "%";
}
