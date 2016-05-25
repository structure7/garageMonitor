# garageMonitor (in development)
Keeping an eye on the garage.
<p align="center"><img src="http://i.imgur.com/To0ewie.jpg"/></p>

## Hardware
* WeMos D1 Mini
* Probably two HC-SR04 distance sensors. Might look into alternates.
* One DS18B20 temperature sensors.
* Bi-directional level shifter. (<a href="http://www.ezsbc.com/index.php/products/ls1.html">Source</a>)

## Libraries and Resources
Title | Include | Link
------|---------|------
OneWire | OneWire.h | https://github.com/PaulStoffregen/OneWire
Arduino-Temperature-Control-Library | DallasTemperature.h | https://github.com/milesburton/Arduino-Temperature-Control-Library
Time | Timelib.h | https://github.com/PaulStoffregen/Time
SimpleTimer | SimpleTimer.h | https://github.com/jfturcot/SimpleTimer
ESP8266/Arduino | ESP8266WiFi.h | https://github.com/esp8266/Arduino
blynk-library | BlynkSimpleEsp8266.h | https://github.com/blynkkk/blynk-library
WidgetRTC | WidgetRTC.h | https://github.com/blynkkk/blynk-library
ESP8266 board mgr | N/A | [json](http://arduino.esp8266.com/stable/package_esp8266com_index.json) & [instructions](https://github.com/esp8266/Arduino#installing-with-boards-manager)
