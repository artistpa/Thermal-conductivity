#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "cont.h"


// "DIMENTIONAL" length of one unit, mm
struct dimstep {
	int xstep;
	int ystep;
};

//size of mesh, number of X and Y units
struct meshsize {
	int xsize;
	int ysize;
};




// class of 2d mesh
class mesh2d {
private:
	//std::vector< std::vector<cell2d*>*> data;
	cont data;
	dimstep meshstep; // mm
	meshsize size; // units
public:
	mesh2d(); // конструктор

	void set_mesh2d (int xlen, int ylen, int xstep, int ystep);
	void clear_mesh();
	void set_temp(int x, int y, int temp); // sets temp temperature in [x, y] cell
	void set_T0(); // sets starting temperature across 
	int get_temp(int x, int y); // returns temperature in [x, y] cell
	int get_uxsize(); // returns x length of mesh in units
	int get_uysize(); // returns y length of mesh in units


	int get_xstep(); // returns xstep (mm)
	int getx(int num_of_cell);// returns id
	int getsize(); //returns mesh length (mm)

};



// constructor
// it only creates mesh, it doesnt set it
mesh2d::mesh2d() {
	this->data = cont(0, 0);
	//std::vector<std::vector<cell2d*>*> dat;
	this->meshstep.xstep = 0;
	this->meshstep.ystep = 0;
	this->size.xsize = 0;

	std::cout << "2d MESH SUCCESSFULLY CREATED" << std::endl;
}


// setting mesh
// this method sets size of mesh and id of every single cell in mesh
// temperature of every cell is equal to 0 K
void mesh2d::set_mesh2d(int xlen, int ylen, int xstep, int ystep) {
	std::cout << "MESH SETTING STARTED" << std::endl;

	//count meshsize
	this->size.xsize = ceil(xlen / xstep);
	this->size.ysize = ceil(ylen / ystep);
	std::cout << "XSIZE = " << this->size.xsize << "UNITS" << std::endl;
	std::cout << "YSIZE = " << this->size.ysize << "UNITS" << std::endl;


	//clearing previous data array and setting a new one
	this->data.clear();
	this->data = cont(this->size.xsize, this->size.ysize);


	//filling data with cells
	for (int j = 0; j < this->size.ysize; j++) {

		for (int i = 0; i < this->size.xsize; i++) {
			this->data.get_el(i, j).set_cell_id(i, j);
			this->data.set_temp_cont(i, j, 0);
		}
	}

	std::cout << "DATA SET " << std::endl;

	// setting meshstep
	this->meshstep.xstep = xstep;
	this->meshstep.ystep = ystep;

	std::cout << std::endl;
	std::cout << "2D MESH SUCSESSFULLY SET" << std::endl;
	std::cout << "SIZE OF DATA: " << this->data.get_xsize() << " " << this->data.get_ysize() << std::endl;

}

void mesh2d::set_temp(int x, int y, int tempr) {
	//this->data.get_el(x, y).set_cell_temp(tempr);
	this->data.set_temp_cont(x, y, tempr);
};

int mesh2d::get_temp(int x, int y) {
	return this->data.get_el(x, y).get_cell_temp();
}

int mesh2d::get_uxsize() {
	return this->size.xsize;
};

int mesh2d::get_uysize() {
	return this->size.ysize;
};



void mesh2d::clear_mesh() {
	this->data.clear();
	this->meshstep.xstep = 0;
	this->meshstep.ystep = 0;
	this->size.xsize = 0;
	this->size.ysize = 0;
}

void mesh2d::set_T0() {
	
}