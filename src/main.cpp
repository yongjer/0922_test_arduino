// 28BYJ-48 Stepper Motor Control with ULN2003 Driver
// Pinout: IN1 -> D10, IN2 -> D11, IN3 -> D12, IN4 -> D13

#include <Arduino.h>
#include <AccelStepper.h>

// Define pin connections
const int IN1 = 10;
const int IN2 = 11;
const int IN3 = 12;
const int IN4 = 13;

// Define motor interface type
#define HALFSTEP 8

// Initialize with pin sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper stepper(HALFSTEP, IN1, IN3, IN2, IN4);

void setup() {
  // Set the maximum speed in steps per second
  stepper.setMaxSpeed(1000);
  // Set the acceleration in steps per second per second
  stepper.setAcceleration(500);
}

void loop() {
  // Set the target position
  stepper.moveTo(4096); // Full rotation (8 steps per rotation * 64 gear reduction)
  
  // Run to target position with set speed and acceleration
  stepper.runToPosition();
  
  // Wait for 1 second
  delay(1000);
  
  // Move back to the original position
  stepper.moveTo(0);
  stepper.runToPosition();
  
  // Wait for 1 second
  delay(1000);
}