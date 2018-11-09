#include "Container.cpp"
#define PI 3.14

using namespace std;

int main(){
    Container vessel;
    float speedOfSoundM = 331+0.6*vessel.getTemperature();
	float speedOfSoundCM = speedOfSoundM*100;
	vessel.update();
    float distance;
    float level;
    float volume;
	if(vessel.getShapeID() == "Cube")
	{
	    distance = (vessel.getDuration()/2)*speedOfSoundCM;
		level = vessel.getSide() - distance;
		volume = vessel.getSide()*vessel.getSide()*level;
	}
	
	else if(vessel.getShapeID() == "Cuboid")
	{
		distance = (vessel.getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - distance;
		volume = vessel.getWidth()*vessel.getLength()*level;
	
	} 
	else if(vessel.getShapeID() == "Cylinder")
	{
		distance = (vessel.getDuration()/2)*speedOfSoundCM;
		level = vessel.getHeight() - distance;
		volume = PI*(vessel.getRadius()*vessel.getRadius())*level;
	}
    cout <<"this is a "+vessel.getShapeID()+" Container with a volume of "+ volume+" and has a water level of "+level <<endl;
    return 0;
}

