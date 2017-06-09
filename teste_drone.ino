#include <Servo.h>
 


#define BUFFER_SIZE 15
Servo esc;
int throttle = 0;
int vel = 0;
int velocity = 0;
int data[15];
int buffer_position = 0;
int string_complete = 0;
int end_write = 0;
int cent = 0;
int dec = 0;
int uni = 0;


void buffer_add(char c)// saves UART message in the buffer
{
  if (buffer_position < BUFFER_SIZE)
  {
    data[buffer_position] = c;
    buffer_position += 1;

  }
}

void serialEvent() // receives UART messages and saves it in the buffer
{
  char c;
  while(Serial.available() > 0)
  {
      c = Serial.read();
      if (c == '\n')
      {
        buffer_add('\0');
        end_write = 1;
        buffer_position = 0;
        string_complete = 1;
      }
      else
      {
        buffer_add(c);
      }
  }
  cent = data[0] - 48;
  dec =  data[1] - 48;
  uni =  data[2] - 48;
  vel = (cent*100) + (dec*10) + uni;

}


void clean_buffer()
{
  for (int i = 0; i < BUFFER_SIZE; ++i)
  {
    data[i] = '\0';
    buffer_position = 0;
    string_complete = 0;
  }
}


Servo esc;

 
void setup()
{
  Serial.begin(57600);
  esc.attach(3);
}
 
void loop()
{
  esc.write()
  
}