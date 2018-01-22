//author: frontsidekante
//functions used in loop()

void getUsableGyroData(){
  mpu.getMotion6(&RawAccX, &RawAccY, &RawAccZ, &RawGyroX, &RawGyroY, &RawGyroZ); 
  usableGyroX = RawGyroX / 131.0;
  usableGyroY = RawGyroY / 131.0;
  usableGyroZ = RawGyroZ / 131.0;
}
