


//I dont even know how to start with these

//this method will return true or false depending on weither there is another xbee in range that says its ready to accpet the data
bool readyToSend()
{
  
}


//method that sends the data.  returns true if successful?(might not be possible to tell if successful though).  
// as the .send() method sends one byte at at time we can just give it the char array
bool sendData(char line[])
{
  for( unsigned int a = 0; a < sizeof(line)/sizeof(line[0]); a = a + 1 ){
    xbee.write(line[a]);
  }

  
}



