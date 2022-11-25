// ask_transmitter.pde
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

const int joystick1 = A0;  // Analog input pin that the joystick is attached to
const int joystick2 = A1;  // Analog input pin that the joystick is attached to

int sen1 = 0;    //joystick one
int sen2 = 0;    //joystick two       

int stick1 = 0;
int stick2 = 0;

String sensor1;
String sensor2;

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

  // //map it to the range of the analog out:

  // sen1 = map(stick1, 0, 1023, 0, 255);
  // sen2 = map(stick2, 0, 1023, 0, 255);


  sen1 = stick1;
  sen2 = stick2;


  sensor1 = String(sen1); 
  sensor2 = String(sen2); 
  

  // print pwm values
  Serial.print("sensor1pwm: ");
  Serial.println(sensor1);
  Serial.print("sensor2pwm: " );
  Serial.println(sensor2);



String comp = sensor1 + "," + sensor2;   // rx-tx msg

//Serial.print(comp);

    const  char *msg = comp.c_str();

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}