//author: frontsidekante
//functions used in setup()

void getSleepModeStatus(MPU6050 mpu){
  if(mpu.getSleepEnabled()){
    Serial.println("Sensor is asleep");
  }else{
    Serial.println("Sensor is active");  
  }
}

void getConnectionStatus(MPU6050 mpu){
  if(mpu.testConnection()){
    Serial.println("I2C connection established");
  }else{
    Serial.println("I2C connection could not be established");  
  }
}

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
