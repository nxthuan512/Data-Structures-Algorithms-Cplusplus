#include <iostream>
#include <string>
#include "movies.h"
#include "main.h"

void add_movie(movies &my_movies, std::string new_name, std::string new_rating, int new_n_watches) {
   if (my_movies.add_movie(new_name, new_rating, new_n_watches)) {
      std::cout << "Movie " << new_name << " is added" << std::endl;
   } else {
      std::cout << "Movie " << new_name << " exists" << std::endl;
   }
   std::cout << std::endl;
}

int main() {
   movies my_movies;

   my_movies.display_movies();

   add_movie(my_movies, "Starwars", "P", 0);
   add_movie(my_movies, "Lord of The Rings", "PG-13", 0);
   add_movie(my_movies, "Starwars", "P", 0);
   add_movie(my_movies, "Die Hard", "R", 0);
   
   my_movies.display_movies();

   return 0;
}
