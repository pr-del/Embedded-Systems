#define THINGER_SERIAL_DEBUG

#include <ThingerESP8266.h>
#include "arduino_secrets.h"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
String readString;
String data;
String v;
String i;
String w;
int a;
int b;
int c;
int ind1; // , locations   10 , 20  , 30 *
int ind2;
int ind3;
void setup() {
  // open serial for monitoring
  Serial.begin(9600);

  // set builtin led as output
  pinMode(LED_BUILTIN, OUTPUT);

  // add WiFi credentials
  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  //thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
 // thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
       thing["temp"] >> [](pson& out){
       out["x"] = a;
       out["y"] = b;
  };
}
//void printdata(int x , int y , String sp){
//  thing["temp"] >> [](pson& out){
//  out["x"] = x;
//  out["y"] = y;
//  };
//}
void loop() {
  thing.handle();
   if (Serial.available() >0) {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == '*') {
      
     ind1 = readString.indexOf(',');
      v = readString.substring(0, ind1);
      ind2 = readString.indexOf(',', ind1+1);   //finds location of second ,
      i = readString.substring(ind1+1, ind2);
      ind3 = readString.indexOf(',',ind2+1);
      w = readString.substring(ind2+1,ind3);
      a = v.toInt();
      b = i.toInt();
//       thing["temp"] >> [](pson& out){
//       out["x"] = a;
//       out["y"] = b;
//  };
     // printdata(a , b , w);
      readString="";
    }else { 
      
      readString += c; } //makes the string readString
      }
     
}
