#pragma once
#include "mesh_1d.h"


class painter {
public:
	painter() : window_size(1000) {}; // sets size of SFML window to 1000
	~painter();

	void display(mesh1d mesh); // displays mesh
private:
	int window_size; //size of the window
	int meshstep; // pixels for 1 unit
};



painter :: ~painter() {};

void painter::display(mesh1d mesh) {

	// setting mesh step
	int meshstep = this->window_size / mesh.get_celnum();
	std::cout << "MESH STEP SET" << std::endl << "1 UNIT IS " << meshstep << " PIXELS" << std::endl;

	// creating SFML window
	sf::RenderWindow window(sf::VideoMode(this->window_size, 100), "SFML works!");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		sf::Uint8 col1 = 0;
		sf::Uint8 col2 = 256;
		sf::Uint8 col3 = 0;

		


		for (int id = 0; id < mesh.get_celnum(); id++) {

			sf::RectangleShape shape(sf::Vector2f(meshstep, 100)); //setting a cell 

			shape.setPosition((id * meshstep), 0); // positioning the cell; (crd * id) is a number of cell * length of a cell in pixels

			// TEST FEATURE WITH COLORS 
			shape.setFillColor(sf::Color{0, col2, col3});
			col1++;
			col2++;
			col3++;
			window.draw(shape);
			
		}
		window.display();

	}

}