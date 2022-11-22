// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 2, 4, 5);

const int joystick1 = A0;  // Analog input pin that the joystick is attached to
const int joystick2 = A1;  // Analog input pin that the joystick is attached to

int sensor1 = 0;    //joystick one
int sensor2 = 0;    //joystick two       

int stick1 = 0;
int stick2 = 0;

void setup()

{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
  
  // read the analog in value:
  stick1 = analogRead(joystick1);
  stick2 = analogRead(joystick2);
  // map it to the range of the analog out:
  sensor1 = map(stick1, 0, 1023, 0, 255);
  sensor2 = map(stick2, 0, 1023, 0, 255);
  
String comp = sensor1 + "," + sensor2;   // rx-tx msg

    const  char *msg = comp.c_str();

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}