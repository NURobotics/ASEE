
//setAmbientBase takes in a pin and returns the ambient light level.  Very useful for the setup() procedure, maybe elsewhere
int setAmbientBase(int pin){
  int baseLevel = analogRead(pin);
  delay(AMBIENT_WAIT_TIME);
  baseLevel+= analogRead(pin);
  delay(AMBIENT_WAIT_TIME);
  baseLevel+=analogRead(pin);
  return baseLevel/=3;
}

//lineDetected() is a boolean function that returns true if any of our main PhotoTransistors see the black line
bool lineDetected(){
  int leftDiff = leftBase -analogRead(leftPhotoTransistor);
  int middleDiff = middleBase - analogRead(middlePhotoTransistor);
  int rightDiff = rightBase - analogRead(rightPhotoTransistor);
  return (leftDiff>LIGHT_THRESHOLD)||(middleDiff>LIGHT_THRESHOLD)||(rightDiff>LIGHT_THRESHOLD);
}

//determineSide() returns 1 if on left 2 if in left middle 3 if in middle 4 if in right middle and 5 if on right
//especially useful if more than one are determined to be reading black
int determineSide(){
  int leftValue = leftBase-analogRead(leftPhotoTransistor);
  int leftMiddleValue=leftMiddleBase-analogRead(leftMiddlePhotoTransistor);
  int middleValue = middleBase-analogRead(middlePhotoTransistor);
  int rightMiddleValue=rightMiddleBase-analogRead(rightMiddlePhotoTransistor);
  int rightValue = rightBase-analogRead(rightPhotoTransistor);
  int leftMinValue = max(leftValue, leftMiddleValue);
  int rightMinValue = max(rightValue, rightMiddleValue);
  int minValue = max(leftMinValue,rightMinValue);
  minValue=max(minValue, middleValue); 
  //that gets the maximum of the difference between the base and the current
  //This basically says whatever changed the most (got the lowest) as compared to the base will be the side we believe the black is closest too
  if (minValue==leftValue){
    return 1;
  }
  else if (minValue==leftMiddleValue){
    return 2;
  }
  else if (minValue==middleValue){
    return 3;
  }
  else if (minValue==rightMiddleValue){
    return 4;
  }
  else if (minValue==rightValue){
    return 5;
  }
  else{
    Serial.println("This shouldnt happen");
    return -1;
  }
}

