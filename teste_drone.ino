#include <Servo.h>
 
Servo esc1, esc2, esc3, esc4;

long elevation, leftRight, fowBack;



// 

void setup()
{
  Serial.begin(9600);
  esc1.attach(6);
  esc2.attach(9);
  esc3.attach(10);
  esc4.attach(11);
  
}
 
void loop()
{
  elevation = pulseIn(7, HIGH); // CH2
  leftRight = pulseIn(8, HIGH); // CH1
  fowBack = pulseIn(12, HIGH); // CH3

  elevation = map(elevation, 968, 1950, 0, 160);
  leftRight = map(leftRight, 900, 1900, -22, 22);
  fowBack = map(fowBack, 900, 1900, -22, 22);

  
  Serial.print("elevation = ");
  Serial.println(elevation);

  Serial.print("leftRight = ");
  Serial.println(leftRight);

  Serial.print("fowBack = ");
  Serial.println(fowBack);
  
  esc1.write(elevation + leftRight - fowBack);
  esc2.write(elevation + leftRight + fowBack);
  esc3.write(elevation - leftRight + fowBack);
  esc4.write(elevation - leftRight - fowBack);
}