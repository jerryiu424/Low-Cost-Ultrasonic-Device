#include <fstream>
#include <iostream>


int main(){
    std::ifstream inFile;    
    inFile.open("/dev/ttyACM0");
    std::string line;
    std::string lastLine = "";
    std::string seclastLine = "";
    getline(inFile,line);
    while(getline(inFile,line)){
        seclastLine = lastLine;
        lastLine = line;
    }
    std::cout<< "last line:"+lastLine << std::endl;
    std::cout<< "second last line:"+seclastLine << std::endl;

    return 0;
}