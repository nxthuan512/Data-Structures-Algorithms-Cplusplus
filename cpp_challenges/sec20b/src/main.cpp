#include "main.hpp"
#include <ostream>

auto song_control(std::list<Song> &playlist, std::list<Song>::iterator current_song, Control action) {
   switch (action) {
      case F: 
         std::cout << "====== Play first song ======" << std::endl;
         std::cout << *current_song;
         break;

      case N:
         std::cout << "====== Play next song ======" << std::endl;
         current_song++;
         if (current_song == playlist.end()) {
            current_song = playlist.begin();
         }
         std::cout << *current_song;
         break;

      case P: 
         std::cout << "====== Play previous song ======" << std::endl;
         if (current_song == playlist.begin()) {
            current_song = playlist.end();
         } else {
            current_song--;
         }
         std::cout << *current_song;
         break;

      case A:
         std::cout << "====== Add new song and play ======" << std::endl;
         playlist.insert(current_song, Song {"You Belong With Me", "Taylor Swift", 5});
         current_song--;
         std::cout << *current_song;
         break;

      case L: 
         std::cout << "====== List the current playlist ======" << std::endl;
         for (const auto &song : playlist) {
            std::cout << song;
         }
         break;

      default:;
   };

   return current_song;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    std::list<Song>::iterator current_song = playlist.begin();
    std::cout << "XT_DEBUG: Size of playlist = " << playlist.size() << std::endl;
    
    Control action = L;
    current_song = song_control(playlist, current_song, action);

    action = F;
    current_song = song_control(playlist, current_song, action);
    action = N;
    current_song = song_control(playlist, current_song, action);
    action = P;
    current_song = song_control(playlist, current_song, action);
    action = A;
    current_song = song_control(playlist, current_song, action);
    action = L;
    current_song = song_control(playlist, current_song, action);

    std::cout << "============" << std::endl;
    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
