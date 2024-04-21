#pragma once
#include <iostream>
#include <vector>
#include "cell2d.h"

class cont {

private:
	std::vector< std::vector<cell2d*>*> data;
	int xsize;
	int ysize;
public:
	cont() {};
	cont(int xsize, int ysize) {
		this->xsize = xsize;
		this->ysize = ysize;

		//creating vectors of pointers to cells and pushing it into data
		for (int i = 0; i < xsize; i++) {
			std::vector<cell2d*>* tmpvec = new std::vector<cell2d*>;
			for (int j = 0; j < ysize; j++) {
				cell2d* tmp = new cell2d;
				tmpvec->push_back(tmp);
			}
			data.push_back(tmpvec);
		}
	};


	//returns an element from coontainer
	//use it, if you want to change smth in cell (ex setting temp)
	cell2d get_el(int i, int j) {
		return *(*data[i])[j];
	}

	//clears container
	void clear() {
		for (int i = 0; i < xsize; i++) {
			for (int j = 0; j < ysize; j++) {
				delete (*data[i])[j];
				(*data[i])[j] = nullptr;
			}
			data[i]->clear();
			delete data[i];
		}
		data.clear();

	}

	int get_xsize();
	int get_ysize();

	void set_temp_cont(int x, int y, int tempr);

};

int cont::get_xsize() {
	return this->xsize;
}

int cont::get_ysize() {
	return this->ysize;
}

void cont::set_temp_cont(const int x, const int y, const int tempr) {
	(*data[x])[y]->set_cell_temp(tempr);
}


