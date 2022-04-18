#include "main.hpp"

void update_dictionary(const int m_line_num, const std::string &m_line, std::map<std::string, int> &word_dict, std::map<std::string, std::set<int>> &word_dict2) {
   // Solution which does use stringstream
   std::string m_word;
   std::stringstream ss(m_line);
   while (ss >> m_word) {
      // Remove punctuations
      if (m_word.back() == ',' || m_word.back() == '.' || m_word.back() == ';') {
         m_word.pop_back();
      }
      // Update the repetition in word_dict and occurences in word_dict2
      if (word_dict.find(m_word) == word_dict.end()) {
         word_dict[m_word] = 1;
      } else {
         word_dict[m_word]++;
      }
      word_dict2[m_word].insert(m_line_num);
   }

   // // Another solution which does not use stringstream
   // std::string m_word = "";
   // for (const auto &m_char : m_line) {
   //    // Remove punctuations
   //    if (m_char != ',' && m_char != '.' && m_char != ';' && m_char != ' ') {
   //       m_word += m_char;
   //    }
   //    // Conclude a word when hitting space
   //    if (m_char == ' ' && m_word != "") {
   //       // Update word_dict and word_dict2
   //       if (m_word != " ") {
   //          // Update the repetition in word_dict and occurences in word_dict2
   //          if (word_dict.find(m_word) == word_dict.end()) {
   //             word_dict[m_word] = 1;
   //          } else {
   //             word_dict[m_word]++;
   //          }
   //          word_dict2[m_word].insert(m_line_num);
   //          m_word = "";
   //       }
   //    }
   // }
   // // The word in the end of line
   // if (m_word != "") {
   //    // Update the repetition
   //    if (m_word != " ") {
   //       if (word_dict.find(m_word) == word_dict.end()) {
   //          word_dict[m_word] = 1;
   //       } else {
   //          word_dict[m_word]++;
   //       }
   //       word_dict2[m_word].insert(m_line_num);
   //    }
   // }
}

int main() {
   std::map<std::string, int> word_dict;
   std::map<std::string, std::set<int>> word_dict2;

   // Open file
   std::string file_name = "/home/nxthuan512/xt_projects/cpp_and_dsa/cpp_challenges/sec20c/words.txt";
   std::ifstream m_file(file_name); 

   if (!m_file) {
      std::cerr << "Cannot open " << file_name << " for read" << std::endl;
      return 1;
   }

   // Read each line and remove punctuations
   std::string m_line;
   int m_line_num = 0;
   while (getline (m_file, m_line)) {
      // std::cout << m_line << std::endl;
      m_line_num++;
      update_dictionary(m_line_num, m_line, word_dict, word_dict2);
   }

   // Part 1
   std::cout << "=========== PART 1 ===========" << std::endl;
   std::cout << std::setw(20) << "WORD" << std::setw(20) << "REPETITION" << std::endl;
   std::cout << "------------------------------" << std::endl;
   for (const auto &m_word : word_dict) {
      std::cout << std::setw(20) << m_word.first << std::setw(20) << m_word.second << std::endl;
   }
   std::cout << std::endl;

   // Part 2
   std::cout << "=========== PART 2 ===========" << std::endl;
   std::cout << std::setw(20) << "WORD" << std::setw(20) << "OCCURRENCES" << std::endl;
   std::cout << "------------------------------" << std::endl;
   for (const auto &m_word : word_dict2) {
      std::cout << std::setw(20) << m_word.first << std::setw(20) << "[ ";
      for (const auto &m_occ : m_word.second) {
         std::cout << m_occ << " ";
      }
      std::cout << "]" << std::endl;
   }

   // Close the file
   m_file.close();
   return 0;
}
