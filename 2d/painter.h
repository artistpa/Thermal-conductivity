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
sf::Uint8 get_r(float T, float Tmin, float Tmax) {
    return (std::round((255 / (Tmax - Tmin)) * T - (255 / (Tmax - Tmin)) * Tmin));
};

sf::Uint8 get_b(float T, float Tmin, float Tmax){
    return (std::round((255 / (Tmin - Tmax)) * T - (255 / (Tmin - Tmax)) * Tmax));
};

// another one temp to color
/*
sf::Color getTemperatureColor(int minTemp, int maxTemp, int currentTemp) {
	// Define the colors for cold (blue) and hot (red) temperatures
	sf::Color coldColor = sf::Color::Blue;
	sf::Color hotColor = sf::Color::Red;

	// Calculate the interpolation factor based on the current temperature
	float t = static_cast<float>(currentTemp - minTemp) / (maxTemp - minTemp);

	// Interpolate between the cold and hot colors
	sf::Color resultColor;
	resultColor.r = static_cast<sf::Uint8>((1 - t) * coldColor.r + t * hotColor.r);
	resultColor.g = static_cast<sf::Uint8>((1 - t) * coldColor.g + t * hotColor.g);
	resultColor.b = static_cast<sf::Uint8>((1 - t) * coldColor.b + t * hotColor.b);

	return resultColor;
}
*/

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

				shape.setFillColor(sf::Color{get_r(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax()), 0, get_b(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax())});
				//sf::Color cl = getTemperatureColor(mesh.get_tmin(), mesh.get_tmax(), mesh.get_temp(ix, iy));
				//shape.setFillColor(cl);
				window.draw(shape);



			}
		}
		//drawing temperature bar
		sf::RectangleShape bar(sf::Vector2f(200, 20));
		bar.setFillColor(sf::Color::Blue);
		bar.setPosition(this->pisize.xpisize, this->pisize.ypisize);

		// Calculate the width of the temperature bar based on the current temperature
		float tempRange = mesh.get_tmax() - mesh.get_tmin();

		sf::RectangleShape tempBar(sf::Vector2f(20, 20));
		tempBar.setFillColor(sf::Color::Red);
		tempBar.setPosition(mesh.get_uxsize(), mesh.get_uxsize());

		window.draw(bar);
		window.draw(tempBar);



		window.display();
	}





}
