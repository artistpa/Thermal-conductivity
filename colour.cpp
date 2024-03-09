#include <cmath>
class colour {
private:
    unsigned int red, green, blue;
public:
void kelvin_to_rgb(unsigned int temp){
    if (temp < 1000){
        red = 0;
        green = 0;
        blue = 255;
    }
    else {
        temp /= 100;
        if (temp <= 66) {
            red = 255;
            green = std::round(99.4708025861 * std::pow(temp - 2, -0.1332047592));
        }
        else {
            red = std::round(329.698727446 * std::pow(temp - 10, -0.1332047592));
            green = std::round(288.1221695283 * pow(temp - 55, -0.0755148492));
        }
    }
    blue = 0;
}
unsigned int get_r(){
    return red;
}
unsigned int get_g(){
    return green;
}
unsigned int get_b(){
    return blue;
}
};
