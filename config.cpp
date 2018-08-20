/**
 *  Class to persist the iotFan module configuration data structure to EEPROM 
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "config.h"


FanConfigClass::FanConfigClass(unsigned int version, const char* name):ModuleConfigClass(version, "iotfan", name, sizeof(FanConfigStruct)) {
}

/**
 * Reset the config data structure to the default values.
 * This is done each time the data structure version is different from the one saved in EEPROM
 * NB: version and name are handled by base class 
 */
void FanConfigClass::initFromDefault() {
  ModuleConfigClass::initFromDefault(); // handles version and name init, ssid and pwd
  setBrightness(60);
}

const char* FanConfigClass::getDefaultUIClassName() {
  Serial.println("FanConfigClass::getDefaultUIClassName");
  return "fanUIClass";
}

/**
 * Return the typed data structure object
 *
 */
FanConfigStruct* FanConfigClass::_getDataPtr(void) {
  return (FanConfigStruct*)ModuleConfigClass::_getDataPtr();
}