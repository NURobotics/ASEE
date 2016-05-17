//setAmbientBase takes in a pin and returns the ambient light level.  Very useful for the setup() procedure, maybe elsewhere
int setAmbientBase(int pin){
  int baseLevel = analogRead(pin);
  delay(ambientWaitTime);
  baseLevel+= analogRead(pin);
  delay(ambientWaitTime);
  baseLevel+=analogRead(pin);
  return baseLevel/=3;
}

//determineSide() returns 1 if on left 2 if in middle 3 if on right
//especially useful if more than one are determined to be reading black
int determineSide(){
  int leftValue = analogRead(leftPhotoTransistor);
  int middleValue = analogRead(middlePhotoTransistor);
  int rightValue = analogRead(rightPhotoTransistor);
  int minValue = min(leftValue, middleValue);
  minValue = min(minValue, rightValue);
  //that gets the minimum of the three photoTranistor Values
  if (minValue==middleValue){
    return 2;
  }
  else if (minValue==leftValue){
    return 1;
  }
  else{
    return 3;
  }
  
}

