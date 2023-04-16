#include <SoftwareSerial.h>
#include "Arduino_SensorKit.h"
#include <U8x8lib.h>
U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

SoftwareSerial ArduinoSlave(2,3);

#define button 4     // connect button to D4
 
int button_state = 0;         // variable for reading the pushbutton status
int potentiometer = A0; //Assign to pin A0

void setup(){
  ArduinoSlave.begin(9600);
  Accelerometer.begin();
  pinMode(button, INPUT);   
  pinMode(potentiometer, INPUT); //Sets the pinmode to input        
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFlipMode(0); 
  u8x8.setFont(u8x8_font_chroma48medium8_r);
}


void loop(){
  
  //Read sensors
  button_state = digitalRead(button);
  float y = Accelerometer.readY();
  int sensor_value = analogRead(potentiometer); //Read the value from the potentiometer connected to the A0 pin
  int value = map(sensor_value, 0, 1023, 0, 100); //Map the value from 0, 1023 to 0, 100
  
  u8x8.setCursor(7, 33);
  
  if (sensor_value > 50){
    u8x8.print("BACK ");
    ArduinoSlave.print("B");
  }
  else {
    if (button_state == HIGH) {
    if (y < -0.1) {
      u8x8.print("<<<");
      ArduinoSlave.print("L");
      
    }
    else if (y > 0.1) {
      u8x8.print(">>>");
      ArduinoSlave.print("R");
    }
    else {
      u8x8.print("---");
      ArduinoSlave.print("F");
    }
  }
  
  else {
    u8x8.print("---");
    ArduinoSlave.print(" ");
  }
  }
  


    u8x8.refreshDisplay();
  delay(100);
}