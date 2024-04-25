#pragma once
#include <iostream>
#include <cmath>
#include "mesh2d.h"
#include "Colour_master.h"
#include "menu.h"


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
private:
	window_size windowsz; //size of the window
	cell_pisize pisize; // pixels for 1 unit
	Solver2d sol; // solver used for finding out temperature in each cell
	Colour_master col; // used for transforming cells temperature into its color
	menu m; // used for creating menu
	int add_temp = 100;
	bool inspector = false;
public:
	painter(int xwinsize, int ywinsize); // sets size of SFML window
	~painter();
	void display(mesh2d mesh); // displays mesh
};
