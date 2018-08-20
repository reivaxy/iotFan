/**
 *  iotinator Fan Agent module
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 

#include <stdio.h>
#include "FanModule.h"

#include "config.h"

#define API_VERSION "1.0"    // modules can check API version to make sure they are compatible...

// Global object to store config
FanConfigClass *config;
XIOTModule* module;

int scl = 12;
int sda = 14;

int speed1Pin = 4;
int speed2Pin = 5;
int speed3Pin = 15;
int oscPin = 16;


void setup(){
  Serial.begin(9600);
  delay(500); // time to connect serial
  
  config = new FanConfigClass((unsigned int)CONFIG_VERSION, (char*)MODULE_NAME);
  config->init();
 
  module = new FanModule(config, 0x3C, sda, scl, speed1Pin, speed2Pin, speed3Pin, oscPin, config->getFlipScreen(), config->getBrightness());
     
}

/*********************************
 * Main Loop
 *********************************/
void loop() {
  // Mandatory periodic call, to refresh display, Clock, check requests
  // on the http API, ...
  module->loop();
  delay(20);  
}

