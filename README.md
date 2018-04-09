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
* Pin Strip (8 Pins needed)

## 2. Tools
* Soldering Iron
* Glue gun

## 3. Build yourself some nice TCRT5000 Breakout Boards
The ones you can buy don't really work well for this and building it yourself is way more fun anyway. You're going to need 2 of these.

![alt text](https://github.com/frontsidekante/balanceboard-arduino-footmouse/blob/master/pictures/BreakoutV2.png "TCRT5000 Diagram")

The grey lines are solder connections below the proto board. The blue, red and black lines are cables. Place the header pins at the blue, red, black and yellow circles. You need to bend the pins of the TCRT5000 a bit so it'll sit on the board 90 degrees rotated.


## 4. Set up the hardware
Place the Leonardo and sensors on the balance board like this:
![alt text](https://github.com/frontsidekante/balanceboard-arduino-footmouse/blob/master/pictures/Hardware_Setup.png "Connection Diagram")




### Connections

**MPU6050 - Arduino**

VCC - 5V

GND - GND

SDA - 2

SCL - 3

**TCRT5000 #1 - Arduino**

5V - 5V

GND - GND

Sensor Pin -  7

LED Pin - 4

**TCRT5000 #2 - Arduino**

5V - 5V

GND - GND

Sensor Pin - 8

LED Pin -12

## 5. Set up the software
This was developed and testet for Ubuntu 16.04. 

1. [Download and install the Arduino Software](https://www.arduino.cc/en/Main/Software)

2. [Download or clone this repo](https://github.com/frontsidekante/balanceboard-arduino-footmouse)

3. Extract the .zip to your sketchbook folder (usually named "Arduino")

4. Create a libraries folder in the Sketchbook folder and extract the 2 external libraries MPU6050 and I2Cdev to that folder

5. Upload Balanceboard.ino to your Leonardo

## 6. Enjoy hands free cursor action
Tilt the board to move the cursor

Lift your left toes and set them right back down to click

Lift your left toes, wait half a second before setting them down to double click

Lift your right toes and set them right back down to open context menu

Lift your right toes, wait half a second before setting them down to activate/deactivate select and drag'n'drop mode
