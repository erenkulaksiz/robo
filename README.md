# Robo

A simple robot with IR distance sensors.

I've used Arduino as an PWM slave and Serial to communicate between RPI and Arduino. Since RPI is limited with PWM controls.
JSON is used as communcation protocol.

## Requirements

- 1x Raspberry Pi 3B
- 1x Arduino Mega 2560
- 3x Sharp GP2Y0A21YK Distance Sensor
- 1x L298N Motor Driver
- 2x DC Motor with Reductor

## Installation

### Rpi installation

- cd js
- npm install
- npm run start

Change connection port on app.js

### Arduino Installation

- Load sketch to the Arduino /arduino folder
- Connect Arduino to Rpi via USB Cable
