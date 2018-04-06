//handles control LED output
void controlLED(){
  if(rightValue == LOW && !selectOn){
    digitalWrite(ledRight,LOW);
  }else if(rightValue == HIGH || selectOn){
    digitalWrite(ledRight,HIGH);  
  }

  if(leftValue == LOW){
    digitalWrite(ledLeft,LOW);
  }else if(leftValue == HIGH){
    digitalWrite(ledLeft,HIGH);  
  }



}
