#ifndef SONG_HPP
#define SONG_HPP

#include <ostream>
#include <string>

class Song {
   friend std::ostream &operator<<(std::ostream &, const Song &);
private:
   std::string m_name;   
   std::string m_singer;
   int m_rating;
public:
   Song(std::string m_name = "Unknown", std::string m_singer = "Unknown", int m_rating = 0);
   ~Song();
   std::string get_details() const;
   bool operator<(const Song &) const;
   bool operator==(const Song &) const;
};


#endif /* SONG_HPP */
