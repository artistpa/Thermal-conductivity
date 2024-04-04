#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Solver2d.hpp"

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
	meshsize size;
	int T_min;
	int T_max; // units
public:
	mesh2d(); // конструктор

	void set_mesh2d (int xlen, int ylen, int xstep, int ystep);
	void clear_mesh();
	void set_T_min();
	void set_T_max();
	int get_T_min();
	int get_T_max();
	void set_temp(int x, int y, float temp); // sets temp temperature in [x, y] cell
	float get_temp(int x, int y);
	int get_uxsize(); // returns x length of mesh in units
	int get_uysize(); // returns y length of mesh in units
    void set_T0_mesh();
    void update(Solver2d s);

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
			this->data.get_el(i, j).set_cell_temp(0);
		}
	}

	std::cout << "DATA SET " << std::endl;

	// setting meshstep
	this->meshstep.xstep = xstep;
	this->meshstep.ystep = ystep;

	std::cout << std::endl;
	std::cout << "2D MESH SUCCESSFULLY SET" << std::endl;

}

void mesh2d::set_T_min(){
    std::cin >> this->T_min;
}

void mesh2d::set_T_max(){
    std::cin >> this->T_max;
}

int mesh2d::get_T_min(){
    return T_min;
}

int mesh2d::get_T_max(){
    return T_max;
}

void mesh2d::set_temp(int x, int y, float temp) {
	this->data.get_el(x, y).set_cell_temp(temp);
}

float mesh2d::get_temp(int x, int y){
    return this->data.get_el(x, y).get_cell_temp();
}

void mesh2d::set_T0_mesh(){
    for (int i = 0; i < get_uysize(); i++)
        set_temp(i, 0, T_max);
    for (int j = 1; j < get_uxsize(); j++)
        set_temp(0, j, T_max);
    for (int i = 1; i < get_uysize(); i++)
        set_temp(i, 49, T_max);
    for (int j = 1; j < (get_uxsize() - 1); j++)
        set_temp(49, j, T_max);
    for (int i = 1; i < (get_uysize() - 1); i++)
        for (int j = 1; j < (get_uxsize() - 1); j++)
            set_temp(i, j, T_min);
};

int mesh2d::get_uxsize() {
	return this->size.xsize;
};

int mesh2d::get_uysize() {
	return this->size.ysize;
};

void mesh2d::update(Solver2d s){
    for (int i = 1; i < (mesh2d::get_uysize() - 1); i++)
        for (int j = 1; j < (mesh2d::get_uxsize() - 1); j++)
            if (mesh2d::get_temp(i, j) <= this->T_max)
                 mesh2d::set_temp(i, j, s(mesh2d::get_temp(i, j), mesh2d::get_temp(i, j - 1), mesh2d::get_temp(i, j + 1), mesh2d::get_temp(i + 1, j), mesh2d::get_temp(i - 1, j)));
};

void mesh2d::clear_mesh() {
	this->data.clear();
	this->meshstep.xstep = 0;
	this->meshstep.ystep = 0;
	this->size.xsize = 0;
	this->size.ysize = 0;

};
