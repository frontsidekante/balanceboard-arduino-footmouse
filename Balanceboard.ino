//author: frontsidekante

//libraries for MPU6050 (gyro/accel)
//https://www.i2cdevlib.com/docs/html/class_m_p_u6050.html
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Mouse.h"
#include "Wire.h"

float height_sensitivity = 6;
float width_sensitivity = 3;

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
unsigned long initiatePowerOff = millis();
unsigned long startTime;

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
  mpu.initialize();
  setOffsets(mpu);
  
  pinMode(ledRight,OUTPUT);
  pinMode(ledLeft,OUTPUT);
  
  pinMode(irLeft, INPUT);
  pinMode(irRight,INPUT);

  //irRight works with internal pullup
  digitalWrite(irRight,HIGH); 
  
  Wire.begin();   
  Mouse.begin();
}

void loop() {
  
  //get gyroscope data
  getUsableGyroData();
  
  //move cursor

  unsigned long currentMillis = millis();
  
  rightValue = digitalRead(irRight);
  leftValue = digitalRead(irLeft);

  ////BLOCK FOR LEFT FOOT
  ////IMPLEMENTS: LEFT CLICK, LEFT DOUBLE CLICK
  if(rightValue == LOW && leftValue == LOW){
    Mouse.move(-usableGyroX/width_sensitivity, usableGyroY/height_sensitivity);
    //delay(16);
    Serial.println(usableGyroX);
  }
  
  //feet were down, are up now 
  if(leftValue == HIGH && lastIrLeftState == LOW){
    //Serial.println("IF 2 ");
    startTime = millis();
    //Mouse.press();   
  }
  //feet were up, are down now 
  else if(leftValue == LOW && lastIrLeftState == HIGH){
    Serial.println("IF 3");
    unsigned long endTime = millis();
    unsigned long duration = endTime - startTime;
    if(duration < 350){
      Mouse.click();
    }
    else{
      Mouse.click();
      Mouse.click();
    }
    //Mouse.release();
  } 
  //feet were up, are still up 
  else if(leftValue == HIGH && lastIrLeftState == HIGH){
    //Serial.println("IF 4");   
  }
  lastIrLeftState = leftValue; 

  ////BLOCK FOR RIGHT FOOT
  ////IMPLEMENTS: OPEN CONTEXT MENU, SCROLL
  
  //feet were down, are up now 
  if(rightValue == HIGH && lastIrRightState== LOW){
    //Serial.println("IF 2 ");
    startTime = millis();
    //Mouse.press(MOUSE_RIGHT);   
  }
  //feet were up, are down now 
  else if(rightValue == LOW && lastIrRightState == HIGH){
    //Serial.println("IF 3");
    unsigned long endTime = millis();
    unsigned long duration = endTime - startTime;
    if(duration < 350){
      //open context menu
      Mouse.click(MOUSE_RIGHT);
    }
    else{
      //activate select mode
      if(!selectOn){
        selectOn = true;
      }     
      else{
        selectOn = false;
      }
    }
    //Serial.print("endTime: ");
    //Serial.print(endTime);
    //Serial.print(" - startTime: ");
    //Serial.print(startTime);
    //Serial.print(" = duration: ");
    Serial.println(duration);
  }

  //feet were up, are still up 
  else if(rightValue == HIGH && lastIrRightState == HIGH){
    
    //Serial.println("IF 4");   
  }

  
  //select / drag and drop
  while(rightValue == LOW && lastIrRightState == LOW){
    if(selectOn){  
    Mouse.press();
    Mouse.move(-usableGyroX/1.5, usableGyroY/1.5);
    rightValue = digitalRead(irRight);
    getUsableGyroData();
    }
    else{
      Mouse.release();
      break;
    }
  }

  //endSession
  //while(rightValue == HIGH && leftValue == HIGH){
  //  rightValue = digitalRead(irRight);
  //  unsigned long count = millis();
    //Serial.println(initiatePowerOff);
    //Serial.println(count);
  //  if(initiatePowerOff - count > 5000){
      //Serial.println("Footmouse Power Off");
      //Mouse.end();
      //break;  
  //  }
  //}
  
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

