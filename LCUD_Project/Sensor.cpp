#include <unistd.h>
#include <fstream>
#include <string>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {

  //To reid or vance or whomever:  This code shows you how the pi can take in the values from the arduino and output them.
  //This should not be in the main like this, it's just a proof of concept.
  //feel free to completely delete it once you have it in the right class

	ifstream inFile;
	string sensorID = 0;
	string line;
	inFile.open("/dev/ttyACM" + sensorID);
	while(getline(inFile, line))
	{

	stringstream ss(line);
	string duration;
	getline(ss,duration, ' ');
	string temperature;
	getline(ss,temperature,' ');

	
	if(!duration.empty() && !temperature.empty()){
	cout << "\nDuration: " << duration;
	cout << "\nTemperature: " << temperature;
}
	usleep(100000);//pause for 1 second


}	
	inFile.close();
	return 0;
}
