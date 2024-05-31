#include "cont.h"


int cont::get_xsize() {
	return this->xsize;
}

int cont::get_ysize() {
	return this->ysize;
}

void cont::set_temp_cont(const int x, const int y, const float tempr) {
	(*data[x])[y]->set_cell_temp(tempr);
}

void cont::clear() {
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

cont::cont(int xsize, int ysize) {
	this->xsize = xsize;
	this->ysize = ysize;

	for (int i = 0; i < xsize; i++) {
		std::vector<cell2d*>* tmpvec = new std::vector<cell2d*>;
		for (int j = 0; j < ysize; j++) {
			cell2d* tmp = new cell2d;
			tmpvec->push_back(tmp);
		}
		data.push_back(tmpvec);

	};
}




