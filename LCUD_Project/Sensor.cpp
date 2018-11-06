#include <unistd.h>
#include <fstream>
#include <string>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {

	ifstream inFile;
	string line;
	inFile.open("/dev/ttyACM2");
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
	usleep(100000);


}	
	inFile.close();
	return 0;
}