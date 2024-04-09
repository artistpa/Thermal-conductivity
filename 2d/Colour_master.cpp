#include "Colour_master.hpp"

sf::Uint8 get_r(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmax - Tmin)) * T - (255 / (Tmax - Tmin)) * Tmin));
};

sf::Uint8 get_b(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmin - Tmax)) * T - (255 / (Tmin - Tmax)) * Tmax));
};

