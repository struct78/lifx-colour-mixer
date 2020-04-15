# LIFX Colour Mixer

This project is a physical colour mixer I created for my kids LIFX bulb.

## credentials.h

This file is where information about your local network and LIFX bulb is stored. Simply rename `credentials.h.example` to `credentials.h` and update the values.

```
#define WIFI_SSID "WIFI_NAME" <-- Your WIFI SSD
#define WIFI_PASS "WIFI_PASSWORD" <-- Your WIFI password
#define LIFX_MAC_ADDRESS "LIFX_MAC_ADDRESS" <-- Find this by logging on to your WIFI router
#define LIFX_IP_ADDRESS "LIFX_IP_ADDRESS" <-- Find this by logging on to your WIFI router
```

## Hardware

* [Alligator to Jumper Male 20cm 10 pin](https://www.littlebird.com.au/products/alligator-to-jumper-male-20cm-10-pin)
* [Premium Male/Male Jumper Wires - 20 x 6 (150mm)](https://www.littlebird.com.au/products/premium-male-male-jumper-wires-20-x-6-150mm)
* [Toggle Switch and Cover - Illuminated (Red)](https://www.littlebird.com.au/products/toggle-switch-and-cover-illuminated-red)
* [Gravity: Analog Slide Position (Potentiometer) Sensor For Arduino](https://www.littlebird.com.au/products/gravity-analog-slide-position-potentiometer-sensor-for-arduino)
* [Breadboard - Translucent Self-Adhesive (Clear)](https://www.littlebird.com.au/products/breadboard-translucent-self-adhesive-clear)
* [Arduino Uno WiFi R2](https://www.littlebird.com.au/products/arduino-uno-wifi-r2)
* Optional [DFRobot Mounting Kit](https://www.littlebird.com.au/products/mounting-kit-standoffs)

## Dependencies
* [ArduinoLifx](https://github.com/tigoe/ArduinoLifx/)
* [WiFiNINA](https://github.com/arduino-libraries/WiFiNINA)
* [WifiUDP](https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266WiFi/src/WiFiUdp.h)

### TODO:
- Fritzing diagram
- Retrieve Mac and IP address automatically