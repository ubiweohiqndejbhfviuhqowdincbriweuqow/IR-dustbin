#include <Servo.h>

#define IR_PIN 2        // Pin connected to the IR sensor
#define SG90_PIN 3      // Pin connected to the SG90 servo

Servo servo;
bool objectDetected = false;

void setup() {
  pinMode(IR_PIN, INPUT);
  servo.attach(SG90_PIN);
}

void loop() {
  // Read the state of the IR sensor
  int irState = digitalRead(IR_PIN);

  if (irState == HIGH && !objectDetected) {  // checks if something detected by the IR sensor
    objectDetected = true;
    servo.write(90);  // open the lid(dhakna) by roatating 90 degree
    delay(3000);      // Wait for 3 seconds
    servo.write(0);   //close the lid by returning servo motor 0(initial state)
  } 
  
  if (objectDetected && irState == LOW) {    //object shamne still thakle ir state low thakbe
    objectDetected = false;
  }
}
