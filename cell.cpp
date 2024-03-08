cell(){
    colour[0] = 115;
    colour[1] = 133;
    colour[2] = 149;
    sf::RectangleShape rectangle(sf::Vector2f(length, length));
    rectangle.setFillColor(sf::Color(100, 250, 50));
    T = 293;
}

void set_colour(unsigned int r, unsigned int g, unsigned int b){
    colour[0] = r;
    colour[1] = g;
    colour[2] = b;
}

void set_temperature(unsigned int temp){
    T = temp;
}

unsigned int get_temperature() const{
    return T;
}
