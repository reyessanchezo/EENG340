/* 
  A simple way to run the Zumo bot in a programmed fashion.  In setup() below, add commands
  for what you want the robot to do.  Once compiled and uploaded the commands will be run in 
  sequence.

  Paul G. Talaga
  Aug 2017
  */

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

void setup()
{
 /*
 p.forward(6);
 p.left(90);
 p.forward(10.5);
 p.right(45);
 p.forward(4.5);
 p.left(90);
 p.forward(9.5);
 p.right(90);
 p.forward(7);
 p.right(90);
 p.forward(19);
 p.right(90);
 p.forward(5);
 p.left(45);//maybe wrong
 p.forward(4);
 p.left(40);
 p.forward(4);
 p.left(40);
 p.forward(4);
 p.right(30);
 p.forward(6.5);
 p.right(45);
 p.forward(7);
 p.right(40);
 p.forward(7);
 p.left(110);
 p.forward(9);//finish???
 */
 
 
 
}

void loop()
{
  // This is the function in the Program class which runs all instructions.
  p.forward(0.5);
  p.reverse(0.5);
  p.update();
}
