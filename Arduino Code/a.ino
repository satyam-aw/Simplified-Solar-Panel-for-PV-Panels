#include <Servo.h>
Servo servo_test;      //initialize a servo object for the connected servo  
                
 void setup() 
 { 
  servo_test.attach(9);   // attach the signal pin of servo to pin9 of arduino
  } 
 
 void loop() 
 { 
  servo_test.write(90);                   //command to rotate the servo to the specified angle 
  }  
