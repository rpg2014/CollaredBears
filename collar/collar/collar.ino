#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//sdcard includes
#include <SPI.h>
#include <SD.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//number of readings for 9d0f sensor
const int numberOfReadings = 10;


//array for storing the orientation data
const int rows = numberOfReadings;
const int columns = 3;
//this creates a 3*10 matrix for storing the x,y,z euler angles
float orientation[rows][columns];

//array for storing accelerometer data.  same size as orinetation array.
float accel[rows][columns];

//sdcard variable
File dataFile;


//buffer for reading lines from the file.
char line[255];

//Main function
//need to set up everything (bno, gps,sdcard,xbees?)
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  //this is an example of using the getOrientation method
  getOrientation(orientation, 10);
  //the orientation array is now populated with data which we can then manipulate and save.  the accelerometer method works the same.
}
