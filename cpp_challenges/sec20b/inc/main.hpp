#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "Song.hpp"

enum Control { F, N, P, A, L };

auto song_control(const std::list<Song> &, std::list<Song>::iterator, Control);

#endif /* MAIN_HPP */
