#include <iostream>
#include "movie.h"

// Constructor
movie::movie(std::string new_name, std::string new_rating, int new_n_watches) 
   : name {new_name}, rating {new_rating}, n_watches {new_n_watches} {
      std::cout << "XT_DEBUG: Call a constructor for movie " << name << std::endl;
}

// Copy constructor
movie::movie(const movie &new_movie) 
   : name {new_movie.name}, rating {new_movie.rating}, n_watches {new_movie.n_watches} {
   std::cout << "XT_DEBUG: Call a SHALLOW copy constructor for movie " << name << std::endl;
}
/* movie::movie(const movie &new_movie) */ 
/*    : movie {new_movie.name, new_movie.rating, new_movie.n_watches} { */
/*    std::cout << "XT_DEBUG: Call a DEEP copy constructor for movie " << name << std::endl; */
/* } */

// Move constructor
movie::movie(movie &&new_movie) noexcept
   : name {new_movie.name}, rating {new_movie.rating}, n_watches {new_movie.n_watches} {
   std::cout << "XT_DEBUG: Call a move constructor for movie " << name << std::endl;
}

// Destructor
movie::~movie() {
   std::cout << "XT_DEBUG: Call a destructor for movie " << name << std::endl;
}

// Set movie name
void movie::set_name(std::string const new_name) {
   this->name = new_name;
}

// Set rating
void movie::set_rating(std::string const new_rating) {
   if (new_rating != "G" && new_rating != "PG" && new_rating != "PG-13" && new_rating != "R") {
      std::cout << "Input rating is unrecognized" << std::endl;
      std::exit(EXIT_FAILURE);
   } else {
      this->rating = new_rating;
   }
}

// Set number of watches
void movie::inc_n_watches() {
   this->n_watches++;
}

// Get movie name
std::string movie::get_name() const {
   return this->name;
}
