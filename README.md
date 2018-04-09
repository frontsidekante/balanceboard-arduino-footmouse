# Build your own footmouse

## 1. Parts
* 1 Balanceboard
* 1 Arduino Leonardo
* 1 MPU6050 Breakout Board
* 2 TCRT5000 IR Sensors
* 2 LEDs
* 2 small proto boards
* 6 resistors (2x 220Ω, 2x 100Ω, 2x 47Ω)
* 14 jumper wires
* Breadboard or additional proto board for power distribution

## 2. Tools
* Soldering Iron
* Hot melt gun

## 3. Set up the hardware



### Connections

####MPU6050 - Arduino

VCC - 5V

GND - GND

SDA - 2

SCL - 3

**TCRT5000 #1 - Arduino

5V - 5V

GND - GND

Sensor Pin -  7

LED Pin - 4

**TCRT5000 #2 - Arduino

5V - 5V

GND - GND

Sensor Pin - 8

LED Pin -12

## 4. Set up the software
This was developed and testet for Ubuntu 16.04. 

1. [Download and install the Arduino Software](https://www.arduino.cc/en/Main/Software)

2. [Download the balanceboard-arduino-footmouse.zip](https://github.com/frontsidekante/balanceboard-arduino-footmouse)

3. Extract the .zip to your sketchbook folder (usually named "Arduino")

4. Create a libraries folder in the Sketchbook folder and extract the 2 external libraries MPU6050 and I2Cdev to that folder

5. Upload Balanceboard.ino to your Leonardo

## 5. Enjoy hands free cursor action
Tilt the board to move the cursor

Lift your left toes and set them right back down to click

Lift your left toes, wait half a second before setting them down to double click

Lift your right toes and set them right back down to open context menu

Lift your right toes, wait half a second before setting them down to activate/deactivate select and drag'n'drop mode