//author: frontsidekante
//functions used in loop()

void getGyroData(){ 
  gyroX = mpu.getRotationX() / 131.0;
  gyroY = mpu.getRotationY() / 131.0;
}

void getIrData(){
  rightState = digitalRead(irRight);
  leftState = digitalRead(irLeft);
}