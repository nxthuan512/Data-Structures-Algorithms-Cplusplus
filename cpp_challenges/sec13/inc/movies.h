#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <vector>
#include "movie.h"

class movies {
   private:
      std::vector <movie> list_movies;

   public:
      bool add_movie(std::string, std::string, int);
      bool inc_n_watches(std::string);
      void display_movies() const;
};

#endif /* MOVIES_H */
