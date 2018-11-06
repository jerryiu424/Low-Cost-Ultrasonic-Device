#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {

	ifstream inFile;
	inFile.open("/dev/ttyACM1");
	while(getline(inFile, line))
	{

	stringstream ss(line);
	string duration;
	getline(ss,duration, ' ');
	string temperature;
	getline(ss,temperature,' ');

	cout << "Duration: " << duration << "\n" << "Temperature: " << temperature;

}	
	inFile.close();
	return 0;
}