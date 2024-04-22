#pragma once
#include <iostream>
#include <cmath>
#include "mesh2d.h"
#include "Solver2d.hpp"
#include "Colour_master.hpp"
#include "menu.hpp"

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
	Solver2d sol;
	Colour_master col;
	int add_temp = 100;
	bool inspector = false;
};

painter::painter(int xwinsize, int ywinsize) {
	this->windowsz.xsize = xwinsize;
	this->windowsz.ysize = ywinsize;
}

painter:: ~painter() {};

void painter::display(mesh2d mesh) {
	// count x and y size of cell in pixels (cell_pisize)
	this->pisize.xpisize = (this->windowsz.xsize / mesh.get_uxsize() ) * 0.9;
	this->pisize.ypisize = (this->windowsz.ysize / mesh.get_uysize() );

	// creating SFML window
	sf::RenderWindow window(sf::VideoMode(this->windowsz.xsize, this->windowsz.ysize), "Thermal conductivity");

	// import a font, it will be used twice or more
	sf::Font font;
	font.loadFromFile("font/arial.ttf");


    // creating menu
	menu(window);

	while (window.isOpen())
	{


		window.clear();
		// creting a background for simulation
		sf::Texture backblackTexture;
		backblackTexture.loadFromFile("images/back_black.png");
		//backblackTexture.create(windowsz.xsize, windowsz.ysize);

		sf::Sprite backg(backblackTexture);
		backg.setPosition(this->windowsz.xsize * 0.95, 0);
		//backg.setScale(100, 100);
		window.draw(backg);
		//backg.setColor(sf::Color(0, 0, 0));
		//backg.setScale(f, 10f);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i position = sf::Mouse::getPosition(window);
				// reacting on mouse tap
				if (event.mouseButton.button == sf::Mouse::Left) {
					if ( ( std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and  std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
						if (inspector == true)
                            mesh.set_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize), mesh.get_tmax());
                        else
                            inspector = true;
					}

				}

				if (event.mouseButton.button == sf::Mouse::Right) {
					if ((std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
						mesh.set_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize), mesh.get_tmin());
					}

				}
			}



		}

		mesh.update(sol);


		for (int ix = 0; ix < mesh.get_uxsize(); ix++) {
			for (int iy = 0; iy < mesh.get_uxsize(); iy++) {

				sf::RectangleShape shape(sf::Vector2f(this->pisize.xpisize, this->pisize.ypisize)); //setting a cell
				//std::cout << "XPISIZE = " << this->pisize.xpisize << std::endl;
				//std::cout << "yPISIZE = " << this->pisize.ypisize << std::endl;
				shape.setPosition(ix * this->pisize.xpisize, iy * this->pisize.ypisize);
				shape.setFillColor(sf::Color{col.get_r(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax()), 0, col.get_b(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax())});
				window.draw(shape);
			}
		}

		// displaying temperature bar
		sf::Texture tempbarTexture;
		tempbarTexture.loadFromFile("images/temp_bar_3.png");

		sf::Sprite tempbar(tempbarTexture);
		tempbar.setPosition(this->windowsz.xsize * 0.9, 0);
		tempbar.setScale(0.52f, 0.52f);
		window.draw(tempbar);

		// displaying Tmax and Tmin on the temperature bar


		sf::Text text_tmax;
		sf::Text text_tmin;
		text_tmax.setFont(font); // font is a sf::Font
		text_tmin.setFont(font);

		// set the string to display
		text_tmax.setString(std::to_string(mesh.get_tmax()));
		text_tmin.setString(std::to_string(mesh.get_tmin()));

		// set the character size
		text_tmax.setCharacterSize(20); // in pixels, not points!
		text_tmin.setCharacterSize(20);

		// set the color
		text_tmax.setFillColor(sf::Color::Black);
		text_tmin.setFillColor(sf::Color::Black);

		// set the text style
		text_tmax.setStyle(sf::Text::Bold);
		text_tmin.setStyle(sf::Text::Bold);

		text_tmax.setPosition(this->windowsz.xsize * 0.9, 0);
		text_tmin.setPosition(this->windowsz.xsize * 0.9, 270);

		window.draw(text_tmax);
		window.draw(text_tmin);

		// displaying temperature in the chosen cell
		sf::Text curtemp;
		sf::Text xcord;
		sf::Text ycord;
		curtemp.setFont(font);
		curtemp.setPosition(this->windowsz.xsize * 0.9, 360);
		curtemp.setString("");
		xcord.setFont(font);
		xcord.setPosition(this->windowsz.xsize * 0.9, 300);
		xcord.setString("");
		ycord.setFont(font);
		ycord.setPosition(this->windowsz.xsize * 0.9, 330);
		ycord.setString("");

		if ((sf::Mouse::getPosition(window).x <= mesh.get_uxsize() * this->pisize.xpisize) and (sf::Mouse::getPosition(window).y <= mesh.get_uysize() * this->pisize.ypisize) and
			(sf::Mouse::getPosition(window).x >= 0) and (sf::Mouse::getPosition(window).y >= 0)) {
			sf::Vector2i position = sf::Mouse::getPosition(window);


			if ((std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
				int curtemp_int = mesh.get_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize));
				curtemp.setString("T:" + std::to_string(curtemp_int)+ " K");
				xcord.setString("X:" + std::to_string(int(std::round(position.x / this->pisize.xpisize))));
				ycord.setString("Y:" + std::to_string(int(std::round(position.y / this->pisize.ypisize))));
			}
		}
		window.draw(curtemp);
		window.draw(xcord);
		window.draw(ycord);


		window.display();
	}
}
