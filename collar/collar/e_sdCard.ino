



String dataFileName = "data.csv";



//this method will save just the data that we want to send through the xbee
void saveData(String dataToSave)
{
  Serial.println(dataToSave);
//  dataFile =  SD.open(dataFileName, FILE_WRITE);
//  dataFile.print(dataToSave);
//  dataFile.close();
  
}

//returns the position of the cursor inthe file after a line is read
long readLineFromFile(char line[], long positionToStartFrom)
{
  dataFile.seek(positionToStartFrom);
  char currentChar = ' ';
  int counter = 0;
  //while we dont have a new line add each character to the char array buffer.  
  while(currentChar!= '\n' && dataFile.available())
  {
    currentChar = dataFile.read();
    if (currentChar!='\n') 
    {
      line[counter] = currentChar;
    }
    counter++;
  }
  return dataFile.position();
}


//might need a arrays to csv method. where we input all of the arrays of our data and output a csv formatted string to write to the file.  

