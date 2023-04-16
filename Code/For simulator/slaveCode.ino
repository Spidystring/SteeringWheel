//Code to receive information and convert it 
//into joystick control to be read in windows

#include <SoftwareSerial.h>
#include <Joystick.h>

SoftwareSerial ArduinoMaster(8,9);

Joystick_ Joystick(0x01,JOYSTICK_TYPE_GAMEPAD,
  1, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but Z Axis
  false, true, true,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering
  
String msg="",m1="",m2="",m3="";
int steer, buttonstate, potentiometer;
int sep, sep1;

void setup(){
  ArduinoMaster.begin(9600);
  Joystick.begin();
  Joystick.setRzAxisRange(-100, 100);
  Joystick.setRyAxisRange(0, 100);
}

void loop(){
  readMasterPort();
  convertMsgToMultiCmd();

  Joystick.setRzAxis(steer);
  Joystick.setRyAxis(potentiometer);
  Joystick.setButton(0, buttonstate);  
}

void readMasterPort(){
 while (ArduinoMaster.available()) {
   delay(10); 
   if (ArduinoMaster.available() >0) {
     char c = ArduinoMaster.read();  //gets one byte from serial buffer
     
     msg += c; //makes the string readString
   }
 }
 ArduinoMaster.flush();
}


void convertMsgToMultiCmd(){
   if (msg.length() >0) {

     sep = msg.indexOf('x');
     sep1 = msg.indexOf('y');
     m1 = msg.substring(0, sep); 
     m2 = msg.substring(sep+1, sep1);
     m3 = msg.substring(sep1+1, msg.length()); 
    
     char carray1[6]; //magic needed to convert string to a number
     m1.toCharArray(carray1, sizeof(carray1));
     steer = atoi(carray1);

     char carray2[6]; //magic needed to convert string to a number
     m2.toCharArray(carray2, sizeof(carray2));
     buttonstate = atoi(carray2);

     char carray3[6]; //magic needed to convert string to a number
     m3.toCharArray(carray3, sizeof(carray3));
     potentiometer = atoi(carray3);
      
     msg="";
 }
}