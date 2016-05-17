
//determineSide() returns 1 if on left 2 if in middle 3 if on right
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

