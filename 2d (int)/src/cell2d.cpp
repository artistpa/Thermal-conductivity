#include "cell2d.h"

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
};

int cell2d::get_cell_temp() {
	return this->temp;
}

void cell2d::set_cell_id(int x, int y) {
	this->id.x = x;
	this->id.y = y;
}
