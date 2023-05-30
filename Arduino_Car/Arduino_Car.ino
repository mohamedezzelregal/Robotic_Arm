#include <Servo.h>
#include <NewPing.h>

const int trigPin = 2;
const int echoPin = 3;

const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;
const int enA = 5;
const int enB = 6;

const int MAX_SPEED = 255;
const int MIN_SPEED = 50;

long duration, cm;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  analogWrite(enA, 0);
  analogWrite(enB, 0);
}
void loop() {

  
// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  //while (Serial.available() < 1) {}
  //int motorSpeed = Serial.read();

  if (Serial.available() > 0) {

  if (distance <= 16.5) { 
    digitalWrite(in1, HIGH);
    
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
      delay(100000);
      delay(100000);
      delay(100000);
      delay(100000);
      delay(100000);
      delay(100000);
      delay(100000);
      delay(100000);

  } else { 
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, 200);
    analogWrite(enB, 200);
  }
  
  analogWrite(enA, 200);
  analogWrite(enB, 200);
}
}