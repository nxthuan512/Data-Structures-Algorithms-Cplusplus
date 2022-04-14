#include "Song.hpp"
#include <string>

Song::Song(std::string name, std::string singer, int rating) 
: m_name (name), m_singer (singer), m_rating (rating) {}

Song::~Song() {}

std::string Song::get_details() const {
   std::string details = "Name: " + m_name + "\nSinger: " + m_singer + "\nRating: " + std::to_string(m_rating);
   return details;
}

bool Song::operator<(const Song &song) {
   if (m_rating < song.m_rating)
      return true;
   else
      return false;
}

bool Song::operator==(const Song &song) {
   if (m_rating == song.m_rating)
      return true;
   else
      return false;
}

std::ostream &operator<<(std::ostream &os, const Song &song) {
   os << song.get_details() << std::endl;
   return os;
}
