//functions used in setup()

void setOffsets(){
  mpu.setXGyroOffset(17);
  mpu.setYGyroOffset(96);
}

void setPinmodes(){
  //Control LED
  pinMode(ledRight,OUTPUT);
  pinMode(ledLeft,OUTPUT);

  //Sensor LED
  pinMode(irLeft, INPUT);
  pinMode(irRight,INPUT); 
  
}

void activatePullups(){
  digitalWrite(irRight,HIGH); 
  digitalWrite(irLeft, HIGH);  
}




