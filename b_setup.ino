//author: frontsidekante
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

//SETUP TEST FUNCTIONS FOR LOGGING AND DEBUGGING
//use while(!Serial){...} to print to serial monitor 
//"while" necessary because Leonardo has only 1 chip for USB communication and processing of sketches

void getSleepModeStatus(){
  if(mpu.getSleepEnabled()){
    Serial.println("MPU is asleep");
  }else{
    Serial.println("MPU is active");  
  }
}

void getConnectionStatus(){
  if(mpu.testConnection()){
    Serial.println("MPU I2C connection established");
  }else{
    Serial.println("MPU I2C connection could not be established");  
  }
}


