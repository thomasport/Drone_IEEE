#include <Servo.h>

#define CH1 5
#define CH2 6
#define CH3 7
#define CH4 8

Servo esc1, esc2, esc3, esc4;


int climb; // elevation
int roll; // left right
int pitch; // forward backward
int yaw; // turn clockwise counterclockwise

void setup()
{
  Serial.begin(9600);
  /*esc1.attach(6);
  esc2.attach(9);
  esc3.attach(10);
  esc4.attach(11);*/
  
}
 
void loop()
{
  yaw = pulseIn(CH1,HIGH); //min-max -> 1041-1846
  climb = pulseIn(CH2, HIGH); //min-max -> 1138-1939
  roll = pulseIn(CH4, HIGH); //min-max -> 1030-1843
  pitch = pulseIn(CH3, HIGH); //min-max -> 1050-1854


  /*climb = map(elevation, 968, 1950, 0, 160);
  roll = map(leftRight, 900, 1900, -22, 22);
  pitch = map(fowBack, 900, 1900, -22, 22);*/

  Serial.print("yaw = ");
  Serial.print(yaw);
  Serial.print("  ");
  
  Serial.print("climb = ");
  Serial.print(climb);
  Serial.print("  ");

  Serial.print("roll = ");
  Serial.print(roll);
  Serial.print("  ");

  Serial.print("pitch = ");
  Serial.println(pitch);
  
  /*esc1.write(elevation + leftRight - fowBack);
  esc2.write(elevation + leftRight + fowBack);
  esc3.write(elevation - leftRight + fowBack);
  esc4.write(elevation - leftRight - fowBack);*/
}
