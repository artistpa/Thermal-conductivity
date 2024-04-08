#pragma once
#include <iostream>
#include "mesh2d.h"


// dimensions of one cell in pixels
struct cell_pisize {
	int xpisize;
	int ypisize;
};

//size of window
struct window_size {
	int xsize;
	int ysize;
};


class painter {
public:
	painter(int xwinsize, int ywinsize); // sets size of SFML window
	~painter();

	void display(mesh2d mesh); // displays mesh
private:
	window_size windowsz; //size of the window
	cell_pisize pisize; // pixels for 1 unit
};

painter::painter(int xwinsize, int ywinsize) {
	this->windowsz.xsize = xwinsize;
	this->windowsz.ysize = ywinsize;
}

painter:: ~painter() {};

void painter::display(mesh2d mesh) {
	// count x and y size of cell in pixels (cell_pisize)
	this->pisize.xpisize = this->windowsz.xsize / mesh.get_uxsize();
	this->pisize.ypisize = this->windowsz.ysize / mesh.get_uysize();

	// creating SFML window
	sf::RenderWindow window(sf::VideoMode(this->windowsz.xsize, this->windowsz.ysize), "SFML works!");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		sf::Uint8 col1 = 100;
		sf::Uint8 col2 = 100;
		sf::Uint8 col3 = 100;




		for (int ix = 0; ix < mesh.get_uxsize(); ix++) {
			for (int iy = 0; iy < mesh.get_uxsize(); iy++) {
				
				sf::RectangleShape shape(sf::Vector2f(this->pisize.xpisize, this->pisize.ypisize)); //setting a cell 
				std::cout << "XPISIZE = " << this->pisize.xpisize << std::endl;
				std::cout << "yPISIZE = " << this->pisize.ypisize << std::endl;



				shape.setPosition(ix * this->pisize.xpisize, iy * this->pisize.ypisize);
				/*if ((ix % 2 == 0) and (iy % 2 == 0)) {
					shape.setFillColor(sf::Color{200, 0, 200});
				}
				else {
					shape.setFillColor(sf::Color{0, 200, 0});
				}*/

				if (mesh.get_temp(ix, iy) != 0) {
					shape.setFillColor(sf::Color{100, 100, 100});
				}

				else {
					shape.setFillColor(sf::Color{200, 200, 200});

				}
				//shape.setFillColor(sf::Color{sf::Uint8(sin(ix) * 100), sf::Uint8(cos(iy) * 100), 0});
				window.draw(shape);
				


			}			
		}
		


		window.display();
	}





}