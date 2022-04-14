#include "main.hpp"

bool is_palindrome(std::string str) {
   std::deque<char> m_str;

   // Fill the deque
   for (auto const &s : str) {
      if (std::isalpha(s)) {
         m_str.push_back(std::toupper(s));
      }
   }
   
   // Compare pop_front and pop_back
   // printf ("XT_DEBUG: ==========================\n");
   // printf ("XT_DEBUG: m_str = %s\n", str.c_str());
   while (m_str.size() >= 2) {
      auto m_front = m_str.front();
      auto m_back = m_str.back();

      // printf ("XT_DEBUG: m_front = %c m_back = %c\n", m_front, m_back);
      if (m_front != m_back) {
         return false;
      }
      m_str.pop_front();
      m_str.pop_back();
   }
   // printf ("XT_DEBUG: ==========================\n");

   return true;
}

int main() {
   std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}
