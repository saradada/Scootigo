#include <NewPing.h>
#include <Servo.h>

#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 400 // Maximum distance (in cm) to ping.

long sensorLeft, sensorRight;

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(9, 10, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping. 
  NewPing(11,12, MAX_DISTANCE)
};

Servo myServo; // creates servo object to control servo
int pos = 0; //variable to store the sevo position

void setup() {
  myServo.attach(8);
}

void loop() { 
  for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through each sensor and display results.
    delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    myServo.write(pos);
    if (i == 0)
    {
      //RIGHT SIDE, echoPin = 10; 
      if (sonar[i].ping_cm() < 30)
      {
        if (pos != 180)
        {
          pos = pos + 15; 
        }
        else
        {
          pos = 90;
        }
      }
    }
    else if (i == 1)
    {
      //LEFT SIDE, echoPin = 12;
      if (sonar[i].ping_cm() < 30)
      {
        if (pos != 180)
        {
          pos = pos - 15; 
        }
        else
        {
          pos = 90;
        }
      }
    }
  }
}

