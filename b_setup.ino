//functions used in setup()
//gets MPU6050 and TCRT5000 ready

//sets offsets for x- and y-axis
void setOffsets(){
  mpu.setXGyroOffset(17);
  mpu.setYGyroOffset(96);
}

//sets pin modes for TCRT5000 Breakout Board
void setPinmodes(){
  //Control LED
  pinMode(ledRight,OUTPUT);
  pinMode(ledLeft,OUTPUT);

  //Sensor LED
  pinMode(irLeft, INPUT);
  pinMode(irRight,INPUT); 
  
}

//activates pull up resistors for TCRT5000
void activatePullups(){
  digitalWrite(irRight,HIGH); 
  digitalWrite(irLeft, HIGH);  
}




