#include "Prog.h"
#include <Wire.h>
#include <Zumo32U4.h>

Program p;

/* Possible commands:
 *    p.forward( distance in inches)
 *    p.reverse( distance in inches)
 *    p.right( angle in degrees)
 *    p.left(  angle in degrees)
 */
 
volatile bool flag = false;
volatile byte myArray[8];
Zumo32U4LCD lcd;

void setup()
{
  Serial.begin(9600);
  Wire.begin(0x21); //7-bit address = 0100001 
  Wire.onReceive(receiveEvent);
  lcd.clear();
  lcd.print("I2C wait");
  delay(1000);
}

void loop()
{
   if (flag == true)
  {
    int value = (myArray[1]<<8)| myArray[2];
    int decimal = (myArray[3]<<8) | myArray[4];
    float argument = value + decimal/256.0f;
    int command = myArray[0];

    flag = false;
    lcd.clear();
    lcd.print(command);
    lcd.gotoXY(0,1);
    lcd.print(argument);

    switch(command){
      case 1: // forward(inches)
      p.forward(argument);
      break;
      case 2: // reverse(inches)
      p.reverse(argument);
      break;
      case 3: // right(degrees)
      p.right(argument);
      break;
      case 4: // left(degrees)
      p.left(argument);
      break;
    }
    
  }
  //received messages are interpreted and added to the move queue
  p.update(); //UI, user must press A before anything will run
}

void receiveEvent(int howMany)
{
  for(int i=0; i<howMany; i++)
  {
    myArray[i] = Wire.read();
    // should read 5 bytes in, 
  }
  flag = true;
}
