#include <SFML/Graphics.hpp>
class cell{
protected:
    const unsigned int length = 30;
    unsigned int colour[3];
    unsigned int T;
public:
    cell();
    void set_colour(unsigned int r, unsigned int g, unsigned int b);
    void set_temperature(unsigned int temp);
    unsigned int get_temperature() const;
};
