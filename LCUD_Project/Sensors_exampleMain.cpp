#include "Sensors.cpp"
#define SLEEP 1500000
using namespace std;

void draw(int []);
string multiply(int );
int main(){
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors())<< endl;    //should be 0
    Sensors first;
    //Sensors second;
    cout << "first sensor has ID: " + first.getSensorID() << endl;
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors()) << endl; 


    //print info of first sensor in 1 second increments 10 times
    int temp[] ={0,0,0,0,0,0,0,0,0,0};
    int position = 0;
    usleep(SLEEP);
    for (int i = 0; i<10;i++){
        first.update();    //read line, which updates duration and temp
        cout << "first sensor has duration: " + to_string(first.getDuration()) + " and temp: " + to_string(first.getTemperature()) << endl;
        temp[position] = ceil(first.getDuration())/10.0;
        position++;
        position = position % 10;
        draw(temp);
        usleep(SLEEP);//pause for 1 second
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
