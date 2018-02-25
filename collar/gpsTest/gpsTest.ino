#include "GPS.h"


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  GPSCoords v(72.382f, 78.2828f);

  Serial.println(v.getString());

}

void loop() {
  // put your main code here, to run repeatedly:

}
