CS3307 Project Group 10
LCUD - Low Cost Ultrasonic Device
README:

What the LCUD is:
The LCUD is a low-cost, accurate (to 1 mL) ultrasonic and temperature sensor system to remotely measure and track the volume of substances in containers anywhere. An ultrasonic sensor and a temperature sensor are attached to an Arduino microcontroller, which sends readings to a raspberry pi (or any linux computer). The algorithm to compute distance from the sensor to the surface and to compute the volume of a liquid or solid in 3 different container shapes is implemented via our class system in C++. An apache server runs on the pi and we insert the results into a mySQL database using C++. Our interface queries the database which is also on the pi and dynamically displays the measurements as well as the date and time. The measurements on the interface are live and refresh every 15 seconds. //The interface also features a sensor-container setup wizard and a GUI display.

How to run and use the LCUD:
//Not sure yet.

Group Members:
Vance Gullberg
Morgan O’Brien
Jerry Iu
Reid Jackson
Joon Lee
Marco Manuel