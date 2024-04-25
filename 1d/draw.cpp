#include "draw.h"

sf::Uint8 get_r(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmax - Tmin)) * T - (255 / (Tmax - Tmin)) * Tmin));
}

sf::Uint8 get_b(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmin - Tmax)) * T - (255 / (Tmin - Tmax)) * Tmax));
}

painter :: ~painter() {};

void painter::display(mesh1d mesh) {

	// setting mesh step
	int meshstep = this->window_size / mesh.get_celnum();
	std::cout << "MESH STEP SET" << std::endl << "1 UNIT IS " << meshstep << " PIXELS" << std::endl;

	// creating SFML window
	sf::RenderWindow window(sf::VideoMode(this->window_size, 100), "Thermal conductivity");
    //int Tmax, Tmin;
    //std::cout << "Enter maximum temperature: ";
    //std::cin >> Tmax;
    //std::cout << "Enter minimum temperature: ";
    //std::cin >> Tmin;

    Solver s;
    s.set_T0(300, 5000, 300);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
        s.update_T();
		for (int id = 0; id < mesh.get_celnum(); id++) {

			sf::RectangleShape shape(sf::Vector2f(meshstep, 100)); //setting a cell

			shape.setPosition((id * meshstep), 0); // positioning the cell; (crd * id) is a number of cell * length of a cell in pixels

			// TEST FEATURE WITH COLORS
			shape.setFillColor(sf::Color{get_r(s.get_T(id), 300, 5000), 0, get_b(s.get_T(id), 300, 5000)});
			window.draw(shape);

		}
		//std::cout << s.get_T(2) << std::endl;
		window.display();

	}

}
