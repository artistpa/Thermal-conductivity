#include "Colour_master.h"

sf::Uint8 Colour_master::get_r(float T, float Tmin, float Tmax) {
    return (std::round((255 / (Tmax - Tmin)) * T - (255 / (Tmax - Tmin)) * Tmin));
};

sf::Uint8 Colour_master::get_b(float T, float Tmin, float Tmax) {
    return (std::round((255 / (Tmin - Tmax)) * T - (255 / (Tmin - Tmax)) * Tmax));
};
