#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
//#define BLYNK_DEBUG
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TimeLib.h> // Used by WidgetRTC.h
#include <WidgetRTC.h>

#define ONE_WIRE_BUS 3 // 10K pull-up already on this pin on WeMos D1 Mini
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

DeviceAddress ds18b20RA = { 0x28, 0xEF, 0x97, 0x1E, 0x00, 0x00, 0x80, 0x54 }; // ADDRESS NOT YET DEFINED (correct)!

char auth[] = "fromBlynkApp";

SimpleTimer timer;

#define TRIGGER 5 // WeMos pin D1
#define ECHO    4 // WeMos pin D2

//WidgetLED led1(V2); // Heartbeat
WidgetRTC rtc;
BLYNK_ATTACH_WIDGET(rtc, V8);

int mkDist, tkDist;

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, "ssid", "pw");

  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  sensors.begin();
  sensors.setResolution(ds18b20RA, 10);

  while (Blynk.connect() == false) {
    // Wait until connected
  }

  rtc.begin();
  timer.setInterval(4000L, readStallStatus); // Send stall occ/non-occ status
  //timer.setInterval(5000L, heartbeatOn); // Blinks Blynk LED to reflect online status

}

void readStallStatus()
{
  long duration, distance;
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);

  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print(distance);
  Serial.println(" CM");
  delay(1000);

  mkDist = distance;
  timer.setTimeout(1000L, sendStallStatus);
}

void sendStallStatus()
{
  Blynk.virtualWrite(25, mkDist);
}

void loop()
{
  Blynk.run();
  timer.run();
}
