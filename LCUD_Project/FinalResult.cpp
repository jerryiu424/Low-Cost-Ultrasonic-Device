#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include "FinalResult.cpp"
#include "Container.cpp"
#include "Sensors.cpp"
FinalResult::FinalResult(){


	sensor.updateLine();
	vessel.getConfiguration();
	speedOfSoundM = 331+06*sensor.getTemperature();
	speedOfSoundCM = SpeedOfSoundM*100;

	if(vessel.getShapeID() == "Cube")
	{
		distance = (sensor.getDuration()/2)*speedOfSoundCM;
		level = vessel.getLength() - cubeDistance;
		volume = vessel.getWidth()*vessel.getLength()*cubeLevel; 

	}
	
	else if(vessel.getShapeID() == "Cuboid")
	{
		distance = (sensor.getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - cuboidDistance;
		volume = vessel.getWidth()*vessel.getLength()*cuboidLevel;
	
	} 
	else if(vessel.getShapeID() == "Cylinder")
	{
		distance = (sensor.getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - cylinderDistance;
		volume = M_PI*(vessel.getRadius*vessel.getRadius)*cylinderLevel;


	}


}


