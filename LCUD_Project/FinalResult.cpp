#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include "FinalResult.h"
#include "Container.cpp"
FinalResult::FinalResult(){


	
	
	speedOfSoundM = 331+0.6*sensor.getTemperature();
	speedOfSoundCM = SpeedOfSoundM*100;
	vessel.getSensor().updateLine();
	if(vessel.getShapeID() == "Cube")
	{
		distance = (vessel.getSensor().getDuration()/2)*speedOfSoundCM;
		level = vessel.getSide() - distance;
		volume = vessel.getSide()*vessel.getSide()*level;
	}
	
	else if(vessel.getShapeID() == "Cuboid")
	{
		distance = (vessel.getSensor().getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - distance;
		volume = vessel.getWidth()*vessel.getLength()*level;
	
	} 
	else if(vessel.getShapeID() == "Cylinder")
	{
		distance = (vessel.getSensor().getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - distance;
		volume = M_PI*(vessel.getRadius()*vessel.getRadius())*level;


	}


}


