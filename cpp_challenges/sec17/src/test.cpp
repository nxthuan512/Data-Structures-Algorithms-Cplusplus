#include "test.hpp"

Test::Test(std::string id, int data) 
: m_id {id}, m_data {data} {
   std::cout << "\tXT_DEBUG: Call a construction: id: " << m_id << ", data: " << m_data << std::endl;
}

Test::~Test() {
   std::cout << "\tXT_DEBUG: Call a destructor: id: " << m_id << ", data: " << m_data << std::endl;
}

void Test::get_info() const {
   std::cout << "INFO: id: " << m_id << ", data: " << m_data << std::endl;
}
