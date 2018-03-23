#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>
  
Adafruit_BNO055 bno = Adafruit_BNO055(55);

//array for storing the orientation data
const int rows = 10;
const int columns = 3;
//this creates a 3*10 matrix for storing the x,y,z euler angles
float orientation[rows][columns];


//Main function

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:


  //this is an example of using the getOrientation method
  getOrientation(orientation, 10);
  //the orientation array is now populated with data which we can then manipulate and save.  
}
