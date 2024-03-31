#ifndef colour
#define colour 1

class colour {
private:
    unsigned int red, green, blue;
public:
void kelvin_to_rgb(unsigned int temp);
unsigned int get_r();
unsigned int get_g();
unsigned int get_b();
};

#endif // colour
