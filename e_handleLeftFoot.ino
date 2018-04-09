//implements click and double click

void handleLeftFoot(){  
  //feet were down, are up now 
  if(leftState == HIGH && lastLeftState == LOW){
    startTime = millis();  
  }
  //feet were up, are down now 
  else if(leftState == LOW && lastLeftState == HIGH){
    unsigned long endTime = millis();
    unsigned long duration = endTime - startTime;
    if(duration < longClick){
      //click
      Mouse.click();
    }
    else{
      //doubleclick
      Mouse.click();
      Mouse.click();
    }
  } 
  //update lastLeftState
  lastLeftState = leftState; 
}
