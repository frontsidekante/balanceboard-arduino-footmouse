//test functions for logging and debugging
//in setup() -> use while(!Serial){...} to print to serial monitor 
//this is necessary because Leonardo has only 1 chip for USB communication and processing of sketches

//prints state of MPU6050 (asleep or active) to serial monitor
void printSleepModeStatus(){
  if(mpu.getSleepEnabled()){
    Serial.println("MPU is asleep");
  }else{
    Serial.println("MPU is active");  
  }
}

//prints I2C connection status of MPU6050 to serial monitor
void printConnectionStatus(){
  if(mpu.testConnection()){
    Serial.println("MPU I2C connection established");
  }else{
    Serial.println("MPU I2C connection could not be established");  
  }
}

//prints gyroscope data for x- and y-axis to serial monitor
void printGyroData(){ 
  Serial.print(" | GyroX: ");
  Serial.print(gyroX);
  Serial.print(" | GyroY: ");
  Serial.print(gyroY);
  delay(200); 
}



  
