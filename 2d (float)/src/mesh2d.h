#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#include "Solver2d.h"
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

struct temp_critical {
	int tmax;
	int tmin;
};


// class of 2d mesh
class mesh2d {
private:
	//std::vector< std::vector<cell2d*>*> data;
	cont data;
	dimstep meshstep; // mm
	meshsize size; // units
	temp_critical tcrit; // T_min and T_max
public:
	mesh2d(); // �����������

	void set_mesh2d(int xlen, int ylen, float xstep, float ystep);
	void clear_mesh();
	void set_temp(int x, int y, float temp); // sets temp temperature in [x, y] cell
	void set_T0(float T_max, float T_min); // sets starting temperature across
	void update(Solver2d &s);
	float get_temp(int x, int y); // returns temperature in [x, y] cell
	int get_uxsize(); // returns x length of mesh in units
	int get_uysize(); // returns y length of mesh in units

	int get_xstep(); // returns xstep (mm)
	int getx(int num_of_cell);// returns id
	int getsize(); //returns mesh length (mm)
	float get_tmin(); // getter for T_min
	float get_tmax(); // getter for T_max
};

