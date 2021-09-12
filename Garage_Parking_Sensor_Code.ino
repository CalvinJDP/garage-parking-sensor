// ----------------------------------------------------------------------------------------------------------------- //
// Purpose: This code is developed to help a person park their car in their garage in the same place every time.
//          There is no need for that silly tennis ball hanging from the ceiling. It is time to move into the
//          modern era.
// Author: Calvin Pereira
// Arduino IDE Version: 1.8.13
// Github link: https://github.com/CalvinJDP/garage-parking-sensor
// ----------------------------------------------------------------------------------------------------------------- //

 const int trig = 2; //Define Trig Pin
 const int echo = 3; //Define Echo Pin
 const int ledG = 4; //Define Green LED Pin
 const int ledY = 5; //Define Yellow LED Pin
 const int ledR = 6; //Define Red LED Pin
 const int buttonA = 7; //Define Button A Pin
 const int buttonB = 8; //Define Button A Pin
 int sweet; //Define sweet we will use this variable to change the distance from the car and sensor
 long distance; //Define distance this variable will be set to the distance recived from the echo pin

 
void setup() {
  pinMode(trig, OUTPUT); //Sets Trig Pin to output
  pinMode(echo, INPUT); //Sets Echo Pin to input
  pinMode(ledG, OUTPUT); //Sets ledG Pin to output
  pinMode(ledY, OUTPUT); //Sets ledY Pin to output
  pinMode(ledR, OUTPUT); //Sets ledR Pin to output
  pinMode(buttonA, INPUT); //Sets buttonA Pin to input
  pinMode(buttonB, INPUT); //Sets buttonB Pin to input
  
  //This will make sure all of the leds are set to OFF
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, LOW);
  digitalWrite(ledR, LOW); 
  delay(5);
  //We will blink the red LED 4 times to let the user know that the sensor is ready for use.
  digitalWrite(ledR, HIGH);   
  delay(1000);
  digitalWrite(ledR, LOW); 
  delay(1000);
  digitalWrite(ledR, HIGH);   
  delay(1000);
  digitalWrite(ledR, LOW); 
  delay(1000);
  digitalWrite(ledR, HIGH);   
  delay(1000);
  digitalWrite(ledR, LOW); 
  delay(1000);
  digitalWrite(ledR, HIGH);   
  delay(1000);
  digitalWrite(ledR, LOW); 
  delay(1000);
  sweet = 0; //Set this variable to 0

}

void loop() {

   
  int stateBa = digitalRead(buttonA); //This will read the input from Button A
  int stateBb = digitalRead(buttonB); //This will read the input from Button B

  //If Button B is read HIGH we will add 5 to sweet. This will increase the distance from the sensor and the car.
  if (stateBa == HIGH) {
    sweet = sweet + 5;
  }

  //If Button A is read HIGH we will subtract 5 from sweet. This will decrease the distance from the sensor and the car.
  if (stateBb == HIGH) {
    sweet = sweet - 5;
  }

  
  //This will reset the trig pin
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  //This will set the trig pin to HIGH
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  //Distance is going to be equal to the feedback from the echo pin
  distance = pulseIn(echo, HIGH);
  

  
  
  if (distance > 2500 + sweet) { //When distance is more than 2000 it will...
    digitalWrite(ledG, HIGH); //Turn on Green LED
    digitalWrite(ledY, LOW); //Turn off Yellow LED
    digitalWrite(ledR, LOW); //Turn off Red LED
  }
  else if ((sweet + 1000 < distance) && (distance < 2500 + sweet)) { //When distance is less than 2000, but more than 1000 it will...
    digitalWrite(ledG, LOW); //Turn off Green LED
    digitalWrite(ledY, HIGH); //Turn on Yellow LED
    digitalWrite(ledR, LOW); //Turn off Red LED
  }
  else if ((sweet + 850 < distance) && (distance < 1000 + sweet)) { //When distance is less than 1000, but more than 300 it will...
    digitalWrite(ledG, LOW); //Turn off Green LED
    digitalWrite(ledY, LOW); //Turn off Yellow LED
    digitalWrite(ledR, HIGH); //Turn on RED lED
  }

  else if (distance < 850 + sweet) { //When distance is less than 850 it will..
    digitalWrite(ledG, LOW); //Turn off Green LED
    digitalWrite(ledY, LOW); //Turn off Yellow LED
    //The red led will blink indicating that the car is too close to the sensor.
    digitalWrite(ledR, HIGH); //Turn on RED lED
    delay(100);
    digitalWrite(ledR, LOW); //Turn off RED lED
    delay(100);
    digitalWrite(ledR, HIGH); //Turn on RED lED
  }
}
