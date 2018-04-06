//author: frontsidekante

//libraries for MPU6050 (gyro/accel)
//https://www.i2cdevlib.com/docs/html/class_m_p_u6050.html
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"
#include "Wire.h"

const float heightSensitivity = 8;
const float widthSensitivity = 4;
const unsigned long longClick = 350;

//signal pins for TCRT5000
const int irRight = 7;
const int irLeft = 8;

//control led pins for TCRT5000
const int ledRight = 4;
const int ledLeft = 12;

//variables for TCRT5000
int rightValue;
int leftValue;
int lastIrRightState = HIGH;
int lastIrLeftState = HIGH;

bool selectOn = false;
bool mouseOn = false;
unsigned long startTime;

MPU6050 mpu;

//variables for mpu
float gyroX, gyroY;

void setup() {

  //sets datarate in bits per second
  Serial.begin(9600);

  //Set up MPU
  mpu.initialize();
  setOffsets();

  setPinmodes();

  activatePullups();

  Wire.begin();
  Mouse.begin();
}

void loop() {

  //Get data from gyroscope
  //returns gyroX, gyroY
  getGyroData();
  //Serial.println(leftValue);
  
  //Get data from infraredsensors
  //returns rightValue, leftValue
  getIrData();

  //Implements cursor movement
  handleBothFeet();

  //Implements leftclick and double click
  handleLeftFoot();
  //Implements open context menu and Select
  handleRightFoot();

  controlLED();

  

}

