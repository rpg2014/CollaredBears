#include "Arduino.h"


#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


  const int rows = 10;
  const int columns = 3;
  //this creates a 3*10 matrix for storing the x,y,z euler angles
  float orientation[rows][columns];

//fuck it just do it all in ino files and methods
//have to pass in the array and the numbers added to it. 
void readData(float orientation[][3],int numberOfReadings)
{

  
  
  
  for(int i = 0; i<=numberOfReadings; i++)
  {
    sensors_event_t event; 
    bno.getEvent(&event);
    orientation[i][0] = event.orientation.x;
    orientation[i][1] = event.orientation.y;
    orientation[i][2] = event.orientation.z;
    
  }
  
  
}





