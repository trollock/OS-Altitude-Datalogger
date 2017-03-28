/*
Bosch BME 280 Open Source Sensor Tag 
Version 1.0.0 BMP_180
Version 2.0.0 Updated to smaller BME_280 sensor
Version 2.0.1 Added RTClib to include program time stamp 
*/
#include <BME280_MOD-1022.h>
#include <Wire.h>
#include "RTClib.h"

int BME280_power = 11;                           // select the pin for the BME 280 sensor
RTC_Millis rtc;

void setup()                                     // This loop only runs once at startup
{
  Wire.begin();                                  //This initializes the Wire I2C library
  Serial.begin(115200);                          //This initializes and sets the baud rate for the Serial communication
  pinMode(BME280_power, OUTPUT);  
//  rtc.begin(DateTime(F(__DATE__), F(__TIME__))); //This grabs local time from the PC you are programming from
     for(int i=1; i<10; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
       for(int i=12; i<49; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
  }
}


void loop()                                      //This is the main loop that is repeated indefinitely
{ 
  wakeUp();    
  BME280Settings();                              //This function is below and sets the BME 280 sensor settings
  BME280.readCompensationParams();               //Read out the BME 280 parameters - must do this before calling the getxxxxx 
  BME280.readMeasurements();                    //Read the pressure, temperature, and humidity measurements.  Defined in BME_280.h and BME_280.cpp
  //serialTestMode();                             //Provides serial output during test mode
  //deployMode();
  gotoSleep();
}

/* 
All functions below here are to streamline code, and control parameters for the sensor or read/write functions
 */
 
void BME280Settings() {                         //This function sets the basic oversampling registers for the BME 280 Sensor
  BME280.writeMode(smForced);                   //Write mode, choose from (forced, normal, sleep)
  BME280.writeOversamplingPressure(os4x);       //Pressure oversampling, Choose from os1x, os2x, os4x, os8x, and os16x, osXXx is # of samples
  BME280.writeOversamplingTemperature(os4x);    //Temperature oversampling, see settings above ^^
  BME280.writeOversamplingHumidity(os16x);       //Humidity oversampling, see settings above ^^
}

void wakeUp() {
  digitalWrite(BME280_power, HIGH);             //Power up the peripherals from sleep mode.
}

void gotoSleep(){
  //digitalWrite(BME280_power, LOW);             //Power up the peripherals from sleep mode.
  sleepSeconds(3);
}

void serialTestMode() {                         //
  Serial.print("Temp=");
  Serial.print(BME280.getTemperature());  // must get temp first
  Serial.print(", Pressure=");
  Serial.print(BME280.getPressure());
  Serial.print(", Humidity=");
  Serial.print(BME280.getHumidity());
  Serial.print(" , ");
  
  //DateTime now = rtc.now();
  //Serial.print(now.year(), DEC);
  //Serial.print('/');
  //Serial.print(now.month(), DEC);
  //Serial.print('/');
  //Serial.print(now.day(), DEC);
  //Serial.print(' ');
  //Serial.print(now.hour(), DEC);
  //Serial.print(':');
  //Serial.print(now.minute(), DEC);
  //Serial.print(':');
  //Serial.print(now.second(), DEC);
  //Serial.println();
}

void deployMode() {
  
}


