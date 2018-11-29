#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <mysql/mysql.h>
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"

# define M_PI 3.14159265358979323846  /* pi */

using namespace std;

void CubeFunc(Cube);
void CylinderFunc(Cylinder);
void CuboidFunc(Cuboid);

Cube createCube();
Cylinder createCylinder();
Cuboid createCuboid();

#endif