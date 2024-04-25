#include "cell.h"

cell1d::cell1d() {
	this->id = 0;
	this->temp = 0;
};

cell1d:: ~cell1d() {
	this->id = 0;
	this->temp = 0;
};


void cell1d::clear_cell() {
	this->id = 0;
	this->temp = 0;
}

void cell1d::set_cell_temp(int tenp){
	this->temp = temp;
};


void cell1d::set_cell_id(int id) {
	this->id = id;
}

int cell1d::getid() {
	return this->id;
}
