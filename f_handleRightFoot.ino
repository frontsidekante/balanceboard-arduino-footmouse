void handleRightFoot(){ 
    //select / drag and drop
  if(rightState == LOW && lastRightState == LOW && selectOn){
    Mouse.press();
    Mouse.move(-gyroX/widthSensitivity, gyroY/heightSensitivity);    
  }else{
      Mouse.release();
      //feet were down, are up now 
      if(rightState == HIGH && lastRightState== LOW){
        startTime = millis();  
      }
      //feet were up, are down now 
      else if(rightState == LOW && lastRightState == HIGH){
        //Serial.println("IF 3");
        unsigned long endTime = millis();
        unsigned long duration = endTime - startTime;
        if(duration < longClick){
          //open context menu
          Mouse.click(MOUSE_RIGHT);
        }
        else{
          //activate select mode
          if(!selectOn){
            selectOn = true;
          }     
          else{
            selectOn = false;
          }
        }
      }
    }
  //update lastRightState
  lastRightState = rightState; 
}
  
  

  

