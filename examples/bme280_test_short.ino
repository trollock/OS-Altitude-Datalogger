/*
Bosch BME 280 Open Source Sensor Tag 
Version 1.0.0 BMP_180
Version 2.0.0 Updated to smaller BMP_280 sensor *sensor is now obsolete*
Version 2.0.1 Added RTClib to include program time stamp 
Version 3.0.0 Upgraded to smaller BME_280 sensor that includes humidity measurements
*/

#include <BME280_MOD-1022.h>
#include <Wire.h>
#include "RTClib.h"

/* Variables related to datalogger operation schedule
--------------------------------------------------------------------------------------*/
int sampleInterval = 1;                           // time between samples in seconds


int BME280_power = 11;                           // select the pin for the BME 280 sensor
int SampleNumber = 0;
int AddressCount = 0;

// variables to keep the values
float temperature = 0;
float pressure = 0;
uint8_t humidity = 0;

__attribute__((section(".text"))) uint8_t TempStore[5000]; 
__attribute__((section(".text"))) float PresStore[5000]; 
__attribute__((section(".text"))) uint8_t HumidStore[5000]; 
__attribute__((section(".text"))) int SampleCount = 1;
__attribute__((section(".text"))) uint16_t Year = 0;
__attribute__((section(".text"))) uint8_t Month = 0;
__attribute__((section(".text"))) uint8_t Day = 0;
__attribute__((section(".text"))) uint8_t Hour = 0;
__attribute__((section(".text"))) uint8_t Minute = 0;
__attribute__((section(".text"))) uint8_t Second = 0;

RTC_Millis rtc;

void setup(){                                     // This loop only runs once at startup
  clockSetup();
  setPins();
  Wire.begin();                                  //This initializes the Wire I2C library
  Serial.begin(9600);                          //This initializes and sets the baud rate for the Serial communication
  downloadData();
  pinMode(BME280_power, OUTPUT);
  rtc.begin(DateTime(F(__DATE__), F(__TIME__))); //This grabs local time from the PC you are programming from i.e. may need adjustment depending on compilation delay
  DateTime now = rtc.now();
  rtc.adjust(DateTime(now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second() + 28));
  timeStamp();
}

void loop()                                      //This is the main loop that is repeated indefinitely
{ 
  wakeUp(); 
  BME280Settings();                              //This function is below and sets the BME 280 sensor settings
  BME280.readCompensationParams();               //Read out the BME 280 parameters - must do this before calling the getxxxxx 
  delay(100);
  BME280.readMeasurements();                    //Read the pressure, temperature, and humidity measurements.  Defined in BME_280.h and BME_280.cpp
  serialTestMode();                             //Provides serial output during test mode
  deployMode();
  gotoSleep();
}

/* -----------------------------------------------------------------------------------------------------------
All functions below here are to streamline code, and control parameters for the sensor or read/write functions
------------------------------------------------------------------------------------------------------------*/
void downloadData(){
  Serial.println("Press any key and hit send within 15 seconds if you want to download data");
  unsigned long starttime = millis();
  unsigned long endtime = starttime;
  while ((endtime - starttime) <=15000){ // this is the wait time for downloads in msec
    while (Serial.available()){
      startTime();
      for (int k=1; k < SampleCount; k++){
        AddressCount = k;
        uint8_t TempOutput = TempStore[AddressCount];
        float PresOutput = PresStore[AddressCount];
        uint8_t HumidOutput = HumidStore[AddressCount];
         Serial.print(k);
         Serial.print(",");
         Serial.print(TempOutput);
         Serial.print(",");
         Serial.print(PresOutput);
         Serial.print(",");
         Serial.println(HumidOutput);
      }
      sleepSeconds(300);
    }
    int loopcount = loopcount+1;
    endtime = millis();
  }
}

void clockSetup() {
   CSCTL0_H = 0xA5;                             // CS password
   CSCTL2 |= SELM__LFXTCLK;  
   CSCTL4 &= ~LFXTOFF;                          // Turn on LFXT
   do{  
     CSCTL5 &= ~(LFXTOFFG);                     // Clear XT1 fault flag
    SFRIFG1 &= ~OFIFG;
   }while (SFRIFG1 & OFIFG);                    // Test oscillator fault flag
}

void setPins() {
       for(int i=1; i<17; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
       }
       for(int i=21; i<28; i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);
       }
 }
 
void BME280Settings() {                         //This function sets the basic oversampling registers for the BME 280 Sensor
  BME280.writeMode(smNormal);                   //Write mode, choose from (forced, normal, sleep)
  BME280.writeOversamplingPressure(os4x);       //Pressure oversampling, Choose from os1x, os2x, os4x, os8x, and os16x, osXXx is # of samples
  BME280.writeOversamplingTemperature(os4x);    //Temperature oversampling, see options above ^^
  BME280.writeOversamplingHumidity(os4x);       //Humidity oversampling, see options above ^^
}

void wakeUp() {
  digitalWrite(BME280_power, HIGH);             //Power up the peripherals from sleep mode.
  delay(50);
}

void gotoSleep(){
  BME280.writeMode(smSleep);
  Wire.endTransmission();
  digitalWrite(BME280_power, LOW);
  digitalWrite(17, LOW);
  digitalWrite(18, LOW);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  PAOUT = 0; PBOUT = 0; PJOUT = 0;
  PADIR = 0xFFFF; PBDIR = 0xFFFF; PJDIR = 0xFF;
  PAIFG = 0; PBIFG = 0;
  sleepSeconds(sampleInterval);
}

void timeStamp(){
  DateTime now = rtc.now();
  Year = now.year();
  Month = now.month();
  Day = now.day();
  Hour = now.hour();
  Minute = now.minute();
  Second = now.second();
}

void startTime(){
  Serial.print(Year, DEC);
  Serial.print('/');
  Serial.print(Month, DEC);
  Serial.print('/');
  Serial.print(Day, DEC);
  Serial.print(' ');
  Serial.print(Hour, DEC);
  Serial.print(':');
  Serial.print(Minute, DEC);
  Serial.print(':');
  Serial.print(Second, DEC);
  Serial.print(',');
  Serial.print("Sample Interval =");
  Serial.print(sampleInterval, DEC);
  Serial.println(" seconds");
  Serial.print("Sample");
  Serial.print(',');
  Serial.print("Temp");
  Serial.print(',');
  Serial.print("Pressure");
  Serial.print(',');
  Serial.println("Humidity");
  delay(100);
}

void serialTestMode() {                         //
  Serial.print("Temp=");
  Serial.print(BME280.getTemperature());  // must get temp first
  Serial.print(", Pressure=");
  Serial.print(BME280.getPressure());
  Serial.print(", Humidity=");
  Serial.print(BME280.getHumidity());
  Serial.print(",");
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  delay(100);
}

void deployMode() {
    temperature = BME280.getTemperature();
    pressure = BME280.getPressure();
    humidity = BME280.getHumidity();
    if (SampleCount <= 5000){
    TempStore[SampleCount] = temperature;
    PresStore[SampleCount] = pressure;
    HumidStore[SampleCount] = humidity;
    SampleCount++;
    }
}


