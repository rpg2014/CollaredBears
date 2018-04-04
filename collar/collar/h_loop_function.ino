//had to move it down here so that all the methods are declared and implemented before it. 
void loop() {
  // put your main code here, to run repeatedly:



  //get all the data
  getOrientation(orientation, numberOfReadings);
  getAcceleration(accel,numberOfReadings);
  int8_t temp = getTemp();
  getGPS(gpsData);

  //convert arrays to a string
  String lineOfData = convertArraysToString(orientation,accel,gpsData,temp);

  //save the data to a file
  saveData(lineOfData);

  //check to see if drone is in range.
  if(readyToSend()){
    //if it is then start sending the entire file
    long positionToStartFrom = 0;
    while(positionToStartFrom <= dataFile.size()){
      long postitionToStartFrom = readLineFromFile(line,positionToStartFrom);
      sendData(line);
    }
    //we could delete the file after this and start over recording.
  }


  //now wait the designated amount of time.
  delay(secondsToMilliseconds(secondsBetweenReadings));
}
