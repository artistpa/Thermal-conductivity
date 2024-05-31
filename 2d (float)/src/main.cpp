#include <SFML/Graphics.hpp>
#include <iostream>
#include "painter.h"
#include "mesh2d.h"

int main() {
	mesh2d a;
	a.set_mesh2d(1, 1, 0.02, 0.02);
	a.set_T0(1500, 100);
    painter b(1200, 500);
	b.display(a);
	a.clear_mesh();
}
