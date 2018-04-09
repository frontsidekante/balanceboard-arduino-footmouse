
void handleLeftFoot(){  
  //feet were down, are up now 
  if(leftState == HIGH && lastLeftState == LOW){
    startTime = millis();  
  }
  //feet were up, are down now 
  else if(leftState == LOW && lastLeftState == HIGH){
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
  //update lastLeftState
  lastLeftState = leftState; 
}
