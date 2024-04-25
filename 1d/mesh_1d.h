#pragma once
#include <vector>
#include <cmath>
#include "cell.h"

class mesh1d {
private:
	std::vector <cell1d *> data;
	int xstep; // length of one unit (mm)
	int celnum; // number of cells in the mesh / length in units
	int length; // lengh of the "rod", (mm)
public:
	mesh1d(); // конструктор
	~mesh1d(); // деструктор

	void set_mesh1d(int length, int discr);
	void clear_mesh();
	int get_celnum();
	int get_xstep(); // returns xstep (mm)
	int getx(int num_of_cell);// returns id
	int getsize(); //returns mesh length (mm)
};

