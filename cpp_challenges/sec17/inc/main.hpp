#ifndef MAIN_HPP
#define MAIN_HPP

#include <memory>
#include <vector>
#include "test.hpp"

auto make();
void fill(std::vector<std::shared_ptr<Test>> &, int);
void display(std::vector<std::shared_ptr<Test>> &);

#endif /* MAIN_HPP */
