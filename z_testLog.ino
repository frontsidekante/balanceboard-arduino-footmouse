//test functions for logging and debugging
//in setup() -> use while(!Serial){...} to print to serial monitor 
//this is necessary because Leonardo has only 1 chip for USB communication and processing of sketches

void printSleepModeStatus(){
  if(mpu.getSleepEnabled()){
    Serial.println("MPU is asleep");
  }else{
    Serial.println("MPU is active");  
  }
}

void printConnectionStatus(){
  if(mpu.testConnection()){
    Serial.println("MPU I2C connection established");
  }else{
    Serial.println("MPU I2C connection could not be established");  
  }
}

void printGyroData(){
  
  Serial.print(" | GyroX: ");
  Serial.print(gyroX);
  Serial.print(" | GyroY: ");
  Serial.print(gyroY);
  delay(200); 
}



  
