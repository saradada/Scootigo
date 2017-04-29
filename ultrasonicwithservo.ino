int trigPin = 11; 
int echoPin = 12;
long duration, cm, inches;

#include <Servo.h>

Servo myservo; // create servo object to control sevo
int pos = 0;    // variable to store the servo position 
void setup() {
  //start serial
  //Serial.begin (115200);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);// attach servo to pin 9 to the servo object

}

void loop() {
  
  // ultrasonic is triggered by a HIGH pulse of 10 or more microseconds
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the signal from the ultrasonic sensor: a HIGH pulse whose
  // duration is the time in microseconds from the sending 
  // of the ping to the reception of its echo off an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  //Convert time into distance (ultrasonic)
  cm = (duration/2)/29.1;
  //Serial.print(cm);
  //Serial.println();
  //SERVO
  if (cm < 30)
  {                              
    myservo.write(pos); // tell servo to go to position in variable 'pos' 
    delay(15); // waits 15ms for the servo to reach the position
    if (pos != 180)
    {
      pos = pos + 15; 
    }
    else
    {
      pos = 0;
    }
  delay(250);
  }
}
