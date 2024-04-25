#pragma once
#include<iostream>

// id of cell (analog of 1 dimensional number)
struct cellid {
	int x;
	int y;
};

class cell2d {
private:
	cellid id; //number of cell [x, y]
	int temp; // temperature
public:
	cell2d(); // constructor
	~cell2d(); // distructor
	void set_cell_id(int x, int y); // setting cells id
	void clear_cell(); // clears cell
	void set_cell_temp(int tenpr); // sets cells temperature
	int get_cell_temp(); // returns cells temperature
};
