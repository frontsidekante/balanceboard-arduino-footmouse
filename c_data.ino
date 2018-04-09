//functions for data retrieval

//gets gyro data for x- and y-axes
//includes conversion to degrees per second
void getGyroData(){ 
  gyroX = mpu.getRotationX() / 131.0;
  gyroY = mpu.getRotationY() / 131.0;
}

//gets infrared sensor data
void getIrData(){
  rightState = digitalRead(irRight);
  leftState = digitalRead(irLeft);
}
