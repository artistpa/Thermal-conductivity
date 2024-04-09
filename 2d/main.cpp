#include <SFML/Graphics.hpp>
#include <iostream>

#include "painter.h"
#include "mesh2d.h"

int main() {
	mesh2d a;
	a.set_mesh2d(30, 30 , 1, 1);
	a.set_T0(9000, 300);
	std::cout << a.get_temp(1, 1);
    painter b(1000, 500);
	b.display(a);
	a.clear_mesh();
}
