//had to move it down here so that all the methods are declared and implemented before it. 
void loop() {
  // put your main code here, to run repeatedly:


    //Serial.print("loop start\n\n");

  //get all the data
  
    getOrientation(orientation);
    
    getGPS(gpsData, gpsFloat);

    
//  getAcceleration(accel,numberOfReadings);
//  int8_t temp = getTemp();


  //convert arrays to a string
//    String lineOfData = convertArraysToString(orientation, gpsData, gpsFloat);
//    Serial.print(gpsData[0]+','+gpsData[1]+','+gpsData[2]+','+gpsData[3]+','+gpsData[4]+','+gpsFloat[0]+','+gpsFloat[1]+','+gpsFloat[2]+',');

  //save the data to a file
    saveData();

  //check to see if drone is in range.
//  if(readyToSend()){
//    //if it is then start sending the entire file
//    long positionToStartFrom = 0;
//    while(positionToStartFrom <= dataFile.size()){
//      long postitionToStartFrom = readLineFromFile(line,positionToStartFrom);
//      sendData(line);
//    }
//    //we could delete the file after this and start over recording.
//  }


//    Serial.print("loop end\n\n");

  //now wait the designated amount of time.
//  delay(secondsToMilliseconds(secondsBetweenReadings));

//    Serial.print("Loop Number: ");
//    Serial.println(loops);

//  loops = loops + 1;
//  if (loops > 30) {
//    abort();
//  }

  delay(1000);
}
