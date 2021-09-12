# garage-parking-sensor

## Description

This project is developed to help a person park their car in their garage in the same place every time. Normally people have a tennis ball hanging from the ceiling. However when ever you need to work on project or organize your garage the tennis ball can get in the way. With this circuit nothing is in the middle of the garage that you have to walk around. There is no need for that silly tennis ball hanging from the ceiling. It is time to move into the modern era.

## Purpose

In my garage it is quiet difficult to park a minivan perfectly. I would have to use the backup camera and use a reference on the floor in order to find a spot closest to the garage door. The van needs to be exceptionally close to the garage door as possible because there are cabinets in front of the car that are used frequently. If the car is too close to the cabinets it becomes difficult to open them. If the van is too far back I run the risk of damaging the car. So, I built a circuit that makes sure the van is parked perfectly, not too close to the cabinets and close enough to the garage door.

## Components
- 1x Arduino Nano or Arduino Uno
- 1x Green, Red, Yellow LED or RGB LED
- 3x 220 Ω Resistors
- 2x 1k Ω Resistors
- 1x Ultra Sonic Distance Sensor
- 2x Push Buttons

## Features

LEDS act like a stop light

Two buttons to change distance

## Arduino Pin #

 - Ultra Sonic Distance Sensor Trig Pin #2
 - Ultra Sonic Distance Sensor Echo Pin #3
 - Green LED Pin #4
 - Yellow LED Pin #5
 - Red LED Pin #6
 - Button A pin #7
 - Button B pin #8


## How to Setup

Step 1 - Park your car where you want it positioned.

Step 2 - Set up the sensor so it directed at the license plate or any flat surface on the vehicle. If the sensor is not directed at a flat surface you will not be able to this circuit. The sensor emits sound waves. When the sound waves hit curved surfaces they do not travel back to the sensor or the sound waves are delayed.

Step 3 - Use the buttons on the circuit to change the distance from the sensor to the car. (Make sure your car is where you want it positioned.) The red led indicates that the car is parked perfectly. NO OTHER LEDS SHOULD BE ON
