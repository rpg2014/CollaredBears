#include "Arduino.h"


#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>


 

//fuck it just do it all in ino files and methods
//have to pass in the array and the numbers added to it. 
void getOrientation(float orientation[][3],int numberOfReadings)
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


//TODO: fill this in.  its gonna look pretty similar to whats above.
void getAcceleration(float accel[][3],int numberOfReadings)
{


}






