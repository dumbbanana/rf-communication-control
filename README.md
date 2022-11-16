# rf-communication
This repo contains code for radio controlled boat used to compete in rowbotics in techfest-IITbombay-2022

## Components

We used 433mhz rf module and 2 Arduino Uno boards for communication and joysticks at transmitter which send analog values from joysticks to the receiver. A mottor driver for N20 metal gear motors to control the speed and direction of the boat.

![Alt text](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2015/05/433-Copy.jpg?w=450&quality=100&strip=all&ssl=1)

we used RadioHead library by airspayce for simple Amplitude-shift keying (ASK) signal modulation.

## Circuit Diagram

The below diagrams depict the circuit for uno to uno connect but we used nodemcu to uno in our testing, therfore in the transmitter we connect data pin to GPIO 4 - D2.

### Transmitter Circuit

![Alt text](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/07/433-mhz-arduino-transmitter_bb.png?resize=768%2C833&quality=100&strip=all&ssl=1)

### Receiver Circuit

![Alt text](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/02/433-mhz-arduino_bb.png?resize=768%2C708&quality=100&strip=all&ssl=1)


## References

https://dronebotworkshop.com/433mhz-rf-modules-arduino/
https://github.com/sparkfun/SparkFun_RadioHead_Arduino_Library
https://components101.com/modules/433-mhz-rf-receiver-module
https://github.com/DiiZei/rethmeter_sensors
https://randomnerdtutorials.com/rf-433mhz-transmitter-receiver-module-with-arduino/
