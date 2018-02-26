#include <SoftwareSerial.h>

const char cListen = '1';
const char cTalk = '2';
const char cEnd = '3';
char inByte='A';

char cStatus = '2';    // For '1', set the current status to Listen; for '2", Talk mode

int RXPin = 3;
int TXPin = 2;

SoftwareSerial portTwo(RXPin, TXPin);

void setup() {
  Serial.begin(9600); // for the connection to PC
  while (!Serial) { ;}
  portTwo.begin(9600);  // for the connection between Arduino and XBee
}  

void loop() {
  switch ( cStatus ) {
    case cListen:
      portTwo.listen();
      Serial.println("start listening ... (receive 2 to switch to Talk)");
      while(inByte != cTalk){
        if (portTwo.available() > 0) {
          inByte = portTwo.read();
          if ( inByte == cTalk ) {
            cStatus = cTalk;
          }
          Serial.write(inByte);
        }       
      }
      cStatus = cTalk;
      break;
    case cTalk:
      Serial.println("Start talking ... (press 1 to switch Listen)");
      while ( inByte != cListen ) {
        if ( Serial.available() > 0 ) {
          inByte = Serial.read();
          if ( inByte == cListen ) {
            cStatus = cListen;
            portTwo.write( cTalk ); //tell the other party to switch to talk
          } else if (inByte != cTalk ) {
            portTwo.write(inByte);
          }
        }
      }
      break;
  }
  inByte = 'A';
  while ( Serial.available() > 0 ) { Serial.read(); } //clear Serial buffer
  while ( portTwo.available() > 0 ) { portTwo.read(); } //clear portTwo buffer
  Serial.print('\n');
}

