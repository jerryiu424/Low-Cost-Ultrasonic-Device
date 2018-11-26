#include "Sensors.cpp"
#include <cstdlib>
#define SLEEP 1500000
using namespace std;

void draw(int []);
string multiply(int);

int main(){
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors())<< endl;    //should be 0
    Sensors first;
    //Sensors second;
    cout << "first sensor has ID: " + first.getSensorID() << endl;
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors()) << endl; 

    //print info duration of first sensor in 1 second increments 10 times
    int temp[] ={0,0,0,0,0,0,0,0,0,0};
    int position = 0;
    usleep(SLEEP);
    for (int i = 0; i<100;i++){
        first.update();    //read line, which updates duration and temp
        usleep(SLEEP);//pause for 1 second
        position++;
        position = position % 10;
        draw(temp);
    }
    return 0;
}
void draw(int a[]){
    ofstream newFile;
    newFile.open("drawing.txt");
    for(int i =0;i<10;i++){
    
        newFile <<multiply(a[i])+".\n";
    }
    newFile.close();

}
string multiply(int t){
    string res = "";
    for (int i = 0;i<=t;i++){
        res = res+"o";
    }
    return res;
}