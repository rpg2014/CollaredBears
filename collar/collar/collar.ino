#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_GPS.h>

//sdcard includes
#include <SPI.h>
#include <SD.h>

//for xbee
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);
//SoftwareSerial xbee(3, 2); // RX, TX

//for GPS
Adafruit_GPS GPS(&mySerial);
#define GPSECHO  false

// this keeps track of whether we're using the interrupt
// off by default!
boolean usingInterrupt = false;
void useInterrupt(boolean); // Func prototype keeps Arduino 0023 happy
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//number of readings for 9d0f sensor
const int numberOfReadings = 1;

const int secondsBetweenReadings = .1; //change this not numberOfReadings

//array for storing the orientation data
const int rows = numberOfReadings;
const int columns = 3;
//this creates a 3*10 matrix for storing the x,y,z euler angles
float orientation[rows][columns];

//array for storing accelerometer data.  same size as orinetation array.
float accel[rows][columns];

//array for storing gps stuff
float gpsData[8];

//sdcard variable
File dataFile;


//buffer for reading lines from the file.
char line[255];

//Main function
//need to set up everything (bno, gps,sdcard,xbees?)
void setup() {
  // put your setup code here, to run once:
  
  // connect at 115200 so we can keep up with GPS
  Serial.begin(115200);
  if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    //while(1);
  }
  
  delay(1000);

  setupGPS();
    
  bno.setExtCrystalUse(true);

}





int secondsToMilliseconds(int seconds){
  return seconds*1000;
}


//i hope this works
String convertArraysToString(float orientation[][3], float accel[][3],float gpsData[4],int8_t temp){
  String gpsDataString = String(gpsData[0]+','+gpsData[1]+','+gpsData[2]+','+gpsData[3]+',');
  String orientString = String(String(orientation[0][0])+","+String(orientation[0][1])+","+String(orientation[0][2])+",");
  String accelString = String(String(accel[0][0])+","+String(accel[0][1])+","+String(accel[0][2])+",");
  String tempString = String(temp);
  
  return String(gpsDataString + orientString + accelString + tempString);
}


