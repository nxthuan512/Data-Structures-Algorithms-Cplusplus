#include <iostream>
#include <string>
#include "movies.h"


// Add new movie
bool movies::add_movie(std::string name, std::string rating, int n_watches) {
   // If we don't use reference, a DEEP copy constructor is call
   //    for(auto mv:list_movies) {
   // Const is added to reference to prevent accidental changes
   for(const auto &mv:list_movies) {
      if (mv.get_name() == name) {
         return false;
      }
   }
   std::cout << "Add new movie (" << name << " " << rating << ")" << std::endl;
   list_movies.push_back(movie{name, rating, n_watches});
   return true;
}

// Increase watches
bool movies::inc_n_watches(std::string name) {
   for(auto &mv:list_movies) {
      if (mv.get_name() == name) {
         mv.inc_n_watches();
         return true;
      }
   }
   return false;
};

// Display all movies
void movies::display_movies() const {
   if (list_movies.size() == 0) {
      std::cout << "There is no movie in the list" << std::endl;
   } else {
      std::cout << "List of movies: " << std::endl;
      for(const auto &mv:list_movies) {
         std::cout << mv.get_name() << std::endl;
      }
   }
};

