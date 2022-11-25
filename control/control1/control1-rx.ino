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

int senint1;
int senint2;

int sencal1;
int sencal2;

const int IN1 = 2;  //motor 1 dir1
const int IN2 = 3;  //motor 1 dir2
const int IN3 = 4;  //motor 2 dir1
const int IN4 = 7;  //motor 2 dir2
const int ENA = 5;  //motor 1 pwm pin
const int ENB = 6;  //motor 2 pwm pin

void setup()
{
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);


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

    //Serial.println(str_out);

    for (int i = 0; i < str_out.length(); i++) {
      if (str_out.substring(i, i + 1) == ",") {
        sensor1 = str_out.substring(0, i);
        sensor2 = str_out.substring(i + 1);
        break;
      }
    }

    // // print string values

    // Serial.print("sensor1: ");
    // Serial.println(sensor1);
    // Serial.print("sensor2: " );
    // Serial.println(sensor2);

    int senint1 = sensor1.toInt();   //convert string to integer variable
    int senint2 = sensor2.toInt();

    // print pwm values
    Serial.print("sensor1pwm: ");
    Serial.println(senint1);
    Serial.print("sensor2pwm: " );
    Serial.println(senint2);


    if (senint1<512){
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      sencal1=-255./512.*senint1+255.;
      analogWrite(ENA, sencal1);
    }
    if(senint1>=512){
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
      sencal1=(255./512.)*senint1-255.;
      analogWrite(ENA, sencal1);
    }

    if (senint2<512){
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      sencal2=-255./512.*senint2+255.;
      analogWrite(ENB, sencal1);
    }

    
    if(senint2>=512){
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
      sencal2=(255./512.)*senint2-255.;
      analogWrite(ENB, sencal2);
    }

    Serial.println(sencal1);
    Serial.println(sencal2);

  }
}