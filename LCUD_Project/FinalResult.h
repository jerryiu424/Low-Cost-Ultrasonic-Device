#ifndef FINALRESULT_H
#define FINALRESULT_H
#include <string>
#include "Container.h"

class FinalResult{
	private:
		float speedOfSoundM, speedOfSoundCM;
		float levesl, distance, volume;
		Container vessel;
			
	public:
		FinalResult();
		float calculateVolume(){return volume;}
		float calculateLevel(){return level;}
		float calculateDistance(){return distance;}
		std::string to_string();
};
#endif