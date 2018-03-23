/*
Example from Arduino SoftwareSerial tutorial
 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3, 2); // RX, TX

String id = String(3331);
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.listen();
//  delay(500);
//  Serial.println("Sending +++");
//  mySerial.write("+++");
//  delay(1000);
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
//  Serial.println("\nSetting id to " + id);
//  
//  mySerial.write("ATID3331\r");
//  delay(500);
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
//  Serial.print("\nSet id to ");
//  mySerial.write("ATID\r");
//  delay(500);
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
//
//  Serial.print("\nSH is ");
//  mySerial.write("ATSH\r");
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
//
//  Serial.print("\nSL is ");
//  mySerial.write("ATSL\r");
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
//  Serial.print("\nwriting ");
//  mySerial.write("ATWR\r");
//  while(mySerial.available()){
//    Serial.write(mySerial.read());
//  }
  
  
}

void loop() // run over and over
{
  
  if (mySerial.available())
    Serial.write(mySerial.read());
  
  if (Serial.available())
    mySerial.write(Serial.read());
    
}
