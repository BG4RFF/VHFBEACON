/********************************************************************************************
 * VHF multimodes beacon Arduino exemple
 * Created 28/02/2015
 * Anthony LE CREN f4goh@orange.fr 
 * Use this code freely
 * testDDS at 144800000/8=18100000
 *******************************************************************************************/

#include <AD9850SPI.h>
#include <VHFBEACON.h>
#include <SPI.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <avr/pgmspace.h>

#define QRG 144800000/8


int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}



void setup() {
   Serial.begin(57600);
   Serial.print(F("Free RAM : "));
   Serial.println(freeRam());
   Beacon.begin(4, 5, 6, 7);   //in order pin sync, led (fix gps), mod et cde
   Beacon.ddsPower(1);   // power down
   DDS.begin(13, 9, 8);   // in order pin W_CLK, FQ_UD et RESET
   DDS.calibrate(125001100);
   Beacon.modulation(1);   //level 1 to enable ics511
   DDS.setfreq(QRG, 0);   // QRG fréquency
 }

void loop() {
}












