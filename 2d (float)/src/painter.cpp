#include "painter.h"


painter::painter(int xwinsize, int ywinsize) {
	this->windowsz.xsize = xwinsize;
	this->windowsz.ysize = ywinsize;
}

painter:: ~painter() {};

void painter::display(mesh2d& mesh) {
	// count x and y size of cell in pixels (cell_pisize)
	this->pisize.xpisize = (this->windowsz.xsize / mesh.get_uxsize()) * 0.9;
	this->pisize.ypisize = (this->windowsz.ysize / mesh.get_uysize());

	// creating SFML window
	sf::RenderWindow window(sf::VideoMode(this->windowsz.xsize, this->windowsz.ysize), "Thermal conductivity (float)");

	// import a font, it will be used twice or more
	sf::Font font;
	font.loadFromFile("../font/arial.ttf");


	// first, we display a menu
	m.creator(window);


	while (window.isOpen())
	{

		// then we set a background for simulation
		window.clear();
		sf::Texture backblackTexture;
		backblackTexture.loadFromFile("../images/back_black.png");

		sf::Sprite backg(backblackTexture);
		backg.setPosition(this->windowsz.xsize * 0.95, 0);
		window.draw(backg);

		// check for some posiible events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// if we want to close SFML window
			if (event.type == sf::Event::Closed)
				window.close();

			// reacting on mouse tap
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i position = sf::Mouse::getPosition(window);
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (( std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and  std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
						if (this->inspector == true)
                            mesh.set_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize), mesh.get_tmax());
                        else
                            this->inspector = true;
					}

				}

				if (event.mouseButton.button == sf::Mouse::Right) {
					if ((std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
						mesh.set_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize), mesh.get_tmin());
					}

				}
			}



		}

		// then we should update our mesh
		mesh.update(sol);

		// finally, we should draw the mesh
		for (int ix = 0; ix < mesh.get_uxsize(); ix++) {
			for (int iy = 0; iy < mesh.get_uxsize(); iy++) {

				sf::RectangleShape shape(sf::Vector2f(this->pisize.xpisize, this->pisize.ypisize)); //setting a cell
				shape.setPosition(ix * this->pisize.xpisize, iy * this->pisize.ypisize);
				shape.setFillColor(sf::Color{col.get_r(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax()), 0, col.get_b(mesh.get_temp(ix, iy), mesh.get_tmin(), mesh.get_tmax())});
				window.draw(shape);



			}
		}

		// after the mesh is drawn we can display some useful information:

		// displaying temperature bar
		sf::Texture tempbarTexture;
		tempbarTexture.loadFromFile("../images/temp_bar_3.png");

		sf::Sprite tempbar(tempbarTexture);
		tempbar.setPosition(this->windowsz.xsize * 0.9, 0);
		tempbar.setScale(0.52f, 0.52f);
		window.draw(tempbar);

		// displaying Tmax and Tmin on the temperature bar
		sf::Text text_tmax;
		sf::Text text_tmin;
		text_tmax.setFont(font); // font is a sf::Font
		text_tmin.setFont(font);

		text_tmax.setString(std::to_string(mesh.get_tmax()));
		text_tmin.setString(std::to_string(mesh.get_tmin()));

		text_tmax.setCharacterSize(20); // in pixels, not points!
		text_tmin.setCharacterSize(20);

		text_tmax.setFillColor(sf::Color::Black);
		text_tmin.setFillColor(sf::Color::Black);

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


		// we should check, if the mouse is inside the window
		// unless we'll face a segfault
		if ((sf::Mouse::getPosition(window).x <= mesh.get_uxsize() * this->pisize.xpisize) and (sf::Mouse::getPosition(window).y <= mesh.get_uysize() * this->pisize.ypisize) and
			(sf::Mouse::getPosition(window).x >= 0) and (sf::Mouse::getPosition(window).y >= 0)) {
			sf::Vector2i position = sf::Mouse::getPosition(window);


			if ((std::round(position.x / this->pisize.xpisize) < mesh.get_uxsize()) and std::round(position.y / this->pisize.ypisize) < mesh.get_uysize()) {
				int curtemp_int = mesh.get_temp(std::round(position.x / this->pisize.xpisize), std::round(position.y / this->pisize.ypisize));
				curtemp.setString("T:" + std::to_string(curtemp_int) + " K");
				xcord.setString("X:" + std::to_string(int(std::round(position.x / this->pisize.xpisize))));
				ycord.setString("Y:" + std::to_string(int(std::round(position.y / this->pisize.ypisize))));
			}
		}

		// after all, display everything
		window.draw(curtemp);
		window.draw(xcord);
		window.draw(ycord);


		window.display();
	}

}
