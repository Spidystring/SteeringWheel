In this section, I will display the project on how the "steering wheel" interacts and control a car in a driving simulator that you can download developed by "68Whiskey" for free at: https://68whiskey.itch.io/lasise-driver

There are two parts in this project, one is the part on the "steering wheel" and the other is the receiver that receives the accelerometer data through bluetooth and convert it into data that a computer simulator can read.

That part is the transmitter.ino and receiver.ino file respectively. The library I use are:
- The <Joystick.h> library where it allows the arduino board to emulate as a gamepad. Link: https://github.com/MHeironimus/ArduinoJoystickLibrary
- The <SoftwareSerial.h> library where it allows the bluetooth module to connect to any* pins. Link: https://docs.arduino.cc/learn/built-in-libraries/software-serial

I will try to explain the code in detail through the comments but if you are interested or unsure in any part of the code, do email me.