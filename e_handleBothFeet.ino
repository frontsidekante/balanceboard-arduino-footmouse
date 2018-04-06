void handleBothFeet(){  
  if(rightValue == LOW && leftValue == LOW){
    Mouse.move(-gyroX/widthSensitivity, gyroY/heightSensitivity);
  }

}

