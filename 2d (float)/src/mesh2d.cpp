 #include "mesh2d.h"


// constructor
// it only creates mesh, it doesnt set it
mesh2d::mesh2d() {
	this->data = cont(0, 0);
	this->meshstep.xstep = 0;
	this->meshstep.ystep = 0;
	this->size.xsize = 0;
	this->tcrit.tmax = 0;
	this->tcrit.tmin = 0;

	std::cout << "2d MESH SUCCESSFULLY CREATED" << std::endl;
};


// setting mesh
// this method sets size of mesh and id of every single cell in mesh
// temperature of every cell is equal to 0 K
void mesh2d::set_mesh2d(int xlen, int ylen, float xstep, float ystep) {
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
	std::cout << "2D MESH SUCCESSFULLY SET" << std::endl;
	std::cout << "SIZE OF DATA: " << this->data.get_xsize() << " " << this->data.get_ysize() << std::endl;

};

void mesh2d::set_temp(int x, int y, float tempr) {
	this->data.set_temp_cont(x, y, tempr);
};

float mesh2d::get_temp(int x, int y) {
	return this->data.get_el(x, y).get_cell_temp();
};

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
	this->tcrit.tmax = 0;
	this->tcrit.tmin = 0;
};

void mesh2d::set_T0(float T_max, float T_min) {
	this->tcrit.tmax = T_max;
	this->tcrit.tmin = T_min;
	for (int i = 0; i < get_uysize(); i++)
		set_temp(i, 0, T_max);
	for (int j = 1; j < get_uxsize(); j++)
		set_temp(0, j, T_max);
	for (int i = 1; i < get_uysize(); i++)
		set_temp(i, get_uxsize() - 1, T_max);
	for (int j = 1; j < (get_uxsize() - 1); j++)
		set_temp(get_uysize() - 1, j, T_max);
	for (int i = 1; i < (get_uysize() - 1); i++)
		for (int j = 1; j < (get_uxsize() - 1); j++)
			set_temp(i, j, T_min);
};

void mesh2d::update(Solver2d &s) {
    s.setsolver(1, 50, 10, this->data);
	#if METHOD==0
		this->data=s(Solvers::EULER);
	#elif METHOD==1
		this->data=s(Solvers::RK4);
	#endif
};

float mesh2d::get_tmax() {
	return this->tcrit.tmax;
};

float mesh2d::get_tmin() {
	return this->tcrit.tmin;
};

