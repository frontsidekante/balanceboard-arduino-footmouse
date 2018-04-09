//implements cursor movement

void handleBothFeet(){  
  if(rightState == LOW && leftState == LOW){
    Mouse.move(-gyroX/widthSensitivity, gyroY/heightSensitivity);
  }
}

