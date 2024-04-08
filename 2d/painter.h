#pragma once
#include <iostream>
#include "mesh2d.h"
#include "Solver2d.hpp"


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

//Temperature to colour
sf::Uint8 get_r(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmax - Tmin)) * T - (255 / (Tmax - Tmin)) * Tmin));
};

sf::Uint8 get_b(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmin - Tmax)) * T - (255 / (Tmin - Tmax)) * Tmax));
};


class painter {
public:
	painter(int xwinsize, int ywinsize); // sets size of SFML window
	~painter();

	void display(mesh2d mesh); // displays mesh
private:
	window_size windowsz; //size of the window
	cell_pisize pisize; // pixels for 1 unit
	Solver2d sol;
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

        mesh.update(sol);


		for (int ix = 0; ix < mesh.get_uxsize(); ix++) {
			for (int iy = 0; iy < mesh.get_uxsize(); iy++) {

				sf::RectangleShape shape(sf::Vector2f(this->pisize.xpisize, this->pisize.ypisize)); //setting a cell
				//std::cout << "XPISIZE = " << this->pisize.xpisize << std::endl;
				//std::cout << "yPISIZE = " << this->pisize.ypisize << std::endl;

                shape.setPosition(ix * this->pisize.xpisize, iy * this->pisize.ypisize);

				shape.setFillColor(sf::Color{get_r(mesh.get_temp(ix, iy), 300, 5000), 0, get_b(mesh.get_temp(ix, iy), 300, 5000)});
				window.draw(shape);



			}
		}



		window.display();
	}





}
