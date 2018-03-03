//author: frontsidekante
//

//libraries for MPU6050 (gyro/accel)
//https://www.i2cdevlib.com/docs/html/class_m_p_u6050.html
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"
#include "Wire.h"

//signal pins for TCRT5000
const int irRight = 7; 
const int irLeft = 8;

//control led pins for TCRT5000
const int ledRight = 2;
const int ledLeft = 12;

//variables for TCRT5000
int rightValue;
int leftValue;
int lastIrRightState = HIGH;
int lastIrLeftState = HIGH;

MPU6050 mpu;

//variables for mpu
int16_t RawAccX, RawAccY, RawAccZ, RawGyroX, RawGyroY, RawGyroZ;
float usableGyroX, usableGyroY, usableGyroZ;
float usableAccX, usableAccY, usableAccZ;
int16_t offset;

void setup() {

  //sets datarate in bits per second
  Serial.begin(9600);

  //setting up mpu
  //mpu.initialize();
  //setOffsets(mpu);
  
  pinMode(ledRight,OUTPUT);
  pinMode(ledLeft,OUTPUT);
  
  pinMode(irLeft, INPUT);
  pinMode(irRight,INPUT);

  //irRight works with internal pullup
  digitalWrite(irRight,HIGH); 

  
  //Wire.begin(); -> right LED stays off otherwise...!???
  
  Mouse.begin();
}

void loop() {
  
  //get gyroscope data
  //getUsableGyroData();
  
  //move cursor
  //Mouse.move(-usableGyroX, usableGyroY);
  //delay(16);
  rightValue = digitalRead(irRight);
  leftValue = digitalRead(irLeft);

  ////BLOCK FOR LEFT FOOT
  //feet are down, nothing happens
  if(leftValue == LOW && lastIrLeftState == LOW){
  }
  //feet were down, are up now 
  else if(leftValue == HIGH && lastIrLeftState == LOW){
    Serial.println("IF 2 ");
    Mouse.press();   
  }
  //feet were up, are down now 
  else if(leftValue == LOW && lastIrLeftState == HIGH){
    Serial.println("IF 3");
    Mouse.release();
  } 
  //feet were up, are still up 
  else if(leftValue == HIGH && lastIrLeftState == HIGH){
    Serial.println("IF 4");   
  }
  lastIrLeftState = leftValue; 

  ////BLOCK FOR RIGHT FOOT
  //feet are down, nothing happens
  if(rightValue == LOW && lastIrRightState == LOW){
  }
  //feet were down, are up now 
  else if(rightValue == HIGH && lastIrRightState== LOW){
    Serial.println("IF 2 ");
    Mouse.press(MOUSE_RIGHT);   
  }
  //feet were up, are down now 
  else if(rightValue == LOW && lastIrRightState == HIGH){
    Serial.println("IF 3");
    Mouse.release(MOUSE_RIGHT);
  } 
  //feet were up, are still up 
  else if(rightValue == HIGH && lastIrRightState == HIGH){
    Serial.println("IF 4");   
  }
  lastIrRightState = rightValue; 

  //BLOCK FOR CONTROL LEDS
  if(rightValue == LOW){
    digitalWrite(ledRight,LOW);
  }else if(rightValue == HIGH){
    digitalWrite(ledRight,HIGH);  
  }

  if(leftValue == LOW){
    digitalWrite(ledLeft,LOW);
  }else if(leftValue == HIGH){
    digitalWrite(ledLeft,HIGH);  
  }
}

