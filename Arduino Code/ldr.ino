#define left A0  // sensor's left
#define right A1 // sensor's right
#define up A2  // sensor's up
#define down A3 // sensor's down

int threshold = 25;
int pos1 =90;
int pos2 =90;

#include <Servo.h>
Servo servo1,servo2;      //initialize a servo object for the connected servo  

void setup() 
{
  servo1.attach(9);servo2.attach(10);   // attach the signal pin of servo to pin9 of arduino
 pinMode(left, INPUT);
 pinMode(up, INPUT);
 pinMode(down, INPUT);
 pinMode(right, INPUT); 
 Serial.begin(9600);
}
int direction1()
{
  int r=analogRead(right),l=analogRead(left);
  int rt=map(analogRead(right),520,960,0,100),lt=map(analogRead(left),700,960,0,100);// 0 - dark and 1023 - light
  //Serial.print(r);Serial.print(", ");Serial.print(l);
  return rt-lt;
}
int direction2()
{
  int r=analogRead(up),l=analogRead(down);
  int rt=map(analogRead(up),400,930,0,100),lt=map(analogRead(down),130,730,0,100);// 0 - dark and 1023 - light
  //Serial.print(r);Serial.print(", ");Serial.print(l);
  return rt-lt;
}
void loop() 
{
 int dir2 = direction2(),dir1 = direction1(),r=0,l=0;
  if(dir2>threshold){Serial.print("Moving up...");pos2-=2;}
  else if(dir2<-1*threshold){Serial.print("Moving down...");pos2+=2;}
  else r=1;
  if(dir1>threshold){Serial.print("Moving right...");pos1+=2;}
  else if(dir1<-1*threshold){Serial.print("Moving left...");pos1-=2;}
  else l=1;
  if(pos2>180)pos2=180;if(pos2<0)pos2=0;if(pos1>180)pos1=180;if(pos1<0)pos1=0;
  if(r&l){Serial.print("Sun at focus...");}
  else{
  Serial.println(pos1);servo1.write(pos1);
  Serial.println(pos2);servo2.write(pos2);}
}
