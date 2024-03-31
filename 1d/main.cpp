#include <SFML/Graphics.hpp>
#include <iostream>
#include "draw.h"


int main()
{
    // creating and setting mesh
    mesh1d mesh = mesh1d();
    mesh.set_mesh1d(1000, 10);

    //displaying mesh using painter
    painter d;
    d.display(mesh);

    //deleting mesh
    mesh.clear_mesh();
}
