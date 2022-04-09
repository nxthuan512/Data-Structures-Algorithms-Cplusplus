#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#include <string>

class Test {
private: 
   std::string m_id;
   int m_data;
public:
   Test(std::string m_id = "Unknown", int m_data = 0);
   void get_info() const;
   ~Test();
};

#endif /* TEST_HPP */
