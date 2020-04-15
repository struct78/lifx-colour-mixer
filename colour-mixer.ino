#include <ArduinoLifx.h>
#include <WiFiNINA.h>
#include <WiFiUDP.h>
#include "credentials.h"
#define LIFX_TRANSITION_TIME 10
#define LIFX_TEMP 65535
#define SWITCH_PIN 8
#define SLIDER_TOLERANCE 5

int red, green, blue, power;
int prevRed, prevGreen, prevBlue, prevPower;
int status = WL_IDLE_STATUS;

typedef struct {
    double r;
    double g;
    double b;
} RGB;

typedef struct {
    double h;
    double s;
    double b;
} HSV;


WiFiSSLClient client;
WiFiUDP udp;
ArduinoLifx lifx(udp);

void setup() {
  Serial.begin(9600);
  pinMode(SWITCH_PIN, INPUT); 
  connectToWifi();
  connectToLifx();
}

void loop() {
  red = analogRead(0);
  green = analogRead(1);
  blue = analogRead(2);
  power = digitalRead(SWITCH_PIN);
  lifx.setPower(power, 0);

  if (power == LOW) {
    return;
  }

  RGB colour = (RGB){ (double)sliderToRGB(red)/256, (double)sliderToRGB(green)/256, (double)sliderToRGB(blue)/256 };
  HSV hsb = rgb2hsb(colour);
  if (power == HIGH) {
    if (abs(prevRed - red) > SLIDER_TOLERANCE || abs(prevGreen - green) > SLIDER_TOLERANCE || abs(prevBlue - blue) > SLIDER_TOLERANCE) {
      lifx.setColor(hsb.h, hsb.s, hsb.b, LIFX_TEMP, LIFX_TRANSITION_TIME);
    }
  }
  
  prevRed = red;
  prevGreen = green;
  prevBlue = blue;
}

HSV rgb2hsb(RGB in) {
  HSV out;
  double min, max, delta;

  min = in.r < in.g ? in.r : in.g;
  min = min  < in.b ? min  : in.b;

  max = in.r > in.g ? in.r : in.g;
  max = max  > in.b ? max  : in.b;

  out.b = max * 65535;
  delta = max - min;
  
  if (delta < 0.00001) {
      out.s = 0;
      out.h = 0;
      return out;
  }
  
  if ( max > 0.0 ) {
      out.s = (delta / max) * 65535;
  } else {
      out.s = 0.0;
      out.h = NAN;
      return out;
  }
  
  if( in.r >= max ) {
      out.h = ( in.g - in.b ) / delta;
  } else {
    if ( in.g >= max ) {
      out.h = 2.0 + ( in.b - in.r ) / delta;
    } else {
      out.h = 4.0 + ( in.r - in.g ) / delta;
    }
  }
  out.h *= 60.0;

  if ( out.h < 0.0 ) {
      out.h += 360.0;
  }

  return out;
}
