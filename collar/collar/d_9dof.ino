#include "Arduino.h"


#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


 

//fuck it just do it all in ino files and methods
//have to pass in the array and the numbers added to it. 
void getOrientation(float orientation[][3])
{

  
  
  
//  for(int i = 0; i < 1; i++)
//  {
    sensors_event_t event; 
    bno.getEvent(&event);
    orientation[0][0] = event.orientation.x;
    orientation[0][1] = event.orientation.y;
    orientation[0][2] = event.orientation.z;
//    
//  }
  
  
}


//TODO: fill this in.  its gonna look pretty similar to whats above.
//void getAcceleration(float accel[][3],int numberOfReadings)
//{
//  for(int i = 0; i < numberOfReadings; i++)
//  {
//    imu::Vector<3> accelerometer = bno.getVector(Adafruit_BNO055::VECTOR_ACCELEROMETER);
//    accel[i][0] = accelerometer.x();
//    accel[i][1] = accelerometer.y();
//    accel[i][2] = accelerometer.z();
//    
//  }
//
//}


//int8_t getTemp(){
//  return bno.getTemp();
//}





