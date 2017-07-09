int trigPin1 = 9; 
int echoPin1 = 10;
int trigPin2 = 11;
int echoPin2 = 12;
long duration1, duration2, cm1, cm2, inches;

#include <Servo.h>

Servo servo1; // create servo object to control sevo
int pos = 0;    // variable to store the servo position 
void setup() {
  //start serial
  //Serial.begin (115200);
  //Define inputs and outputs
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  servo1.attach(8);// attach servo to pin 8 to the servo object

}

void loop() {
  
  // ultrasonic is triggered by a HIGH pulse of 10 or more microseconds
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW); // should i repeat this step w/ the delay?
  delayMicroseconds(5);
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH); // see above
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW); 
  digitalWrite(trigPin2, LOW); // see above
  
  // Read the signal from the ultrasonic sensor: a HIGH pulse whose
  // duration1 is the time in microseconds from the sending 
  // of the ping to the reception of its echo off an object.
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  duration2 = pulseIn(echoPin2, HIGH);
  
  //Convert time into distance (ultrasonic)
  cm1 = (duration1/2)/29.1;
  cm2 = (duration2/2)/29.1;
  //Serial.print(cm1);
  //Serial.println();
  //SERVO
  if (cm1 < 30)
  {                              
    servo1.write(pos); // tell servo to go to position in variable 'pos' 
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

  if (cm2 < 30)
  {                              
    servo1.write(pos); // tell servo to go to position in variable 'pos' 
    delay(15); // waits 15ms for the servo to reach the position
    if (pos != 180)
    {
      pos = pos - 15; 
    }
    else
    {
      pos = 0;
    }
  delay(250);
  }
}
