/**
 *  iotinator Fan Agent module
 *  Xavier Grosjean 2018
 *  Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International Public License
 */
 
#include "FanModule.h"
 
FanModule::FanModule(FanConfigClass* config, int displayAddr, int displaySda, int displayScl,
                      int speed1Pin, int speed2Pin, int speed3Pin, int oscPin, bool flipScreen,
                       uint8_t brightness):XIOTModule(config, displayAddr, displaySda, displayScl, flipScreen, brightness) {
  _speed1Pin = speed1Pin;
  _speed2Pin = speed2Pin;
  _speed3Pin = speed3Pin;
  _oscPin = oscPin;
  pinMode(speed1Pin, OUTPUT);
  pinMode(speed2Pin, OUTPUT);
  pinMode(speed3Pin, OUTPUT);
  pinMode(oscPin, OUTPUT);
  _oledDisplay->setLineAlignment(2, TEXT_ALIGN_CENTER);
  setOsc(false);
  setSpeed(0);
}

char* FanModule::_customData() {
//  Serial.println("FanModule::_customData");
  char* data = (char *)malloc(100);
  sprintf(data, "{\"speed\":%d, \"osc\":\"%s\"}", _speed, _osc ? "on": "off");
  return data;  
}

char* FanModule::_globalStatus() {
  char message[10];
  sprintf(message, "%d/%s", _speed, _osc ? "on": "off");
  return strdup(message);  
}


// Process SMS message, syntax can be
// 3
// on
// 2/on
bool FanModule::customProcessSMS(const char* phoneNumber, const bool isAdmin, const char* message) {
  if(strcmp(message, "on") == 0) {
    setOsc(true);
  }
  if(strcmp(message, "off") == 0) {
    setOsc(false);
  }
  // If first char is between 0 and 3
  if(*message >= 48 && *message <= 51) {
    setSpeed((int) (*message - 48));
  }
  char* slash = strchr(message, '/');
  if(slash != NULL) {
    customProcessSMS(phoneNumber, isAdmin, slash+1);
  }
  return true;
}

char* FanModule::useData(char* data, int* httpCode) {
Serial.println("fan");
Serial.println(data);
  const int bufferSize = 3*JSON_OBJECT_SIZE(1);
  StaticJsonBuffer<bufferSize> jsonBuffer;   
  JsonObject& root = jsonBuffer.parseObject(data); 
  if (!root.success()) {
    _oledDisplay->setLine(1, "Got bad data", TRANSIENT, NOT_BLINKING);
  } else {
    const char *osc = (const char*)root["osc"];
    if(strcmp(osc, "on") == 0) {
      setOsc(true);
    } else {
      setOsc(false);
    }
    int speed = (int)root["speed"];
    setSpeed(speed);
  }
  *httpCode = 200;
  return NULL;  // default response will be the same payload as the registering one => insures updating agent in master agentCollection
}

void FanModule::setOsc(bool osc) {
  _osc = osc;
  digitalWrite(_oscPin, _osc ? HIGH : LOW);
  refreshDisplay();
}

void FanModule::setSpeed(int speed) {
  _speed = speed;
  digitalWrite(_speed1Pin, LOW);
  digitalWrite(_speed2Pin, LOW);
  digitalWrite(_speed3Pin, LOW);
  switch(speed) {
    case 1:
      digitalWrite(_speed1Pin, HIGH);
      break;
    case 2:
      digitalWrite(_speed2Pin, HIGH);
      break;
    case 3:
      digitalWrite(_speed3Pin, HIGH);
      break;
      
  }
  refreshDisplay();
}

void FanModule::refreshDisplay() {
  char message[100];
  sprintf(message, "Speed %d, Osc %s", _speed, _osc ? "ON": "OFF");
  _oledDisplay->setLine(2, message, NOT_TRANSIENT, NOT_BLINKING);
}