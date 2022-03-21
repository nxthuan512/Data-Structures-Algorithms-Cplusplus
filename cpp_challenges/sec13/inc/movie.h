#ifndef MOVIE_H
#define MOVIE_H

#include <cstdlib>
#include <string>

class movie {
   private:
      std::string name;
      std::string rating;
      int n_watches {0};

   public: 
      movie(std::string new_name, std::string new_rating, int new_n_watches);
      movie(const movie &new_movie) ;
      movie(movie &&new_movie) noexcept;
      ~movie();

      // Set movie name
      void set_name(std::string const new_name);

      // Set rating
      void set_rating(std::string const new_rating);

      // Increase number of watches
      void inc_n_watches();

      // Get movie name
      std::string get_name() const;
};

#endif /* MOVIE_H */
