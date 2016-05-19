
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

//determineSide() returns 1 if on left 2 if in middle 3 if on right
//especially useful if more than one are determined to be reading black
int determineSide(){
  int leftValue = leftBase-analogRead(leftPhotoTransistor);
  int middleValue = middleBase-analogRead(middlePhotoTransistor);
  int rightValue = rightBase-analogRead(rightPhotoTransistor);
  int minValue = max(leftValue, middleValue);
  minValue = max(minValue, rightValue);
  //that gets the maximum of the difference between the base and the current
  //This basically says whatever cahnged the most (got the lowest) as compared to the base will be the side we believe the black is closest too
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

