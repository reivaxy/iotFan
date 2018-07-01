/**
 *  Definition of the config data structure for the iotFan module and the class to persist it to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#pragma once

#include <XIOTConfig.h>
#include <XUtils.h>

#define CONFIG_VERSION 1
#define MODULE_NAME "Fan"

struct FanConfigStruct:ModuleConfigStruct {
  // Add config fields needed if any
};

class FanConfigClass:public ModuleConfigClass {
public:
  FanConfigClass(unsigned int version, const char* name);
  void initFromDefault();
  const char* getDefaultUIClassName() override;

protected:
  FanConfigStruct* _getDataPtr(void);  
};
