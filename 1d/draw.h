#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "mesh_1d.h"
#include "solver.h"


class painter {
public:
	painter() : window_size(1000) {}; // sets size of SFML window to 1000
	~painter();

	void display(mesh1d mesh); // displays mesh
private:
	int window_size; //size of the window
	int meshstep; // pixels for 1 unit
};
