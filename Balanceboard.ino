//author: frontsidekante
//

//https://www.i2cdevlib.com/docs/html/class_m_p_u6050.html
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"

MPU6050 mpu;

int16_t RawAccX, RawAccY, RawAccZ, RawGyroX, RawGyroY, RawGyroZ;
float usableGyroX, usableGyroY, usableGyroZ;
float usableAccX, usableAccY, usableAccZ;

int16_t offset;

void setup() {

  //sets datarate in bits per second
  Serial.begin(9600);

  //"while" necessary because Leonardo has only 1 chip for USB communication and processing of sketches
  while(!Serial){
    mpu.initialize();
    getConnectionStatus(mpu);
    getSleepModeStatus(mpu);
    setOffsets(mpu); 
  } 
  delay(500);
}

void loop() {

  getUsableGyroData();
  Mouse.begin();
  Mouse.move(usableGyroY, usableGyroX);
  delay(10);
}




