/**
 *  iotinator Fan module 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once 
#include "config.h"
#include <XIOTModule.h>
 
class FanModule:public XIOTModule {
public:
  FanModule(FanConfigClass* config, int displayAddr, int displaySda, int displayScl, 
            int speed1Pin, int speed2Pin, int speed3Pin, int oscPin, bool flipScreen, uint8_t brightness);
  
protected:
  int _speed = 0;
  bool _osc = false;
    
  char* _customData() override;
  char* useData(char *, int *) override;
  void setOsc(bool);
  void setSpeed(int);
  void refreshDisplay();
  
  int _speed1Pin;
  int _speed2Pin;
  int _speed3Pin;
  int _oscPin;
};