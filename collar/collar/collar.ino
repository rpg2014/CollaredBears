#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

//sdcard includes
#include <SPI.h>
#include <SD.h>

//for xbee
#include <SoftwareSerial.h>


SoftwareSerial xbee(3, 2); // RX, TX
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//number of readings for 9d0f sensor
const int numberOfReadings = 10;

const int secondsBetweenReadings = 10;

//array for storing the orientation data
const int rows = numberOfReadings;
const int columns = 3;
//this creates a 3*10 matrix for storing the x,y,z euler angles
float orientation[rows][columns];

//array for storing accelerometer data.  same size as orinetation array.
float accel[rows][columns];

float gpsData[4];
//sdcard variable
File dataFile;


//buffer for reading lines from the file.
char line[255];

//Main function
//need to set up everything (bno, gps,sdcard,xbees?)
void setup() {
  // put your setup code here, to run once:

}





int secondsToMilliseconds(int seconds){
  return seconds*1000;
}



//this still needs to be done
String convertArraysToString(float orientation[][3], float accel[][3],float gpsData[4],int8_t temp){
  return "filler";
}


