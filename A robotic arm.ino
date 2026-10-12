/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-mg996r
 */

#include <Servo.h>

Servo servoBase, servoShoulder, servoElbow, servoWrist, servoRotation, servoGripper;  // create servo object to control a servo

void setup() {
  Serial.begin(9600);
  servoBase.attach(3);  // attaches the servo on pin 9 to the servo objectư
  servoShoulder.attach(5);  // attaches the servo on pin 9 to the servo objectư
  servoElbow.attach(6);  // attaches the servo on pin 9 to the servo objectư
  servoWrist.attach(9);  // attaches the servo on pin 9 to the servo objectư
  servoRotation.attach(10);  // attaches the servo on pin 9 to the servo objectư
  servoGripper.attach(11);  // attaches the servo on pin 9 to the servo objectư
  //servo.write(0);   // rotate slowly servo to 0 degrees immediately
  moveServoSmoothly(servoBase, 0);
  moveServoSmoothly(servoShoulder, 50);
  moveServoSmoothly(servoWrist, 0);

  delay(1000);
}

void loop() {

  moveServoSmoothly(servoBase, 180);
  delay(1000);

  moveServoSmoothly(servoBase, 0);
  delay(1000);
}

void moveServoSmoothly(Servo servo, int targetPosition) {
  int currentPosition = servo.read();

  int increment = (targetPosition > currentPosition) ? 1 : -1;

  for (int pos = currentPosition; pos != targetPosition; pos += increment) {
    servo.write(pos);
    delay(15); // Delay for smoother movement, adjust as needed
  }
} 
