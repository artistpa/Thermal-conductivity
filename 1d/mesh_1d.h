#pragma once
#include "cell.h"
#include <math.h>

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

mesh1d:: mesh1d() {
	std::vector<cell1d *>  dat;
	this->data = dat;
	this->xstep = 0;
	this->length = 0;
	std::cout << "1D MESH CREATED" << std::endl << std::endl;
}


mesh1d:: ~mesh1d() {
	
}

void mesh1d::clear_mesh() {
	for (int i = 0; i < this->data.size(); i++) {
		this->data[i]->clear_cell();
		delete this->data[i];
		this->data[i] = NULL;
	}
	this->data.clear();
	this->xstep = 0;
}

void mesh1d::set_mesh1d(int length, int xstep) {
	int celnum = (length / xstep);
	int curpos = 0; // current position
	std::cout << "START MESHING" << std::endl << std::endl;


	for (int i = 0; i < celnum; i++) {
		cell1d* newcell = new cell1d;
		newcell->set_cell_id(curpos);
		this->data.push_back(newcell);
		curpos = curpos + 1;
	}
	this->xstep = xstep;
	this->celnum = celnum;
	this->length = length;
	std::cout << "MESHING FINISHED " << std::endl << "NUMBER OF CELLS : " << celnum << std::endl << "1 UNIT IS  " << xstep << " mm" << std::endl << std::endl;

} 

int mesh1d::get_celnum() {
	return this->celnum;
}

int mesh1d::get_xstep() {
	return this->xstep;
}

int mesh1d::getx(int num_of_cell) {
	int res = this->data[num_of_cell]->getid();
	return res;
}

int mesh1d::getsize() {
	return this->length;	
}

