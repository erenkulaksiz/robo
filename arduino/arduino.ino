#include <ArduinoJson.h>
#include <SharpIR.h>

int LeftCM, MiddleCM, RightCM;

StaticJsonDocument<1024> json;

#define LeftIRPin A2
#define MiddleIRPin A1
#define RightIRPin A0
#define model 1080
SharpIR LeftIRSensor = SharpIR(LeftIRPin, model);
SharpIR MiddleIRSensor = SharpIR(MiddleIRPin, model);
SharpIR RightIRSensor = SharpIR(RightIRPin, model);

void setup() {
  Serial.begin(9600);
}

void loop() {
  LeftCM = LeftIRSensor.distance();
  MiddleCM = MiddleIRSensor.distance();
  RightCM = RightIRSensor.distance();
  json["leftIR"] = LeftCM;
  json["middleIR"] = MiddleCM;
  json["rightIR"] = RightCM;

  serializeJson(json, Serial);
  Serial.println();
}
