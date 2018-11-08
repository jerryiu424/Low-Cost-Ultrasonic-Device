#ifndef FINALRESULT_H
#define FINALRESULT_H
#include <string>
#include "Container.cpp"
#include "Sensors.cpp"

class FinalResult{

	private:
		std::float speedOfSoundM, speedOfSoundCM;
		std::float level, distance, volume;
		std::Sensors sensor;
		std::Container vessel;
		
	
	public:
		FinalResult();
		std::float calculateVolume(){return volume};
		std::float calculateLevel(){return level};
		std::float calculateDistance(){return distance};
		std::string to_string();



}