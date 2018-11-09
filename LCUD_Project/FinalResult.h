#ifndef FINALRESULT_H
#define FINALRESULT_H
#include <string>
#include "Container.cpp"

class FinalResult{
	private:
		float speedOfSoundM, speedOfSoundCM;
		float level, distance, volume;
		Container vessel;
		
	
	public:
		FinalResult();
		float calculateVolume(){return volume};
		float calculateLevel(){return level};
		float calculateDistance(){return distance};
		std::string to_string();

};
#endif