#pragma once
#include<iostream>

struct cellid {
	int x;
	int y;
};

class cell2d {
private:
	cellid id; //number of cell [x, y]
	int temp; // temperature
public:
	cell2d();
	~cell2d();
	void set_cell_id(int x, int y);
	void clear_cell(); // clears cell
	void set_cell_temp(int tenpr); // sets cells temperature
	int get_cell_temp(); // returns cells temperature
};



cell2d::cell2d() {
	this->id.x = 0;
	this->id.y = 0;
	this->temp = 0;
};

cell2d:: ~cell2d() {
	this->id.x = 0;
	this->id.y = 0;
	this->temp = 0;
};


void cell2d::clear_cell() {
	this->id.x = 0;
	this->id.y = 0;
	this->temp = 0;
}

void cell2d::set_cell_temp(int tempr) {
	this->temp = tempr;
	//std::cout << "SETTING CELL TEMP TO: " << tempr << " REAL TEMP: " << this->temp << std::endl;
};

int cell2d::get_cell_temp() {
	return this->temp;
}

// setting cells ID (more like units, defenitely not mm)
void cell2d::set_cell_id(int x, int y) {
	this->id.x = x;
	this->id.y = y;
}
