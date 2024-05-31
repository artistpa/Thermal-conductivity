#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>


// this class is used for transforming cell temperature into its color
class Colour_master {
public:
    //Temperature to colour
    sf::Uint8 get_r(float T, float Tmin, float Tmax);
    sf::Uint8 get_b(float T, float Tmin, float Tmax);
};
