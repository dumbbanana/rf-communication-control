// ask_receiver.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

String sensor1;   //pwm value from joystick1
String sensor2;   //pwm value from joystick2
String str_out;

const int motor1pwm = 10;  // motor 1 pwm pin
const int motor2pwm = 11;  // motor 2 pwm pin

void setup()
{
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Non-blocking
  {
  int i;
  buf[buflen]='\0';
  // Message with a good checksum received, dump it.
  //driver.printBuffer("Got:", buf, buflen);
  // Serial.println((char*)buf);
  // Serial.println();

    str_out = String((char*)buf);

    for (int i = 0; i < str_out.length(); i++) {
      if (str_out.substring(i, i + 1) == ",") {
        sensor1 = str_out.substring(0, i);
        sensor2 = str_out.substring(i + 1);


    Serial.print("sensor1: ");
    Serial.println(sensor1);
    Serial.print("sensor2: " );
    Serial.println(sensor2);

    int senint1 = sensor1.toInt();   //convert string to integer variable
    int senint2 = sensor2.toInt();


    analogWrite(motor1pwm, senint1);
    analogWrite(motor2pwm, senint2);
      }
    }
  }
}