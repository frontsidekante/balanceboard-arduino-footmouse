void handleRightFoot(){ 
    //select / drag and drop
  if(rightValue == LOW && lastIrRightState == LOW && selectOn){
    Mouse.press();
    Mouse.move(-gyroX/widthSensitivity, gyroY/heightSensitivity);    
    //rightValue = digitalRead(irRight);
    //getGyroData();
  }else{
      Mouse.release();
      //break;
        //feet were down, are up now 
      if(rightValue == HIGH && lastIrRightState== LOW){
        startTime = millis();  
      }
      //feet were up, are down now 
      else if(rightValue == LOW && lastIrRightState == HIGH){
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
  
  lastIrRightState = rightValue; 
}
  
  

  

