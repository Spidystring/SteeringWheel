In this section, I will display the project on how the "steering wheel" interacts and control a bluetooth car.

There are two parts in this project, one is the part on the "steering wheel" and the other is the receiver that receives the accelerometer data through bluetooth and convert it into data that the bluetooth car can read.

That part is the remoteController.ino and bluetoothCarCode.ino file respectively. The library I use are:
- The <AFMotor.h> library where it allows the motorsheild to run. Link: https://github.com/adafruit/Adafruit-Motor-Shield-library
- The <SoftwareSerial.h> library where it allows the bluetooth module to connect to any* pins. Link: https://docs.arduino.cc/learn/built-in-libraries/software-serial

I will try to explain the code in detail through the comments but if you are interested or unsure in any part of the code, do email me.