//#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
#include <Adafruit_GPS.h>

//sdcard includes
//#include <SPI.h>
#include <SD.h>

//for xbee
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2);
//SoftwareSerial xbee(3, 2); // RX, TX

//for GPS
Adafruit_GPS GPS(&mySerial);
#define GPSECHO  false

//int loops = 0;

// this keeps track of whether we're using the interrupt
// off by default!
boolean usingInterrupt = false;
void useInterrupt(boolean); // Func prototype keeps Arduino 0023 happy
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//number of readings for 9d0f sensor
//const int numberOfReadings = 1;

//const int secondsBetweenReadings = .1; //change this not numberOfReadings

//array for storing the orientation data
//const int rows = numberOfReadings;
//const int columns = 1;
//this creates a 3*10 matrix for storing the x,y,z euler angles
float orientation[1][3];

//array for storing accelerometer data.  same size as orinetation array.
//float accel[rows][columns];

//array for storing gps stuff
int gpsData[5];

float gpsFloat[3];

//sdcard variable



//buffer for reading lines from the file.
//char line[255];

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

  Serial.print("Setup Complete\n");
  
  delay(1000);

  pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  

  setupGPS();
    
  bno.setExtCrystalUse(true);

}





//int secondsToMilliseconds(int seconds){
//  return seconds*1000;
//}


//i hope this works
//String convertArraysToString(float orientation[][columns], int gpsData[], float gpsFloat[]){
//  Serial.println("Conversion Start: ");
//  String gpsDataString = (String)gpsData[0]+','+gpsData[1]+','+gpsData[2]+','+gpsData[3]+','+gpsData[4]+','+gpsFloat[0]+','+gpsFloat[1]+','+gpsFloat[2]+',';
//  Serial.println(gpsDataString);
//  String orientString = (String)orientation[0][0] + ',' + orientation[0][1] + ',' + orientation[0][2];
//  Serial.println(orientString);
//  //String tempString = String(temp);
//  
//  return gpsDataString + orientString;
//}


