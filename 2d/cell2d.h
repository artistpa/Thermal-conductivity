#pragma once
#include<iostream>

struct cellid {
	int x;
	int y;
};

class cell2d {
private:
	cellid id; //number of cell [x, y]
	float temp; // temperature
public:
	cell2d();
	~cell2d();
	void set_cell_id(int x, int y);
	void clear_cell(); // clears cell
	void set_cell_temp(float temp); // sets cells temperature
	float get_cell_temp();
	int getid_x(); //  returns x_coord
	int getid_y(); // returns y_coord
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

void cell2d::set_cell_temp(float temp) {
	this->temp = temp;
};

float cell2d::get_cell_temp(){
    return temp;
}

// setting cells ID (more like units, defenitely not mm)
void cell2d::set_cell_id(int x, int y) {
	this->id.x = x;
	this->id.y = y;
}

int cell2d::getid_x() {
	return this->id.x;
}

int cell2d::getid_y() {
	return this->id.y;
}





