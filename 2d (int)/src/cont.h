#pragma once
#include <iostream>
#include <vector>
#include "cell2d.h"

class cont {

private:
	std::vector< std::vector<cell2d*>*> data;
	int xsize;
	int ysize;
public:
	cont() {}; // default constructor
	cont(int xsize, int ysize); // specific constructor
	//cell2d get_el(int i, int j); // returns an element from coontainer
	cell2d get_el(int i, int j) {
		return *(*data[i])[j];
	}
	void clear(); // clears container
	int get_xsize(); // returns x size of container
	int get_ysize(); // returns y size of container
	void set_temp_cont(int x, int y, int tempr); // sets temperature in the chosen cell

};


