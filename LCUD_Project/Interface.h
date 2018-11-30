/** 
 *  @brief      The Interface program.
 *
 *  @details    
 *              This program starts by either loading a pre-existing container, or creates a new one;
 *              it then reads data from the sensor to determind the volume of the fluid in the container.  
 *              We then periodically take an average of the data, and send it to our database.
 * 
 *  @author     Marco Manuel
 *  @author     Vance Gullberg
 *  @author     Morgan O'Brien
 *  @author     Jerry Iu 
 *  @author     Joon Lee
 *  @author     Reid Jackson
 */ 
#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <mysql/mysql.h>
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"

#define M_PI 3.14159265358979323846  /* pi */

using namespace std;

void CubeFunc(Cube);
void CylinderFunc(Cylinder);
void CuboidFunc(Cuboid);

Cube createCube();
Cylinder createCylinder();
Cuboid createCuboid();

#endif