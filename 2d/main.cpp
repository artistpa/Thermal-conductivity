#include <SFML/Graphics.hpp>
#include <iostream>

#include "painter.h"
#include "mesh2d.h"

int main() {
	mesh2d a;
	a.set_mesh2d(100, 100, 1, 2);
	painter b(1000, 500);
	b.display(a);
	a.clear_mesh();
}