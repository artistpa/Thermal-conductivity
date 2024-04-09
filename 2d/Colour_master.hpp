#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Colour_master {
public:
    //Temperature to colour
    sf::Uint8 get_r(int T, float Tmin, float Tmax);
    sf::Uint8 get_b(int T, float Tmin, float Tmax);
};
