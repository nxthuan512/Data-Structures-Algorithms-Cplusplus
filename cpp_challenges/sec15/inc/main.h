#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include "account.h"
#include "savings_account.h"
#include "chequing_account.h"
#include "trust_account.h"

void get_all_balances(const std::vector<account> &);
void get_all_balances(const std::vector<savings_account> &);
void get_all_balances(const std::vector<chequing_account> &);
void get_all_balances(const std::vector<trust_account> &);

#endif /* MAIN_H */
