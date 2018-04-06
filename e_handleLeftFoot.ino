void handleLeftFoot(){  
  //feet were down, are up now 
  if(leftValue == HIGH && lastIrLeftState == LOW){
    startTime = millis();  
  }
  //feet were up, are down now 
  else if(leftValue == LOW && lastIrLeftState == HIGH){
    Serial.println("IF 3");
    unsigned long endTime = millis();
    unsigned long duration = endTime - startTime;
    if(duration < longClick){
      Mouse.click();
    }
    else{
      Mouse.click();
      Mouse.click();
    }
  } 
  lastIrLeftState = leftValue; 
}
