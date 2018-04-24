
//this method will save just the data that we want to send through the xbee
void saveData()
{

  File dataFile;

  
//  Serial.println(dataToSave);

  dataFile =  SD.open("data.txt", FILE_WRITE); 


if (dataFile) {
  
  
//  dataFile.println(dataToSave);



for (int i = 0; i < 5; i++) {
//   Serial.println(gpsData[i]);

   dataFile.print(gpsData[i]);
   dataFile.print(",");
}

for (int i = 0; i < 3; i++) {
//   Serial.println(gpsFloat[i]);

   dataFile.print(gpsFloat[i]);
   dataFile.print(",");
}

for (int i = 0; i < 3; i++) {
//   Serial.println(orientation[0][i]);

   dataFile.print(orientation[0][i]);
   dataFile.print(",");
}

dataFile.print("\n");

  dataFile.close();

} else {
    // if the file didn't open, print an error:
    Serial.println("error opening file");
 }
  
}

////returns the position of the cursor inthe file after a line is read
//long readLineFromFile(char line[], long positionToStartFrom)
//{
//  dataFile.seek(positionToStartFrom);
//  char currentChar = ' ';
//  int counter = 0;
//  //while we dont have a new line add each character to the char array buffer.  
//  while(currentChar!= '\n' && dataFile.available())
//  {
//    currentChar = dataFile.read();
//    if (currentChar!='\n') 
//    {
//      line[counter] = currentChar;
//    }
//    counter++;
//  }
//  return dataFile.position();
//}


//might need a arrays to csv method. where we input all of the arrays of our data and output a csv formatted string to write to the file.  

