//author: frontsidekante
//functions used in setup()

void setOffsets(MPU6050 mpu){
  Serial.print("Setting Offsets...");
  mpu.setXGyroOffset(14);
  mpu.setYGyroOffset(97);
  mpu.setZGyroOffset(12);
  mpu.setXAccelOffset(-1289);
  mpu.setYAccelOffset(-1358);
  mpu.setZAccelOffset(1208);
  Serial.println(" Done");
}

//SETUP TEST FUNCTIONS FOR LOGGING AND DEBUGGING
//use while(!Serial){...} to print to serial monitor 
//"while" necessary because Leonardo has only 1 chip for USB communication and processing of sketches

void getSleepModeStatus(MPU6050 mpu){
  if(mpu.getSleepEnabled()){
    Serial.println("MPU is asleep");
  }else{
    Serial.println("MPU is active");  
  }
}

void getConnectionStatus(MPU6050 mpu){
  if(mpu.testConnection()){
    Serial.println("MPU I2C connection established");
  }else{
    Serial.println("MPU I2C connection could not be established");  
  }
}


