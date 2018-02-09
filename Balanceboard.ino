//author: frontsidekante
//

//libraries for MPU6050 (gyro/accel)
//https://www.i2cdevlib.com/docs/html/class_m_p_u6050.html
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"

//libraries for BH1750 (light sensor)
#include <Wire.h>
#include <BH1750.h>

//sensors
BH1750 LuxR(0x5c);
BH1750 LuxL(0x23);
MPU6050 mpu;

int16_t RawAccX, RawAccY, RawAccZ, RawGyroX, RawGyroY, RawGyroZ;
float usableGyroX, usableGyroY, usableGyroZ;
float usableAccX, usableAccY, usableAccZ;

int16_t offset;

void setup() {

  //sets datarate in bits per second
  Serial.begin(9600);

  //TODO: testen, ob notwendig
  Wire.begin();

  //setting up mpu
  mpu.initialize();
  setOffsets(mpu);

  //setting up light sensor
  //Low Resolution Mode - (4 lx precision, 16ms measurement time)
  LuxR.begin(BH1750::CONTINUOUS_LOW_RES_MODE);
  LuxL.begin(BH1750::CONTINUOUS_LOW_RES_MODE);
  Mouse.begin();
}

void loop() {

  //get gyroscope data
  getUsableGyroData();
  //get lightsensor data
  uint16_t rightLux = LuxR.readLightLevel();
  uint16_t leftLux = LuxL.readLightLevel();
  //move cursor
  //Mouse.move(usableGyroY, usableGyroX);
  //delay(16);

  //leftlux
  if(rightLux <= 3 && rightLux){
    Serial.print("click");
    Mouse.click();
  }
  
  Serial.print("RightLux: ");
  Serial.print(rightLux);
  Serial.print(" lx | ");

  Serial.print("LeftLux: ");
  Serial.print(leftLux);
  Serial.println(" lx");
  delay(500);
}

