#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>

void update_dictionary(const int m_line_num, const std::string &m_line, std::map<std::string, int> &word_dict, std::map<std::string, std::set<int>> &word_dict2);

#endif /* MAIN_HPP */
