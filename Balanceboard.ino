//main file

//include libraries
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"
#include "Wire.h"

//set cursor sensitivity
const float heightSensitivity = 8;
const float widthSensitivity = 4;

//set duration of long click
const unsigned long longClick = 350;

//TCRT5000 signal pins 
const int irRight = 7;
const int irLeft = 8;

//TCRT5000 control led pins
const int ledRight = 4;
const int ledLeft = 12;

//TCRT5000 state variables
int rightState;
int leftState;
int lastRightState = HIGH;
int lastLeftState = HIGH;

//flag for drag and drop / select
bool selectOn = false;

//used to calculate duration of lifting toes
unsigned long startTime;

//MPU constructor
MPU6050 mpu;

//holds gyroscope values for 
float gyroX, gyroY;

//initialize libraries, get sensors ready
void setup() {

  //sets datarate in bits per second
  Serial.begin(9600);

  //sets up MPU
  mpu.initialize();
  setOffsets();

  setPinmodes();

  activatePullups();

  Wire.begin();
  Mouse.begin();
}

//get sensor data, controll cursor movements and mouse functionality
void loop() {

  getGyroData();

  getIrData();

  //Implements cursor movement
  handleBothFeet();

  //Implements leftclick and double click
  handleLeftFoot();
  
  //Implements open context menu and Select
  handleRightFoot();

  //handles controlLED
  controlLED();

  

}

