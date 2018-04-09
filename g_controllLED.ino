//handles control LED output
//LED lights up when toes are up
//right LED also lights up when in select mode 

void controlLED(){
  if(rightState == LOW && !selectOn){
    digitalWrite(ledRight,LOW);
  }else if(rightState == HIGH || selectOn){
    digitalWrite(ledRight,HIGH);  
  }

  if(leftState == LOW){
    digitalWrite(ledLeft,LOW);
  }else if(leftState== HIGH){
    digitalWrite(ledLeft,HIGH);  
  }
}
